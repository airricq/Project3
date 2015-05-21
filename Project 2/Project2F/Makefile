project_2F: driver_2F.o my_struct.o
	gcc -o project_2F my_struct.o driver_2F.o

driver_2F.o: driver_2F.c prototypes.h my_struct.h
	gcc -c -I. driver_2F.c

my_struct.o: driver_2F.c prototypes.h my_struct.h
	gcc -c -I. my_struct.c

clean:
	rm *.o
	rm my_output
