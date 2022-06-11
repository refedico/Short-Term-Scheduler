CFLAGS = -O3
CC = gcc
TARGET = sts
OBJ = main.o queue.o util.o
.PHONY = clean

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET)
