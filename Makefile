.DEFAULT_GOAL := shared

clean:
	@rm -rf ./bin

shared:
	@mkdir -p ./bin
	@gcc -fPIC -shared -o ./bin/libatompack.so ./src/*.c

test:
	@gcc -lm -o testatompack ./src/*.c
	@./testatompack
	@rm ./testatompack
