#include <sink.h>
#include <source.h>

#ifndef FILTER_DEF
#define FILTER_DEF

class Filter : public Sink, public Source{
	public:
		void Execute(){}
};

class Shrinker : public Filter{
	public:
		virtual void Execute();
};

class LRConcat : public Filter{
	public:
		virtual void Execute();
};

class TBConcat : public Filter{
	public:
		virtual void Execute();
};

class Blender : public Filter{
	float factor;
	public:
		void SetFactor(float fact);
		virtual void Execute();
};
#endif
