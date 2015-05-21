#ifndef IMAGE_DEF
#define IMAGE_DEF
class Image{
	unsigned char *data;
	int width;
	int height;

	public:
		Image();
		void setData(unsigned char *inputData);
		void setWidth(int inputWidth);
		void setHeight(int inputHeight);
		int getWidth();
		int getHeight();		
		unsigned char* getData();
};
#endif
