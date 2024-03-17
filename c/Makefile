CFLAGS = -Wextra -Wall -Werror -pedantic -pedantic-errors
CLIBFLAGS = -c $(CFLAGS)

result.o:
	gcc result.h $(CLIBFLAGS) -o result.o

fatchar.o: result.o
	gcc fatchar.c $(CLIBFLAGS) -o fatchar.o

http.o: http.h
	gcc http.c $(CLIBFLAGS) -o http.o

webserver: main.c fatchar.o result.o http.o
	gcc main.c $(CFLAGS) -o webserver

build: webserver
	echo "Build Complete"

test: webserver
	gcc test_http.c $(CFLAGS) -o http_test
	./http_test

run: webserver
	./webserver

clean:
	rm -f webserver http_test *.o

