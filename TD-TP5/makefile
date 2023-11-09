CC = gcc
CFLAGS = -Wall # -Wextra -std=c99
LDFLAGS = -lm
EXEC = calculatrice

all: $(EXEC)

calcul.o: calcul.h calcul.c
	$(CC) $(CFLAGS) -c calcul.c $(LDFLAGS)

calculatrice_f_ext.o: calculatrice_f_ext.h calculatrice_f_ext.c
	$(CC) $(CFLAGS) -c calculatrice_f_ext.c $(LDFLAGS)

$(EXEC): calcul.o calculatrice_f_ext.o calculatrice.c libcalc.a
	$(CC) $(CFLAGS) -o $(EXEC) calcul.o calculatrice_f_ext.o calculatrice.c -L. -lcalc $(LDFLAGS)

libcalc.a: calcul.o calculatrice_f_ext.o
	ar rcs libcalc.a calcul.o calculatrice_f_ext.o

clean:
	rm -f calcul.o calculatrice_f_ext.o $(EXEC) libcalc.a

mrproper: clean
	rm -f *~