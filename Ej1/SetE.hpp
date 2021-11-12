#ifndef Sete
#define Sete
#include <vector>
#include "E.hpp"
#include "V.hpp"
#include "Set.hpp"

using namespace std;

class SetE : public Set {
private:
    vector<E> edges;
public:
    SetE(/* args */);
    void add(V*, V*);
    void dummyFunct() {};
    vector<E>* getElements();
    ~SetE();
};

#endif