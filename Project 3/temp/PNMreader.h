#include <source.h>

#ifndef PNMREAD_DEF
#define PNMREAD_DEF

class PNMreader : public Source{
	char *filename;
	public:
		PNMreader(char *f_in);
		virtual void Execute();
};
#endif
