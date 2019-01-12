#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cmath>
#include <string>
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

int main(){
	int size;
	std::cin >> size;
	unsigned int* a = new unsigned int[size/16];
	std::vector <unsigned int> results;
	cerr << "size: " << size << endl;
	for (int i = 0; i < size / 16; i++) {   // Read size / 16 integers to a
	    string temp;
		cin >> temp;
		a[i] = (unsigned int)(stoul(temp, nullptr, 16));
		cerr << "a " << i << " " << a[i] << endl;
	}
	unsigned int* test = new unsigned int[size/16];
	unsigned int* res = new unsigned int[size/16];
	for(int i = 0; i < std::pow(2, 16); i++){
	    for(int j = 0; j < std::pow(2, 16); j++){
	        test[0] = i; 
	        test[1] = j;
	        res = encode(test, size);
	        if(res[0] == a[0] && res[1] == a[1]){
	            cerr << "found match "<< endl;
	            cout << setfill('0') << setw(8) << hex << test[0];
	            cout << " ";
	            cout << setfill('0') << setw(8) << hex << test[1];
	        }
	    }
	}
    
    
    
}
