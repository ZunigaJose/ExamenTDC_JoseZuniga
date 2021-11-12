#include "Seq.hpp"
#include "SetV.hpp"
Seq::Seq(/* args */) {

}

Seq::Seq(Set *v, Set *e) {
    //SetV *x = dynamic_cast<SetV *>(v);
    this->sets.push_back(v);
    this->sets.push_back(e);
}



Seq::~Seq()
{
}