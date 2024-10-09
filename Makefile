

all:
	gcc -o build/slasher src/slasher.c -lssl -lcrypto
clean:
	rm -rf build/*
