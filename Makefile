# for how this works see ~/docs/books/ref/make.pdf p.20
#
# If testing foo.cpp:
# 	add foo.o to objects
# 	add foo.h to test.o dependencies
# 	add line `foo.o : dependencies`

# I don't know why but this does not add debug info to the executable.  Maybe
# the *.o are not being compiled with `-g` flag.

objects = nombres.o tabs.o tests.o input.o output.o alloc.o sort.o \
	  estructuras_voidptr/list.o \
	  estructuras_voidptr/stack.o \
	  estructuras_voidptr/queue.o \
	  estructuras_voidptr/bintree.o

a.out : $(objects)
	g++ -o a.out -g -lm $(objects)

nombres.o : nombres.h
tabs.o : tabs.h
tests.o : nombres.h input.h alloc.h sort.h \
	  estructuras_voidptr/list.h \
	  estructuras_voidptr/stack.h \
	  estructuras_voidptr/queue.h \
	  estructuras_voidptr/bintree.h
input.o : input.h
output.o : output.h
alloc.o : alloc.h
sort.o : sort.h
estructuras_voidptr/list.o : estructuras_voidptr/list.h
estructuras_voidptr/stack.o : estructuras_voidptr/stack.h
estructuras_voidptr/queue.o : estructuras_voidptr/queue.h
estructuras_voidptr/bintree.o : estructuras_voidptr/bintree.h

.PHONY : clean
clean :
	rm a.out $(objects)
