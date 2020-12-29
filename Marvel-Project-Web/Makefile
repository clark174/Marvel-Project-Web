#MakeFile to build and deploy the Sample US CENSUS Name Data using ajax
# For CSC3004 Software Development

user = clark1
CC= g++

#For Optimization
#CFLAGS= -O2
#For debugging
CFLAGS= -std=c++14

RM= /bin/rm -f

all: marvelSearch PutCGI PutHTML

nameIndex.o: nameIndex.cpp nameIndex.h characters.h
	$(CC) $(CFLAGS) nameIndex.cpp -c

nameMap.o: nameMap.cpp nameMap.h characters.h
	$(CC) $(CFLAGS) nameMap.cpp -c

yearIndex.o: yearIndex.cpp yearIndex.h characters.h
	$(CC) $(CFLAGS) yearIndex.cpp -c

characters.o: characters.cpp characters.h
	$(CC) $(CFLAGS) characters.cpp -c

marvelSearch.o: marvelSearch.cpp nameMap.h nameIndex.h yearIndex.h
	$(CC) -c $(CFLAGS) marvelSearch.cpp

marvelSearch: marvelSearch.o nameIndex.o nameMap.o characters.o yearIndex.o
	$(CC) marvelSearch.o -o marvelSearch nameIndex.o nameMap.o yearIndex.o characters.o -L/usr/local/lib -lcgicc

PutCGI: marvelSearch
	chmod 757 marvelSearch
	cp -f marvelSearch /usr/lib/cgi-bin/$(user)_marvelSearch.cgi 

	echo "Current contents of your cgi-bin directory: "
	ls -l /usr/lib/cgi-bin/

PutHTML:
	cp namelookup.html /var/www/html/class/softdev/$(user)/marvelLookup/
	cp namelookup.css /var/www/html/class/softdev/$(user)/marvelLookup/
	cp namelookup.js /var/www/html/class/softdev/$(user)/marvelLookup/
	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/class/softdev/$(user)/marvelLookup/
clean:
	rm -f *.o  marvelSearch
