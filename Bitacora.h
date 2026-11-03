// Carlos Francisco Sanchez Llanes A01741201
// Santiago Guillen Cebreros A01742859
// Mauro Solorzano Ortiz A01642569
// Act 3.4 - Actividad Integral de BST 
// 3/11/2026
#pragma once
#include <string>
#include <vector>

class Bitacora {
    private :
        int dia,mesNum,segAño;
        std::string mes, razon, tiempo, ip;
        std::vector<int> ipSeparado;
        std::vector<int> separarIp(std::string);
    public :
        Bitacora() = default;
        Bitacora(std::string,int,std::string,std::string,std::string);
        std::string getInfo() const;
        std::string getMes()const;
        int mesANumero() const;
        int getMesNum() const;
        int getSegundos() const;
        int getSegAño() const;
        std::string getIpSinPuerto() const;
        bool mismaIp(const Bitacora&) const;
        bool operator<(const Bitacora&) const;
};