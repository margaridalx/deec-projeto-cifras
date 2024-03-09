.PHONY = all clean
OBJECTS = main.o cifras.o

all: cifras

cifras: $(OBJECTS)
	gcc $(OBJECTS) -o $@

%.o: %.c
	gcc -c $< -o $@

clean:
	rm cifras *.o
