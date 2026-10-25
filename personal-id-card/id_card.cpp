// =====================================================================
//  Proje      : Konsol Tanıtım Kartı
//  Hazırlayan : Burak Yiğit Solmaz
//  Okul       : Ankara Üniversitesi - Bilgisayar Programcılığı (2. Sınıf)
//  Not        : Program for döngüsü ve if yapıları kullanılarak yazılmıştır.
// =====================================================================

#include <iostream>
#include <string>
#include <cctype>
#ifdef _WIN32
#include <windows.h>   // Windows'ta Türkçe karakterler için
#endif

using namespace std;

// ---------- Bilgilerim ----------
const string AD_SOYAD = "Burak Yiğit Solmaz";
const string OKUL     = "Ankara Üniversitesi";
const string BOLUM    = "Bilgisayar Programcılığı";
const int    SINIF    = 2;
const int    YAS      = 19;

const int TOPLAM_SAYISI = 12;
const string yetenekler[TOPLAM_SAYISI] = {
    "C", "C++", "HTML", "CSS", "JavaScript", "SQL", "MySQL", "PHP",
    "Unity", "Blender", "Visual Studio Code", "Git"
};


// ---------- Yardımcı fonksiyonlar ----------

void cizgiCiz(int uzunluk = 50, char karakter = '=') {
    for (int i = 0; i < uzunluk; i++) {
        cout << karakter;
    }
    cout << endl;
}

void baslikYaz(const string& baslik) {
    cout << endl;
    cizgiCiz();
    cout << "  " << baslik << endl;
    cizgiCiz();
}

// Yazıyı küçük harfe çevirir (arama yaparken büyük/küçük harf fark etmesin diye)
string kucukHarf(string yazi) {
    for (size_t i = 0; i < yazi.length(); i++) {
        yazi[i] = tolower(yazi[i]);
    }
    return yazi;
}

// Dilin hangi alana ait olduğunu söyler
string kategori(const string& dil) {
    if (dil == "HTML" || dil == "CSS" || dil == "JavaScript" || dil == "PHP") {
        return "Web geliştirme";
    } else if (dil == "SQL" || dil == "MySQL") {
        return "Veritabanı";
    } else if (dil == "Unity" || dil == "Blender" || dil == "Visual Studio Code" || dil == "Git") {
        return "Araç / Yazılım";
    } else {
        return "Genel amaçlı programlama";
    }
}


// ---------- Menü seçenekleri ----------

void kisiselBilgiler() {
    baslikYaz("KİŞİSEL BİLGİLER");
    cout << "Ad Soyad : " << AD_SOYAD << endl;
    cout << "Yaş      : " << YAS << endl;
    cout << "Okul     : " << OKUL << endl;
    cout << "Bölüm    : " << BOLUM << endl;
    cout << "Sınıf    : " << SINIF << ". sınıf" << endl;

    if (SINIF == 1) {
        cout << "\nDurum    : Eğitimin ilk yılındayım." << endl;
    } else if (SINIF == 2) {
        cout << "\nDurum    : Eğitimin ikinci yılındayım, öğrenmeye devam ediyorum." << endl;
    } else {
        cout << "\nDurum    : İleri seviye öğrenci." << endl;
    }
}

void bildigimDiller() {
    baslikYaz("BİLDİĞİM DİLLER VE ARAÇLAR");

    int webSayisi = 0;
    int veritabaniSayisi = 0;
    int genelSayisi = 0;
    int aracSayisi = 0;

    for (int i = 0; i < TOPLAM_SAYISI; i++) {
        string tur = kategori(yetenekler[i]);
        cout << (i + 1) << ") " << yetenekler[i] << "  ->  " << tur << endl;

        if (tur == "Web geliştirme") {
            webSayisi++;
        } else if (tur == "Veritabanı") {
            veritabaniSayisi++;
        } else if (tur == "Araç / Yazılım") {
            aracSayisi++;
        } else {
            genelSayisi++;
        }
    }

    int dilSayisi = genelSayisi + webSayisi + veritabaniSayisi;

    cout << endl;
    cizgiCiz(50, '-');
    cout << "Toplam " << dilSayisi << " dil ve " << aracSayisi << " araç kullanıyorum:" << endl;
    cout << "  Genel amaçlı programlama : " << genelSayisi << endl;
    cout << "  Web geliştirme           : " << webSayisi << endl;
    cout << "  Veritabanı               : " << veritabaniSayisi << endl;
    cout << "  Araç / Yazılım           : " << aracSayisi << endl;
}

void dilSorgula() {
    baslikYaz("DİL / ARAÇ SORGULA");
    cout << "Bir dil veya araç adı yaz (örn: php, js, git, vscode): ";

    string aranan;
    cin >> aranan;
    aranan = kucukHarf(aranan);

    // Kısaltma desteği
    if (aranan == "js") {
        aranan = "javascript";
    } else if (aranan == "vscode" || aranan == "vs") {
        aranan = "visual studio code";
    }

    bool bulundu = false;

    for (int i = 0; i < TOPLAM_SAYISI; i++) {
        if (kucukHarf(yetenekler[i]) == aranan) {
            if (kategori(yetenekler[i]) == "Araç / Yazılım") {
                cout << "\nEvet! " << yetenekler[i] << " kullanıyorum. ("
                     << kategori(yetenekler[i]) << ")" << endl;
            } else {
                cout << "\nEvet! " << yetenekler[i] << " biliyorum. ("
                     << kategori(yetenekler[i]) << ")" << endl;
            }
            bulundu = true;
            break;
        }
    }

    if (bulundu == false) {
        cout << "\nBunu henüz bilmiyorum ama öğrenmeye açığım!" << endl;
    }
}

void menuYazdir() {
    baslikYaz("TANITIM KARTI - MENÜ");
    cout << "1 - Kişisel bilgiler" << endl;
    cout << "2 - Bildiğim diller ve araçlar" << endl;
    cout << "3 - Dil / araç sorgula" << endl;
    cout << "4 - Hepsini göster" << endl;
    cout << "0 - Çıkış" << endl;
    cizgiCiz(50, '-');
}


// ---------- Ana program ----------

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    cout << "Merhaba! Ben " << AD_SOYAD << "." << endl;
    cout << OKUL << " " << BOLUM << " " << SINIF
         << ". sınıf öğrencisiyim." << endl;

    // for(;;) sonsuz döngü: kullanıcı 0 yazana kadar menü tekrar gösterilir
    for (;;) {
        menuYazdir();

        int secim;
        cout << "Seçimin: ";
        cin >> secim;

        // Harf girilirse programın çökmesini engelle
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Lütfen bir sayı gir!" << endl;
            continue;
        }

        if (secim == 1) {
            kisiselBilgiler();
        } else if (secim == 2) {
            bildigimDiller();
        } else if (secim == 3) {
            dilSorgula();
        } else if (secim == 4) {
            kisiselBilgiler();
            bildigimDiller();
        } else if (secim == 0) {
            cout << "\nGörüşürüz!" << endl;
            break;
        } else {
            cout << "Geçersiz seçim, 0-4 arası bir sayı gir." << endl;
        }
    }

    return 0;
}