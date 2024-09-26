#include "hash.h"
#include "timer.h"

using namespace std;

int main() {
    int lineNums[10] = {2,4,8,16,32,64,128,256,512,789};
    for(int lineNum : lineNums) {
        string input = getKonstitucija(lineNum);
        Timer hashavimas;
        hashStr(input);
        cout << lineNum << ": "<< hashavimas.elapsed() << "s" << endl;
    }
}