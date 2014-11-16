#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

void reverseStr(char* src, int srcLength, char* desStr, int desLength) {
	if ( (srcLength <= 0) ) {
		desStr[desLength] = '\0';
		return; 
	}

	srcLength--;
	desStr[desLength] = src[srcLength];

	desLength++;
	reverseStr(src,srcLength,desStr,desLength);
}

void main() {
	char srcStr[] = "PratiseCOdingEveryday.com";
	int srcLength = sizeof(srcStr) / sizeof(char) - 1; //remove "/0";
	
	char* desStr = (char*)malloc(sizeof(char) * srcLength  + 1);
	int desLength = 0;

	reverseStr(srcStr,srcLength,desStr,desLength);
	cout << srcStr << endl;
	cout << desStr << endl;

}