#include "algo.h"
#include "lifo_int.h"
#include "tadhash.h"
#include "space.h"
#include "assert.h"

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
  parcours = lifo_delete(parcours);
}

void affichage_chemin(int depart, int arrivee,double max_x,double max_y,double min_x,double min_y, graph_t g,SDL_PHWindow* f1)
{
  //on cree la pile et on empile l'arrivée
  lifo_int_t parcours = lifo_new();
  int numero1,numero2;
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
  numero1 = lifo_pop(&parcours);
  while(!lifo_is_empty(parcours))
  {
    numero2 = lifo_pop(&parcours);
    trace_arc(f1,g.data[numero1].x,g.data[numero1].y,g.data[numero2].x,g.data[numero2].y,max_x,max_y,min_x,min_y,SDL_PH_RED);
    numero1 = numero2;
  }
  SDL_PH_FlushWindow(f1);
}

//retourne le graph construit et prend en fonction la hashtable
graph_t creation_graph(FILE* f,hashtable_t* tab_station, int* nb_espace)
{
  int depart,arrivee,count,choix,res=0;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv;
  double val;
  double lat,longi;
  char** line=NULL ;
  char** name=NULL ;
  char mot[512];
  graph_t g;


  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  fscanf(f,"%d %d ",&nbsommet,&nbarcs);
  fgets(mot,511,f);
  line =  calloc(nbsommet,sizeof(*line));
  if (line==NULL) { printf("erreur alloaction tableau de char line\n"); exit(EXIT_FAILURE);}
  *line = calloc(nbsommet*128,sizeof(**line));
  if (*line==NULL) { printf("erreur alloaction tableau de char *name\n");free(line); exit(EXIT_FAILURE);}
  name =  calloc(nbsommet,sizeof(*name));
  if (name==NULL) { printf("erreur alloaction tableau de char name\n"); exit(EXIT_FAILURE);}
  *name = calloc(nbsommet*128,sizeof(**name));
  if (*name==NULL) { printf("erreur alloaction tableau de char *name\n");free(name); exit(EXIT_FAILURE);}
  g = graph_new(nbsommet,nbarcs);
  for(indice=1;indice<nbsommet;indice++)
  {
    name[indice]=name[indice-1]+128;
    line[indice]=line[indice-1]+128;
  }
  for(indice=0;indice<g.size_vertices;indice++)                 //Boucle pour rensigner les sommets dans le graph
  {

    fscanf(f,"%d %lf %lf %s", &numero, &lat, &longi, line[indice]);
    //strcat(line, " ");
    fgets(name[indice],128,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    g.data[indice] = vertex_new(numero, line[indice], longi, lat,name[indice]);
    if(hashtable_put(name[indice],numero,*tab_station)==0){printf("cle non presente dans la table de hashage");} // on ajoute a notre table de hash le nouveau somme
  }
  fgets(mot,511,f);
  *nb_espace = count_space(mot); // add_space(char* station) (rajouter aussi \n) strcat(mot,"\n")
  for(indice=0;indice<g.size_egdes;indice++)                  //Boucle pour rensigner les arcs dans le graph
  {
    fscanf(f,"%d %d %lf ",&noeud_dep,&noeud_arriv,&val);
    g.data[noeud_dep].edges = listedge_add(edge_new(noeud_arriv,(double)val),g.data[noeud_dep].edges );
  }
  for(count=0;count<g.size_vertices;count++)                //renseigne la longueur leqs listes
  {
    g.data[count].sizeedges = listedge_size(g.data[count].edges);
  }
  free(*name);
  free(*line);
  free(line);      //possiblement faux (a verifier sur linux)
  free(name);
  return g;
}

graph_t creation_graph_affichage(FILE* f,double *  max_x,double* max_y,double* min_x,double* min_y,hashtable_t* tab_station, int* nb_espace,SDL_PHWindow* f1)
{
  int depart,arrivee,count,choix,res=0;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv;
  double val;
  double lat,longi;
  char** line=NULL ;
  char** name=NULL ;
  char mot[512];
  graph_t g;


  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  fscanf(f,"%d %d ",&nbsommet,&nbarcs);
  fgets(mot,511,f);
  line =  calloc(nbsommet,sizeof(*line));
  if (line==NULL) { printf("erreur alloaction tableau de char line\n"); exit(EXIT_FAILURE);}
  *line = calloc(nbsommet*128,sizeof(**line));
  if (*line==NULL) { printf("erreur alloaction tableau de char *name\n");free(line); exit(EXIT_FAILURE);}
  name =  calloc(nbsommet,sizeof(*name));
  if (name==NULL) { printf("erreur alloaction tableau de char name\n"); exit(EXIT_FAILURE);}
  *name = calloc(nbsommet*128,sizeof(**name));
  if (*name==NULL) { printf("erreur alloaction tableau de char *name\n");free(name); exit(EXIT_FAILURE);}
  g = graph_new(nbsommet,nbarcs);
  for(indice=1;indice<nbsommet;indice++)
  {
    name[indice]=name[indice-1]+128;
    line[indice]=line[indice-1]+128;
  }
  for(indice=0;indice<g.size_vertices;indice++)                 //Boucle pour rensigner les sommets dans le graph
  {

    fscanf(f,"%d %lf %lf %s", &numero, &lat, &longi, line[indice]);
    //strcat(line, " ");
    fgets(name[indice],128,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    g.data[indice] = vertex_new(numero, line[indice], longi, lat,name[indice]);
    max_x_y(max_x,max_y,min_x,min_y, lat, longi); //permet de trouver les max des coordonnes
    if(hashtable_put(name[indice],numero,*tab_station)==0){printf("cle non presente dans la tablle de hashage");} // on ajoute a notre table de hash le nouveau somme
  }
  fgets(mot,511,f);
  *nb_espace = count_space(mot); // add_space(char* station) (rajouter aussi \n) strcat(mot,"\n")
  for(indice=0;indice<g.size_egdes;indice++)                  //Boucle pour rensigner les arcs dans le graph
  {

    fscanf(f,"%d %d %lf ",&noeud_dep,&noeud_arriv,&val);
    g.data[noeud_dep].edges = listedge_add(edge_new(noeud_arriv,(double)val),g.data[noeud_dep].edges );
    trace_arc(f1,g.data[noeud_dep].x,g.data[noeud_dep].y,g.data[noeud_arriv].x,g.data[noeud_arriv].y,*max_x,*max_y,*min_x,*min_y,SDL_PH_BLACK);
  }
  for(count=0;count<g.size_vertices;count++)                //renseigne la longueur des listes
  {
    g.data[count].sizeedges = listedge_size(g.data[count].edges);
  }
  free(*name);
  free(*line);
  free(line);      //possiblement faux (a verifier sur linux)
  free(name);
  return g;
}

int choix_int_algo(graph_t g)
{
  int depart,arrivee,choix,res;
  printf("Choisissez l'algorithme a utiliser :\n1 : Dijkstra\n2 : A*\n");
  scanf("%d",&choix);
  if(choix==1)
  {
    puts("DEBUT DIJKSTRA");
    printf("Choisissez le numero de la station depart : ");
    scanf("%d",&depart);
    printf("Choisissez le numero de la station arrivee : ");
    scanf("%d",&arrivee);
    res = Dijkstra(depart,arrivee,g);
  }
  else if(choix==2)
  {
    puts("DEBUT A*");printf("Choisissez le numero de la station depart : ");
    scanf("%d",&depart);puts("");
    printf("Choisissez le numero de la station arrivee : ");
    scanf("%d",&arrivee);
    res = Astar(depart,arrivee,g);
  }
  else{printf("Error : wrong input");exit(0);}
  if(res==1){printf("Chemin le plus court : ");print_chemin(depart,arrivee,g);}
  puts("suppression graph et liste..."); //suppresion du graphe
  //fonction a ne pas oublier après : fclose(f)
  return g.data[arrivee].cout;
}

int choix_char_algo(graph_t g,hashtable_t* tab_station)
{
  int choix,res,cout;
  char* depart=NULL;int num_depart;
  char* arrivee=NULL;int num_arrivee;
  printf("Choisissez l'algorithme a utiliser :\n1 : Dijkstra\n2 : A*\n");
  if(scanf("%d",&choix)==1){fgetc( stdin );}
  else{choix = 0;}
  depart = malloc(128);
  arrivee = malloc(128);
  res =0;
  if(choix==1)
  {
    puts("DEBUT A*");printf("Choisissez le numero de la station depart : ");
    scanf( "%[^\n]", depart );
    fgetc( stdin );
    printf("Choisissez le numero de la station arrivee : ");
    scanf( "%[^\n]", arrivee );puts("");fgetc( stdin );
    depart = add_space(depart,count_space(g.data[1].nom));
    arrivee = add_space(arrivee,count_space(g.data[1].nom));
    if(!(hashtable_get_value(depart, &num_depart, *tab_station)&&hashtable_get_value(arrivee, &num_arrivee, *tab_station))){printf("une des station n'existe pas");}
    else{
      g = same_name(g,num_depart);
      g = same_name(g,num_arrivee);
      res = Dijkstra(num_depart,num_arrivee,g);
      printf("resultat : %d",res);puts("");
    }
  }

  else if(choix==2)
  {
    puts("DEBUT A*");printf("Choisissez le numero de la station depart : ");
    scanf( "%[^\n]", depart );
    fgetc( stdin );
    printf("Choisissez le numero de la station arrivee : ");
    scanf( "%[^\n]", arrivee );puts("");fgetc( stdin );
    depart = add_space(depart,count_space(g.data[5].nom));
    arrivee = add_space(arrivee,count_space(g.data[5].nom));

    if(!(hashtable_get_value(depart, &num_depart, *tab_station)&&hashtable_get_value(arrivee, &num_arrivee, *tab_station))){printf("une des station n'existe pas");exit(0);}

    g = same_name(g,num_depart);
    g = same_name(g,num_arrivee);
    res = Astar(num_depart,num_arrivee,g);
    printf("resultat : %d",res);puts("");
  }
  else{printf("Error : wrong input");exit(0);}
  if(res==1){printf("Chemin le plus court : ");print_chemin(num_depart,num_arrivee,g); cout = g.data[num_arrivee].cout;}
  else{cout = -1;}
  free(depart);free(arrivee);
  return cout;
}

int choix_char_algo_affichage(graph_t g,double max_x,double max_y,double min_x,double min_y,hashtable_t* tab_station,SDL_PHWindow* f1)
{
  int choix,res;
  char* depart=NULL;int num_depart;
  char* arrivee=NULL;int num_arrivee;
  printf("Choisissez l'algorithme a utiliser :\n1 : Dijkstra\n2 : A*\n");
  scanf("%d",&choix);fgetc( stdin );
  depart = malloc(128);
  arrivee = malloc(128);
  if(choix==1)
  {
    puts("DEBUT A*");printf("Choisissez le numero de la station depart : ");
    scanf( "%[^\n]", depart );
    fgetc( stdin );
    printf("Choisissez le numero de la station arrivee : ");
    scanf( "%[^\n]", arrivee );puts("");fgetc( stdin );
    depart = add_space(depart,count_space(g.data[1].nom));
    arrivee = add_space(arrivee,count_space(g.data[1].nom));
    if(!(hashtable_get_value(depart, &num_depart, *tab_station)&&hashtable_get_value(arrivee, &num_arrivee, *tab_station))){printf("une des station n'existe pas");exit(0);}

    g = same_name(g,num_depart);
    g = same_name(g,num_arrivee);
    res = Dijkstra(num_depart,num_arrivee,g);
    printf("resultat : %d",res);puts("");
    free(depart);free(arrivee);
  }

  else if(choix==2)
  {
    puts("DEBUT A*");printf("Choisissez le numero de la station depart : ");
    scanf( "%[^\n]", depart );
    fgetc( stdin );
    printf("Choisissez le numero de la station arrivee : ");
    scanf( "%[^\n]", arrivee );puts("");fgetc( stdin );
    depart = add_space(depart,count_space(g.data[5].nom));
    arrivee = add_space(arrivee,count_space(g.data[5].nom));

    if(!(hashtable_get_value(depart, &num_depart, *tab_station)&&hashtable_get_value(arrivee, &num_arrivee, *tab_station))){printf("une des station n'existe pas");exit(0);}

    g = same_name(g,num_depart);
    g = same_name(g,num_arrivee);
    res = Astar(num_depart,num_arrivee,g);
    free(depart);free(arrivee);
  }
  else{printf("Error : wrong input");exit(0);}
  if(res==1){affichage_chemin(num_depart,num_arrivee,max_x,max_y,min_x,min_y,g,f1);printf(" Appuyez sur ENTREE pour supprimer") ;
  getchar() ;}
  else {printf("chemin impossible\n");}
  *tab_station = hashtable_delete(*tab_station);
  //fonction a ne pas oublier après : fclose(f)
  int cout = g.data[num_arrivee].cout;
  g = graph_delete(g);
  return cout;
}

graph_t same_name(graph_t g, int numero)
{
  char* nom = g.data[numero].nom;
  listedge_t liste = g.data[numero].edges;
  int k,nb=0;
  int longueur;
  longueur = listedge_size(g.data[numero].edges);
  for(k=0;k<longueur;k++)
  {
    if(strcmp(nom,g.data[liste->val.arrivee].nom)==0)
    {
      g.data[numero].edges = listedge_add(edge_new(liste->val.arrivee,0),g.data[numero].edges);
      nb++;
    }
    liste = liste->next;
  }
  g.data[numero].sizeedges+=nb;
  return g;
}
