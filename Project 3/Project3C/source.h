#include <image.h>
#ifndef SOURCE_H
#define SOURCE_H

class Source{
	protected:
		Image picture;
	
	public:
		virtual void Execute() = 0;
		Image *GetOutput();
};
#endif
