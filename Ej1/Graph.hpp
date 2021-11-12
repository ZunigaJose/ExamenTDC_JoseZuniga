#ifndef Grph
#define Grph
#include "Seq.hpp"
#include "SetE.hpp"
#include "Set.hpp"
#include "SetV.hpp"

using namespace std;
class Graph {
private:
    Seq s;
public:
    Graph(/* args */);
    Graph(SetV*, SetE*);
    int ** generarMatriz();
    SetV* getV();
    SetE* getE();
    ~Graph();
};

#endif
