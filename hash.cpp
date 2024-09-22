#include <iostream>
#include <iomanip> 
#include <string>
#include <limits>
#include <bitset>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void printData(vector<bitset<8>> input) {
    cout << "Dvejatainė reprezentacija:" << endl;
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

void readInput(vector<bitset<8>> &input) {
    int option;
    string inputText;

    pasirinktiEiga("Pasirinkite įvesties tipą.\n1 - Tekstas komandinėje eilutėje,\n2 - Duomenys iš failo\n", &option, 2);
    if(option == 1) {
        cout << "Jūsų tekstas: " << endl;
        cin >> inputText;

        for(char c : inputText) {
            bitset<8> b((unsigned char)c);
            input.push_back(b);
        }
        input.shrink_to_fit();
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

        while (buffer.get(c)) {
            bitset<8> b((unsigned char)c);
            input.push_back(b);
        }
        input.shrink_to_fit();
        buffer.clear();
    }
}

int main() {
    int option;
    vector<bitset<8>> input;
    
    readInput(input);

    printData(input);
}