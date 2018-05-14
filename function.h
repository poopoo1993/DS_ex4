#include <fstream>
#include <vector>
#include <iomanip>
#include <string.h>
#include <math.h>
#include "class.h"

using namespace std;

fstream fin;//for in file
fstream fout;//for out file

void welcomeMsg(){
	cout << "*****************************************" << endl;
	cout << " On-machine Exercise                    *" << endl;
	cout << " Mission 1: Make a binary file          *" << endl;
	cout << " Mission 2: Hashing with Linear probing *" << endl;
	cout << "*****************************************" << endl;
}

void missionOneMsg(){
	cout << "########################################################" << endl;
	cout << "Mission 1: Transform a text file into a binary file     " << endl;
	cout << "########################################################" << endl << endl;
}

void missionTwoMsg(){
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "Mission 2: Build a hash table by linear probing         " << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
}

void openFile(string &fileName){

	while(!fin.is_open()){
		cout<<"Input the file name (e.g., 401, 402): [0]Quit"<<endl;
		cin>>fileName;

		if(fileName == "0"){exit(0);}//enter 0 for quit.

		string temp ="input" + fileName + ".txt";
		fin.open(temp.c_str(),ios::in|ios::binary);
		if(!fin.is_open()){ //check the file exist, and it's open.
			cout<<"The file isn't exist."<<endl;
		}else{
			string temp = "input" + fileName +".bin";
			fout.open(temp.c_str(),ios::out|ios::binary);
		}
	}
	cout<< endl;
	
}

void readLine(vector <data> &Data){
	
	data *line = new data;
	int temp[6];
	fin>>line->sid;
	fin>>line->sName;
	
	for(int i = 0; i < 6; i++){
		fin>>temp[i];
	}
	
	line->score1 = (unsigned char)temp[0];
	line->score2 = (unsigned char)temp[1];
	line->score3 = (unsigned char)temp[2];
	line->score4 = (unsigned char)temp[3];
	line->score5 = (unsigned char)temp[4];
	line->score6 = (unsigned char)temp[5];
	
	fin>>line->averageScore;
	Data.push_back(*line);
	
}

void readFile(vector <data> &Data){ //close in-file here
	while(!fin.eof()){
		readLine(Data);
	}
	Data.pop_back();
	fin.close();
}

void importBinaryFile(vector <data> &Data){ // close out-file here

	for(int i = 0; i < Data.size(); i++){
		fout.write(Data[i].sid,sizeof(Data[i].sid));
		fout.write(Data[i].sName,sizeof(Data[i].sName));
		fout.write(reinterpret_cast<char*>(&Data[i].score1),sizeof(Data[i].score1));
		fout.write(reinterpret_cast<char*>(&Data[i].score2),sizeof(Data[i].score2));
		fout.write(reinterpret_cast<char*>(&Data[i].score3),sizeof(Data[i].score3));
		fout.write(reinterpret_cast<char*>(&Data[i].score4),sizeof(Data[i].score4));
		fout.write(reinterpret_cast<char*>(&Data[i].score5),sizeof(Data[i].score5));
		fout.write(reinterpret_cast<char*>(&Data[i].score6),sizeof(Data[i].score6));
		fout.write(reinterpret_cast<char*>(&Data[i].averageScore),sizeof(Data[i].averageScore));
	}
	
	cout << "~~ A binary file has been successfully created! ~~" << endl;
	fout.close();
}

void printData(vector <data> &Data){
	
	for(int i = 0; i < Data.size(); i++){
		
		cout<<"["<<i+1<<"] "<<Data[i].sid<<", "<<Data[i].sName<<",	";
		int temp1 = static_cast<int>(Data[i].score1);
		int temp2 = static_cast<int>(Data[i].score2);
		int temp3 = static_cast<int>(Data[i].score3);
		int temp4 = static_cast<int>(Data[i].score4);
		int temp5 = static_cast<int>(Data[i].score5);
		int temp6 = static_cast<int>(Data[i].score6);
		cout<<temp1<<"	"<<temp2<<"	";
		cout<<temp3<<"	"<<temp4<<"	";
		cout<<temp5<<"	"<<temp6<<"	";
		cout<<Data[i].averageScore<<endl;
		
		if((i+1)%20 == 0){
			system("pause");
		}
		
	}
	system("pause");
}

void openFileinBinary(string fileName){
	string temp = "input" + fileName + ".bin";
	fin.open(temp.c_str(),ios::in|ios::binary);
	temp = "input" + fileName + ".tab";
	fout.open(temp.c_str(),ios::out);
}


/*streampos getFileSize(){
	streampos size;
	fin.seekg(0,ios::end);
	size = fin.tellg();
	cout << "size : "<<size<<endl;
	fin.seekg(0,ios::beg);
	return size;
}*/


void readBinaryFile(data* &binaryData, int fileSize){
	
	int times = fileSize;
	for(int i = 0; i < times; i++){
		
		fin.read(binaryData[i].sid,sizeof(binaryData[i].sid));
		fin.read(binaryData[i].sName,sizeof(binaryData[i].sName));
		fin.read(reinterpret_cast<char*>(&binaryData[i].score1),sizeof(binaryData[i].score1));
		fin.read(reinterpret_cast<char*>(&binaryData[i].score2),sizeof(binaryData[i].score2));
		fin.read(reinterpret_cast<char*>(&binaryData[i].score3),sizeof(binaryData[i].score3));
		fin.read(reinterpret_cast<char*>(&binaryData[i].score4),sizeof(binaryData[i].score4));
		fin.read(reinterpret_cast<char*>(&binaryData[i].score5),sizeof(binaryData[i].score5));
		fin.read(reinterpret_cast<char*>(&binaryData[i].score6),sizeof(binaryData[i].score6));
		fin.read(reinterpret_cast<char*>(&binaryData[i].averageScore),sizeof(binaryData[i].averageScore));	
				
	}
	
	fin.close();
	
}

int findPrimeNumberBiggerthan(int number){
	
	int temp = pow(number,0.5);
	int counter = 2;
	while(1){
		
		if(number % counter == 0){
			number++;
			counter = 2;
			continue;
		}else if (counter > temp){
			break;
		}
		counter++;
		
	}
	
	return number;
	
}

int hash(char* sid,int hashTableSize){
	int hashValue = 1;
	for(int i = 0; i < 10; i++){
		if((int)sid[i] >= 48 && (int)sid[i] <= 57){  //ASCII 1~9
			hashValue = (hashValue*(int)sid[i]) % hashTableSize;
		}	
	} 
	return hashValue;
}

void buildHashTable(data* binaryData, hashTable* HashTable, int fileSize, int hashTableSize){
	
	for(int i = 0; i < fileSize; i++){
		
		int hashValue = hash(binaryData[i].sid, hashTableSize);
		int position = hashValue;
		while(1){
			if((int)HashTable[position].sid[0] == 0){
				
				HashTable[position].hashValue = hashValue;
				memcpy(HashTable[position].sid, binaryData[i].sid, sizeof(binaryData[i].sid));
				memcpy(HashTable[position].sName, binaryData[i].sName, sizeof(binaryData[i].sName));
				HashTable[position].averageScore = binaryData[i].averageScore;
				break;	
				
			}else{
				position++;
				if(position == hashTableSize){
					position = 0;
				}
			}	
		}	
	}
	
	cout<<"~~ The hash table has been successfully created! ~~"<<endl<<endl;

	
}

void importHashTable(hashTable* HashTable,  int hashTableSize){
	
	fout<<" --- Hash Table --- by Linear probing"<<endl;
	
	for(int i = 0; i < hashTableSize; i++){
		
		fout << "["<<setw(3)<<i<<"]";
		if((int)HashTable[i].sid[0] != 0){
			fout << setw(11) << HashTable[i].hashValue<<"," ;
			fout << setw(11)<< HashTable[i].sid<<"," ;
			fout << setw(8)<< HashTable[i].sName<<"," ;
			fout << setw(11)<< HashTable[i].averageScore<<endl;
		}else{
			fout<<endl;
		}
		
	}
	
	fout.close();
	
}

void comparisonsonAverage(hashTable* HashTable,data* binaryData, int hashTableSize, int fileSize){
	
	int probingTimesatSuccessfulCase = 0;
	for(int i = 0; i < fileSize; i++){
		int temp = hash(binaryData[i].sid, hashTableSize);
		while(1){
			probingTimesatSuccessfulCase++;
			if(memcmp(HashTable[temp].sid, binaryData[i].sid, sizeof(HashTable[temp].sid))==0){
				break;
			}else{
				temp++;
				if(temp == hashTableSize){
					temp = 0;
				}
			}
		}
	}
	
	
	int probingTimesatUnsuccessfulCase = 0;
	for(int i = 0; i < hashTableSize; i++){
		int temp = i;
		while(1){
			probingTimesatUnsuccessfulCase++;
			if(HashTable[temp].hashValue == -1){
				break;
			}else{
				temp++;
				if(temp == hashTableSize){
					temp = 0;
				}
			}
		}
	}
	
	float loadFactor = (float)fileSize/(float)hashTableSize;
	double averageProbingatUnsuccessfulCase = ((double)probingTimesatUnsuccessfulCase - (double)hashTableSize) / (double)hashTableSize;
	double averageProbingatSuccessfulCase = (double)probingTimesatSuccessfulCase / (double)fileSize;
	cout << "unsuccessful search: "<< fixed << setprecision(4) <<averageProbingatUnsuccessfulCase<<" comparisons on average"<<endl<<endl<<endl;
	cout << "successful search: "<< fixed << setprecision(4) <<averageProbingatSuccessfulCase<<" comparisons on average"<<endl<<endl;
		
}







