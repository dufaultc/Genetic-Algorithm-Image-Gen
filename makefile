CFLAGS=-g -O2 -Wall -pg
CC=gcc

PROGRAM_NAME= evolve
OBJS = main.o readwriteppm.o fitness.o population.o evolve.o \
	crossover.o mutate.o

$(PROGRAM_NAME): $(OBJS)
	$(CC) -pg -o $@ $? -lm

escher:
	make; make
	./evolve me.ppm me2.ppm 5000 24 3e-2
mcmaster: 	
	make; make
	./evolve mcmaster.ppm mcmaster2.ppm 2000 100 3e-2

clean:
	rm  *.o $(PROGRAM_NAME) *~
