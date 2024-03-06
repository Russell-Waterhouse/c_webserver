

webserver:
	gcc main.c  -Wextra -Wall -Werror -pedantic -pedantic-errors -o webserver

build: webserver
	echo "Build Complete"

test: webserver
	./webserver

run: webserver
	./webserver

clean:
	rm -f webserver

