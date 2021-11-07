all: project1

project1:
	cc project1.c -o project1 -pedantic 

run: clean project1
	./project1 tests/input.txt
	make clean

test:
	bats tests.bats

clean:
	rm -f project1
