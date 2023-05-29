make: build run

# -fdiagnostics-color=always -g

build:
	g++ src/*.cpp -o bin/bin -Ilib -Llib -ltermDisplay -lm

run:
	./bin/bin