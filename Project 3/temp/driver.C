#include <PNMreader.h>

int main(int argc, char *argv[]){
	PNMreader reader(argv[1], argv[2]);
	
	reader.Execute();
	return(0);
}
