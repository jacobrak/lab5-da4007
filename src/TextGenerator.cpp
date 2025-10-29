#include "TextGenerator.h"
#include <iostream>

using namespace std;
TextGenerator::TextGenerator(int k_input, int length_input){
    k = k_input;
    length = length_input;
}
string TextGenerator::ReturnWord(){
    return word;
}