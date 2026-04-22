
FILES = $(wildcard src/*.cpp)

build/main: $(FILES)
	@echo building...
	@g++ $^ -o build/main
	@echo done

r: build/main
	build/main

clean:
	@rm build/main
	@echo cleaned