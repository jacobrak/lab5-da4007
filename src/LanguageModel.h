#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <iostream>
#include <map> 

using namespace std;
class LanguageModel{
public:
    LanguageModel(int k_value);

    void train(const string& filename);

    string PickRandom();
private:
    int k;
    map<string, float> Probabilities;

    string ReadFileOneLine(const string& filename);
};

#endif