#include <fstream>
#include <vector>
#include "class.h"

using namespace std;

fstream fin;//for in file
fstream fout;//for out file
vector<data> Data;//there is only one copy of Data, so declare it here.

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
		fin.open(temp.c_str(),ios::in);
		if(!fin.is_open()){ //check the file exist, and it's open.
			cout<<"The file isn't exist."<<endl;
		}else{
			string temp = "input" + fileName +".bin";
			fout.open(temp.c_str(),ios::out|ios::binary);//ios::binary for write into binary code.
		}
	}
	cout<< endl;
}

void readLine(){
	data *line = new data;
	fin>>line->sid;
	fin>>line->sName;
	for(int i = 0; i < 6; i++){
		fin>>line->score[i];
	}
	fin >> line->averageScore;
	Data.push_back(*line);
}

void readFile(){
	while(!fin.eof()){
		readLine();
	}

}

void importBinaryFile(){

	for(int i = 0; i < Data.size(); i++){
		fout.write(Data[i].sid.c_str(), sizeof(Data[i].sid.c_str()));
		fout.write(Data[i].sName.c_str(), sizeof(Data[i].sName.c_str()));
		fout.write((char*)Data[i].score, sizeof((char*)Data[i].score));
		fout.write((char*)Data[i].averageScore, sizeof((char*)Data[i].averageScore));

	}
	cout << "~~ A binary file has been successfully created! ~~" << endl;
}



