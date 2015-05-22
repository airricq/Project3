#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <PNMreader.h>
using namespace std;
PNMreader::PNMreader(char *f_in){
	filename = f_in;
}
void PNMreader::Execute(){
	FILE *f_in;
	FILE *f_out;
	char pnmType[2];
	int temp_width(0);
	int temp_height(0);
	int max_val(0);
	unsigned char *temp_data(NULL);
	
	f_in = fopen(filename, "rb"); 
	fscanf(f_in, "%s\n%d %d\n%d\n", pnmType, &temp_width,  &temp_height, &max_val);
	temp_data = new unsigned char[3 * temp_width * temp_height]; 
	fread(temp_data, sizeof(unsigned char), 3 * temp_width * temp_height, f_in);
	
	picture.setWidth(temp_width);
	picture.setHeight(temp_height);
	picture.setData(temp_data);
	cout << "PNMreader address: " << &picture << endl;
	fclose(f_in);
}
