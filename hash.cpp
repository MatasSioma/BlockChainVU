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

#include "hash.h"

using namespace std;

void printHex(vector<bitset<8>> &input) {
    cout << endl << "Hex reprezentacija:" << endl << "0x";
    for(const auto& byte : input) cout << hex << setw(2) << setfill('0') << byte.to_ulong();
    cout << endl;
}

void printBin(vector<bitset<8>> &input) {
    cout << endl << "Dvejatainė reprezentacija:" << endl;
    for(const auto& byte : input) cout << byte.to_string() << "'";
    cout << endl;
}

void pasirinktiEiga(string msg, int* option, int max) {
    while (true) {
        try {
            cout << msg;
            cin >> *option;
            if(!cin.good() || *option < 1 || *option > max) {
                throw invalid_argument("Netinkama įvestis. Įveskite skaičių nuo 1 iki " + to_string(max));
            }
            break;
        } catch(invalid_argument &e) {
            cerr << e.what() << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string getInputString() {
    int option;
    string inputText;

    pasirinktiEiga("Pasirinkite įvesties tipą.\n1 - Tekstas komandinėje eilutėje,\n2 - Duomenys iš failo\n", &option, 2);
    if(option == 1) {
        cout << "Jūsų tekstas: " << endl;
        cin >> inputText;

        return inputText;
    } else {
        string inFileName;
        ifstream is;
        
        while(true) {
            try {
                cout << "Įveskite failo pavadinimą: ";
                cin >> inFileName;
                is.open(inFileName);
                if (is.fail()) throw invalid_argument("Failas nerastas.");
                break;
            } catch (exception &e) {
                cerr << e.what() << endl;
            }
        }

        stringstream buffer;
        string result;
        string line;

        option = 0;
        cout << "kiek eilučių nuskaityti? (0 - visas): ";
        cin >> option;
        cout << endl;

        if (option == 0) {
            buffer << is.rdbuf();
            is.close();
            return buffer.str();
        } else {
            for (int i = 0; i < option; ++i) {
                if (getline(is, line)) {
                    result += line + "\n";
                } else break;
            }
            is.close();
            return result;
        }
    }
}

string getKonstitucija(int lineNum) {
    ifstream is;
    string line, result;
    is.open("duomenys/konstitucija.txt");

    for (int i = 0; i < lineNum; ++i) {
        if (getline(is, line)) {
            result += line + "\n";
        } else break;
    }
    is.close();
    return result;

}

void readInput(vector<bitset<8>> &arr, string inputText) {
    if(inputText == "") {
        vector<bitset<8>> empty(32);
        arr = empty;
        return;
    }
    for(char c : inputText) {
        bitset<8> b((unsigned char)c);
        arr.push_back(b);
    }
    arr.shrink_to_fit();
}

bitset<8> SBoxTransformation(bitset<8> &input) {
    return ((input << 1) ^ (input >> 3)) ^ ((input << 4) & (input >> 2));
}

vector<bitset<8>> TransformTo256(vector<bitset<8>> arr) {
    if(arr.size() % 32 != 0) {
        int i = 0;
        while (arr.size() % 32 != 0) {
            arr.push_back(SBoxTransformation(arr.at(i).flip()));
            i++;
        }
    }

    if(arr.size() == 32) {
        return arr;
    }

    vector<bitset<8>> newArr;
    newArr.reserve(32);

    for (int i = 0; i < 32; i++) {
        auto leftValue = arr.at(i).to_ulong();
        auto rightValue = arr.at(i + 32).to_ulong();
        newArr.push_back(bitset<8>(((leftValue ^ rightValue) + ((leftValue << 1) | (rightValue >> 1))) % 256));
    }

    if (arr.size() > 64) {
        newArr.insert(newArr.end(), arr.begin() + 64, arr.end());
    }

    return TransformTo256(newArr);
}

//Mazas pokytis reiskia daug (avalanche effect)
void magnify(vector<bitset<8>> &arr) {
    for (auto it = arr.begin(); it != arr.end(); it++) {
        *it = SBoxTransformation(*it);

        int index = distance(arr.begin(), it);
        auto oppositeIt = (arr.end() - (index + 1));

        *oppositeIt = SBoxTransformation((*oppositeIt ^ *it).flip());

        if (oppositeIt == it) {
            bitset<8> checker("10101010");
            *oppositeIt = SBoxTransformation((*oppositeIt ^ checker).flip());
        }
    }
}

void joinTwoArr(vector<bitset<8>> &arr, vector<bitset<8>> &output) {
    int i = 0;
    for (auto it = output.begin(); it != output.end(); it++) {
        auto leftValue = it->to_ulong();
        auto rightValue = arr[i].to_ulong();
        *it = bitset<8>(((leftValue ^ rightValue) + ((rightValue << 3) | (rightValue >> 5))) % 256);
        *it = SBoxTransformation(*it);

        i++;
    }
}

vector<bitset<8>> hashStr(string &userInputStr) {
    vector<bitset<8>> randomStr, userInput, output(32);

    readInput(randomStr, pseudo_random_256b);
    readInput(userInput, userInputStr);
    magnify(userInput);
    userInput = TransformTo256(userInput);
    joinTwoArr(userInput, output);

    return output;
}