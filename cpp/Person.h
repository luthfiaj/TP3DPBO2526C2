#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string Nama;
    int Umur;

    Person(string Nama, int Umur) {
        this->Nama = Nama;
        this->Umur = Umur;
    }

    Person() {
    }

    void setNama(string Nama) {
        this->Nama = Nama;
    }

    string getNama() {
        return Nama;
    }

    void setUmur(int Umur) {
        this->Umur = Umur;
    }

    int getUmur() {
        return Umur;
    }

    virtual void Tampilkan() {
        cout << "Nama    : " << Nama;
        cout << ", Umur    : " << Umur << endl;
    }
};

#endif