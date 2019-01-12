#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <bitset>
#include <cmath>

using namespace std;

void printValue(unsigned int* val, int size) {
	for(int i = 0; i < size / 16; i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << setfill('0') << setw(8) << hex << val[i];       // print result
	}
	cout << endl;
}

//void initializeVar(unsigned int* var, unsigned int value1, unsigned int value2, int size){
	
//}

unsigned int* encode(unsigned int* in, int size){
	unsigned int* b = new unsigned int[size / 16]; // <- output tab
	for (int i = 0; i < size / 16; i++) {   // Write size / 16 zeros to b
		b[i] = 0;
	}	

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			b[(i + j) / 32] ^= ( (in[i / 32] >> (i % 32)) &
					(in[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);   // Magic centaurian operation
			//cout << dec << "i: " << i << ", j: " <<  j << "	";
			//printValue(b, size);
			//cout << std::bitset<16> (( (in[i / 32] >> (i % 32)) &
						//(in[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32)) << endl;   // Magic centaurian operation

		}
	}
	return b;
}

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

	unsigned int* test = new unsigned int[size/16];
	bool matchFound = false;
	for(unsigned int i = 0; i < std::pow(2, 16); i++){
		for(unsigned int j = 0; j < std::pow(2, 16); j++){
			test[0] = i;
			test[1] = j;
			unsigned int * temp = encode(test, size);
			if(temp[0] == a[0] && temp[1] == a[1]){
				cout << "found match" << endl;
				printValue(test, size);
				matchFound = true;
				break;
			}
		}
		if(matchFound){
			break;
		}
		cout << "next 2^16" << endl;
	}
	/* 
	   Good luck humans     
	   */
	return 0;
}
