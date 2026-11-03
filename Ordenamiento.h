#pragma once
#include <vector>
#include "Bitacora.h"

using namespace std;

struct Ordenamiento{
    Ordenamiento() = default;
private:
    void mezcla(vector<Bitacora*> &v, int ini, int fin);
    void mergesort(vector<Bitacora*> &v, int ini, int fin);

public:
    void ordenarMerge(vector<Bitacora*> &v);
};