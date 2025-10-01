CO = g++ -I$(Include) -Wall -DDEBUG -w

Classe = ./Classe/
Include = ./Include/

all: Test1
	

Test1: Test1.cpp Model.o
	$(CO) Test1.cpp -o Test1 Model.o

Model.o:  $(Classe)Model.cpp
	$(CO) -c $(Classe)Model.cpp -o  Model.o


