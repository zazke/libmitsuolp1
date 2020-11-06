# for how this works see ~/docs/books/ref/make.pdf p.20
#
# If testing foo.cpp:
# 	add foo.o to objects
# 	add foo.h to test.o dependencies
# 	add line `foo.o : dependencies`

objects = nombres.o tabs.o tests.o input.o output.o alloc.o sort.o

a.out : $(objects)
	g++ -o a.out -g -lm $(objects)

nombres.o : nombres.h
tabs.o : tabs.h
tests.o : nombres.h input.h alloc.h sort.h
input.o : input.h
output.o : output.h
alloc.o : alloc.h
sort.o : sort.h

.PHONY : clean
clean :
	rm a.out $(objects)
