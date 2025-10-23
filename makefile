Classe = ./Classe/
Include = ./Include/


CO = g++ -I$(Include) -Wall -DDEBUG -w

all: Test2a Test2b Test2c
	

Test1: Test1.cpp Model.o
	$(CO) Test1.cpp -o Test1 Model.o

Test2a: Test2a.cpp Model.o Car.o
	$(CO) Test2a.cpp -o Test2a Model.o Car.o Option.o

Test2b:	Test2b.cpp Model.o Car.o Option.o
	$(CO) Test2b.cpp -o Test2B Model.o Car.o Option.o

Test2c: Test2c.cpp Model.o Car.o Option.o
	$(CO) Test2c.cpp -o Test2c Model.o Car.o Option.o

Model.o:  $(Classe)Model.cpp
	$(CO) -c $(Classe)Model.cpp -o  Model.o

Car.o:	$(Classe)Car.cpp
	$(CO) -c $(Classe)Car.cpp -o Car.o

Option.o:	$(Classe)Option.cpp
	$(CO) -c $(Classe)Option.cpp -o Option.o
