#include <PNMwriter.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
void PNMwriter::Write(char *filename){
	FILE *f_out;
	f_out = fopen(filename, "wb");

	cout << "PNMwrite img address: " << input << endl;
	fprintf(f_out, "P6\n%d %d\n%d\n", input->getWidth(), input->getHeight(), 255);
	fwrite(input->getData(), sizeof(unsigned char), 3 * input->getWidth() * input->getHeight(), f_out);
	fclose(f_out);
}

