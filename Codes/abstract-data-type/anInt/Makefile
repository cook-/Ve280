# variable definition

CC = g++

DEFS =
LIBS =
INCLUDES = #-I.
HEADERS = #int_t.h int_impl.h
MAINSRCS = main.C
OTHSRCS = anInt.C
SRCS = $(MAINSRCS) $(OTHSRCS)
OBJS = $(SRCS:.C=.o)
TARGETS = $(MAINSRCS:.C=)

CFLAGS = -g -Wall $(INCLUDES) $(DEFS)

%.o: %.C
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS) $(LIBS)

depend:
	makedepend -Y $(INCLUDES) $(SRCS)

memcheck: $(TARGETS)
	valgrind --leak-check=full ./$(TARGETS)

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all depend memcheck clean 
