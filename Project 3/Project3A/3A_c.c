#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int r;
	int c;
	unsigned char *Data;

} Image;

Image *
ReadImage(char *filename)
{
    FILE *f_in;
	f_in = fopen(filename, "rb");
	Image *img;
    char pnmType[2];
    int temp_width;
	int temp_height;
	int maxVal;

    fscanf(f_in, "%s\n%d %d\n%d\n", pnmType, &temp_width, &temp_height, &maxVal);
	img = (Image *) malloc(sizeof(Image));
	img->r = temp_width;
	img->c = temp_height;
	img->Data =  malloc(3 * img->r * img->c * sizeof(unsigned char));
	fread(img->Data, sizeof(unsigned char), 3 * img->r * img->c, f_in);
    fclose(f_in);
    return img;
}

void WriteImage(Image *img, char *filename)
{
	FILE *f_out;
	f_out = fopen(filename, "wb");
	
	fprintf(f_out, "P6\n%d %d\n%d\n", img->r, img->c, 255);
	fwrite(img->Data, sizeof(unsigned char), 3 * img->r * img->c, f_out);
	fclose(f_out);
}

Image *
YellowDiagonal(Image *input)
{
	int i;
	
	for (i = 0; i < input->c; i++){
		input->Data[3 * (i * input->r + i) + 0] = 255;
		input->Data[3 * (i * input->r + i) + 1] = 255;
		input->Data[3 * (i * input->r + i) + 2] = 0;
	}
	return input;
}

int main(int argc, char *argv[])
{ 
	if (argc != 3)
    {
        fprintf(stderr, "Usage: ./3A_c.c <input image file> <output image file>\n");
        exit(EXIT_FAILURE);
    }

	Image *img;
	img = ReadImage(argv[1]);
	YellowDiagonal(img);
	WriteImage(img, argv[2]);
}
