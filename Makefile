

all:
	gcc -o build/slasher src/slasher.c -lssl -lcrypto
	gcc -o build/example src/example.c -lssl -lcrypto

example:
	gcc -o build/example src/example.c -lssl -lcrypto

clean:
	rm -rf build/*
