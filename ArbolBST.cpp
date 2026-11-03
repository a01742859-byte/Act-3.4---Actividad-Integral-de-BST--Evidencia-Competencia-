// Carlos Francisco Sanchez Llanes A01741201
// Santiago Guillen Cebreros A01742859
// Mauro Solorzano Ortiz A01642569
// Act 3.4 - Actividad Integral de BST 
// 3/11/2026
#include <string>
#include <iostream>
#include <queue>
#include "ArbolBST.h"

ArbolNum::ArbolNum() : raiz(nullptr) {}

ArbolNum::~ArbolNum() {
    destruirArbol(raiz);
}

void ArbolNum::destruirArbol(NodoBST* nodo) {
    if(nodo == nullptr) return;
    destruirArbol(nodo->izq);
    destruirArbol(nodo->der);
    delete nodo;
}

void ArbolNum::insertar(int dato,std::string ip) {
    insertar(dato,raiz,ip);
}

void ArbolNum::insertar(int dato,NodoBST* nodo,std::string ip) {
    if(nodo == nullptr) {
        raiz = new NodoBST(dato,ip);
        return;
    }

    if(nodo->dato == dato) {
        nodo->ips.push_back(ip);
        return;
    }

    if(nodo->dato > dato) {
        if(nodo->izq == nullptr) {
            nodo->izq = new NodoBST(dato,ip);
            return;
        }
        insertar(dato,nodo->izq,ip);
    }
    else if(nodo->dato < dato) {
        if(nodo->der == nullptr) {
            nodo->der = new NodoBST(dato,ip);
            return;
        }
        insertar(dato,nodo->der,ip);
    }
}

void ArbolNum::imprimirMaximos(int n) {
    imprimirMaximos(n,raiz);
}

void ArbolNum::imprimirMaximos(int& n,NodoBST* nodo) {
    if(nodo == nullptr || n <= 0) return;

    imprimirMaximos(n,nodo->der);
    for(size_t i{0}; i < nodo->ips.size() && n > 0; i++) {
        std::cout << nodo->ips[i] << " " << nodo->dato << std::endl;
        n--;
    }
    imprimirMaximos(n,nodo->izq);
}

void ArbolNum::imprimirPorNivel() {
    std::queue<NodoBST*> niveles;
    niveles.push(raiz);
    while(!niveles.empty()) {
        NodoBST* temp = niveles.front();
        std::cout << temp->dato << " ";
        niveles.pop();
        if(temp->izq != nullptr) niveles.push(temp->izq);
        if(temp->der != nullptr) niveles.push(temp->der);
    }
    std::cout << std::endl;
}