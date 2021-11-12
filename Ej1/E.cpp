#include "E.hpp"

E::E(/* args */) {

}

E::E(V* x, V* y) {
    this->x = x;
    this->y = y;
}

V* E::getX() {
    return this->x;
}

V* E::getY() {
    return this->y;
}

E::~E() {

}