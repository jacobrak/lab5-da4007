#include "LanguageModel.h"
#include <iostream>

int main() {
    int k = 3;  

    LanguageModel model(k);
    model.train("moby_dick.txt");  
    string output = model.PickRandom();
    cout << output;
    return 0;
}