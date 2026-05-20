#include "Konum.hpp"

// Koordinat ve yönü set eder
Konum::Konum(int x,int y, Yon yon){
	this->x = x;
	this->y = y;
	this->yon = yon;
}

// Varsayýlan yönü asaði olarak ayarlayan yapýcý metot
Konum::Konum(int x,int y){
	this->x = x;
	this->y = y;
	this->yon = ASAGI;
}

// Baþlangýç noktasý (0,0)
Konum::Konum(){
	x=0; y=0; yon=ASAGI;
}

// Mevcut yöne göre hareket fonksiyonunu çaðýrýr
Konum Konum::AyniYon(){
	switch(yon){
		case YUKARI: return Yukari();
		case SAG:    return Sag();
		case ASAGI:  return Asagi();
		default:     return Sol();
	}
}

Konum Konum::SaatYonu(Yon yn){
	switch(yn){
		case YUKARI: return Sag();
		case SAG:    return Asagi();
		case ASAGI:  return Sol();
		default:     return Yukari();
	}
}

// Temel hareketler: Mevcut koordinatlarý deðiþtirmez, yeni bir Konum objesi üretir
Konum Konum::Asagi() { return Konum(x+1, y, ASAGI);  } 
Konum Konum::Yukari(){ return Konum(x-1, y, YUKARI); } 
Konum Konum::Sol()   { return Konum(x, y-1, SOL);    } 
Konum Konum::Sag()   { return Konum(x, y+1, SAG);    } 

// Mevcut yönün tam zýttýný döndürür 
Yon Konum::TersYon(){
	if(yon == ASAGI)  return YUKARI;
	if(yon == YUKARI) return ASAGI;
	if(yon == SOL)    return SAG;
	if(yon == SAG)    return SOL;
	return YUKARI;
}
