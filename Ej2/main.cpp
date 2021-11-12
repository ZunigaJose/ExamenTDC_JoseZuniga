#include <iostream>
#include <fstream>
#include <string>
#include "Juego.hpp"
using namespace std;

void printOptions(vector<string>);
int select(vector<string> opts, int player);
bool validar(int &, int, int);

int main() {
    fstream file;
    cout << "Ingrese el nombre del archivo (jueguito.txt): ";
    string fileP;
    cin >> fileP;
    file.open(fileP, ios::in);
    if (!file) {
        cout << "Ese archivo no existe!" << endl;
        return -1;
    }
    Juego game;
    game.readFile(&file);
    file.close();
    game.printTable();
    int menuOpt, opt, p1, p2, result;
    do {
        p1 = select(game.getOptions(), 1);
        p2 = select(game.getOptions(), 2);
        game.play(p1, p2);
        cout << "0. Salir" << endl << "1. Continuar: ";
        while (!validar(opt, 1, 0)) {
            cout << "Vuelva a intentar" << endl;
        }
    } while (opt);
    
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

void printOptions(vector<string> opts) {
    int i = 1;
    for (string str : opts) {
        cout << i++ << ". " << str << endl;
    }
}

int select(vector<string> opts, int player) {
    printOptions(opts);
    int opt;
    cout << "Ingrese la opcion del jugador " << player << ": ";
    if (!validar(opt, opts.size())) {
        return select(opts, player);
    }
    return opt;
}