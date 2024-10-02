main: hash.cpp main.cpp
	g++ -O1 main.cpp hash.cpp -o main

konstitucija: konstitucija.cpp hash.cpp
	g++ -O1 konstitucija.cpp hash.cpp -o konstitucija

tests: tests.cpp hash.cpp
	g++ -O1 tests.cpp hash.cpp -o test

compare: compare.cpp hash.cpp
	g++ -O1 compare.cpp hash.cpp SHA/md5.cpp SHA/sha1.cpp SHA/sha256.cpp -o compare
