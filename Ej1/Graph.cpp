#include "Graph.hpp"
#include <iostream>

Graph::Graph(/* args */) {

}

Graph::Graph(SetV *v, SetE *e) {
    this->s = Seq(v, e);
}

int**  Graph::generarMatriz() {
    SetV* vertices = dynamic_cast<SetV*>(this->s.getElementos()->at(0));
    SetE* edges = dynamic_cast<SetE*>(this->s.getElementos()->at(1));
    V *x, *y;
    int size = vertices->getElements()->size();
    int ** matriz = new int*[size];
    for (int i = 0; i < size; i++) {
        x = &(vertices->getElements()->at(i));
        matriz[i] = new int[size];
        for (int j = 0; j < size; j++) {
            y = &(vertices->getElements()->at(j));
            matriz[i][j] = 0;
            for (E &edge : *edges->getElements()) {
                if (i !=j && (edge.getX()->getId() == x->getId() || edge.getY()->getId() == x->getId()) 
                && (edge.getX()->getId() == y->getId() || edge.getY()->getId() == y->getId())) {
                    matriz[i][j] = 1;
                    break;
                }
            }
        }
    }
    return matriz;
}

SetV* Graph::getV() {
    return dynamic_cast<SetV*>(this->s.getElementos()->at(0));
}

SetE* Graph::getE() {
    return dynamic_cast<SetE*>(this->s.getElementos()->at(1));
}

Graph::~Graph() {
    
}