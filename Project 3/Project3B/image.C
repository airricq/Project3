#include "image.h"
Image::Image() : width(0), height(0), data(0) {}

void Image::setData(unsigned char *inputData){
	data = inputData;
}

void Image::setWidth(int inputWidth){
	width = inputWidth;
}

void Image::setHeight(int inputHeight){
	height = inputHeight;
}

int Image::getWidth(){
	return width;
}

int Image::getHeight(){
	return height;
}

unsigned char* Image::getData(){
	return data;
}

