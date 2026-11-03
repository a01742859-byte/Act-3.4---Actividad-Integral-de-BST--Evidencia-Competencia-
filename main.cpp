// Carlos Francisco Sanchez Llanes A01741201
// Santiago Guillen Cebreros A01742859
// Mauro Solorzano Ortiz A01642569
// Act 3.4 - Actividad Integral de BST 
// 3/11/2026
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Bitacora.h"
#include "ArbolBST.h"


int main() {
    std::vector<Bitacora*> bitacora;
    std::ifstream archivo{"bitacora2.txt"};
    if(!archivo.is_open()) std::cerr << "Archivo no abre" << std::endl;
    int dia;
    std::string mes,tiempo,ip,razon;
    while(archivo >> mes >> dia >> tiempo >> ip) {
        archivo.ignore();
        std::getline(archivo,razon);
        bitacora.push_back(new Bitacora(mes,dia,tiempo,ip,razon));
    }

    std::ofstream archivOrd("bitacoraOrdenadaIP-Eq4-BST.txt");

    for(size_t i{0}; i < bitacora.size(); i++) {
        for(size_t j{0}; j + 1 < bitacora.size() - i; j++) {
            if(*bitacora[j + 1] < *bitacora[j]) {
                std::swap(bitacora[j], bitacora[j + 1]);
            }
        }
    }

    for(size_t i{0}; i < bitacora.size(); i++) {
        archivOrd << bitacora[i]->getInfo() << std::endl;
    }

    archivOrd.close();

    const int NumerodeIps = 5;   

    ArbolNum arbol;
    if(!bitacora.empty()) {
        int contador = 1;   

        for(size_t i = 1; i < bitacora.size(); i++) {
            if(bitacora[i]->mismaIp(*bitacora[i - 1])) {
                contador++;                  
            } else {
                arbol.insertar(contador, bitacora[i - 1]->getIpSinPuerto());
                contador = 1;                
            }
        }
    }
    

    arbol.imprimirMaximos(NumerodeIps);
    arbol.imprimirPorNivel();


    for(size_t i = 0; i < bitacora.size(); i++) {
        delete bitacora[i];
    }


    return 0;
}

