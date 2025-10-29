#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H
#include <iostream>
#include <map> 

using namespace std;

class TextGenerator{
public:
    TextGenerator(int k_input, int length_input, const string& filename);

    string Generate_text();

private:
    int k;
    int length;
    string text_file;
    string word;
    map<string, float> Probabilities;
    
    string ReturnWord();

    void CreateMap();
};
#endif