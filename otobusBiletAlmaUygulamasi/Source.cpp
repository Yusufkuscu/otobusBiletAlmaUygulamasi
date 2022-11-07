#include <iostream>
#include <string>,
using namespace std;

void slogan(string& slogan) {
	cout << slogan << endl;
}


class Sehir {

private:
	string sehir1;
	string sehir2;
	string sehir3;
	string mesage;

public:
	Sehir() {
		sehir1 = "ÝSTANBUL-ANKARA";
		sehir2 = "ANKARA-ÇANKIRI";
		sehir3 = "ÝSTANBUL-ÇANKIRI";
		mesage = "Hoþgeldiniz.";
	}

	Sehir(string sehir1, string sehir2, string sehir3, string mesage) {
		this->sehir1 = sehir1;
		this->sehir2 = sehir2;
		this->sehir3 = sehir3;
		this->mesage = mesage;
	}
	~Sehir() {
		cout << " " << endl;
	}

	friend void mesaj(Sehir mesaj);
	friend class Yazdir;
};


void mesaj(Sehir mesaj) {
	cout << mesaj.mesage << endl;
}


class Yazdir {
public:
	static void showInfos(Sehir sehirbilgi) {
		cout << "<<< Seferlerimiz >>>" << endl;
		cout << sehirbilgi.sehir1 << endl;
		cout << sehirbilgi.sehir2 << endl;
		cout << sehirbilgi.sehir3;

	}

};


class UcretTarih : public Yazdir {
private:
	int istank;
	int ankcank;
	int istcank;
	string gun;



public:
	UcretTarih(int istank, int ankcank, int istcank, string gun) {
		this->istank = istank;
		this->ankcank = ankcank;
		this->istcank = istcank;
		this->gun = gun;
	}

	friend class Yazdir2;

};


class Yazdir2 {
public:
	static void showInf(UcretTarih ucretBilgi) {
		cout << "<<< Ücret Listesi >>>" << endl;
		cout << "ÝSTANBUL-ANKARA: " << ucretBilgi.istank << " TL" << endl;
		cout << "ANKARA-ÇANKIRI: " << ucretBilgi.ankcank << " TL" << endl;
		cout << "ÝSTANBUL-ÇANKIRI: " << ucretBilgi.istcank << " TL" << endl;
	}

};


class Kullanici {
private:
	int toplamBiletSayisi;

public:
	int biletSayisi;
	string* bilet;

	Kullanici(int toplamBiletSayisi) {
		this->toplamBiletSayisi = toplamBiletSayisi;
		biletSayisi = 0;
		bilet = new string[toplamBiletSayisi];
		for (int i = 0; i < toplamBiletSayisi; i++) {
			bilet[i] = "";
		}
	}

	void biletArtir() {
		biletSayisi++;
	}

	void koltukSay() {
		cout << "Toplam Bilet Sayýsý : " << toplamBiletSayisi << endl;
		int bosBiletSayisi = toplamBiletSayisi - biletSayisi;
		cout << "Dolu Bilet Sayýsý : " << biletSayisi << endl;
		cout << "Boþ Bilet Sayýsý : " << bosBiletSayisi << endl;
	};


	void biletRezerveEt(int koltukNo, string adSoyad) {
		if (koltukNo <= toplamBiletSayisi) {
			if (bilet[koltukNo - 1] == "") {
				bilet[koltukNo - 1] = adSoyad;
				biletArtir();
			}
			else {
				cout << "Bu bilet daha önce satýlmýþtýr." << endl;
			}
		}
		else {
			cout << toplamBiletSayisi << " koltuk bulunmaktadýr" << endl;;
		}

	}

	void biletListele() {
		for (int i = 0; i < toplamBiletSayisi; i++) {
			cout << i + 1 << ". koltuk : " << bilet[i] << endl;
		}
	}

};


int main() {

	setlocale(LC_ALL, "Turkish");

	string slgn = "En çok kullanýlan bilet uygulamasý!";
	slogan(slgn);
	cout << endl;
	Sehir sehir("1)Ýstanbul-Ankara", "2)Ankara-Çankýrý", "3)Ýstanbul-Çankýrý", "Sefere 2 gün kala biletinizi iptal ettirebilirsiniz");


	UcretTarih ucret(300, 120, 400, "Pazartesi");
	ucret.showInfos(sehir);
	mesaj(sehir);
	cout << endl << endl;
	Yazdir2::showInf(ucret);

	cout << endl << endl;


	int sefer;
	cout << "Sefer Seçiniz: ";
	cin >> sefer;

	string day;
	cout << "Gün Giriniz : ";
	cin >> day;


	int kapasite = 5;
	Kullanici kullanýcý(kapasite);
	cout << endl;
	cout << "Bilet Durumlarý " << endl;
	kullanýcý.biletRezerveEt(1, "DOLU");

	kullanýcý.biletListele();
	kullanýcý.koltukSay();

	cout << endl;
	int koltukSec;
	cout << "Koltuk Seçiniz : ";
	cin >> koltukSec;
	string isimGir;
	cout << "Ýsim Giriniz: ";
	cin >> isimGir;

	kullanýcý.biletRezerveEt(koltukSec, isimGir);

	cout << endl << endl;


	if (koltukSec < 6 && koltukSec != 1) {

		cout << "<<< Bilet Bilgileri >>>" << endl;

		switch (sefer)
		{
			setlocale(LC_ALL, "Turkish");
		case 1:
			cout << "Ýsim : " << isimGir << "\nKoltuk No : " << koltukSec << "\nSefer : Ýstanbul-Ankara " << "\nGün : " << day << "\nSAAT : 09:00" << "\nFiyat : 300 TL";
			break;
		case 2:
			cout << "Ýsim : " << isimGir << "\nKoltuk No : " << koltukSec << "\nSefer : Ankara-Çankýrý " << "\nGün : " << day << "\nSAAT : 21:00" << "\nFiyat : 120 TL";
			break;
		case 3:
			cout << "Ýsim : " << isimGir << "\nKoltuk No : " << koltukSec << "\nSefer : Ýstanbul-Çankýrý " << "\nGün : " << day << "\nSAAT : 10:00" << "\nFiyat : 400 TL";
			break;
		default:
			break;
		}

	}

	return 0;
}