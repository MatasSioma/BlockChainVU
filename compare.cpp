#include "hash.h"
#include "timer.h"

//Funkcijų implementacijos paimtos iš - http://www.zedwood.com/article/cpp-sha256-function
#include "SHA/md5.h"
#include "SHA/sha1.h"
#include "SHA/sha256.h"

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

int main() {
    int strLens[5] = {3, 45, 128, 1000, 100000};
    int testCount = 5;
    for(int strLen : strLens) {
        double avgMano = 0, avgSHA = 0, diff;
        for(int n = 0; n < testCount; n++) {
            string input = generateRandomString(strLen);

            Timer SHA;
            sha256(input);
            avgSHA += SHA.elapsed();

            Timer Mano;
            hashStr(input, "");
            avgMano += Mano.elapsed();
        }
        avgMano /= testCount;
        avgSHA /= testCount;

        diff = avgSHA / avgMano;

        cout << dec << strLen << " simbolių ilgio įvesčiai, SHA256: " << avgSHA << "s, ManoHashF(x): " << avgMano << "s. "
        << "Laikų santykis = " << diff << " t.y. vidurkis per " << testCount << " bandymus." << endl;
    }
}