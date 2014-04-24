CC = g++

PATH_SRC = src
PATH_OBJ = obj
PATH_DOC = doc
PATH_LIB = lib
PATH_BIN = bin
PATH_TST = tests
PATH_INC = include

FLAGS_DBG = -g -Wall
FLAGS_CC = -std=c++98 -pedantic $(FLAGS_DBG)
FLAGS_INC = -I$(PATH_INC)
FLAGS_LIB = -L$(PATH_LIB)

vpath %.cpp $(PATH_SRC)
vpath %.hpp $(PATH_INC)
vpath %.o $(PATH_OBJ)
vpath %.a $(PATH_LIB)

all: main

%.o: %.cpp | obj_dir
		$(CC) $(FLAGS_CC) $(FLAGS_INC) -o $(PATH_OBJ)/$@ -c $<

main: main.o libqlot.a | bin_dir
	$(CC) $(FLAGS_LIB) -o $(PATH_BIN)/$@ $(PATH_OBJ)/main.o -lqlot

date.o: date.cpp date.hpp
pourcentage.o: pourcentage.cpp pourcentage.hpp
reference_article.o: reference_article.cpp reference_article.hpp
article.o: article.cpp article.hpp date.hpp reference_article.hpp
stock.o: stock.cpp stock.hpp article.hpp
article_vendu.o: article_vendu.cpp article_vendu.hpp reference_article.hpp
vente.o: vente.cpp vente.hpp date.hpp article.hpp article_vendu.hpp reference_article.hpp
historique_ventes.o: historique_ventes.cpp historique_ventes.hpp vente.hpp
article_affichage.o: article_affichage.cpp article_affichage.hpp
articles_existants.o: articles_existants.cpp article.hpp article_stock.hpp reference_article.hpp date.hpp pourcentage.hpp
article_stock.o: article_stock.cpp article_stock.hpp reference_article.hpp pourcentage.hpp
article_vendu.o: article_vendu.cpp article_vendu.hpp reference_article.hpp
magasin.o: magasin.cpp magasin.hpp date.hpp pourcentage.hpp reference_article.hpp article.hpp article_affichage.hpp article_stock.hpp article_vendu.hpp vente.hpp stock.hpp historique_ventes.hpp articles_existants.hpp condition_article.hpp condition_vente.hpp
es.o: es.cpp es.hpp magasin.hpp
main.o: main.cpp es.hpp magasin.hpp

libqlot.a: magasin.o date.o pourcentage.o reference_article.o article.o stock.o article_vendu.o vente.o historique_ventes.o article_affichage.o articles_existants.o article_stock.o article_vendu.o es.o | lib_dir
	ar -crv $(PATH_LIB)/libqlot.a $(PATH_OBJ)/magasin.o $(PATH_OBJ)/date.o $(PATH_OBJ)/pourcentage.o $(PATH_OBJ)/reference_article.o $(PATH_OBJ)/article.o $(PATH_OBJ)/stock.o $(PATH_OBJ)/article_vendu.o $(PATH_OBJ)/vente.o $(PATH_OBJ)/historique_ventes.o $(PATH_OBJ)/article_affichage.o $(PATH_OBJ)/articles_existants.o $(PATH_OBJ)/article_stock.o $(PATH_OBJ)/es.o
	ranlib $(PATH_LIB)/libqlot.a

obj_dir:
		@mkdir -p $(PATH_OBJ)

lib_dir:
		@mkdir -p $(PATH_LIB)

bin_dir:
		@mkdir -p $(PATH_BIN)

doc:
		@doxygen

clean:
		@rm -rf $(PATH_OBJ) $(PATH_LIB) $(PATH_BIN)

cleandoc:
		@rm -rf $(PATH_DOC)

cleanall: clean cleandoc
		@echo "Clean."

archive:
		@tar -cvzf $(shell basename `pwd`).tar.gz $(PATH_SRC) $(PATH_INC) makefile AUTHORS COPYING LICENSE README README.md
