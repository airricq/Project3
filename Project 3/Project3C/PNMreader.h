#include <source.h>
#ifndef PNM_READER
#define PNM_READER

class PNMreader : public Source{
	char *inputFile;
	
	public:
		PNMreader(char *filename);
		virtual void Execute();
};
#endif
