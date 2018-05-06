#include <iostream>
#include <string>
#include <fstream>
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
	cout << "########################################################" << endl;
}

void openFlie(){
	
	string fileName;
	while(!fin.is_open()){
		cout<<"Input the file name (e.g., 401, 402): [0]Quit"<<endl;
		cin>>fileName;
		
		if(fileName == "0"){exit(0)};//enter 0 for quit.
		
		string temp = fileName + ".txt";
		fin.open(fileName.c_str(),ios::in);
		if(!fin.is_open()){ //check the file exist, and it's open.
			cout<<"The file isn't exist."<<endl;
		}else
			string temp = fileName+".bin";
			fout.open(temp,ios::out|ios::binary);//ios::binary for write into binary code.
		}
	}
}

void readLineinto(vector <data> &Data){
	data *line = new data;
	fin>>line.sid;
	fin>>line.sName
	for(int i = 0; i < 6; i++){
		fin>>line.score[i];
	}
	fin >> line.averageScore;
	Data.pushback(line);
}

void readFileinto(vector <data> &Data){
	while(!fin.eof()){
		readLineinto(Data);
	}
}


