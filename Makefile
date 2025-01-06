CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lcunit

all: test_trois_plus_grand

test_trois_plus_grand: Test/test_trois_plus_grand.c Fonction/trois_plus_grand.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f test_trois_plus_grand
