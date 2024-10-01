main: hash.cpp main.cpp
	g++ -O1 main.cpp hash.cpp -o main

konstitucija: konstitucija.cpp hash.cpp
	g++ -O1 konstitucija.cpp hash.cpp -o konstitucija

poros: poros.cpp hash.cpp
	g++ -O1 poros.cpp hash.cpp -o poros
