#ifndef PEMAIN_H
#define PEMAIN_H

#include "Person.h"

class Pemain : public Person {
private:
    int NomorPunggung;
    string Posisi;

public:
    Pemain(
        string Nama,
        int Umur,
        int NomorPunggung,
        string Posisi
    ) : Person(Nama, Umur) {

        this->NomorPunggung = NomorPunggung;
        this->Posisi = Posisi;
    }

    Pemain() {
    }

    int getNomorPunggung() {
        return NomorPunggung;
    }

    void setNomorPunggung(int NomorPunggung) {
        this->NomorPunggung = NomorPunggung;
    }

    string getPosisi() {
        return Posisi;
    }

    void setPosisi(string Posisi) {
        this->Posisi = Posisi;
    }

    void Tampilkan() override {
        cout << "Nama            : " << getNama() << endl;
        cout << "Umur            : " << getUmur() << endl;
        cout << "Nomor Punggung  : " << NomorPunggung << endl;
        cout << "Posisi          : " << Posisi << endl;
    }
};

#endif