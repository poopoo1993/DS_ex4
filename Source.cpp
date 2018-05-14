#include "function.h"

using namespace std;

int main(void){

	while(1){
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
		
		//mission two start
		missionTwoMsg();
		openFileinBinary(fileName);
		data* binaryData = new data[fileSize];
		readBinaryFile(binaryData,fileSize);
		int hashTableSize = findPrimeNumberBiggerthan(fileSize*1.2); //1.2 is homework require.
		hashTable* HashTable = new hashTable[hashTableSize];
		buildHashTable(binaryData, HashTable , fileSize, hashTableSize);
		importHashTable(HashTable, hashTableSize);
		comparisonsonAverage(HashTable, binaryData, hashTableSize, fileSize);	
		//mission two end
		
		string continueIndex = "";
		cout<<endl<<"[0]Quit or [Any other key]continue?"<<endl;
		cin>>continueIndex;
		if(continueIndex == "0"){
			exit(0);
		}
		
	}

	
}
