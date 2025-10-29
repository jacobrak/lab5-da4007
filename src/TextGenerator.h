#include <iostream>

using namespace std;

class TextGenerator{
public:
    TextGenerator(int k, int length);

    string ReturnString();
private:
    int k;
    int length;
    string word;
};