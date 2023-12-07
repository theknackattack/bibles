#pragma once
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> split(std::string line);

class Concordance {
 public:
    Concordance();
    std::vector<std::string> lookup(const std::string&) const;
    std::vector<std::string> lookupWords(const std::vector<std::string> words) const;
 private:
    std::unordered_map<std::string, std::set<int>> wordsToLineNumbers;
    std::vector<std::string> lines;
    friend std::istream& operator>>(std::istream& fin, Concordance& object);
};

std::istream& operator>>(std::istream& fin, Concordance& object);