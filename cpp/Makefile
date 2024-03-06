webserver:
	g++ main.cpp -std=c++20 -Wextra -Wall -Werror -pedantic -pedantic-errors -o webserver

build: webserver
	echo "Build Complete"

test: webserver
	./webserver

run: webserver
	./webserver

clean:
	rm -f webserver

