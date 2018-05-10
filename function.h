#include <fstream>
#include <vector>
#include "class.h"

using namespace std;

fstream fin;//for in file
FILE * fout;//for out file
vector <data> Data;//there is only one copy of Data, so declare it here.

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

void openFile(){

	string fileName;
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
			fout = fopen((const char*)temp.c_str(),"wb");
		}
	}
	cout<< endl;
	
}

void readLine(){
	
	data *line = new data;
	int temp[6];
	fin>>line->sid;
	fin>>line->sName;
	
	for(int i = 0; i < 6; i++){
		fin>>temp[i];
	}
	
	line->score1 = temp[0];
	line->score2 = temp[1];
	line->score3 = temp[2];
	line->score4 = temp[3];
	line->score5 = temp[4];
	line->score6 = temp[5];
	
	fin>>line->averageScore;
	Data.push_back(*line);
	
}

void readFile(){
	while(!fin.eof()){
		readLine();
	}
	if(Data.back().averageScore == 0){
		Data.pop_back();
	}
}

void importBinaryFile(){

	fwrite(&Data.at(0),32,Data.size(),fout);
	cout << "~~ A binary file has been successfully created! ~~" << endl;
}





