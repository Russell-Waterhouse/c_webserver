

webserver:
	gcc main.c -Wall -Werror -o webserver

build: webserver
	echo "Build Complete"

test: webserver
	./webserver

run: webserver
	./webserver

clean:
	rm -f webserver

