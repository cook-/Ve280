# variable definition

CC = g++

DEFS = -DNDEBUG
LIBS =
INCLUDES = #-I.
HEADERS =
MAINSRCS = min.C
OTHSRCS =
SRCS = $(MAINSRCS) $(OTHSRCS)
OBJS = $(SRCS:.C=.o)
TARGETS = $(MAINSRCS:.C=)

CFLAGS = -g -Wall $(DEFS)

%.o: %.C
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS) $(LIBS)

depend:
	makedepend -Y $(INCLUDES) $(SRCS)

memcheck: $(TARGETS)
	@#-valgrind --leak-check=full ./$(TARGETS) $(TESTDIR)/x6dn x6dn

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all depend memcheck clean 
