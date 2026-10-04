#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Team.h"
#include <vector>

class Tournament {
private:
    string NamaTurnamen;
    string Lokasi;
    vector<Team> ListTeam;

public:

    Tournament(
        string NamaTurnamen,
        string Lokasi
    ) {

        this->NamaTurnamen = NamaTurnamen;
        this->Lokasi = Lokasi;
    }

    Tournament() {
    }

    string getNamaTurnamen() {
        return NamaTurnamen;
    }

    void setNamaTurnamen(string NamaTurnamen) {
        this->NamaTurnamen = NamaTurnamen;
    }

    string getLokasi() {
        return Lokasi;
    }

    void setLokasi(string Lokasi) {
        this->Lokasi = Lokasi;
    }

    void TambahTeam(Team team) {
        ListTeam.push_back(team);
    }

    Team& getTeam(int index) {
        return ListTeam[index];
    }

    void Tampilkan() {

        cout << "Nama Turnamen   : "
             << NamaTurnamen << endl;

        cout << "Lokasi          : "
             << Lokasi << endl;

        cout << "Daftar Tim:" << endl;

        int i = 1;

        for (Team& team : ListTeam) {

            cout << "\n========================="
                 << endl;

            cout << "       Tim: "
                 << i << endl;

            team.TampilkanTim();

            cout << "========================="
                 << endl;

            i++;
        }
    }
};

#endif