#include "function.h"

using namespace std;

int main(void){

	welcomeMsg();
	
	//mission one start
	missionOneMsg();
	
	string fileName;
	openFile(fileName);
	readFile();
	importBinaryFile();
	printData();
	
	//mission one end
	

	
}
