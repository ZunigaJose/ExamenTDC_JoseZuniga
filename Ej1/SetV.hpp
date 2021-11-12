#ifndef Setv
#define Setv
#include <vector>
#include "V.hpp"
#include "Set.hpp"
using namespace std;


class SetV : public Set{
private:
    vector<V> verts;    
public:
    SetV(/* args */);
    void add(char);
    vector<V>* getElements();
    void dummyFunct() {};
    V* getVbyId(char);
    ~SetV();
};

#endif