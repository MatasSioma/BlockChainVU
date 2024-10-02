#include "hash.h"

using namespace std;

int main() {
    string input = getInputString();
    string salt = getSalt();
    printHex(hashStr(input, salt));
}