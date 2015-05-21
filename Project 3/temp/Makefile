SRC=driver.C image.C source.C PNMreader.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o proj3C

.C.o: $<
	g++ -I. -c $<

run:
	./proj3C input.pnm output.pnm

clean:
	rm *.o
