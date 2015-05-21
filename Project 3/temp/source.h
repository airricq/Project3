#ifndef SOURCE_DEF
#define SOURCE_DEF
#include <image.h>
#include <stdio.h>
class Source{
	protected:
		char *file_in;
		char *file_out;
		Image picture;
		Image * GetOutput();
		virtual void Execute()=0;
};
#endif
