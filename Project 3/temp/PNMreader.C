#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <PNMreader.h>

PNMreader::PNMreader(char *fin, char *fout){
	file_in = fin;
	file_out = fout;
}
void PNMreader::Execute(){
	FILE *f_in;
	FILE *f_out;
	char pnmType[2];
	int temp_width(0);
	int temp_height(0);
	int max_val(0);
	unsigned char *temp_data(NULL);
	
	f_in = fopen(file_in, "rb"); 
	fscanf(f_in, "%s\n%d %d\n%d\n", pnmType, &temp_width,  &temp_height, &max_val);
	temp_data = new unsigned char[3 * temp_width * temp_height]; 
	fread(temp_data, sizeof(unsigned char), 3 * temp_width * temp_height, f_in);
	fclose(f_in);
	
	f_out = fopen(file_out, "wb");
	fprintf(f_out, "P6\n%d %d\n%d\n", temp_width, temp_height, max_val);
	fwrite(temp_data, sizeof(unsigned char), 3 * temp_width * temp_height, f_out);
	fclose(f_out);
//	delete[] temp_data;
}
