.DEFAULT_GOAL := shared

shared:
	@mkdir -p ./bin
	@gcc -fPIC -shared -o ./bin/libatompack.so ./src/*.c

clean:
	@rm -rf ./bin
