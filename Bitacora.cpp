// Carlos Francisco Sanchez Llanes A01741201
// Santiago Guillen Cebreros A01742859
// Mauro Solorzano Ortiz A01642569
// Act 3.4 - Actividad Integral de BST 
// 3/11/2026
#include "Bitacora.h"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <vector>

Bitacora::Bitacora(std::string mes,int dia, std::string tiempo, std::string ip , std::string razon) {
    this->mes=mes;
    this->dia=dia;
    this->tiempo=tiempo;
    this->ip=ip;
    this->razon=razon;
    mesNum = mesANumero();
    segAño = getSegundos();
    ipSeparado = separarIp(ip);
} 

std::string Bitacora::getInfo() const{
    return mes + " " + std::to_string(dia) + " " + tiempo + " " + ip + " " + razon;
}

std::string Bitacora::getMes() const{
    return mes;
}

int Bitacora::mesANumero() const {
    if (mes == "Jan") return 1;
    if (mes == "Feb") return 2;
    if (mes == "Mar") return 3;
    if (mes == "Apr") return 4;
    if (mes == "May") return 5;
    if (mes == "Jun") return 6;
    if (mes == "Jul") return 7;
    if (mes == "Aug") return 8;
    if (mes == "Sep") return 9;
    if (mes == "Oct") return 10;
    if (mes == "Nov") return 11;
    if (mes == "Dec") return 12;
    
    throw std::runtime_error("Formato de mes invalido: " + mes);
}

int Bitacora::getMesNum() const {
    return mesNum;
}

int Bitacora::getSegundos() const {
    const int diasAcumulados[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    
    int hora = std::stoi(tiempo.substr(0,2));
    int minutos = std::stoi(tiempo.substr(3,2));
    int segundos = std::stoi(tiempo.substr(6,2));

    int diasTotales = diasAcumulados[getMesNum() - 1] + dia; 

    return (diasTotales * 86400) + (hora * 3600) + (minutos * 60) + segundos;
}

int Bitacora::getSegAño() const {
    return segAño;
}

std::vector<int> Bitacora::separarIp(std::string ip) {
    std::vector<int> aux;

    for(size_t i{0}; i < ip.size(); i++) {
        if(ip[i] == '.' || ip[i] == ':') {
            ip[i] = ' ';
        }
    }
    
    std::istringstream flujo(ip);
    int numero;
    for(int i{0}; i < 5; i++) {
        flujo >> numero;
        aux.push_back(numero);
    }

    return aux;
}

bool Bitacora::operator<(const Bitacora& otro) const {
    for(int i{0}; i < 5 ; i++) {
        if(this->ipSeparado[i] == otro.ipSeparado[i]) continue;

        else if(this->ipSeparado[i] < otro.ipSeparado[i]) return true;

        else return false;
    }
    return false;
}

bool Bitacora::mismaIp(const Bitacora& otro) const {
    for(int i{0}; i < 4 ; i++) {
        if(this->ipSeparado[i] == otro.ipSeparado[i]) continue;

        else if(this->ipSeparado[i] != otro.ipSeparado[i]) return false;
    }
    return true;
}

std::string Bitacora::getIpSinPuerto() const {
    return ip.substr(0, ip.find(':'));   
}