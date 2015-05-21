#include <image.h>
#ifndef SINK_DEF
#define SINK_DEF
class Sink{
	protected:
		Image *input;
		Image *input2;
	
	public:
		void SetInput(Image *img);
		void SetInput2(Image *img);
};
#endif
