#include "LanguageModel.h"
#include <iostream>
#include <map>
#include <fstream>
#include <random>

using namespace std;

LanguageModel::LanguageModel(int k_value){
    k = k_value;
}
void LanguageModel::Train(const string& filename){
    string one_line = ReadFileOneLine(filename);

    Probabilities.clear();

    // Incase of mismatch
    if (int(one_line.size()) < k + 1){
        std::cerr << "Error: text wrong length for k = " << k << endl;
        return;
    }

    map<string, int> counts;   
    int size = 0;                        

    // Slide window and count (int conversion necessary)
    for (int i = 0; i + k <= int(one_line.size()); ++i) {
        string w = one_line.substr(i, k);
        counts[w]++;                     // count this k-gram
        size++;                          // total number of windows
    }

    // Convert counts to frequencies 
    for (auto& p : counts) {
        Probabilities[p.first] = float(p.second) / float(size);
    }
    // Prints values
    //for (auto& p : Probabilities) {
    //    std::cout << p.first << " " << p.second << std::endl;
    //}
}
string LanguageModel::ReadFileOneLine(const string& filename){ 
    ifstream file(filename); 
    if (!file){ cerr << "Error opening file" << endl; 
        exit(1); 
    } 

    // Read file line by line into one giant line 
    string one_line; 
    string word; 
    while (getline(file, word)){ 
        one_line += word + '\n'; 
    } 

    // Remove last newline 
    if (!one_line.empty() && one_line.back() == '\n') { 
        one_line.pop_back(); 
    } 
    return one_line; 
}
string LanguageModel::PickRandom(){
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
    return "";
}