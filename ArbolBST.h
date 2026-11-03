// Carlos Francisco Sanchez Llanes A01741201
// Santiago Guillen Cebreros A01742859
// Mauro Solorzano Ortiz A01642569
// Act 3.4 - Actividad Integral de BST 
// 3/11/2026
#pragma once
#include <vector>

struct NodoBST {
    int dato;
    std::vector<std::string> ips;
    NodoBST* izq,
           * der;
    NodoBST(int dato,std::string ip) : dato(dato), izq(nullptr), der(nullptr) {
        ips.push_back(ip);
    }
};

class ArbolNum {
    public :
        ArbolNum();
        void insertar(int,std::string);
        ~ArbolNum();
        void imprimirMaximos(int);
        void imprimirPorNivel();
    private :
        NodoBST* raiz;
        void insertar(int,NodoBST*,std::string);
        void destruirArbol(NodoBST*);
        void imprimirMaximos(int&,NodoBST*);
};