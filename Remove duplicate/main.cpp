#include <stdlib.h>
#include <iostream>
#include <bitset>

using namespace std;

#define NO_CHARS 255


char *  findDuplicate(char * srcString, bitset<NO_CHARS> &hashBit) {
	
	
	int length = strlen(srcString);
	char * desStr = (char * ) malloc (sizeof(char) * (length + 1) );

	int currentIndex = 0;

	for (int i = 0; i < length; i++) {
		if (hashBit[srcString[i]] == 0) {
			hashBit.set(srcString[i],1);
			desStr[currentIndex] = srcString[i];
			currentIndex ++;
		}
	}

	desStr[currentIndex] = '\0';

	return desStr;
}


char *  findDuplicate2(char * srcString, bitset<NO_CHARS> &hashBit) {
	
	int length = strlen(srcString);
	

	int currentIndex = 0;

	for (int i = 0; i < length; i++) {
		if (hashBit[srcString[i]] == 0) {
			hashBit.set(srcString[i],1);
			srcString[currentIndex] = srcString[i];
			currentIndex ++;
		}
	}

	srcString[currentIndex] = '\0';

	return srcString;
}

// use hashing to remove duplicate string
void main() {
	/*
	I think that the pointer is a pointer to the string literal, and that string cannot be changed, while an array would copy the string literal to the stack, 
	and you are free to modify it. So when I want to use a string I don't plan on changing, I use the pointer to avoid the small extra copying and memory us
	*/


	char * srcString = "test string";  // remove also special character // Write Protected
	//char srcString[] = "test string"; // NOT Write Protected
	bitset<NO_CHARS> hashBit;

	char * resultString = findDuplicate2(srcString, hashBit);
	cout << resultString << endl; // print everything. cout << * resultString // print 1st char
}