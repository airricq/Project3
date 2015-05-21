#include <source.h>

#ifndef PNMREAD_DEF
#define PNMREAD_DEF

class PNMreader : public Source{
	public:
		PNMreader(char *fin, char *fout);
		virtual void Execute();
};
#endif
