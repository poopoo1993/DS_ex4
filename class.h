#include <iostream>
#include <string>

using namespace std;

class data{

public:
	string sid = "";
	string sName = "";
	int score[6] = {};
	float averageScore = 0;

	void printData(){

		cout<<sid<<","<<sName<<",";
		for(int i = 0; i < 6; i++){
			cout << "	" << score[i];
		}
		cout << "	" << averageScore << endl;

	}
};
