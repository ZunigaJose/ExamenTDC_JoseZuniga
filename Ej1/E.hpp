#ifndef Cedge
#define Cedge
#include "V.hpp"

class E {
private:
    V* x;
    V* y;    
public:
    E(/* args */);
    E(V*, V*);
    V* getX();
    V* getY();
    ~E();
};

#endif