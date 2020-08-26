CC = gcc            # default is CC = cc
CFLAGS = -g -Wall   # default is CFLAGS = [blank]
CPPFLAGS =          # default is CPPFLAGS = [blank]
LDFLAGS = -lpthread # default is LDFLAGS = [blank]

all: example

example: example.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS)

clean: 
	$(RM) -f *.o example