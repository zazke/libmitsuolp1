# for how this works see ~/docs/books/ref/make.pdf p.20
#
# If testing foo.cpp:
# 	add foo.o to objects
# 	add foo.h to test.o dependencies
# 	add line `foo.o : dependencies`

# I don't know why but this does not add debug info to the executable.  Maybe
# the *.o are not being compiled with `-g` flag.
#
# To debug just compile all with 
# `g++ -g *.cpp estructuras_voidptr/*.cpp estructuras_class/*.cpp`

CC = g++
objects = nombres.o tabs.o tests.o input.o output.o alloc.o sort.o \
	  estructuras_voidptr/list.o \
	  estructuras_voidptr/stack.o \
	  estructuras_voidptr/queue.o \
	  estructuras_voidptr/bintree.o \
	  estructuras_class/SLNode.o \
	  estructuras_class/DLNode.o \
	  estructuras_class/DoublyLinkedList.o \
	  estructuras_class/Queue.o \
	  estructuras_class/PriorityQueue.o \
	  estructuras_class/A.o \
	  estructuras_class/List.o \
	  estructuras_class/Stack.o \
	  estructuras_class/BST.o


a.out : $(objects)
	$(CC) -o $@ -g -lm $(objects)


# Having the following commented makes the default build not notice changes
# in headers because there is no implicit dependency to them.  `make clean`
# and `make` in that case.  Only adding things objects is convinient enough
# to justify it.

#nombres.o : nombres.h
#tabs.o : tabs.h
#tests.o : nombres.h input.h alloc.h sort.h \
#	  estructuras_voidptr/list.h \
#	  estructuras_voidptr/stack.h \
#	  estructuras_voidptr/queue.h \
#	  estructuras_voidptr/bintree.h \
#	  estructuras_class/SLNode.h \
#	  estructuras_class/List.h \
#	  estructuras_class/DoublyLinkedList.h
#input.o : input.h
#output.o : output.h
#alloc.o : alloc.h
#sort.o : sort.h
#estructuras_voidptr/list.o : estructuras_voidptr/list.h
#estructuras_voidptr/stack.o : estructuras_voidptr/stack.h
#estructuras_voidptr/queue.o : estructuras_voidptr/queue.h
#estructuras_voidptr/bintree.o : estructuras_voidptr/bintree.h
#estructuras_class/SLNode.o : estructuras_class/SLNode.h
#estructuras_class/List.o : estructuras_class/List.h \
#    			   estructuras_class/SLNode.h

.PHONY : clean
clean :
	rm a.out $(objects)
