#ifndef seq
#define seq
#include <vector>
#include "Set.hpp"

using namespace std;
class Seq {
private:
    vector<Set*> sets;
public:
    Seq(/* args */);
    Seq(Set*, Set*);
    vector<Set*>* getElementos() {return &sets;};
    ~Seq();
};

#endif