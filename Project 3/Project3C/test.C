#include <PNMreader.h>
#include <PNMwriter.h>
#include <filters.h>

int main(int argc, char *argv[]){
	PNMreader reader(argv[1]);
	PNMwriter writer;
	Shrinker shrinker1;

	shrinker1.SetInput(reader.GetOutput());
	writer.SetInput(shrinker1.GetOutput());
	
	reader.Execute();
	shrinker1.Execute();
	writer.Write(argv[2]);
	return 0;
}
