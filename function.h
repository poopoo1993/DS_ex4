#include <iostream>
#include <string>
#include <fstream>
#include "class.h"

using namespace std;

fstream fin;
fstream fout;



void openFlie(){
	string fileName;
	while(!fin.is_open()){
		cout<<"Please enter file name : (401,402,....)"<<endl;
		cin>>fileName;
		string temp = fileName + ".txt";
		fin.open(fileName.c_str(),ios::in);
		if(!fin.is_open()){
			cout<<"The file isn't exist."<<endl;
		}else
			string temp = fileName+".bin";
			fout.open(temp,ios::out|ios::binary);
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


