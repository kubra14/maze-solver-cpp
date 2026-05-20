#ifndef LABIRENT_HPP 
#define LABIRENT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdio>
#include <windows.h> // Sleep ve system("cls") için gerekli

using namespace std;

#include "Konum.hpp"
#include "Stack.hpp"

#define YUKSEKLIK 20 
#define GENISLIK 50  

class Labirent{
public:
    char harita[YUKSEKLIK][GENISLIK]; // Labirentin görsel yapýsý
    int x, y;        
    Yon yon;         
    Konum bitis;     // Hedef koordinat
    Stack<Konum>* yigit; // Gidilen yollarý tutan yýðýt Backtracking için

    Labirent(Konum, Konum);   
    Konum mevcutKonum();      
    bool adimAt(Konum, Konum);
    void ayarla(Konum, Yon);  
    bool CikisaGeldimi();     
    bool EngelVarmi(Konum);   
    string yaz();             
};

#endif

