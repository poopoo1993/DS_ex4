#include <fstream>
#include <vector>
#include "class.h"
#include <sys/stat.h>

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
		int temp1 = static_cast<int> (binaryData[i].score1);
		int temp2 = static_cast<int> (binaryData[i].score2);
		int temp3 = static_cast<int> (binaryData[i].score3);
		int temp4 = static_cast<int> (binaryData[i].score4);
		int temp5 = static_cast<int> (binaryData[i].score5);
		int temp6 = static_cast<int> (binaryData[i].score6);
		cout<<"["<<i+1<<"]"<<temp1<<" "<<temp2<<" "<<temp3<<" "<<temp4<<" "<<temp5<<" "<<temp6<<endl; 
			
	}
	
	fin.close();
	
}






