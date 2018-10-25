all : pub.x sub.x

pub.x : pub.o
	g++ -g -std=gnu++11 -I. -o pub.x pub.o -L/usr/local/lib -lnats -lprotobuf

pub.o : pub.cpp
	g++ -g -std=gnu++11 -I. -c pub.cpp

sub.x : sub.o
	g++ -g -std=gnu++11 -I. -o sub.x sub.o -L/usr/local/lib -lnats -lprotobuf

sub.o : sub.cpp
	g++ -g -std=gnu++11 -I. -c sub.cpp

clean :
	rm -f pub.x pub.o sub.x sub.o 
