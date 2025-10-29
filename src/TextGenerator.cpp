#include "TextGenerator.h"
#include "LanguageModel.h"
#include <iostream>
#include <cassert>

using namespace std;

TextGenerator::TextGenerator(int k_input, int length_input, const string& filename){
    k = k_input;
    length = length_input;
    text_file = filename;
}

string TextGenerator::Generate_text(){
    LanguageModel Model(k);
    Model.train(text_file);
    string random_text = Model.PickRandom();

    word += random_text;
    string tmp = random_text;
    while (int(word.size()) != length){
        tmp;
        CreateMap();
    }
    return ReturnWord();
}
void TextGenerator::CreateMap(){
    
}

string TextGenerator::ReturnWord(){
    return word;
}