#include "hash.h"

using namespace std;

int main() {
    // ivestis
    vector<bitset<8>> randomStr, userInput, output(32);

    readInput(userInput, getInputString());
    readInput(randomStr, pseudo_random_256b);

    userInput = TransformTo256(userInput);

    magnify(userInput);
    joinTwoArr(userInput, output);
    magnify(output);

    printHex(output);
}