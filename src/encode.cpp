#include "encode.h"
#include <iostream>
#include <iomanip>

using namespace std;

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
			//cout << std::bitset<32> (( (in[i / 32] >> (i % 32)) &
						//(in[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32)) << endl;   // Magic centaurian operation

		}
	}
	return b;
}

std::vector<std::bitset<32>> encode2(std::vector<std::bitset<32>> in){
	//unsigned int* b = new unsigned int[size / 16]; // <- output tab
	int size = in.size() * 16;
	std::vector<std::bitset<32>> out;
	out.resize(in.size());
	for (int i = 0; i < size / 16; i++) {   // Write size / 16 zeros to b
		out[i].reset();
	}	

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			out[(i + j) / 32] ^= ( (in[i / 32] >> (i % 32)) &
					(in[j / 32 + size / 32] >> (j % 32)) & std::bitset<32>(1) ) << ((i + j) % 32);   // Magic centaurian operation
			//cout << dec << "i: " << i << ", j: " <<  j << "	";
			//printValue(out, size);
			//cout << std::bitset<32> (( (in[i / 32] >> (i % 32)) &
						//(in[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32)) << endl;   // Magic centaurian operation

		}
	}
	return out;
}

std::vector<std::bitset<32>> encode3(std::vector<std::bitset<32>> in){
	std::vector<std::vector<unsigned int>> n_flips;
	n_flips.resize(in.size(), std::vector<unsigned int>(32));
	int size = in.size() * 16;
	std::vector<std::bitset<32>> out;
	out.resize(in.size());
	for (int i = 0; i < size / 16; i++) {   // Write size / 16 zeros to b
		out[i].reset();
	}	

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			//bool flip =  ((in[i / 32] >> (i % 32)) &
					//(in[j / 32 + size / 32] >> (j % 32)))[0]; 
			bool flip =  in[i / 32][ i % 32 ] &
					in[j / 32 + size / 32][ j % 32 ]; 
			if(flip){
				out[(i + j) / 32][(i + j) % 32].flip();
				n_flips[(i + j) / 32][(i + j) % 32]++;
			}
		}
	}
	for(size_t i = 0; i < n_flips.size(); i++){
		for(int j = n_flips[i].size()-1; j >= 0; j--){
			
			cout << dec <<  n_flips[i][j] << " ";
		}
		cout << "		";
	}
	cout << endl;
	return out;
}
void printValue(unsigned int* val, int size) {
	for(int i = 0; i < size / 16; i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << setfill('0') << setw(8) << hex << val[i];       // print result
	}
	cout << endl;
}

void printValue(std::vector<std::bitset<32>> val) {
	for(size_t i = 0; i < val.size(); i++){
		unsigned int intVal = (unsigned int)(val[i].to_ulong());
		cout << setfill('0') << setw(8) << hex << intVal << " ";       // print result
	}
	cout << endl;
}
void printBinary(std::vector<std::bitset<32>> val){
	for(size_t i = 0; i < val.size(); i++){
		for(size_t j = 0; j < val[i].size(); j++)
		{
			cout << val[i].to_string()[j] << " ";
		}
		cout << "		";
	}
	cout << endl;
}

std::vector<std::bitset<32>> toBitset(unsigned int* val, int size){
	std::vector<std::bitset<32>> converted;
	converted.resize(size/16);
	for(size_t i = 0; i < converted.size(); i++){
		converted[i] = val[i];
	}
	return converted;
}

void printCorrect(std::vector<std::bitset<32>> val){
	for(size_t i = 0; i < val.size(); i++){
		for(size_t j = 0; j < val[i].size(); j++)
		{
			cout << val[i].to_string('O', 'X' )[j] << " ";
		}
		cout << "		";
	}
	cout << endl;
}
