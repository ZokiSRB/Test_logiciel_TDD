CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lcunit

all: test_trois_plus_grand test_premier test_est_suite_arithmetique

test_trois_plus_grand: Test/test_trois_plus_grand.c Fonction/trois_plus_grand.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_premier: Test/test_premier.c Fonction/premier.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_est_suite_arithmetique: Test/test_est_suite_arithmetique.c Fonction/est_suite_arithmetique.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f test_trois_plus_grand test_premier test_est_suite_arithmetique
