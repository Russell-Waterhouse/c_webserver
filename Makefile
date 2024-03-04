

webserver:
	gcc main.c -Wall -Werror -o webserver

test: webserver
	./webserver

clean:
	rm -f webserver

