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
	
	line->score1 = (unsigned char)temp[0];
	line->score2 = (unsigned char)temp[1];
	line->score3 = (unsigned char)temp[2];
	line->score4 = (unsigned char)temp[3];
	line->score5 = (unsigned char)temp[4];
	line->score6 = (unsigned char)temp[5];
	
	fin>>line->averageScore;
	Data.push_back(*line);
	
}

void readFile(){ //close in-file here
	while(!fin.eof()){
		readLine();
	}
	if(Data.back().averageScore == 0){
		Data.pop_back();
	}
	fin.close();
}

void printData(){
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

void importBinaryFile(){ // close out-file here

	fwrite(&Data.at(0),32,Data.size(),fout);
	fclose(fout);
	cout << "~~ A binary file has been successfully created! ~~" << endl;
	
}









