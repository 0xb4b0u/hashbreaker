# compiler
CC = gcc

# compiler flags
CFLAGS = -o

# compiler libraries
LIBS = -l crypto -l ssl

all: client server

rebuild : clean all

client:
	$(CC) $(CFLAGS) client/client client/client.c lib/hashlib.c lib/stringslib.c lib/comlib.c $(LIBS)

server:
	$(CC) $(CFLAGS) server/server server/server.c lib/comlib.c

clean:
	rm -f client/client server/server
