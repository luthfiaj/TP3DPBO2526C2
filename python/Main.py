from Tournament import Tournament
from Team import Team
from Pelatih import Pelatih
from Pemain import Pemain


tournament = Tournament(
    "Cosion Volleyball 2026",
    "Lapangan C FPMIPA"
)


# ============================================
# TIM 1
# ============================================

pelatih1 = Pelatih(
    "Luthfi Aulia Jodi Ukai",
    42,
    "Level 999"
)

team1 = Team(
    "ByteForce",
    pelatih1
)

team1.TambahPemain(
    Pemain("Bintang", 19, 7, "Quicker, Trapper, Libero")
)

team1.TambahPemain(
    Pemain("Wingko", 19, 10, "Setter")
)

team1.TambahPemain(
    Pemain("Daffa", 25, 9, "Middle Blocker")
)

team1.TambahPemain(
    Pemain("Yusuf", 20, 3, "Outside Hitter")
)

team1.TambahPemain(
    Pemain("Faiz", 20, 1, "Outside Hitter")
)

team1.TambahPemain(
    Pemain("Juan", 40, 21, "Penglaris")
)

tournament.TambahTeam(team1)


# ============================================
# TIM 2
# ============================================

pelatih2 = Pelatih(
    "Subhan",
    21,
    "Level -99"
)

team2 = Team(
    "BPKB",
    pelatih2
)

team2.TambahPemain(
    Pemain("Rafi", 20, 3, "Setter")
)

team2.TambahPemain(
    Pemain("Ute", 22, 12, "Middle Blocker")
)

tournament.TambahTeam(team2)


# ============================================
# TIM 3
# ============================================

pelatih3 = Pelatih(
    "Julian",
    23,
    "Level 2"
)

team3 = Team(
    "STNK",
    pelatih3
)

team3.TambahPemain(
    Pemain("Samsul", 23, 5, "Quicker")
)

team3.TambahPemain(
    Pemain("Bayu", 23, 8, "ACE")
)

tournament.TambahTeam(team3)


# ============================================
# TIM 4
# ============================================

pelatih4 = Pelatih(
    "Irfan",
    24,
    "Level 5"
)

team4 = Team(
    "All Star",
    pelatih4
)

team4.TambahPemain(
    Pemain("Alghi", 25, 11, "Setter")
)

team4.TambahPemain(
    Pemain("Edwin", 40, 4, "Middle Blocker")
)

tournament.TambahTeam(team4)


# ============================================
# TIM 5
# ============================================

pelatih5 = Pelatih(
    "Rudi Hartono",
    47,
    "Level 3"
)

team5 = Team(
    "Cimahi Warriors",
    pelatih5
)

team5.TambahPemain(
    Pemain("Bagas", 20, 9, "Opposite")
)

team5.TambahPemain(
    Pemain("Fikri", 19, 6, "Libero")
)

tournament.TambahTeam(team5)


# ============================================
# MENU
# ============================================

while True:

    print("\n============================================")
    print("           Cosion Volleyball 2026")
    print("============================================")
    print("1. Tambah Tim")
    print("2. Tampilkan Semua Tim")
    print("3. Tambah Pemain")
    print("4. Keluar")
    print("============================================")

    Pilihan = int(input("Mau Pilih Apa: "))


    # ========================================
    # TAMBAH TIM
    # ========================================

    if Pilihan == 1:

        print("\n=========== Tambah Tim ===========")

        NamaTim = input("Nama Tim        : ")
        namaPelatih = input("Nama Pelatih    : ")
        umurPelatih = int(input("Umur Pelatih    : "))
        lisensi = input("Lisensi          : ")

        pelatih = Pelatih(
            namaPelatih,
            umurPelatih,
            lisensi
        )

        team = Team(
            NamaTim,
            pelatih
        )

        tournament.TambahTeam(team)

        print("\nTim Berhasil Ditambahkan!")


    # ========================================
    # TAMPILKAN SEMUA TIM
    # ========================================

    elif Pilihan == 2:

        print("\n=========== Data Tim ===========")

        tournament.Tampilkan()


    # ========================================
    # TAMBAH PEMAIN
    # ========================================

    elif Pilihan == 3:

        print("\n========== TAMBAH PEMAIN ==========")

        tournament.Tampilkan()

        NomorTim = int(
            input("\nPilih nomor tim: ")
        )

        NamaPemain = input(
            "Nama Pemain       : "
        )

        UmurPemain = int(
            input("Umur Pemain       : ")
        )

        NomorPunggung = int(
            input("Nomor Punggung    : ")
        )

        Posisi = input(
            "Posisi            : "
        )

        pemain = Pemain(
            NamaPemain,
            UmurPemain,
            NomorPunggung,
            Posisi
        )

        teamDipilih = tournament.getTeam(
            NomorTim - 1
        )

        teamDipilih.TambahPemain(pemain)

        print(
            "\nPemain berhasil ditambahkan ke tim!"
        )


    # ========================================
    # KELUAR
    # ========================================

    elif Pilihan == 4:

        print(
            "\nSampai Jumpa Di Cosion Volleyball 2026"
        )

        break


    # ========================================
    # PILIHAN SALAH
    # ========================================

    else:

        print(
            "\nGa ada nomor segitu!!!!"
        )