#include "encode.h"
#include <bitset>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cassert>

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
	
	std::vector<std::bitset<32>> convertedA = toBitset(a, size);
	//cout << "before: " << endl;
	//printValue(a, size);
	//printValue(convertedA);
	//cout << "after: " << endl;
	// printBinary(toBitset( encode(a, size), size ));
	printBinary(convertedA);
	auto encoded1 = encode(a, size);
	std::vector<std::bitset<32>> encoded2 = encode2(convertedA);
	std::vector<std::bitset<32>> encoded3 = encode3(convertedA);
	for(int i = 0; i < size/16; i++)
	{
		assert(encoded1[i] == (unsigned int)(encoded2[i].to_ulong()));
		assert(encoded1[i] == (unsigned int)(encoded3[i].to_ulong()));
	}
	//printValue(encode2(convertedA));
	printBinary(encoded3);
	std::vector<std::bitset<32>> solution(size/16);
	std::vector<std::bitset<32>> mustBeTrue(size/16);
	std::vector<std::bitset<32>> mustBeFalse(size/16);
	
	
	// solution[0][0] = encoded3[0][0];
	// solution[1][0] = encoded3[0][0];
	// solution[0][31] = encoded3[1][30];
	// solution[1][31] = encoded3[1][30];
	printBinary(solution);
	std::vector<std::bitset<32>> correct(size/16);
	for(int i = 0; i < size/16; i++){
		correct[i] = ~( solution[i] ^ std::bitset<32>( a[i] ) );
	}
	printCorrect(correct);
	printValue(encoded3);

	/* 
	   Good luck humans     
	   */
	return 0;
}
