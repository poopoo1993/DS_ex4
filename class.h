#include <iostream>
#include <string>
#include "function.h"

using namespace std;

class data{

public:
	string sid = "";
	string sName = "";
	int score[6] = {};
	double averageScore = 0;
	
	void printData(){
		
		cout<<sid<<","<<sName<<",";
		for(int i = 0; i < 6; i++){
			cout << "	" << score[i];
		}
		cout << "	" << averageScore << endl;
		
	}
};
