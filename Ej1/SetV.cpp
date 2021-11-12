#include "SetV.hpp"
#include <algorithm>
#include <iostream>
using namespace std;
SetV::SetV(/* args */) {
}

bool isIn(char ch, vector<V> vect) {
    for (V i : vect) {
        if (i.getId() == ch) {
            return true;
        }
    }
    return false;
}

V* SetV::getVbyId(char id) {
    for (V &element : this->verts) {
        if(element.getId() == id) {
            return &element;
        }
    }
    return NULL;
}

void SetV::add(char id) {
    if(!isIn(id, this->verts)) {
        this->verts.push_back(V(id));
    } else {
        cout << "Ya existe una arista con ese ID" <<endl;
    }   
}

vector<V>* SetV::getElements() {
    return &this->verts;
}

SetV::~SetV() {
}
