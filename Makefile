#<Mostafa Mahtab, G01468551
#CS 262, Lab section 208
#Lab 7

CC = gcc
CLFAGS = -g -Wall -lm
TARGET = lab7_mmahtab_208

all:  $(TARGET).c
	$(CC) $(TARGET).c -o $(TARGET) $(CFLAGS)
clean:
	rm $(TARGET)
