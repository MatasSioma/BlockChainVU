#include "hash.h"
#include <random>

using namespace std;

string generateRandomString(int length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyz";
    
    std::random_device rd;  // Non-deterministic random number generator
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string randomString;
    for (int i = 0; i < length; i++) {
        randomString += characters[distribution(generator)];
    }

    return randomString;
}

string hashToString(const vector<bitset<8>>& hash) {
    string hashString;
    for (const auto& b : hash) {
        hashString += b.to_string();  // Convert each bitset to a string
    }
    return hashString;
}

void matchingPairsTest() {
    int matching = 0;
    int lineNum = 25000;
    int strLen[4] = {10,100,500,1000};

    for(int n = 0; n < 4; n++) {
        for(int line = 0; line < lineNum; line++) {
            string str1 = generateRandomString(strLen[n]);
            string str2 = generateRandomString(strLen[n]);
            if(hashToString(hashStr(str1)) == hashToString(hashStr(str2))) {
                matching++;
            }
        }
    }

    cout << "Sutampaciu porų hashų: "<< matching << endl;
    cout << "iš " << lineNum * 4 << " porų" << endl;
}

int main() {
    matchingPairsTest();
}
