result.o:
	gcc result.h -c -Wextra -Wall -Werror -pedantic -pedantic-errors -o result.o

fatchar.o: result.o
	gcc fatchar.c -c -Wextra -Wall -Werror -pedantic -pedantic-errors -o fatchar.o

http.o: http.h
	gcc http.c -c -Wextra -Wall -Werror -pedantic -pedantic-errors -o http.o

webserver: main.c fatchar.o result.o http.o
	gcc main.c -Wextra -Wall -Werror -pedantic -pedantic-errors -o webserver

build: webserver
	echo "Build Complete"

test: webserver
	./webserver

run: webserver
	./webserver

clean:
	rm -f webserver fatchar.o result.o http.o

