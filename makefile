Classe = ./Classe/
Include = ./Include/

CO = g++ -I$(Include) -Wall -DDEBUG

all: Test1 Test2a Test2b Test2c Test3 Test4 Test5

Test1: Test1.cpp Model.o
	$(CO) Test1.cpp -o Test1 Model.o

Test2a: Test2a.cpp Model.o Car.o Option.o Person.o
	$(CO) Test2a.cpp -o Test2a Model.o Car.o Option.o Person.o

Test2b: Test2b.cpp Model.o Car.o Option.o Person.o
	$(CO) Test2b.cpp -o Test2b Model.o Car.o Option.o Person.o

Test2c: Test2c.cpp Model.o Car.o Option.o Person.o
	$(CO) Test2c.cpp -o Test2c Model.o Car.o Option.o Person.o

Test3: Test3.cpp Model.o Car.o Option.o Person.o
	$(CO) Test3.cpp -o Test3 Model.o Car.o Option.o Person.o

Test4: Test4.cpp Model.o Car.o Option.o Person.o Actor.o Client.o Employee.o
	$(CO) Test4.cpp -o Test4 Model.o Car.o Option.o Person.o Actor.o Client.o Employee.o

Test5: Test5.cpp Model.o Car.o Option.o Person.o Actor.o Client.o Employee.o
	$(CO) Test5.cpp -o Test5 Model.o Car.o Option.o Person.o Actor.o Client.o Employee.o

# === Compilation des objets ===
Model.o: $(Classe)Model.cpp
	$(CO) -c $(Classe)Model.cpp -o Model.o

Car.o: $(Classe)Car.cpp
	$(CO) -c $(Classe)Car.cpp -o Car.o

Option.o: $(Classe)Option.cpp
	$(CO) -c $(Classe)Option.cpp -o Option.o

Person.o: $(Classe)Person.cpp
	$(CO) -c $(Classe)Person.cpp -o Person.o

Actor.o:	$(Classe)Actor.cpp
	$(CO) -c $(Classe)Actor.cpp -o Actor.o

Client.o:	$(Classe)Client.cpp
	$(CO) -c $(Classe)Client.cpp -o Client.o

Employee.o:	$(Classe)Employee.cpp
	$(CO) -c $(Classe)Employee.cpp -o Employee.o


# === Nettoyage des fichiers compilés ===
clean:
	rm -f *.o Test1 Test2a Test2b Test2c Test3 Test4
