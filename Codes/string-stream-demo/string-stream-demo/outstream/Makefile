#variable definition

CC = g++

MAINSRCS = outstream.C
OTHSRCS = #say_hello.C
SRCS = $(MAINSRCS) $(OTHSRCS)
OBJS = $(SRCS:.C=.o)
TARGETS = $(MAINSRCS:.C=)

CFLAGS = -g -Wall

%.o: %.C
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGETS)
