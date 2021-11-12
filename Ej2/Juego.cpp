#include "Juego.hpp"
#include <iostream>
using namespace std;
Juego::Juego(/* args */) {

}

void Juego::readFile(fstream *file) {
    string line;
    string word = "";
    getline(*file, line);
    for (int i = 0; i < line.length(); i++) {
        if (line.at(i) != ',') {
            word += line.at(i);
        } else {
            this->options.push_back(word);
            word = "";
        }
    }
    this->options.push_back(word);
    while(getline(*file, line)) {
        word = "";
        vector<bool> temp;
        for (int i = 0; i < line.length(); i++) {
            if (line.at(i) != ',') {
                word += line.at(i);
            } else {
                temp.push_back((bool)stoi(word));
                word = "";
            }
        }
        temp.push_back((bool)stoi(word));
        this->matriz.push_back(temp);
    }
}

vector<string> Juego::getOptions() {
    return this->options;
}

void Juego::play(int p1, int p2) {
    if (p1 == p2) {
        cout << "Hubo un empate!" << endl;
    }
    bool resultP1 = this->matriz.at(p1 - 1).at(p2 - 1);
    cout << "Gano el jugador " << ((resultP1) ? "1" : "2") << "!!!" << endl;
}

void Juego::printTable() {
    cout << "El orden de filas y columnas es: " << endl;
    for (string str : this->options) {
        cout << str << ", ";
    }
    cout << endl << "Tabla: " << endl;
    for (vector<bool> vect : this->getMatriz()) {
        for (bool val : vect) {
            cout << (val ? 'T' : 'F') << ' ';
        }
        cout << endl;
    }
}

vector<vector<bool>> Juego::getMatriz() {
    return this->matriz;
}

Juego::~Juego() {
}
