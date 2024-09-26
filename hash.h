#ifndef HASH_H
#define HASH_H

#include <vector>
#include <iostream>
#include <iomanip> 
#include <string>
#include <limits>
#include <bitset>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>

#define pseudo_random_256b "aePcvgOuOJ1ubrOKwUZZUemayZPeGwtp"

using namespace std;

void printHex(vector<bitset<8>> &input);
void printBin(vector<bitset<8>> &input);

void pasirinktiEiga(string msg, int* option, int max);
string getInputString();
string getKonstitucija(int lineNum);

void readInput(vector<bitset<8>> &arr, string inputText);
vector<bitset<8>> TransformTo256(vector<bitset<8>> arr);
void magnify(vector<bitset<8>> &arr);
void joinTwoArr(vector<bitset<8>> &arr, vector<bitset<8>> &output);

vector<bitset<8>> hashStr(string &userInputStr);

#endif