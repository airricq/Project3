#include <filters.h>
#include <stdlib.h>
#define COLOR_DIMENSION 3
#define MAX_VAL 255

void Shrinker::Execute(){
	unsigned char *inputBuff;
	unsigned char *outputBuff;
	int maxVal(0);

	inputBuff = (unsigned char*) malloc(COLOR_DIMENSION * input->getWidth() * input->getHeight() * sizeof(unsigned char));
	picture.setWidth(input->getWidth()/2);
	picture.setHeight(input->getHeight()/2);
	outputBuff = (unsigned char*) malloc (COLOR_DIMENSION * picture.getWidth() * picture.getHeight() * sizeof(unsigned char));

	for(int r = 0; r < picture.getHeight(); r++){
		for(int c = 0; c < picture.getWidth(); c++){
			outputBuff[3 * (r * picture.getWidth() + c) + 0] = inputBuff[6 * (r * input->getWidth() + c) + 0];
			outputBuff[3 * (r * picture.getWidth() + c) + 1] = inputBuff[6 * (r * input->getWidth() + c) + 1];
			outputBuff[3 * (r * picture.getWidth() + c) + 2] = inputBuff[6 * (r * input->getWidth() + c) + 2];
		}
	}
	picture.setData(outputBuff);
}

void LRConcat::Execute(){
	unsigned char *leftBuff;
	unsigned char *rightBuff;
	unsigned char *outputBuff;

	leftBuff = (unsigned char*) malloc(COLOR_DIMENSION * input->getWidth() * input->getHeight() * sizeof(unsigned char));
	rightBuff = (unsigned char*) malloc(COLOR_DIMENSION * input->getWidth() * input->getHeight() * sizeof(unsigned char));
	outputBuff = (unsigned char*) malloc(COLOR_DIMENSION * (input->getWidth() + input2->getWidth())
			 * input->getHeight() * sizeof(unsigned char));
	
	leftBuff = input->getData();
	rightBuff = input2->getData();

	for(int r = 0; r < input->getHeight(); r++){
		for(int c = 0; c < input->getWidth(); c++){
			outputBuff[3 * (r * input->getWidth() + c) + 0] = leftBuff[3 * (r * input->getWidth() + c) + 0];
			outputBuff[3 * (r * input->getWidth() + c) + 1] = leftBuff[3 * (r * input->getWidth() + c) + 1];
			outputBuff[3 * (r * input->getWidth() + c) + 2] = leftBuff[3 * (r * input->getWidth() + c) + 2];
		}
	}
	for(int r = 0; r < input->getHeight(); r++){
		for(int c = 0; c < input->getWidth(); c++){
			outputBuff[3 * (r * input->getWidth() + c + input->getWidth()) + 0] 
				= rightBuff[3 * (r * input->getWidth() + c) + 0];
			outputBuff[3 * (r * input->getWidth() + c + input->getWidth()) + 1] 
				= rightBuff[3 * (r * input->getWidth() + c) + 1];
			outputBuff[3 * (r * input->getWidth() + c + input->getWidth()) + 2] 
				= rightBuff[3 * (r * input->getWidth() + c) + 2];
		}
	}
	picture.setWidth(input->getWidth() + input2->getWidth());
	picture.setHeight(input->getHeight());
	picture.setData(outputBuff);
}

void TBConcat::Execute(){
	unsigned char *topBuff;
	unsigned char *bottomBuff;
	unsigned char *outputBuff;

	topBuff = (unsigned char*) malloc(COLOR_DIMENSION * input->getWidth() * input->getHeight() 
				* sizeof(unsigned char));
	bottomBuff = (unsigned char*) malloc(COLOR_DIMENSION * input2->getWidth() * input2->getHeight() 
				* sizeof(unsigned char));
	outputBuff = (unsigned char*) malloc(COLOR_DIMENSION * input->getWidth() 
				 * (input->getHeight() + input2->getHeight()) * sizeof(unsigned char));

	topBuff = input->getData();
	bottomBuff = input2->getData();

	for(int r = 0; r < input->getHeight(); r++){
		for(int c = 0; c < input->getWidth(); c++){
			outputBuff[3 * (r * input->getWidth() + c) + 0] 
				= topBuff[3 * (r * input->getWidth() + c) + 0];
			outputBuff[3 * (r * input->getWidth() + c) + 1] 
				= topBuff[3 * (r * input->getWidth() + c) + 1];
			outputBuff[3 * (r * input->getWidth() + c) + 2] 
				= topBuff[3 * (r * input->getWidth() + c) + 2];
		}	
	}
	for(int r = 0; r < input2->getHeight(); r++){
		for(int c = 0; c < input2->getWidth(); c++){
			outputBuff[3 * ((r + input2->getHeight()) * input2->getWidth() + c) + 0]
				= bottomBuff[3 * (r * input2->getWidth() + c) + 0];
			outputBuff[3 * ((r + input2->getHeight()) * input2->getWidth() + c) + 1]
				= bottomBuff[3 * (r * input2->getWidth() + c) + 1];
			outputBuff[3 * ((r + input2->getHeight()) * input2->getWidth() + c) + 2]
				= bottomBuff[3 * (r * input2->getWidth() + c) + 2];
		}
	}
	picture.setData(outputBuff);
	picture.setWidth(input->getWidth());
	picture.setHeight(input->getHeight() + input2->getHeight());
}

void Blender::Execute(){
	unsigned char *buff1;
	unsigned char *buff2;
	unsigned char *buffOut;

	buff1 = (unsigned char*) malloc(COLOR_DIMENSION * input->getHeight() * input->getWidth() * sizeof(unsigned char));
	buff2 = (unsigned char*) malloc(COLOR_DIMENSION * input2->getHeight() * input2->getWidth() * sizeof(unsigned char));
	buffOut = (unsigned char*) malloc(COLOR_DIMENSION * input->getHeight() * input->getWidth() * sizeof(unsigned char));

	buff1 = input->getData();
	buff2 = input2->getData();
	int redFactor(0);
	int greenFactor(0);
	int blueFactor(0);
	for(int r = 0; r < input->getHeight(); r++){
		for(int c = 0; c < input->getWidth(); c++){
			redFactor = (buff1[3 * (r * input->getWidth() + c) + 0] * factor)
						+ (buff2[3* (r * input2->getWidth() + c) + 0] * (1 - factor));
			greenFactor = (buff1[3 * (r * input->getWidth() + c) + 1] * factor)
						+ (buff2[3* (r * input2->getWidth() + c) + 1] * (1 - factor));
			blueFactor = (buff1[3 * (r * input->getWidth() + c) + 2] * factor)
						+ (buff2[3* (r * input2->getWidth() + c) + 2] * (1 - factor));
			
			buffOut[3 * (r * input->getWidth() + c) + 0] = redFactor;
			buffOut[3 * (r * input->getWidth() + c) + 1] = greenFactor;
			buffOut[3 * (r * input->getWidth() + c) + 2] = blueFactor;
			
		}
	}
	picture.setWidth(input->getWidth());
	picture.setHeight(input->getHeight());
	picture.setData(buffOut);
}




