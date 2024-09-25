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

using namespace std;

#define pseudo_random_256b "aePcvgOuOJ1ubrOKwUZZUemayZPeGwtp"

void printData(vector<bitset<8>> &input) {
    cout << endl << "Dvejatainė reprezentacija:" << endl;
    for(const auto& byte : input) cout << byte.to_string() << "'";
    cout << endl << "Hex reprezentacija:" << endl << "0x";
    for(const auto& byte : input) cout << hex << setw(2) << setfill('0') << byte.to_ulong();
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
        char c;
        
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
            
        buffer << is.rdbuf();
        is.close();

        return buffer.str();
    }
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

vector<bitset<8>> TransformTo256(vector<bitset<8>> arr) {
    if(arr.size() % 32 != 0) {
        int i = 0;
        while (arr.size() % 32 != 0) {
            arr.push_back(arr.at(i).flip());
            i++;
        }
    } if (arr.size() == 32) {
        return arr;
    }

    vector<bitset<8>> newArr;
    newArr.reserve(32);

    for (int i = 0; i < 32; i++) {
        newArr.push_back(arr.at(i) ^ arr.at(i + 32));
    }

    if (arr.size() > 64) {
        newArr.insert(newArr.end(), arr.begin() + 64, arr.end());
    }

    return TransformTo256(newArr);

}

//Mazas pokytis reiskia daug (avalanche effect) (teoriskai)
void magnify(vector<bitset<8>> &arr) {
    for (auto it = arr.begin(); it != arr.end(); it++) {
        *it = it->to_ulong() * it->to_ulong() % 256;
        
        int index = distance(arr.begin(), it);
        auto oppositeIt = (arr.end() - (index + 1));
        *oppositeIt = (*oppositeIt^*it).flip();

        if(oppositeIt == it) {
            bitset<8> checker("10101010");
            for(int i = 0; i < arr.size() % 2; i++) checker.flip();
            *oppositeIt = *oppositeIt & checker;
        }
    }
}

int main() {
    // ivestis
    vector<bitset<8>> randomStr, userInput, output(32);

    readInput(userInput, getInputString());
    readInput(randomStr, pseudo_random_256b);

    userInput = TransformTo256(userInput);

    magnify(userInput);
    int i = 0;
    for (auto it = output.begin(); it != output.end(); it++) {
        *it = (*it^userInput[i]);
        i++;
    }
    magnify(output);

    printData(output);
}