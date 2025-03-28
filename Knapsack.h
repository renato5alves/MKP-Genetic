
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Item.h"
#include <iostream>
using namespace std;
class Knapsack
{
private:
    vector<Item*> _itens; 
    int _n;     // number of itens
    int _m;     // number of constraints
    int _w;     // best solution finded
    int *_constraints; // knapsack constraints
public:
    char *filename; // arquivo de entrada
    Knapsack
    (char *filename)
    {
        this->filename = filename;
    };
    inline Item* get_item(int id)
    {
        return this->_itens[id];
    };
    inline int* get_constraints()
    {
        return this->_constraints;
    };
    inline int get_n(){ return this->_n;};
    inline int get_m(){ return this->_m;};
    inline int get_w(){ return this->_w;};
    void build();
    //int get_n();

};
