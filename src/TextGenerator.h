#include <iostream>

using namespace std;

class TextGenerator{
public:
    TextGenerator(int k_input, int length_input);

    string ReturnWord();
private:
    int k;
    int length;
    string word;
};