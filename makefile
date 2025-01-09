.PHONY: build 

build:
	gcc \
		-std=c99 \
		src/main.c \
	-o build/ql.exe 

run: ./build/ql.exe
	./build/ql.exe


clean: ./build/ql.exe
	rm build/ql.exe