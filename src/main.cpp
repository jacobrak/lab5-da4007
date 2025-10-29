#include "LanguageModel.h"
#include "TextGenerator.h"
#include <iostream>

int main() {
    int k = 3;  
    int length = 6;
    string filename =  "../moby_dick.txt";
    TextGenerator text_generation(k, length, filename);
    string output = text_generation.Generate_text();
    cout << output << endl;
    return 0;
}