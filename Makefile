# Ce Makefile permet de générer les executables
# - pour les tests f1main et f2main du repertoire tests
#-  pour le programme pccmain du repertoire src

# les fichiezrs executables sont situés sdnas le repertoire bin


#Les repertoires
#Pour les fichiers d'entete
INCDIR=./include
#Pour les fichiers executables
BINDIR=./bin
#Pour les fichiers binaires (.o)
OBJDIR=./obj
#Pour les fichiers de tests
TESTS=./tests
#Pour les fichiers sources .c
SRCDIR=./src

#Le nom du compilateur
CC=gcc

#Les options du compilateur : compilation (-c) et debug (-g). On peut ajouter -O3 pour optimiser quand le code est juste
CFLAGS=-c -g -I$(INCDIR)

#Les options de l'editeur de liens : -lm pour la bibliothèque mathématique. Voir les Makefile de TP pour ajouter la SDL si besoin
LDFLAGS= -lm

#Les executables que l'on veut construire: a la fois ceux des tests et ceux des programmes finaux
EXEDIR=$(BINDIR)/pccmain $(BINDIR)/graph $(BINDIR)/arc $(BINDIR)/test_edge $(BINDIR)/test_readprint


#Les fichiers binaire : ajouter les noms des nouveaux fichiers ici
OBJ=$(OBJDIR)/arc.o $(OBJDIR)/graph.o

#Pour construire tous les executables
all: $(EXEDIR)

#pour construire pccmain qui utilise tous les fichiers binaires
$(BINDIR)/pccmain : $(OBJ) $(OBJDIR)/pccmain.o
	$(CC) -o $@ $^ $(LDFLAGS)

#pour construire le test test_edge qui utilise arc.o
$(BINDIR)/test_edge : $(OBJDIR)/arc.o $(OBJDIR)/test_edge.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINDIR)/test_graph : $(OBJDIR)/graph.o $(OBJDIR)/arc.o $(OBJDIR)/test_graph.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINDIR)/test_readprint : $(OBJ) $(OBJDIR)/test_readprint.o
	$(CC) -o $@ $^ $(LDFLAGS)

# pour construire les fichiers binaires .o
$(OBJDIR)/%.o : $(TESTS)/%.c
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/* $(EXEDIR) *.dSYM
