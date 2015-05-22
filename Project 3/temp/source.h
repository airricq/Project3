#include <image.h>
#ifndef SOURCE_DEF
#define SOURCE_DEF
class Source{
	protected:
		Image picture;
	public:
		Image * GetOutput();
		virtual void Execute() = 0;
};
#endif
