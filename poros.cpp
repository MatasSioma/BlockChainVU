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

    cout << "Sutampančių porų hashų: "<< matching << endl;
    cout << "iš " << lineNum * 4 << " porų" << endl;
}

int BitDiff(vector<bitset<8>>& hash1, vector<bitset<8>>& hash2) {
    int diffCount = 0;
    for (int i = 0; i < 32; i++) {
        for(int b = 0; b < 8; b++) {
            if (hash1[i].test(b) != hash2[i].test(b)) {
                diffCount++;
            }
        }
    }
    return diffCount;
}

int HexDiff(vector<bitset<8>>& hash1, vector<bitset<8>>& hash2) {
    int diffCount = 0;
    for (int i = 0; i < 32; i++) {
        for(int b = 0; b < 2; b++) {
            if (hash1[i].test(0 + b*4) != hash2[i].test(0 + b*4) ||
                hash1[i].test(1 + b*4) != hash2[i].test(1 + b*4) ||
                hash1[i].test(2 + b*4) != hash2[i].test(2 + b*4) ||
                hash1[i].test(3 + b*4) != hash2[i].test(3 + b*4)
            ) {
                diffCount++;
            }
        }
    }
    return diffCount;
}

void avalancheEffectTest() {
    srand(time(nullptr));
    int pairCount = 100000;
    int strLength = 500;
    vector<int> bitDissimilarity;
    vector<int> hexDissimilarity;

    int minBitDiff = strLength * 8, maxBitDiff = 0, totalBitDiff = 0;
    int minHexDiff = strLength * 2, maxHexDiff = 0, totalHexDiff = 0;

    for (int i = 0; i < pairCount; i++) {
        string baseString = generateRandomString(strLength);

        string modifiedString = baseString;
        int changeIndex = rand() % strLength;
        modifiedString[changeIndex] = (char) rand() % 26 + 61;

        vector<bitset<8>> hash1 = hashStr(baseString);
        vector<bitset<8>> hash2 = hashStr(modifiedString);

        int bitDiff = BitDiff(hash1, hash2);
        int hexDiff = HexDiff(hash1, hash2);

        bitDissimilarity.push_back(bitDiff);
        hexDissimilarity.push_back(hexDiff);

        minBitDiff = min(minBitDiff, bitDiff);
        maxBitDiff = max(maxBitDiff, bitDiff);
        totalBitDiff += bitDiff;

        minHexDiff = min(minHexDiff, hexDiff);
        maxHexDiff = max(maxHexDiff, hexDiff);
        totalHexDiff += hexDiff;

        // if(bitDiff == 0 || hexDiff == 0) {
        //     printHex(hash1);
        //     printHex(hash2);
        // }
    }

    double avgBitDiff = static_cast<double>(totalBitDiff) / pairCount;
    double avgHexDiff = static_cast<double>(totalHexDiff) / pairCount;

    cout << "Bitų lygio Nepanašumas: " << endl;
    cout << "Minimum: " << minBitDiff << " bitai" << endl;
    cout << "Maximum: " << maxBitDiff << " bitai" << endl;
    cout << "Average: " << avgBitDiff << " bitai" << endl;

    cout << "\nHex lygio Nepanašumas: " << endl;
    cout << "Minimum: " << minHexDiff << " hex skaitmenys" << endl;
    cout << "Maximum: " << maxHexDiff << " hex skaitmenys" << endl;
    cout << "Average: " << avgHexDiff << " hex skaitmenys" << endl;
}

int main() {
    // matchingPairsTest();
    avalancheEffectTest();

    // string str1 = "adf";
    // string str2 = "adg";

    // vector<bitset<8>> hash1 = hashStr(str1);
    // vector<bitset<8>> hash2 = hashStr(str2);

    // int diff = HexDiff(hash1, hash2);

    // printHex(hash1);
    // printHex(hash2);

    // cout << diff << endl;
}
