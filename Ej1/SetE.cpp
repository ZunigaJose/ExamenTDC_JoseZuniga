#include "SetE.hpp"

SetE::SetE(/* args */) {

}

bool alreadyExists(vector<E> edges, V* x, V* y) {
    for (E edge : edges) {
        if ((edge.getX() == x || edge.getY() == x) && (edge.getX() == y || edge.getY() == y)) {
            return true;
        }
    }
    return false;
}

void SetE::add(V* x, V* y) {
    if (x != NULL && y != NULL && x != y && !alreadyExists(this->edges, x, y)) {
        this->edges.push_back(E(x, y));
    }
}



vector<E> *SetE::getElements() {
    return &this->edges;
}

SetE::~SetE() {

}
