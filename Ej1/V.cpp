#include "V.hpp"
V::V(/* args */) {

}

V::V(char id) {
    this->id = id;
}

void V::setTag(string tag) {
    this->tag = tag;
}

char V::getId() {
    return this->id;
}

string V::getTag() {
    return this->tag;
}

V::~V() {

}
