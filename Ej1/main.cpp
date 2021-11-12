#include "E.hpp"
#include "V.hpp"
#include "SetV.hpp"
#include "SetE.hpp"
#include "Graph.hpp"
#include <iostream>
#include <fstream>
using namespace std;

char validarChar(string);
int ingresarLeer();
int menuContinue();
void deleteMatriz(int**, int);
void readEdges(fstream&, SetV*, SetE*);
void readVertices(fstream&, SetV*);
int menu();

int main() {
    SetV setv;
    SetE sete;
    char id, id2;
    string str;
    V *vertice1 = NULL, *vertice2 = NULL;
    int ** matriz, size;
    fstream file;
    cout << "Agregar vertices:" << endl;
    if (ingresarLeer() == 1) {
        do {
            id = validarChar(": ");
            setv.add(id);
        } while (menuContinue());
    } else {
        //leer archivo aqui
        cout << "Ingrese el nombre del archivo (vertices.txt): ";
        cin >> str;
        file.open(str, ios::in);
        if (!file) {
            cout << "Ese archivo no existe!" << endl;
            return -1;
        }
        readVertices(file, &setv);
        file.close();
    }
    cout << "Agregar aristas:" << endl;
    if (ingresarLeer() == 1) {
        do {
            vertice1 = NULL;
            vertice2 = NULL;
            id = validarChar(": ");
            vertice1 = setv.getVbyId(id);
            if (vertice1 == NULL) {
                cout << "No existe un vertice con ese ID" << endl;
                continue;
            }
            id2 = validarChar(": ");
            vertice2 = setv.getVbyId(id2);
            if (vertice2 == NULL) {
                cout << "No existe un vertice con ese ID" << endl;
                continue;
            }
            sete.add(vertice1, vertice2);
        } while (menuContinue());
    } else {
        //leer archivo aqui
        cout << "Ingrese el nombre del archivo (aristas.txt): ";
        cin >> str;
        file.open(str, ios::in);
        if (!file) {
            cout << "Ese archivo no existe!" << endl;
            return -1;
        }
        readEdges(file, &setv, &sete);
        file.close();
    }
    Graph g (&setv, &sete);
    int opcion = menu();
    
    do {
        switch (opcion) {
        case 1:
            do {
                id = validarChar(": ");
                g.getV()->add(id);
                
            } while (menuContinue());
            break;
        case 2:
            do {
                vertice1 = NULL;
                vertice2 = NULL;
                id = validarChar(": ");
                vertice1 = setv.getVbyId(id);
                if (vertice1 == NULL) {
                    cout << "No existe un vertice con ese ID" << endl;
                    continue;
                }
                id2 = validarChar(": ");
                vertice2 = setv.getVbyId(id2);
                if (vertice2 == NULL) {
                    cout << "No existe un vertice con ese ID" << endl;
                    continue;
                }
                g.getE()->add(vertice1, vertice2);
            } while (menuContinue());
            break;
        case 3:
            matriz = g.generarMatriz();
            size = g.getV()->getElements()->size();
            cout << "   ";
            for (V v : *(g.getV()->getElements())) {
                cout << '[' << v.getId() << ']';
            }
            cout << endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (j == 0) {
                        cout << "[" << g.getV()->getElements()->at(i).getId() << ']';
                    }
                    cout << '[' << matriz[i][j] << ']';
                }
                cout << endl;
            }
            //deleteMatriz(matriz, size);
            break;
        case 4:
            id = validarChar(" a buscar: ");
            vertice1 = g.getV()->getVbyId(id);
            if (vertice1) {
                cout << "Ingrese la Etiqueta: ";
                getline(cin, str);
                vertice1->setTag(str);
            }
            cout << "ID " << "Tag" << endl;
            for (V vertice : *g.getV()->getElements()) {
                cout << vertice.getId() << " " << vertice.getTag() << endl;
            }
            
            break;
        }
        opcion = menu();
    } while (opcion);

    return 0;
}

bool validar(int &entrada, int max, int min = 1) {
    if(!(cin >> entrada) || entrada < min || entrada > max) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingreso no valido!" << endl;
        return false;
    }
    return true;
}

int menu() {
    cout << "1. Agregar Vertice\n2. Agregar arista\n3.Representar Grafo en Matriz\n4. Etiquetar Vertice\n0. Salir: ";
    int opt;
    if (validar(opt, 4, 0)) {
        return opt;
    }
    return menu();
}

int ingresarLeer() {
    cout << "1. Ingresar Manual\n2. Leer Archivo: ";
    int opt;
    if (validar(opt, 2)) {
        return opt;
    }
    return ingresarLeer();
}

int menuContinue() {
    cout << "0. Salir\n1. Continuar: ";
    int opt;
    if (validar(opt, 1, 0)) {
        return opt;
    }
    return menuContinue();
}

char validarChar(string str) {
    string input;
    cout << "Ingrese el ID del vertice" << str;
    cin >> input;
    while (input.length() != 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Ingrese de nuevo: ";
        cin >> input;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    return input[0];
}


void readVertices(fstream &file, SetV *vertices) {
    string line;
    getline(file, line);
    for (int i = 0; i < line.length(); i++) {
        if (i %2 == 0) {
            vertices->getElements()->push_back(V(line.at(i)));
        }
    }
    file.close();
}

void readEdges(fstream &file,SetV* vertices, SetE* edges) {
    string line, str;
    bool error = false;
    V *vert1, *vert2;
    while (getline(file, line)) {
        vert1 = NULL;
        vert2 = NULL;
        vert1 = vertices->getVbyId(line.at(0));
        vert2 = vertices->getVbyId(line.at(2));
        if (vert1 && vert2) {
            edges->add(vert1, vert2);
        } else {
            error = false;
        }
    }
    
    file.close();
}

void deleteMatriz(int** matriz, int sz) {
    for (int i = 0; i < sz; i++) {
        delete [] matriz[sz];
    }
    delete [] matriz;
}