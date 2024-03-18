CFLAGS = -Wextra -Wall -Werror -pedantic -pedantic-errors -Wconversion -Wsign-conversion -Wshadow -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-unused-result -Wno-implicit-fallthrough -Wno-sign-compare -Wno-strict-aliasing -Wno-implicit-function-declaration -Wno-implicit-int -Wno-implicit -Wno-implicit-int
CLIBFLAGS = -c $(CFLAGS)

result.o: result.h
	gcc result.h $(CLIBFLAGS) -o result.o

fatchar.o: result.o fatchar.c fatchar.h
	gcc fatchar.c $(CLIBFLAGS) -o fatchar.o

http.o: http.h http.h fatchar.o result.o
	gcc http.c $(CLIBFLAGS) -o http.o

webserver: main.c fatchar.o result.o http.o
	gcc main.c $(CFLAGS) -o webserver

build: webserver
	echo "Build Complete"

test: webserver
	gcc test_http.c http.o fatchar.o $(CFLAGS) -o http_test
	./http_test

run: webserver
	./webserver

clean:
	rm -f webserver http_test *.o

