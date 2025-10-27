#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <iostream>
#include <map> 

using namespace std;
class LanguageModel{
public:
    LanguageModel(int k_value);

private:
    int k;
    map<char, float> Probabilities;
};

#endif