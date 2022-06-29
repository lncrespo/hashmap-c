test: build_test
	bin/test-hashmap

run: build
	bin/hash_table

debug: build_debug
	bin/hash_table

build_debug: prebuild
	/bin/cc *.c -g -o bin/hash_table

build_test: prebuild
	/bin/cc tests/*.c *.c -O3 -o bin/test-hashmap

build: prebuild
	/bin/cc *.c -O3 -o bin/hash_table

prebuild:
	mkdir -p bin
