#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>

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
	int size;
	std::cin >> size;
	std::vector<string> in(size/16);
	unsigned int* a = new unsigned int[size/16];
	cout << "size: " << size;
	for (int i = 0; i < size / 16; i++) {   // Read size / 16 integers to a
		cin >> in[i] 
		a[i] = int(strtoul(in[i], nullptr, 16));
		cout << "a " << i << " " << a[i] << endl;
	}
}
