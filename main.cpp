#include "hash.h"

using namespace std;

int main() {
    string input = getInputString();
    vector<bitset<8>> output = hashStr(input);
    printHex(output);
}