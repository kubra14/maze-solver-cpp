#include "Labirent.hpp"

int main(){
    // Labirenti baþlat
	Labirent *labirent = new Labirent(Konum(0,20),Konum(18,11));
	
    // Ýlk konumu yýðýta ekle ve ilk adýmý atarak baþla
	labirent->yigit->push(Konum(labirent->x,labirent->y,ASAGI));
	labirent->ayarla(Konum(labirent->x,labirent->y,ASAGI).Asagi(),ASAGI);	

	while(!labirent->CikisaGeldimi()){ // Çýkýþa ulaþana kadar dön
		int denemeYonSayisi=1;
		Konum oncekiKonum = labirent->yigit->top(); // Çýkmaz sokak olursa dönülecek yer
		Konum mevcutKonum = labirent->mevcutKonum();
		
		Konum ileri = mevcutKonum.AyniYon(); // Önce baktýðýn yöne gitmeyi dene
		
		// Eðer ileri gidemezsen farklý yönleri dene
		if(!labirent->adimAt(mevcutKonum,ileri)){
			int i=0;
			bool sonuc = false;
			Konum yeni = mevcutKonum;

			// 4 yönü de deneyene kadar dön
			while(!sonuc && denemeYonSayisi<5){	
				yeni = mevcutKonum.SaatYonu((Yon)((mevcutKonum.yon+i)%4));		
								
				i++;
				denemeYonSayisi++;

				// Geldiðin yöne hemen geri dönmeyi engelle
				if(yeni.yon == mevcutKonum.TersYon()){
					sonuc=false;
				}
				else{
					sonuc = labirent->adimAt(mevcutKonum,yeni);
				}
			}

			// Eðer hiçbir yöne gidemezse
			if(denemeYonSayisi == 5){
				labirent->yigit->pop(); // Yýðýttan son konumu çýkar 
				labirent->ayarla(oncekiKonum,oncekiKonum.TersYon());
			}
		}
	}
	
	cout<<"CIKISA GELDI"<<endl;
	
	getchar(); // Ekranýn hemen kapanmasýný önlemek için bir tuþ bekle
	
	delete labirent; // Belleði temizle
	return 0;
}

