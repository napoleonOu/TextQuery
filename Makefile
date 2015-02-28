testmain:testmain.o TextQuery.o
	g++ -std=c++11 -g -o testmain  testmain.o TextQuery.o
testmain.o:testmain.cc TextQuery.h QueryResult.h
	g++ -std=c++11 -g  -c testmain.cc
TextQuery.o:TextQuery.cc TextQuery.h 
	g++ -std=c++11 -g  -c TextQuery.cc
clean:
	rm testmain testmain.o TextQuery.o
