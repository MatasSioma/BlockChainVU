#include <iostream>
#include <iomanip> 
#include <string>
#include <limits>
#include <bitset>
#include <vector>
#include <fstream>
#include <sstream>

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
    for(char c : inputText) {
        bitset<8> b((unsigned char)c);
        arr.push_back(b);
    }
    arr.shrink_to_fit();
}

int main() {
    // ivestis
    vector<bitset<8>> randomStr;
    vector<bitset<8>> userInput;

    readInput(userInput, getInputString());
    readInput(randomStr, pseudo_random_256b);

    // Maišymas
    // 1. Užtikrinti kad mažas pakitimas reiškia "daug" avalanche effect
    printData(userInput);

    for (auto it = userInput.begin(); it != userInput.end(); it++) {
        int index = distance(userInput.begin(), it);
        it->flip();
        *it = it->to_ulong() * (userInput.size() * 8) % 255;

        auto oppositeIt = (userInput.end() - index);
        *oppositeIt = (*oppositeIt^*it);
    }

    printData(userInput);
}