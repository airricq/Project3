#include <stdlib.h>
#include <printf.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *f_in, *f_out;
	int buff_size = 25;
	int *buffer;
	int i;

	if (argc != 3){
		printf("Usage: %s <file1> <file2>\nargc = %u", argv[0], argc);
		exit(EXIT_FAILURE);
	}
	f_in = fopen(argv[1], "r");
	
	buffer = malloc(buff_size*sizeof(int));
	for(i = 0; i < 5; i++){
		fread(buffer + (5*i), sizeof(int), 5, f_in);
		fseek(f_in, 5*sizeof(int), SEEK_CUR);
	}
	f_out = fopen(argv[2], "w");
	for(i = 0; i < 25; i++)
		fprintf(f_out, "%d\n", *(buffer+i));	

	fclose(f_in);
	fclose(f_out);
	free(buffer);	
	return 0;
}
