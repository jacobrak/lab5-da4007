#include "LanguageModel.h"
#include "TextGenerator.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4){
        cerr << "output should be in format ./output <k> <filename> <length>" << endl;
        exit(1);
    }
    int k = stoi(argv[1]);  
    int length = stoi(argv[3]);
    string filename =  argv[2];
    TextGenerator text_generation(k, length, filename);
    string output = text_generation.Generate_text();
    cout << output << endl;
    return 0;
}