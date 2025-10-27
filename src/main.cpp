#include "LanguageModel.h"
#include <iostream>

int main() {
    int k = 3;  

    LanguageModel model(k);
    model.train("moby_dick.txt");  

    return 0;
}