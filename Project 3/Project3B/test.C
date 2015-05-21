#include <iostream>
#include "functions.h"
#include "image.h"
using namespace std;

int main(int argc, char *argv[]){
	Image img, img2, img3, img4, img5;
	ReadImage(argv[1], img);
	LeftRightConcatenate(img, img, img3);
    WriteImage(argv[2], img3);

	return(0);
};
