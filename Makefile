#CC=gcc33
CC=gcc
OBJFILES = \
find_smallest_factor.o
CFLAGS= -g -DLINUX 
#CFLAGS=-O2 -g
LINKFLAGS =
LIBS = -lm -lgmp



%.o: %.c Makefile
	$(CC) -c $(CFLAGS) -o $@ $<

find_smallest_factor: $(OBJFILES)
	$(CC) $(CFLAGS) $(LINKFLAGS) $(OBJFILES) $(LIBS) -o $@

clean:
	rm -f $(OBJFILES) *~ t1 *.i find_smallest_factor.o
