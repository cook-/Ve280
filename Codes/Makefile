CC = g++
SRCS = strlen.C
OBJS = $(SRC:.C=.o)
TARGETS = $(SRCS:.C=)

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS)

%.o: %.C
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(TARGETS)

