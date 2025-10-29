#ifndef TEXTGENERATOR_H
#define TEXTGENERATOR_H
#include <iostream>

using namespace std;

class TextGenerator{
public:
    TextGenerator(int k_input, int length_input, const string& filename);

    string Generate_text();

    string ReturnWord();
private:
    int k;
    int length;
    string text_file;
    string word;
};
#endif