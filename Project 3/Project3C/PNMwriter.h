#include <sink.h>
#ifndef PNM_WRITER
#define PNM_WRITER

class PNMwriter : public Sink{
	public:
		void Write(char *filename);
};
#endif

