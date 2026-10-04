#ifndef PELATIH_H
#define PELATIH_H

#include "Person.h"

class Pelatih : public Person {
private:
    string Lisensi;

public:
    Pelatih(
        string Nama,
        int Umur,
        string Lisensi
    ) : Person(Nama, Umur) {

        this->Lisensi = Lisensi;
    }

    Pelatih() {
    }

    string getLisensi() {
        return Lisensi;
    }

    void setLisensi(string Lisensi) {
        this->Lisensi = Lisensi;
    }

    void Tampilkan() override {
        cout << "Nama            : " << getNama() << endl;
        cout << "Umur            : " << getUmur() << endl;
        cout << "Lisensi         : " << Lisensi << endl;
    }
};

#endif