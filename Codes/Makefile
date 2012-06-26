CC = g++
CFLAGS = -g -Wall
SRCS = strlen.C
OBJS = $(SRCS:.C=.o)
TARGETS = $(SRCS:.C=)

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS)

%.o: %.C
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(TARGETS)

