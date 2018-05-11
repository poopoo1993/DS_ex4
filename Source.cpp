#include "function.h"

using namespace std;

int main(void){

	welcomeMsg();
	string fileName;
	
	//mission one start
	missionOneMsg();
	vector <data> Data;
	openFile(fileName);
	readFile(Data);
	importBinaryFile(Data);
	printData(Data);
	int fileSize = Data.size();
	Data.clear(); //home need us re-read file by binary file.
	//mission one end
	
	missionTwoMsg();
	openFileinBinary(fileName);
	data* binaryData = new data[fileSize];
	readBinaryFile(binaryData,fileSize);
	
}
