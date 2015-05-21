#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <PNMreader.h>
using namespace std;

#define COLOR_DIMENSION 3
#define MAX_VAL 255

PNMreader::PNMreader(char *filename) : inputFile(filename) {}

void PNMreader::Execute(){
	FILE *f_in;
	f_in = fopen(inputFile, "rb");
	char pnmType[2];
	int temp_width;
	int temp_height;
	int maxVal;
	unsigned char *temp_data;
	fscanf(f_in, "%s\n%d %d\n%d\n", pnmType, &temp_width, &temp_height, &maxVal);
	temp_data = (unsigned char*) malloc(COLOR_DIMENSION * temp_width * temp_height *sizeof(unsigned char));
	cout << "width: " << temp_width << "	height: " << temp_height << endl;

	//fread(temp_data, sizeof(unsigned char), COLOR_DIMENSION * temp_width * temp_height, f_in); 
	fscanf(f_in, "%hhu", temp_data);

	cout << "successful fread" << endl;
	picture.setWidth(temp_width);
	picture.setHeight(temp_height);
	picture.setData(temp_data);
	fclose(f_in);
}

