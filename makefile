CC=gcc
CFLAGS=-I. -g -w
DEPS= 
OBJ = bucketsort.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
bucketsort: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)