#include <iostream>
#include <string>

using namespace std;

struct data{

	char sid[10];
	char sName[10];
	unsigned char score1;
	unsigned char score2;
	unsigned char score3;
	unsigned char score4;
	unsigned char score5;
	unsigned char score6;
	float averageScore;

};

class hashTable{

public:
	int hashValue = -1;
	char sid[10];
	char sName[10];
	float averageScore = 0;
	
	
};
