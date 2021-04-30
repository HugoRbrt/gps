#include "algo.h"
#include "lifo_int.h"
#include "tadhash.h"
int Dijkstra(int depart, int arrivee, graph_t g)
{
  list_t Atraiter = list_new();   //ligne 1
  list_t Atteint = list_new();
  listedge_t l;
  int indice,k;
  double DistTemp;
  vertex_t * u=NULL;
  vertex_t * v=NULL;
  if((depart<0)||(depart>g.size_vertices)||(arrivee<0)||(arrivee>g.size_vertices)){Atteint = list_delete(Atteint);Atraiter = list_delete(Atraiter);return 0;}//si la station n'existe pas

  for(indice=0;indice<g.size_vertices;indice++) //ligne 2
  {
    g.data[indice].pcc = DBL_MAX;
    g.data[indice].cout = DBL_MAX;
  }
  g.data[depart].pcc = 0; //ligne 3
  g.data[depart].cout = 0;
  Atraiter = list_addsort( &g.data[depart], Atraiter);//ligne 4

  while(!list_isempty(Atraiter))//ligne 5
  {
    u = Atraiter->v;    //ligne 6
    Atraiter = list_delfirst(Atraiter);
    if(u->numero == arrivee)//ligne 7
    {
      Atteint = list_delete(Atteint);Atraiter = list_delete(Atraiter);
      return 1;//ligne 8
    }
    else//ligne9
    {//ligne10 de commentaire
      Atteint = list_addfirst(u,Atteint);//ligne11
      l = u->edges;//ligne12
      for(indice=0;indice<u->sizeedges;indice++)
      {
        DistTemp = u->pcc + l->val.cout;//ligne13
        v = &g.data[l->val.arrivee];
        if((NULL==list_findnum(v->numero,Atteint))&&(DistTemp<v->pcc))//ligne14
        {//ligne15 de commentaire
          v->cout = DistTemp;//ligne16
          v->pcc=DistTemp;//ligne17
          v->pere = u->numero;//trouver chemin
          Atraiter = list_addsort(v,Atraiter);//ligne18
        }//ligne19 de commentaire
        l = l->next;
      }//ligne20 de commentaire
    }//ligne21 de commentaire
  }//ligne22 de commentaire
  Atteint = list_delete(Atteint);Atraiter = list_delete(Atraiter);
  if(g.data[arrivee].cout<DBL_MAX)//ligne23
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int Astar(int depart, int arrivee, graph_t g)
{
  list_t Atraiter = list_new();   //ligne 1
  list_t Atteint = list_new();
  listedge_t l;
  int indice,k;
  double DistTemp;
  vertex_t * u=NULL;
  vertex_t * v=NULL;
  if((depart<0)||(depart>g.size_vertices)||(arrivee<0)||(arrivee>g.size_vertices)){Atteint = list_delete(Atteint);Atraiter = list_delete(Atraiter);return 0;}//si la station n'existe pas
  for(indice=0;indice<g.size_vertices;indice++) //ligne 2
  {
    g.data[indice].pcc = DBL_MAX;
    g.data[indice].cout = DBL_MAX;
  }
  g.data[depart].pcc = 0; //ligne 3
  g.data[depart].cout = 0;
  Atraiter = list_addsort( &g.data[depart], Atraiter);//ligne 4
  while(!list_isempty(Atraiter))//ligne 5
  {
    u = Atraiter->v;    //ligne 6
    Atraiter = list_delfirst(Atraiter);
    if(u->numero == arrivee)//ligne 7
    {
      Atteint = list_delete(Atteint);Atraiter = list_delete(Atraiter);
      return 1;//ligne 8
    }
    else//ligne9
    {//ligne10 de commentaire
      Atteint = list_addfirst(u,Atteint);//ligne11
      l = u->edges;//ligne12
      for(indice=0;indice<u->sizeedges;indice++)
      {
        DistTemp = u->pcc + l->val.cout;//ligne13
        v = &g.data[l->val.arrivee];
        if((NULL==list_findnum(v->numero,Atteint))&&(DistTemp<v->pcc))//ligne14
        {//ligne15 de commentaire
          v->cout = DistTemp+heuristique(*v,g.data[arrivee]);//ligne16
          v->pcc=DistTemp;//ligne17
          v->pere = u->numero;//trouver chemin
          Atraiter = list_addsort(v,Atraiter);//ligne18
        }//ligne19 de commentaire
        l = l->next;
      }//ligne20 de commentaire
    }//ligne21 de commentaire
  }//ligne22 de commentaire
  Atteint = list_delete(Atteint);Atraiter = list_delete(Atraiter);
  if(g.data[arrivee].cout<DBL_MAX)//ligne23
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

double heuristique(vertex_t v, vertex_t a)
{
  return (fabs(v.x - a.x) + fabs(v.y - a.y ))/2 ;
}

void print_chemin(int depart, int arrivee, graph_t g)
{
  //on cree la pile et on empile l'arrivée
  lifo_int_t parcours = lifo_new();
  //printf("Chemin pour aller de %d a %d :",depart, arrivee);puts("");
  int indice = arrivee;
  while(indice != depart)
  {
    //on empile tout nos stations
    //printf("%d <- ",indice);
    parcours = lifo_push(indice,parcours);
    indice = g.data[indice].pere;
  }
  parcours = lifo_push(depart,parcours);
  //la liste est complete il ne reste plus qu a l'afficher
  //printf("%d",indice);puts("");
  lifo_print(parcours,g);
}
//retourne le graphe construit et prend en fonction la hashtable
graphe_t creation_graphe(hashtable_t* tab_station)
{
  int depart,arrivee,count,choix,res=0;
  FILE* f;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv;
  double val;
  double lat,longi;
  char* Ligne;
  char mot[512];
  graph_t g;
  *tab_station = hashtable_new(26); //reste a definir m; ~le nombre de station differente pour le metro

  f=fopen("text/metroetu.txt","r");

  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  fscanf(f,"%d %d ",&nbsommet,&nbarcs);
  fgets(mot,511,f);
  Ligne = malloc(129*nbsommet+1);
  g = graph_new(nbsommet,nbarcs);
  for(indice=0;indice<g.size_vertices;indice++)                 //Boucle pour rensigner les sommets dans le graph
  {

    fscanf(f,"%d %lf %lf %s", &numero, &lat, &longi, Ligne+(128*indice));
    strcat(Ligne, " ");
    fgets(mot,511,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    g.data[indice] = vertex_new(numero, Ligne+(indice*128), longi, lat);
    *tab_station = hashtable_put(ligne,numero,tab_station); // on ajoute a notre table de hash le nouveau sommet
  }
  fgets(mot,511,f);
  for(indice=0;indice<g.size_egdes;indice++)                  //Boucle pour rensigner les arcs dans le graph
  {
    fscanf(f,"%d %d %lf ",&noeud_dep,&noeud_arriv,&val);
    g.data[noeud_dep].edges = listedge_add(edge_new(noeud_arriv,(double)val),g.data[noeud_dep].edges );
  }
  for(count=0;count<g.size_vertices;count++)                //renseigne la longueur leqs listes
  {
    g.data[count].sizeedges = listedge_size(g.data[count].edges);
  }
  return g;
}

int choix_algo(graphe_t g)
{
  char * debut;
  char * arrivee;
  printf("Choisissez l'algorithme a utiliser :\n1 : Dijkstra\n2 : A*\n");
  scanf("%d",&choix);
  if(choix==1)
  {
    puts("DEBUT DIJKSTRA");
    printf("Choisissez le nom de la station depart : ");
    scanf("%s",&depart);
    printf("Choisissez le nom de la station arrivee : ");
    scanf("%s",&arrivee);puts("");
    res = Dijkstra(depart,arrivee,g);
    printf("resultat : %d",res);puts("");
    tab_station = hashtable_delete(tab_station);
  }
  else if(choix==2)
  {
    puts("DEBUT A*");printf("Choisissez le numero de la station depart : ");
    scanf("%d",&depart);puts("");
    printf("Choisissez le numero de la station arrivee : ");
    scanf("%d",&arrivee);puts("");
    res = Astar(depart,arrivee,g);
    printf("resultat : %d",res);puts("");
    tab_station = hashtable_delete(tab_station);

  }
  else{printf("Error : wrong input");exit(0);}
  if(res==1){printf("Chemin le plus court : ");print_chemin(depart,arrivee,g);}

  puts("suppression graph et liste...");
  g = graph_delete(g);
  tab_station = hashtable_delete(tab_station);
  puts("*fin*");
  fclose(f);
  return g.data[arrivee].cout;
}
