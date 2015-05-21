#include <functions.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;
#define COLOR_DIMENSION 3
#define MAX_VAL 255
void ReadImage(char *filename, Image &output)
{
    FILE *f_in;
	f_in = fopen(filename, "rb");
	Image *img;
    char pnmType[2];
    int temp_width;
	int temp_height;
	int maxVal;
	unsigned char* temp_data;

    fscanf(f_in, "%s\n%d %d\n%d\n", pnmType, &temp_width, &temp_height, &maxVal);
	img = (Image *) malloc(sizeof(Image));
	temp_data =  (unsigned char*) malloc(COLOR_DIMENSION * temp_width * temp_height * sizeof(unsigned char));
	fread(temp_data, sizeof(unsigned char), COLOR_DIMENSION * temp_width  * temp_height, f_in);
	
	img->setWidth(temp_width);
	img->setHeight(temp_height);
	img->setData(temp_data);

	output.setWidth(img->getWidth());
	output.setHeight(img->getHeight());
	output.setData(img->getData());
    fclose(f_in);
}

void WriteImage(char *filename, Image &img){
	FILE *f_out;
	f_out = fopen(filename, "wb");

	cout << "width: " << img.getWidth() << "	height: " << img.getHeight() << endl;
	fprintf(f_out, "P6\n%d %d\n%d\n", img.getWidth(), img.getHeight(), MAX_VAL);
	fwrite(img.getData(), sizeof(unsigned char), COLOR_DIMENSION * img.getWidth() * img.getHeight(), f_out);
	fclose(f_out);
}

void HalveInSize(Image &input, Image &output){
	unsigned char *inputBuff;
	unsigned char *outputBuff;

	inputBuff = (unsigned char*) malloc(COLOR_DIMENSION * input.getWidth() * input.getHeight() * sizeof(unsigned char));	
	inputBuff = input.getData();
	output.setWidth(input.getWidth() / 2);
	output.setHeight(input.getHeight() / 2);
	outputBuff = (unsigned char*) malloc(COLOR_DIMENSION * output.getWidth() * output.getHeight() * sizeof(unsigned char));
	for(int r = 0; r < output.getHeight(); r++){
		for(int c = 0; c < output.getWidth(); c++){
			outputBuff[3 * (r * output.getWidth() + c) + 0] = inputBuff[3 * (2 * r * input.getWidth() + 2 * c) + 0];
			outputBuff[3 * (r * output.getWidth() + c) + 1] = inputBuff[3 * (2 * r * input.getWidth() + 2 * c) + 1];
			outputBuff[3 * (r * output.getWidth() + c) + 2] = inputBuff[3 * (2 * r * input.getWidth() + 2 * c) + 2];
		}
	}	
	output.setData(outputBuff);
}

void LeftRightConcatenate(Image &leftInput, Image &rightInput, Image &output){
	unsigned char *leftBuff;
	unsigned char *rightBuff;
	unsigned char *outputBuff;

	leftBuff = (unsigned char*) malloc(COLOR_DIMENSION * leftInput.getWidth() * leftInput.getHeight() 
				* sizeof(unsigned char));
	rightBuff = (unsigned char*) malloc(COLOR_DIMENSION * rightInput.getWidth() * rightInput.getHeight() 
				* sizeof(unsigned char));
	outputBuff = (unsigned char*) malloc(COLOR_DIMENSION * (leftInput.getWidth() + rightInput.getWidth()) 
				 * leftInput.getHeight() * sizeof(unsigned char));

	leftBuff = leftInput.getData();
	rightBuff = rightInput.getData();

	for(int r = 0; r < leftInput.getHeight(); r++){
		for(int c = 0; c < leftInput.getWidth(); c++){
			outputBuff[3 * (r * leftInput.getWidth() + c) + 0] 
				= leftBuff[3 * (r * leftInput.getWidth() + c) + 0];
			outputBuff[3 * (r * leftInput.getWidth() + c) + 1] 
				= leftBuff[3 * (r * leftInput.getWidth() + c) + 1];
			outputBuff[3 * (r * leftInput.getWidth() + c) + 2] 
				= leftBuff[3 * (r * leftInput.getWidth() + c) + 2];
		}	
	}
	for(int r = 0; r < leftInput.getHeight(); r++){
		for(int c = 0; c < rightInput.getWidth(); c++){
			outputBuff[3 * (r * rightInput.getWidth() + (c + leftInput.getWidth())) + 0] 
				= rightBuff[3 * (r * rightInput.getWidth() + c) + 0];
			outputBuff[3 * (r * rightInput.getWidth() + (c + leftInput.getWidth())) + 1] 
			   	= rightBuff[3 * (r * rightInput.getWidth() + c) + 1];
			outputBuff[3 * (r * rightInput.getWidth() + (c + leftInput.getWidth())) + 2] 
				= rightBuff[3 * (r * rightInput.getWidth() + c) + 2];
		}	
	}
	output.setData(outputBuff);
	output.setWidth(leftInput.getWidth() + rightInput.getWidth());
	output.setHeight(leftInput.getHeight());
}

void TopBottomConcatenate(Image &topInput, Image &bottomInput, Image &output){
	unsigned char *topBuff;
	unsigned char *bottomBuff;
	unsigned char *outputBuff;

	topBuff = (unsigned char*) malloc(COLOR_DIMENSION * topInput.getWidth() * topInput.getHeight() 
				* sizeof(unsigned char));
	bottomBuff = (unsigned char*) malloc(COLOR_DIMENSION * bottomInput.getWidth() * bottomInput.getHeight() 
				* sizeof(unsigned char));
	outputBuff = (unsigned char*) malloc(COLOR_DIMENSION * topInput.getWidth() 
				 * (topInput.getHeight() + bottomInput.getHeight()) * sizeof(unsigned char));

	topBuff = topInput.getData();
	bottomBuff = bottomInput.getData();

	for(int r = 0; r < topInput.getHeight(); r++){
		for(int c = 0; c < topInput.getWidth(); c++){
			outputBuff[3 * (r * topInput.getWidth() + c) + 0] 
				= topBuff[3 * (r * topInput.getWidth() + c) + 0];
			outputBuff[3 * (r * topInput.getWidth() + c) + 1] 
				= topBuff[3 * (r * topInput.getWidth() + c) + 1];
			outputBuff[3 * (r * topInput.getWidth() + c) + 2] 
				= topBuff[3 * (r * topInput.getWidth() + c) + 2];
		}	
	}
	for(int r = 0; r < bottomInput.getHeight(); r++){
		for(int c = 0; c < bottomInput.getWidth(); c++){
			outputBuff[3 * ((r + bottomInput.getHeight()) * bottomInput.getWidth() + c) + 0]
				= bottomBuff[3 * (r * bottomInput.getWidth() + c) + 0];
			outputBuff[3 * ((r + bottomInput.getHeight()) * bottomInput.getWidth() + c) + 1]
				= bottomBuff[3 * (r * bottomInput.getWidth() + c) + 1];
			outputBuff[3 * ((r + bottomInput.getHeight()) * bottomInput.getWidth() + c) + 2]
				= bottomBuff[3 * (r * bottomInput.getWidth() + c) + 2];
		}
	}
	output.setData(outputBuff);
	output.setWidth(topInput.getWidth());
	output.setHeight(topInput.getHeight() + bottomInput.getHeight());
}

void Blend(Image &input1, Image &input2, float factor, Image&output){
	unsigned char *buff1;
	unsigned char *buff2;
	unsigned char *buffOut;

	buff1 = (unsigned char*) malloc(COLOR_DIMENSION * input1.getHeight() * input1.getWidth() * sizeof(unsigned char));
	buff2 = (unsigned char*) malloc(COLOR_DIMENSION * input2.getHeight() * input2.getWidth() * sizeof(unsigned char));
	buffOut = (unsigned char*) malloc(COLOR_DIMENSION * input1.getHeight() * input1.getWidth() * sizeof(unsigned char));

	buff1 = input1.getData();
	buff2 = input2.getData();
	int redFactor(0);
	int greenFactor(0);
	int blueFactor(0);
	for(int r = 0; r < input1.getHeight(); r++){
		for(int c = 0; c < input1.getWidth(); c++){
			redFactor = (buff1[3 * (r * input1.getWidth() + c) + 0] * factor)
						+ (buff2[3* (r * input2.getWidth() + c) + 0] * (1 - factor));
			greenFactor = (buff1[3 * (r * input1.getWidth() + c) + 1] * factor)
						+ (buff2[3* (r * input2.getWidth() + c) + 1] * (1 - factor));
			blueFactor = (buff1[3 * (r * input1.getWidth() + c) + 2] * factor)
						+ (buff2[3* (r * input2.getWidth() + c) + 2] * (1 - factor));
			
			buffOut[3 * (r * input1.getWidth() + c) + 0] = redFactor;
			buffOut[3 * (r * input1.getWidth() + c) + 1] = greenFactor;
			buffOut[3 * (r * input1.getWidth() + c) + 2] = blueFactor;
			
		}
	}
	output.setWidth(input1.getWidth());
	output.setHeight(input1.getHeight());
	output.setData(buffOut);
}








