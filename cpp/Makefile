CPPFLAGS = -std=c++23 -Wextra -Wall -Weffc++ -Werror -pedantic -pedantic-errors -Wconversion -wSign-conversion -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wunreachable-code -Winit-self -Wno-variadic-macros -Wno-parentheses -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable -Wno-unused-value -Wno-unused-but-set-variable -Wno-unused-local-typedefs
CPPLIBFLAGS = -c $(CPPFLAGS)

webserver:
	g++ $(CPPFLAGS) main.cpp -o webserver

build: webserver
	echo "Build Complete"

test: webserver
	./webserver

run: webserver
	./webserver

clean:
	rm -f webserver

