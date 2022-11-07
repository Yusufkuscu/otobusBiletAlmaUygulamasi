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
		sehir1 = "�STANBUL-ANKARA";
		sehir2 = "ANKARA-�ANKIRI";
		sehir3 = "�STANBUL-�ANKIRI";
		mesage = "Ho�geldiniz.";
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
		cout << "<<< �cret Listesi >>>" << endl;
		cout << "�STANBUL-ANKARA: " << ucretBilgi.istank << " TL" << endl;
		cout << "ANKARA-�ANKIRI: " << ucretBilgi.ankcank << " TL" << endl;
		cout << "�STANBUL-�ANKIRI: " << ucretBilgi.istcank << " TL" << endl;
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
		cout << "Toplam Bilet Say�s� : " << toplamBiletSayisi << endl;
		int bosBiletSayisi = toplamBiletSayisi - biletSayisi;
		cout << "Dolu Bilet Say�s� : " << biletSayisi << endl;
		cout << "Bo� Bilet Say�s� : " << bosBiletSayisi << endl;
	};


	void biletRezerveEt(int koltukNo, string adSoyad) {
		if (koltukNo <= toplamBiletSayisi) {
			if (bilet[koltukNo - 1] == "") {
				bilet[koltukNo - 1] = adSoyad;
				biletArtir();
			}
			else {
				cout << "Bu bilet daha �nce sat�lm��t�r." << endl;
			}
		}
		else {
			cout << toplamBiletSayisi << " koltuk bulunmaktad�r" << endl;;
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

	string slgn = "En �ok kullan�lan bilet uygulamas�!";
	slogan(slgn);
	cout << endl;
	Sehir sehir("1)�stanbul-Ankara", "2)Ankara-�ank�r�", "3)�stanbul-�ank�r�", "Sefere 2 g�n kala biletinizi iptal ettirebilirsiniz");


	UcretTarih ucret(300, 120, 400, "Pazartesi");
	ucret.showInfos(sehir);
	mesaj(sehir);
	cout << endl << endl;
	Yazdir2::showInf(ucret);

	cout << endl << endl;


	int sefer;
	cout << "Sefer Se�iniz: ";
	cin >> sefer;

	string day;
	cout << "G�n Giriniz : ";
	cin >> day;


	int kapasite = 5;
	Kullanici kullan�c�(kapasite);
	cout << endl;
	cout << "Bilet Durumlar� " << endl;
	kullan�c�.biletRezerveEt(1, "DOLU");

	kullan�c�.biletListele();
	kullan�c�.koltukSay();

	cout << endl;
	int koltukSec;
	cout << "Koltuk Se�iniz : ";
	cin >> koltukSec;
	string isimGir;
	cout << "�sim Giriniz: ";
	cin >> isimGir;

	kullan�c�.biletRezerveEt(koltukSec, isimGir);

	cout << endl << endl;


	if (koltukSec < 6 && koltukSec != 1) {

		cout << "<<< Bilet Bilgileri >>>" << endl;

		switch (sefer)
		{
			setlocale(LC_ALL, "Turkish");
		case 1:
			cout << "�sim : " << isimGir << "\nKoltuk No : " << koltukSec << "\nSefer : �stanbul-Ankara " << "\nG�n : " << day << "\nSAAT : 09:00" << "\nFiyat : 300 TL";
			break;
		case 2:
			cout << "�sim : " << isimGir << "\nKoltuk No : " << koltukSec << "\nSefer : Ankara-�ank�r� " << "\nG�n : " << day << "\nSAAT : 21:00" << "\nFiyat : 120 TL";
			break;
		case 3:
			cout << "�sim : " << isimGir << "\nKoltuk No : " << koltukSec << "\nSefer : �stanbul-�ank�r� " << "\nG�n : " << day << "\nSAAT : 10:00" << "\nFiyat : 400 TL";
			break;
		default:
			break;
		}

	}

	return 0;
}