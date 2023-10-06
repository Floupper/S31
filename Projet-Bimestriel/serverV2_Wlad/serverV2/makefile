CC = gcc
CFLAGS = -Wall

all: addServ subServ multServ divServ rdivServ mainServ

addServ: addServ.c
	$(CC) $(CFLAGS) -o addServ addServ.c

subServ: subServ.c
	$(CC) $(CFLAGS) -o subServ subServ.c

multServ: multServ.c
	$(CC) $(CFLAGS) -o multServ multServ.c

divServ: divServ.c
	$(CC) $(CFLAGS) -o divServ divServ.c

rdivServ: rdivServ.c
	$(CC) $(CFLAGS) -o rdivServ rdivServ.c

mainServ: mainServV2.c
	$(CC) $(CFLAGS) -o mainServ mainServV2.c

clean:
	rm -f addServ subServ multServ divServ rdivServ mainServ