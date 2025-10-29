#include "TextGenerator.h"
#include "LanguageModel.h"
#include <iostream>

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

    return random_text;
}

string TextGenerator::ReturnWord(){
    return word;
}