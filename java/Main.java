import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Tournament tournament = new Tournament("Cosion Volleyball 2026", "Lapangan C FPMIPA");



        // Tim 1
        Pelatih pelatih1 =
                new Pelatih("Luthfi Aulia Jodi Ukai", 42, "Level 999");

        Team team1 =
                new Team("ByteForce", pelatih1);

        Pemain pemain1 =
                new Pemain("Bintang", 19, 7, "Quicker, Trapper, Libero");

        Pemain pemain2 =
                new Pemain("Wingko", 19, 10, "Setter");
        Pemain pemain3 =
                new Pemain("Daffa", 25, 9, "Middle Blocker");
        Pemain pemain4 =
                new Pemain("Yusuf", 20, 3, "Outside Hitter");
        Pemain pemain5 =
                new Pemain("Faiz", 20, 1, "Outside Hitter");
        Pemain pemain6 =
                new Pemain("Juan", 40, 21, "Penglaris");

        team1.TambahPemain(pemain1);
        team1.TambahPemain(pemain2);
        team1.TambahPemain(pemain3);
        team1.TambahPemain(pemain4);
        team1.TambahPemain(pemain5);
        team1.TambahPemain(pemain6);

        tournament.TambahTeam(team1);


            // Tim 2
        Pelatih pelatih2 =
        new Pelatih("Subhan", 21, "Level -99");

        Team team2 =
        new Team("BPKB", pelatih2);

        Pemain pemain7 =
        new Pemain("Rafi", 20, 3, "Setter");

        Pemain pemain8 =
        new Pemain("Ute", 22, 12, "Middle Blocker");

        team2.TambahPemain(pemain7);
        team2.TambahPemain(pemain8);

        tournament.TambahTeam(team2);


            // Tim 3
        Pelatih pelatih3 =
        new Pelatih("Julian", 23, "Level 2");

        Team team3 =
        new Team("STNK", pelatih3);

        Pemain pemain9 =
        new Pemain("Samsul", 23, 5, "Quicker");

        Pemain pemain10 =
        new Pemain("Bayu", 23, 8, "ACE");

        team3.TambahPemain(pemain9);
        team3.TambahPemain(pemain10);

        tournament.TambahTeam(team3);


            // Tim 4
        Pelatih pelatih4 =
        new Pelatih("Irfan", 24, "Level 5");

        Team team4 =
        new Team("All Star", pelatih4);

        Pemain pemain11 =
        new Pemain("Alghi", 25, 11, "Setter");

        Pemain pemain12 =
        new Pemain("Edwin", 40, 4, "Middle Blocker");

        team4.TambahPemain(pemain11);
        team4.TambahPemain(pemain12);

        tournament.TambahTeam(team4);


            // Tim 5
        Pelatih pelatih5 =
        new Pelatih("Rudi Hartono", 47, "Level 3");

        Team team5 =
        new Team("Cimahi Warriors", pelatih5);

        Pemain pemain13 =
        new Pemain("Bagas", 20, 9, "Opposite");

        Pemain pemain14 =
        new Pemain("Fikri", 19, 6, "Libero");

team5.TambahPemain(pemain13);
team5.TambahPemain(pemain14);

tournament.TambahTeam(team5);
        int Pilihan;

        do{
            System.out.println("\n============================================");
            System.out.println("           Cosion Volleyball 2026");
            System.out.println("============================================");
            System.out.println("1. Tambah Tim");
            System.out.println("2. Tampilkan Semua Tim");
            System.out.println("3. Tambah Pemain");
            System.out.println("4. Keluar");
            System.out.println("============================================");
            System.out.println("Mau Pilih Apa:");

            Pilihan = input.nextInt();
            input.nextLine();

            switch (Pilihan) {

                case 1:
                    System.out.println ("\n=========== Tambah Tim ===========");

                    System.out.println("Nama Tim        :");
                    String NamaTim = input.nextLine();

                    System.out.println("Nama Pelatih:");
                    String namaPelatih = input.nextLine();

                    System.out.println("Umur Pelatih:");
                    int umurPelatih = input.nextInt();
                    input.nextLine();

                    System.out.println("Lisensi     :");
                    String lisensi = input.nextLine();

                    Pelatih pelatih = new Pelatih(namaPelatih, umurPelatih, lisensi);
                    Team team = new Team(NamaTim, pelatih);

                    tournament.TambahTeam(team);

                    System.out.println("\nTim Berhasil Ditambahkan!");

                    break;

                    case 2:
                        System.out.println("\n=========== Data Tim ===========");
                        tournament.Tampilkan();
                        break;

                    case 3:

                        System.out.println("\n========== TAMBAH PEMAIN ==========");

                        tournament.Tampilkan();

                        System.out.print("\nPilih nomor tim: ");
                        int NomorTim = input.nextInt();
                        input.nextLine();

                        System.out.print("Nama Pemain       : ");
                        String NamaPemain = input.nextLine();

                        System.out.print("Umur Pemain       : ");
                        int UmurPemain = input.nextInt();

                        System.out.print("Nomor Punggung    : ");
                        int NomorPunggung = input.nextInt();
                        input.nextLine();

                        System.out.print("Posisi            : ");
                        String Posisi = input.nextLine();

                        Pemain pemain = new Pemain(NamaPemain,UmurPemain,NomorPunggung,Posisi);

                        Team teamDipilih = tournament.getTeam(NomorTim - 1);


                        teamDipilih.TambahPemain(pemain);

                        System.out.println("\nPemain berhasil ditambahkan ke tim!");

                        break;

                    case 4:
                        System.out.println("\nSampai Jumpa Di Cosion Volleyball 2026");
                        break;

                    default:
                        System.out.println("\nGa ada nomor segitu!!!!");
            }
            
        }while (Pilihan != 4);
        input.close();
    }
}