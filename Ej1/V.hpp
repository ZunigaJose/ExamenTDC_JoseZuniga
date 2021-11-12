#ifndef Cvertice
#define Cvertice
#include <string>

using namespace std;

class V {
private:
    char id;
    string tag;
public:
    V(/* args */);
    V(char);
    void setTag(string);
    char getId();
    string getTag();
    ~V();
};

#endif