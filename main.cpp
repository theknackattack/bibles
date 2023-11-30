#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Concordance.hpp"

using namespace std;

bool playAgain() {
    string s;
    cout << "Continue? [Y/N] " << flush;
    cin >> s;
    return s[0] == 'Y' || s[0] == 'y';
}

int main(int argc, const char* argv[]) {
    ifstream fin(argv[1]);
    Concordance concordance;
    fin >> concordance;

    do {
        cout << "What would you like to search? " << std::flush;
        string word;
        getline(cin, word);

        for (const string& line : concordance.lookupWords(split(word))) {
            cout << line << endl;
        }
    } while (playAgain());



    return 0;
}