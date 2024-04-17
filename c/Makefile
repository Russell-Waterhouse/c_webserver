CFLAGS = -std=c17 -Wextra -Wall -Werror -pedantic -pedantic-errors -Wconversion -Wsign-conversion -Wshadow -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-unused-result -Wno-implicit-fallthrough -Wno-sign-compare -Wno-strict-aliasing -Wno-implicit-function-declaration -Wno-implicit-int -Wno-implicit -Wno-implicit-int
CLIBFLAGS = -c $(CFLAGS)

result.o: result.h
	gcc result.h $(CLIBFLAGS) -o target/result.o

fatchar.o: result.o fatchar.c fatchar.h
	gcc fatchar.c $(CLIBFLAGS) -o target/fatchar.o

http.o: http.h http.h fatchar.o result.o
	gcc http.c $(CLIBFLAGS) -o target/http.o

webserver: main.c fatchar.o result.o http.o
	gcc main.c $(CFLAGS) -o target/webserver

build: webserver
	echo "Build Complete"

test: webserver
	gcc test_http.c target/http.o target/fatchar.o $(CFLAGS) -o target/http_test
	valgring --leak-check=yes ./target/http_test

test_no_valgrind: webserver
	gcc test_http.c target/http.o target/fatchar.o $(CFLAGS) -o target/http_test
	./target/http_test

run: webserver
	./target/webserver

clean:
	rm -f target/*

