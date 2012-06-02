#variable definition

CC = g++

MAINSRCS = hungry_cat.C
OTHSRCS = io.C
SRCS = $(MAINSRCS) $(OTHSRCS)
OBJS = $(SRCS:.C=.o)
TARGETS = p1

CFLAGS = -g -Wall

%.o: %.C
	$(CC) $(CFLAGS) -o $@ -c $< 

all: $(TARGETS)

$(TARGETS): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGETS) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGETS)

