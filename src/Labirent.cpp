#include "Labirent.hpp"

// Haritayý dosyadan okur ve baþlangýç deðerlerini atar
Labirent::Labirent(Konum baslangic, Konum bitis){
	FILE* fp = fopen("Harita.txt", "r");
	unsigned char karakter = 0;
	int satir=0, sutun=0;
	x = baslangic.x;
	y = baslangic.y;
	this->bitis = bitis;
	yon = ASAGI;
	yigit = new Stack<Konum>(); // Hareket geçmiþi için yýðýt oluþturulur
	yigit->push(Konum(-1,-1,yon)); // Stack’in boþ olduðunu anlamak için iþaret 
	                               //Geri dönüþün duracaðý noktayý belirler
    
	while (!feof(fp)) { // Dosya sonuna kadar oku
	   karakter = getc(fp);
	   if(karakter == 255) break;
	   if(karakter == 10){ // Satýr sonu karakteri boþluk gelirse
		 satir++;
		 sutun=0;
	   }
	   else{
			harita[satir][sutun] = karakter; // Karakteri matrise yerleþtir
			sutun++;
	   }
	}
	fclose(fp);
}

// Mevcut konumu paket olarak döndürür
Konum Labirent::mevcutKonum(){
	return Konum(x,y,yon);
}

// Yol boþsa adým atar ve gelinen konumu yýðýta kaydeder
bool Labirent::adimAt(Konum mevcut, Konum ileri){
	if(!EngelVarmi(ileri)){
		yigit->push(mevcut); // Çýkmaz sokak ihtimaline karþý mevcut yeri kaydet
		ayarla(ileri, ileri.yon);
		return true;
	}
	return false;
}

// Koordinatlarý günceller, iz býrakýr ve haritayý ekrana çizer
void Labirent::ayarla(Konum konum, Yon yon){
	system("cls"); // Ekraný temizle
	this->x = konum.x;
	this->y = konum.y;
	this->yon = yon;
	harita[konum.x][konum.y] = '-'; // Geçilen yerleri iþaretle
	cout<<yaz();
	Sleep(30); // Animasyon için bekle
}

// Mevcut koordinatlar bitiþ noktasý mý kontrol eder
bool Labirent::CikisaGeldimi(){
	return x == bitis.x && y == bitis.y;
}

// Gidilmek istenen yer sýnýr dýþý, duvar veya geçilmiþ yol mu
bool Labirent::EngelVarmi(Konum konum){			
	if(konum.x >= YUKSEKLIK || konum.x < 0 || 
	   konum.y >= GENISLIK || konum.y < 0)
		return true; // Harita dýþý engeldir

	return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';
}

// Haritayý string formatýnda hazýrlar
string Labirent::yaz(){
	char YonChr[] = {'v', '<', '^', '>'}; 
	stringstream ss;
	for(int satir=0; satir<YUKSEKLIK; satir++){
		ss<<setw(10);
		for(int sutun=0; sutun<GENISLIK; sutun++){
			if(satir == x && sutun == y) ss<<YonChr[yon]; // Karakterin yeri
			else{
				 if(harita[satir][sutun] == '-') ss<<' '; // Ýzleri boþluk göster
				 else ss<<harita[satir][sutun]; // Duvarlarý göster
			}
		}	
		ss<<endl;				
	}
	return ss.str();
}
