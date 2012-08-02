# variable definition

CC = g++

DEFS =
LIBS =
INCLUDES = -I.
HEADERS = list.h
TEMPLATES = list.C
MAINSRCS = main.C
OTHSRCS =
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
	@valgrind --leak-check=full ./$(TARGETS)

tags: $(SRCS) $(HEADERS) $(TEMPLATES)
	ctags $^

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all depend memcheck tags clean 

# DO NOT DELETE

main.o: list.h list.C
