#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <iostream>
#include <map> 

using namespace std;
class LanguageModel{
public:
    LanguageModel(int k_value);

    void Train(const string& filename);

    string PickRandom();
    
    string ReadFileOneLine(const string& filename);
private:
    int k;
    map<string, float> Probabilities;
};

#endif