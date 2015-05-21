prog: test.o functions.o image.o
	g++ -o proj3B test.o functions.o image.o

test.o: test.C functions.h image.h
	g++ -c -I. test.C

functions.o: functions.C functions.h image.h
	g++ -c -I. functions.C

image.o: image.C image.h
	g++ -c -I. image.C

run:
	./proj3B 3A_input.pnm pic.pnm

png: 
	pnmtopng < pic.pnm > pic.png

clean:
	rm *.o
	rm proj3B
	rm pic.pnm
