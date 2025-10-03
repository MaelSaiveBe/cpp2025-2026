Classe = ./Classe/
Include = ./Include/


CO = g++ -I$(Include) -Wall -DDEBUG -w

all: Test2a Test1
	

Test1: Test1.cpp Model.o
	$(CO) Test1.cpp -o Test1 Model.o

Test2a: Test2a.cpp Model.o Car.o
	$(CO) Test2a.cpp -o Test2a Model.o Car.o

Model.o:  $(Classe)Model.cpp
	$(CO) -c $(Classe)Model.cpp -o  Model.o

Car.o:	$(Classe)Car.cpp
	$(CO) -c $(Classe)Car.cpp -o Car.o
