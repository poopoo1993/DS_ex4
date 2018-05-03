#include <iostream>
#include <string>
#include <fstream>

using namespace std;

fstream fin;
fstream fout_bin,fout_asc;

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
			string temp_bin = fileName+".bin";
			string temp_asc = fileName+".asc";
			fout_bin.open(temp_bin,ios::out|ios::binary);
			fout_asc.open(temp_asc,ios::out);
		}
	}
}

void readFile(){
}
