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

    bool playAgain = true;
    string s;

    do {
        cout << "What would you like to search? " << flush;
        string word;
        getline(cin, word);

        for (const string& line : concordance.lookupWords(split(word))) {
            cout << line << endl;
        }
        cout << "Continue? [Y/N] " << flush;
        cin >> s;
        if (s[0] == 'N' || s[0] == 'n') {
            playAgain = false;
        }

    } while (playAgain);



    return 0;
}