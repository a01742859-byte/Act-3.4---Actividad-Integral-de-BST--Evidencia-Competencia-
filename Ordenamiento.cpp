#include "Ordenamiento.h"
using namespace std;
void Ordenamiento::mezcla(vector<Bitacora*> &v, int ini, int fin){
    int central = (ini+fin) / 2;
    int tam = fin-ini+1;
    vector<Bitacora*> tmp(tam);
    int i=ini;
    int j=central+1;
    int k=0;

    while(i<=central && j <= fin){
        if(*v[i] < *v[j]){
            tmp[k] = v[i];
            i++;
        } else{
            tmp[k] = v[j];
            j++;
        }
        k++;
    }

    while(i<=central){
        tmp[k]=v[i];
        i++;
        k++;
    }

    while(j<=fin){
        tmp[k]=v[j];
        j++;
        k++;
    }
    for(int index=0; index<tam; index++){
        v[ini+index]=tmp[index];
    }
}

void Ordenamiento::mergesort(vector<Bitacora*> &v, int ini, int fin){
    if(ini<fin){
        int central=(ini+fin)/2;
        mergesort(v,ini,central);
        mergesort(v,central+1,fin);
        mezcla(v,ini,fin);
    }
}

void Ordenamiento::ordenarMerge(vector<Bitacora*> &v){
    if(!v.empty()){
        mergesort(v,0,v.size()-1);
    }
}