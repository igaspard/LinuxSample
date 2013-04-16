########################################################################
#	Author: Gaspard Shen
#	Mail:	syusyang@gmail.com
########################################################################

OBJECTS		= 
LIBRARIES	=
PROGRAMS	= env fork-exec fork print-pid system thread-create

LDLIBS		+= -lpthread

.PHONY:         all clean

# Default target: build everything.
all:            $(OBJECTS) $(LIBRARIES) $(PROGRAMS)

# Clean up build products.
clean:
	rm -f *.o *.a $(PROGRAMS)
