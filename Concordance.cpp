#include <algorithm>
#include <iterator>
#include <sstream>

#include "Concordance.hpp"

using namespace std;

Concordance::Concordance() {

}

vector<string> split(string line) {
    vector<string> result;
    string word;
    stringstream ss(line);
    while (!ss.eof()) {
        ss >> word;
        result.push_back(word);
    }
    return result;
}

vector<string> Concordance::lookupWords(const vector<string> words) const {
    set<int> lineNumbers = wordsToLineNumbers.at(words[0]);
    for (const string& w : words) {
        set<int> newLines = wordsToLineNumbers.at(w);
        set<int> copy;
        std::set_intersection(
            lineNumbers.begin(), lineNumbers.end(),
            newLines.begin(), newLines.end(),
            inserter(copy, copy.end()));
        lineNumbers = copy;
    }
    vector<string> result;
    transform(lineNumbers.begin(), lineNumbers.end(), back_inserter(result), [this](int i){
        return lines[i];
    });
    return result;
}


vector<string> Concordance::lookup(const string& word) const {
    vector<string> result;
    if (wordsToLineNumbers.count(word)) {
        const set<int>& lineNums = wordsToLineNumbers.at(word);
        transform(lineNums.begin(), lineNums.end(), back_inserter(result), [this](int i){
        return lines[i];
        });
    }
    
    return result;
}

std::istream& operator>>(std::istream& fin, Concordance& object) {
    while (!fin.eof()) {
        string line;
        getline(fin, line);
        vector<string> words = split(line);
        int lineNum = object.lines.size();
        for (string& w : words) {
            object.wordsToLineNumbers[w].insert(lineNum);
        }
        object.lines.push_back(line);
    }

    return fin;
}