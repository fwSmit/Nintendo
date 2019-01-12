#pragma once
#include <bitset>
#include <vector>

unsigned int* encode(unsigned int* in, int size);
std::vector<std::bitset<32>> encode2(std::vector<std::bitset<32>> in);
std::vector<std::bitset<32>> encode3(std::vector<std::bitset<32>> in);
void printValue(unsigned int* val, int size);
void printValue(std::vector<std::bitset<32>> val);
