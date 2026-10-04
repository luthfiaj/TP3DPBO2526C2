#ifndef TEAM_H
#define TEAM_H

#include "Pelatih.h"
#include "Pemain.h"
#include <vector>

class Team {
private:
    string NamaTim;
    Pelatih Coach;
    vector<Pemain> ListPemain;

public:

    Team(
        string NamaTim,
        Pelatih Coach
    ) : NamaTim(NamaTim), Coach(Coach) {
    }

    Team() {
    }

    string getNamaTim() {
        return NamaTim;
    }

    void setNamaTim(string NamaTim) {
        this->NamaTim = NamaTim;
    }

    Pelatih getCoach() {
        return Coach;
    }

    void setCoach(Pelatih Coach) {
        this->Coach = Coach;
    }

    void TambahPemain(Pemain pemain) {
        ListPemain.push_back(pemain);
    }

    void TampilkanTim() {

        cout << "Nama Tim    : " << getNamaTim() << endl;

        Coach.Tampilkan();

        cout << "Daftar Pemain   :" << endl;

        int i = 1;

        for (Pemain pemain : ListPemain) {

            cout << "--------------------" << endl;
            cout << "       Pemain " << i << endl;

            pemain.Tampilkan();

            cout << "--------------------" << endl;

            i++;
        }
    }
};

#endif