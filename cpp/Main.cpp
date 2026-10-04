#include <iostream>
#include <string>

#include "Tournament.h"
#include "Team.h"
#include "Pelatih.h"
#include "Pemain.h"

using namespace std;

int main() {

    Tournament tournament(
        "Cosion Volleyball 2026",
        "Lapangan C FPMIPA"
    );


    // ============================================
    // TIM 1
    // ============================================

    Pelatih pelatih1(
        "Luthfi Aulia Jodi Ukai",
        42,
        "Level 999"
    );

    Team team1(
        "ByteForce",
        pelatih1
    );

    team1.TambahPemain(
        Pemain(
            "Bintang",
            19,
            7,
            "Quicker, Trapper, Libero"
        )
    );

    team1.TambahPemain(
        Pemain(
            "Wingko",
            19,
            10,
            "Setter"
        )
    );

    team1.TambahPemain(
        Pemain(
            "Daffa",
            25,
            9,
            "Middle Blocker"
        )
    );

    team1.TambahPemain(
        Pemain(
            "Yusuf",
            20,
            3,
            "Outside Hitter"
        )
    );

    team1.TambahPemain(
        Pemain(
            "Faiz",
            20,
            1,
            "Outside Hitter"
        )
    );

    team1.TambahPemain(
        Pemain(
            "Juan",
            40,
            21,
            "Penglaris"
        )
    );

    tournament.TambahTeam(team1);


    // ============================================
    // TIM 2
    // ============================================

    Pelatih pelatih2(
        "Subhan",
        21,
        "Level -99"
    );

    Team team2(
        "BPKB",
        pelatih2
    );

    team2.TambahPemain(
        Pemain(
            "Rafi",
            20,
            3,
            "Setter"
        )
    );

    team2.TambahPemain(
        Pemain(
            "Ute",
            22,
            12,
            "Middle Blocker"
        )
    );

    tournament.TambahTeam(team2);


    // ============================================
    // TIM 3
    // ============================================

    Pelatih pelatih3(
        "Julian",
        23,
        "Level 2"
    );

    Team team3(
        "STNK",
        pelatih3
    );

    team3.TambahPemain(
        Pemain(
            "Samsul",
            23,
            5,
            "Quicker"
        )
    );

    team3.TambahPemain(
        Pemain(
            "Bayu",
            23,
            8,
            "ACE"
        )
    );

    tournament.TambahTeam(team3);


    // ============================================
    // TIM 4
    // ============================================

    Pelatih pelatih4(
        "Irfan",
        24,
        "Level 5"
    );

    Team team4(
        "All Star",
        pelatih4
    );

    team4.TambahPemain(
        Pemain(
            "Alghi",
            25,
            11,
            "Setter"
        )
    );

    team4.TambahPemain(
        Pemain(
            "Edwin",
            40,
            4,
            "Middle Blocker"
        )
    );

    tournament.TambahTeam(team4);


    // ============================================
    // TIM 5
    // ============================================

    Pelatih pelatih5(
        "Rudi Hartono",
        47,
        "Level 3"
    );

    Team team5(
        "Cimahi Warriors",
        pelatih5
    );

    team5.TambahPemain(
        Pemain(
            "Bagas",
            20,
            9,
            "Opposite"
        )
    );

    team5.TambahPemain(
        Pemain(
            "Fikri",
            19,
            6,
            "Libero"
        )
    );

    tournament.TambahTeam(team5);


    // ============================================
    // MENU
    // ============================================

    int Pilihan;

    do {

        cout << "\n============================================"
             << endl;

        cout << "           Cosion Volleyball 2026"
             << endl;

        cout << "============================================"
             << endl;

        cout << "1. Tambah Tim" << endl;
        cout << "2. Tampilkan Semua Tim" << endl;
        cout << "3. Tambah Pemain" << endl;
        cout << "4. Keluar" << endl;

        cout << "============================================"
             << endl;

        cout << "Mau Pilih Apa: ";
        cin >> Pilihan;

        cin.ignore();


        switch (Pilihan) {


            // ====================================
            // TAMBAH TIM
            // ====================================

            case 1: {

                cout << "\n=========== Tambah Tim ==========="
                     << endl;

                string NamaTim;
                string namaPelatih;
                int umurPelatih;
                string lisensi;

                cout << "Nama Tim        : ";
                getline(cin, NamaTim);

                cout << "Nama Pelatih    : ";
                getline(cin, namaPelatih);

                cout << "Umur Pelatih    : ";
                cin >> umurPelatih;
                cin.ignore();

                cout << "Lisensi         : ";
                getline(cin, lisensi);

                Pelatih pelatih(
                    namaPelatih,
                    umurPelatih,
                    lisensi
                );

                Team team(
                    NamaTim,
                    pelatih
                );

                tournament.TambahTeam(team);

                cout << "\nTim Berhasil Ditambahkan!"
                     << endl;

                break;
            }


            // ====================================
            // TAMPILKAN SEMUA TIM
            // ====================================

            case 2: {

                cout << "\n=========== Data Tim ==========="
                     << endl;

                tournament.Tampilkan();

                break;
            }


            // ====================================
            // TAMBAH PEMAIN
            // ====================================

            case 3: {

                cout << "\n========== TAMBAH PEMAIN =========="
                     << endl;

                tournament.Tampilkan();

                int NomorTim;

                cout << "\nPilih nomor tim: ";
                cin >> NomorTim;
                cin.ignore();

                string NamaPemain;
                int UmurPemain;
                int NomorPunggung;
                string Posisi;

                cout << "Nama Pemain       : ";
                getline(cin, NamaPemain);

                cout << "Umur Pemain       : ";
                cin >> UmurPemain;

                cout << "Nomor Punggung    : ";
                cin >> NomorPunggung;
                cin.ignore();

                cout << "Posisi            : ";
                getline(cin, Posisi);

                Pemain pemain(
                    NamaPemain,
                    UmurPemain,
                    NomorPunggung,
                    Posisi
                );

                Team& teamDipilih =
                    tournament.getTeam(NomorTim - 1);

                teamDipilih.TambahPemain(pemain);

                cout << "\nPemain berhasil "
                     << "ditambahkan ke tim!"
                     << endl;

                break;
            }


            // ====================================
            // KELUAR
            // ====================================

            case 4:

                cout << "\nSampai Jumpa Di "
                     << "Cosion Volleyball 2026"
                     << endl;

                break;


            // ====================================
            // PILIHAN SALAH
            // ====================================

            default:

                cout << "\nGa ada nomor segitu!!!!"
                     << endl;
        }

    } while (Pilihan != 4);

    return 0;
}