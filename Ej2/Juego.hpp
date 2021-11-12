#ifndef CJuego
#define CJuego
#include <vector>
#include <string>
#include <fstream>

using namespace std;
class Juego {
private:
    vector<string> options;
    vector<vector<bool>> matriz;
public:
    Juego(/* args */);
    ~Juego();
    vector<string> getOptions();
    vector<vector<bool>> getMatriz();
    void printTable();
    void play(int, int);
    void readFile(fstream*);
};

#endif