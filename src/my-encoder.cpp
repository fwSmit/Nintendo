#include "encode.h"
#include <bitset>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;


//void initializeVar(unsigned int* var, unsigned int value1, unsigned int value2, int size){
	
//}


int main(int argc, char *argv[]){
	if(argc == 1){
		cout << "Please provide command line arguments SIZE 0xFFFFFFFF 0xFFFFFFFF" << endl;
		return -1;
	}
	if(argc < 4){
		cout << "Too few arguments" << endl;
		return -1;
	}
	if(argc > 4){
		cout << "Too many arguments" << endl;
		return -1;
	}

	int size;
	std::stringstream convert(argv[1]); // set up a stringstream variable named convert, initialized with the input from argv[1]

	if (!(convert >> size)) // do the conversion
	{
		cout << "Please input a number for SIZE" << endl;
		return -1; // if conversion fails, set myint to a default value
	}

	unsigned int* a = new unsigned int[size / 16]; // <- input tab to encrypt

	//cout << "size: " << size << endl;
	for (int i = 0; i < size / 16; i++) {   // Read size / 16 integers to a
		a[i] = int(strtoul(argv[2+i], nullptr, 16));
	}
	
	std::vector<std::bitset<32>> convertedA;
	convertedA.resize(size/16);
	for(int i = 0; i < convertedA.size(); i++){
		convertedA[i] = a[i];
	}
	//cout << "before: " << endl;
	//printValue(a, size);
	//printValue(convertedA);
	//cout << "after: " << endl;
	printValue(encode(a, size), size);
	//printValue(encode2(convertedA));
	printValue(encode3(convertedA));

	/* 
	   Good luck humans     
	   */
	return 0;
}
