# variable definition

CC = g++
HEADERS = dlist.h
MAINSRCS = call.C
SRCS = $(MAINSRCS)
OBJS = $(SRCS:.C=.o)
TARGETS = $(MAINSRCS:.C=)

CFLAGS = -g -Wall

%.o: %.C
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS)

memcheck: $(TARGETS)
	valgrind --leak-check=full ./$(TARGETS)

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all memcheck clean 
