#include "TextGenerator.h"
#include "LanguageModel.h"
#include <iostream>
#include <cassert>
#include <random>

using namespace std;

TextGenerator::TextGenerator(int k_input, int length_input, const string& filename){
    k = k_input;
    length = length_input;
    text_file = filename;
}

string TextGenerator::Generate_text(){
    // Call LanguageModel for random pick
    LanguageModel Model(k);
    Model.Train(text_file);
    string random_text = Model.PickRandom();

    // Get full text from LanguageModel
    string FullText = Model.ReadFileOneLine(text_file);

    word += random_text;
    string tmp = random_text;

    // Run while loop until word_size is equal to length
    while (int(word.size()) != length){
        CreateMap(FullText, tmp);
        string s = string(1, PickRandom()); // convert to string
        tmp = tmp.substr(1); // Get rid of first character
        tmp += s;
        word += s;
    }
    return ReturnWord();
}
void TextGenerator::CreateMap(string text, string random_text){
    Probabilities.clear();

    int items_found = 0;
    int pos = 0;
    while (true) {
        pos = text.find(random_text, pos);    
        if (pos == string::npos) break;

        size_t nextIdx = pos + k;             
        if (nextIdx < text.size()) {
            char c = text[nextIdx];
            Probabilities[c]++;                    
            items_found++;
        }
        pos += 1;                               
    }

    if (items_found == 0) {
        cerr << "Small Language Model cannot predict next charcter please enter in Openai APIkey:" << endl;
        exit(1);
    }
    for (auto& p : Probabilities) {
        Probabilities[p.first] = float(p.second) / float(items_found);
    }

}
char TextGenerator::PickRandom(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0, 1);

    float random_number = dist(gen);
    float running_sum = 0;

    for (auto& p : Probabilities) {
        running_sum += p.second;
        if (running_sum >= random_number) {
            return p.first;
        }
    }
    // Fallback switch
    cerr << "Pickrandom Failed" << endl;
    exit(1);
}
string TextGenerator::ReturnWord(){
    return word;
}