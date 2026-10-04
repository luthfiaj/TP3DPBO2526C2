# TP3DPBO2526C2 — Sistem Turnamen Voli (Cosion Volleyball 2026)

Saya Luthfi Aulia Jodi dengan NIM 2521743 mengerjakan Tugas Praktikum 3 dalam mata kuliah Desain Pemrograman Berbasis Objek untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang dispesifikasikan. Aamiin.

## Deskripsi Program

Tugas Praktikum 3 (DPBO 2025/2026, kelas C2): program pengelolaan data turnamen voli yang dibuat menggunakan pendekatan Pemrograman Berorientasi Objek (OOP). Program yang sama dibuat dalam tiga bahasa, yaitu **Java**, **Python**, dan **C++**, dengan alur dan output yang sama persis.

Program ini digunakan untuk mengelola data turnamen **Cosion Volleyball 2026** yang berlokasi di **Lapangan C FPMIPA**, mulai dari menambahkan tim, menampilkan seluruh tim beserta pelatih dan pemainnya, sampai menambahkan pemain ke tim yang dipilih.

Program menggunakan enam class:

- `Person` sebagai class induk (superclass) yang menyimpan nama dan umur.
- `Pemain` dan `Pelatih` sebagai class turunan dari `Person`.
- `Team` sebagai class yang menyimpan satu pelatih dan daftar pemain.
- `Tournament` sebagai class yang menyimpan daftar tim.
- `Main` sebagai program utama yang menangani menu dan input pengguna.

## Daftar Isi

1. [Struktur Folder](#1-struktur-folder)
2. [Desain Program](#2-desain-program)
3. [Alur Kode](#3-alur-kode)
4. [Cara Menjalankan](#4-cara-menjalankan)
5. [Dokumentasi Program](#5-dokumentasi-program)
6. [Catatan dan Batasan](#6-catatan-dan-batasan)

---

## 1. Struktur Folder

```
TP3DPBO2526C2/
├── cpp/
│   ├── Main.cpp
│   ├── Main.exe
│   ├── Pelatih.h
│   ├── Pemain.h
│   ├── Person.h
│   ├── Team.h
│   └── Tournament.h
├── Dokumentasi/
│   ├── C++/
│   │   ├── Keluar.png
│   │   ├── Menu.png
│   │   ├── Tambah Pemain.png
│   │   ├── Tambah Tim.png
│   │   └── Tampilin Data.png
│   ├── Java/
│   │   ├── Keluar.png
│   │   ├── Menu.png
│   │   ├── Tambah Pemain.png
│   │   ├── Tambah Tim.png
│   │   └── Tampilin Data.png
│   └── Python/
│       ├── Keluar.png
│       ├── Menu.png
│       ├── Tambah Pemain.png
│       ├── Tambah Tim.png
│       └── Tampilin Data.png
├── java/
│   ├── Main.java          # program utama + menu
│   ├── Pelatih.java       # class Pelatih (turunan Person)
│   ├── Pemain.java        # class Pemain (turunan Person)
│   ├── Person.java        # class induk
│   ├── Team.java          # class Team
│   └── Tournament.java    # class Tournament
└── python/
    ├── Main.py
    ├── Pelatih.py
    ├── Pemain.py
    ├── Person.py
    ├── Team.py
    └── Tournament.py
```

Keterangan:

| Folder / File | Isi |
|---|---|
| `cpp/`, `java/`, `python/` | Source code program dalam masing-masing bahasa |
| `Dokumentasi/` | Screenshot hasil program yang dikelompokkan per bahasa |
| `Main.exe` | Hasil kompilasi program C++ |
| `README.md` | Penjelasan program |

---

## 2. Desain Program

### 2.1 Konsep OOP yang Digunakan

| Konsep | Penerapan |
|---|---|
| **Class & Object** | `Person`, `Pemain`, `Pelatih`, `Team`, dan `Tournament` merupakan class. Setiap pemain, pelatih, tim, dan turnamen yang dibuat merupakan sebuah object. |
| **Inheritance (Pewarisan)** | `Pemain` dan `Pelatih` mewarisi `Person` menggunakan `extends`, sehingga atribut `Nama` dan `Umur` tidak perlu ditulis ulang. |
| **Polymorphism (Override)** | Method `Tampilkan()` pada `Person` ditimpa (`@Override`) oleh `Pemain` dan `Pelatih` sehingga masing-masing menampilkan data yang berbeda. |
| **Enkapsulasi** | Atribut pada `Pemain`, `Pelatih`, `Team`, dan `Tournament` dibuat `private` dan diakses melalui getter dan setter. |
| **Konstruktor** | Setiap class memiliki constructor berparameter dan constructor kosong (*constructor overloading*). Pada class turunan, constructor memanggil `super(Nama, Umur)`. |
| **Getter & Setter** | Digunakan untuk membaca dan mengubah atribut, misalnya `getNama()`, `setPosisi()`, `getCoach()`. |
| **Komposisi / Agregasi** | `Tournament` memiliki banyak `Team`, dan `Team` memiliki satu `Pelatih` serta banyak `Pemain`. |
| **Collection** | Data tim dan pemain disimpan menggunakan `ArrayList` (`List<Team>` dan `List<Pemain>`). |
| **Pemisahan tanggung jawab** | Tiap class mengurus datanya sendiri, sedangkan `Main` hanya menangani menu dan input. |

### 2.2 Class Person

Class induk yang menyimpan data dasar seseorang.

**Atribut**

| Atribut | Tipe | Keterangan |
|---|---|---|
| `Nama` | String | Nama orang |
| `Umur` | int | Umur orang |

**Method**

| Method | Fungsi |
|---|---|
| `Person(Nama, Umur)` | Constructor untuk mengisi nama dan umur |
| `Person()` | Constructor kosong |
| `setNama()` / `getNama()` | Mengubah / mengambil nama |
| `setUmur()` / `getUmur()` | Mengubah / mengambil umur |
| `Tampilkan()` | Menampilkan nama dan umur dalam satu baris |

### 2.3 Class Pemain (extends Person)

**Atribut tambahan**

| Atribut | Tipe | Keterangan |
|---|---|---|
| `NomorPunggung` | int | Nomor punggung pemain |
| `Posisi` | String | Posisi bermain (Setter, Libero, dll.) |

**Method**

| Method | Fungsi |
|---|---|
| `Pemain(Nama, Umur, NomorPunggung, Posisi)` | Constructor, memanggil `super(Nama, Umur)` |
| `Pemain()` | Constructor kosong |
| `getNomorPunggung()` / `setNomorPunggung()` | Mengambil / mengubah nomor punggung |
| `getPosisi()` / `setPosisi()` | Mengambil / mengubah posisi |
| `Tampilkan()` *(override)* | Menampilkan nama, umur, nomor punggung, dan posisi per baris |

### 2.4 Class Pelatih (extends Person)

**Atribut tambahan**

| Atribut | Tipe | Keterangan |
|---|---|---|
| `Lisensi` | String | Level lisensi pelatih |

**Method**

| Method | Fungsi |
|---|---|
| `Pelatih(Nama, Umur, Lisensi)` | Constructor, memanggil `super(Nama, Umur)` |
| `Pelatih()` | Constructor kosong |
| `getLisensi()` / `setLisensi()` | Mengambil / mengubah lisensi |
| `Tampilkan()` *(override)* | Menampilkan nama, umur, dan lisensi per baris |

### 2.5 Class Team

**Atribut**

| Atribut | Tipe | Keterangan |
|---|---|---|
| `NamaTim` | String | Nama tim |
| `Coach` | Pelatih | Pelatih tim (satu orang) |
| `ListPemain` | List&lt;Pemain&gt; | Daftar pemain dalam tim |

**Method**

| Method | Fungsi |
|---|---|
| `Team(NamaTim, Coach)` | Constructor untuk mengisi nama tim dan pelatih |
| `Team()` | Constructor kosong |
| `getNamaTim()` / `setNamaTim()` | Mengambil / mengubah nama tim |
| `getCoach()` / `setCoach()` | Mengambil / mengubah pelatih |
| `TambahPemain(pemain)` | Menambahkan pemain ke `ListPemain` |
| `TampilkanTim()` | Menampilkan nama tim, pelatih, dan seluruh pemain bernomor urut |

### 2.6 Class Tournament

**Atribut**

| Atribut | Tipe | Keterangan |
|---|---|---|
| `NamaTurnamen` | String | Nama turnamen |
| `Lokasi` | String | Lokasi pertandingan |
| `ListTeam` | List&lt;Team&gt; | Daftar tim yang ikut turnamen |

**Method**

| Method | Fungsi |
|---|---|
| `Tournament(NamaTurnamen, Lokasi)` | Constructor, sekaligus membuat `ListTeam` kosong |
| `Tournament()` | Constructor kosong |
| `getNamaTurnamen()` / `setNamaTurnamen()` | Mengambil / mengubah nama turnamen |
| `getLokasi()` / `setLokasi()` | Mengambil / mengubah lokasi |
| `TambahTeam(team)` | Menambahkan tim ke `ListTeam` |
| `getTeam(index)` | Mengambil tim berdasarkan index (dimulai dari 0) |
| `Tampilkan()` | Menampilkan informasi turnamen beserta seluruh tim |

### 2.7 Class Diagram

![Uploading class-diagram.svg…]()

Cara membaca diagram:

| Simbol | Arti |
|---|---|
| Garis dengan segitiga kosong | **Inheritance** — `Pemain` dan `Pelatih` mewarisi `Person` |
| Garis dengan belah ketupat kosong | **Agregasi** — `Tournament` memiliki banyak `Team`, `Team` memiliki banyak `Pemain` |
| Garis dengan panah terbuka | **Asosiasi** — `Team` menyimpan satu `Pelatih` sebagai `Coach` |
| Garis putus-putus dengan panah | **Dependensi** — `Main` menggunakan / membuat object dari class tersebut |
| `+` / `-` | Visibilitas `public` / `private` |

### 2.8 Pembagian Tanggung Jawab

| Bagian | File | Tugas |
|---|---|---|
| Model dasar | `Person.java` | Menyimpan nama dan umur, menjadi induk bagi pemain dan pelatih |
| Model pemain | `Pemain.java` | Menambah nomor punggung dan posisi |
| Model pelatih | `Pelatih.java` | Menambah lisensi |
| Model tim | `Team.java` | Menyimpan pelatih dan daftar pemain, serta menampilkannya |
| Model turnamen | `Tournament.java` | Menyimpan daftar tim, serta menampilkannya |
| Program utama | `Main.java` | Membuat data awal, menampilkan menu, menerima input, dan memanggil method yang sesuai |

### 2.9 Fitur Program

Program memiliki 4 menu utama:

| Menu | Fitur | Fungsi |
|---|---|---|
| 1 | Tambah Tim | Menambahkan tim baru beserta pelatihnya |
| 2 | Tampilkan Semua Tim | Menampilkan seluruh tim, pelatih, dan pemain |
| 3 | Tambah Pemain | Menambahkan pemain ke tim yang dipilih berdasarkan nomor tim |
| 4 | Keluar | Mengakhiri program |

### 2.10 Penyimpanan Data

Data disimpan menggunakan `ArrayList` secara bertingkat:

```
Tournament
 └── ListTeam  (List<Team>)
      ├── Team 1 ── Coach (Pelatih) + ListPemain (List<Pemain>)
      ├── Team 2 ── Coach (Pelatih) + ListPemain (List<Pemain>)
      └── ...
```

Berbeda dengan array biasa, `ArrayList` ukurannya dinamis sehingga jumlah tim dan pemain tidak dibatasi secara tetap.

Data hanya disimpan di dalam memori selama program berjalan. Setelah program ditutup, data yang ditambahkan akan hilang.

---

## 3. Alur Kode

### 3.1 Alur Utama Program

Program dimulai dengan membuat object `Scanner` dan object `Tournament`.

```java
Scanner input = new Scanner(System.in);
Tournament tournament = new Tournament("Cosion Volleyball 2026", "Lapangan C FPMIPA");
```

Kemudian program memasukkan 5 tim awal beserta pelatih dan pemainnya, lalu masuk ke perulangan `do-while` untuk menampilkan menu.

```
Mulai
  ↓
Membuat Scanner
  ↓
Membuat object Tournament
  ↓
Memasukkan 5 tim awal (pelatih + pemain)
  ↓
Menampilkan menu
  ↓
User memilih menu
  ↓
Menjalankan fitur
  ↓
Pilihan = 4?
  ├── Tidak → kembali ke menu
  └── Ya → Program selesai
```

### 3.2 Data Awal

Program memiliki 5 tim yang langsung dibuat ketika program dijalankan.

| No | Tim | Pelatih | Umur | Lisensi | Jumlah Pemain |
|---|---|---|---|---|---|
| 1 | ByteForce | Luthfi Aulia Jodi Ukai | 42 | Level 999 | 6 |
| 2 | BPKB | Subhan | 21 | Level -99 | 2 |
| 3 | STNK | Julian | 23 | Level 2 | 2 |
| 4 | All Star | Irfan | 24 | Level 5 | 2 |
| 5 | Cimahi Warriors | Rudi Hartono | 47 | Level 3 | 2 |

Pemain pada tim ByteForce:

| Nama | Umur | No. Punggung | Posisi |
|---|---|---|---|
| Bintang | 19 | 7 | Quicker, Trapper, Libero |
| Wingko | 19 | 10 | Setter |
| Daffa | 25 | 9 | Middle Blocker |
| Yusuf | 20 | 3 | Outside Hitter |
| Faiz | 20 | 1 | Outside Hitter |
| Juan | 40 | 21 | Penglaris |

### 3.3 Tambah Tim

Pada menu 1, program meminta data tim dan pelatih.

```
Pilih menu 1
   ↓
Masukkan Nama Tim
   ↓
Masukkan Nama Pelatih
   ↓
Masukkan Umur Pelatih
   ↓
Masukkan Lisensi
   ↓
Buat object Pelatih
   ↓
Buat object Team (NamaTim, Pelatih)
   ↓
tournament.TambahTeam(team)
   ↓
Tampilkan "Tim Berhasil Ditambahkan!"
```

Tim yang baru ditambahkan belum memiliki pemain. Pemain ditambahkan melalui menu 3.

### 3.4 Tampilkan Semua Tim

Menu 2 memanggil `tournament.Tampilkan()`. Pemanggilan berjalan bertingkat:

```
tournament.Tampilkan()
   ↓  (loop setiap tim)
team.TampilkanTim()
   ↓
Coach.Tampilkan()        → versi Pelatih (override)
   ↓  (loop setiap pemain)
pemain.Tampilkan()       → versi Pemain (override)
```

Karena `Tampilkan()` ditimpa pada `Pelatih` dan `Pemain`, setiap object menampilkan format miliknya sendiri walaupun dipanggil dengan nama method yang sama.

### 3.5 Tambah Pemain

Pada menu 3, program menampilkan seluruh tim terlebih dahulu agar user bisa melihat nomor tim.

```
Pilih menu 3
   ↓
Tampilkan semua tim
   ↓
Pilih nomor tim
   ↓
Masukkan Nama, Umur, Nomor Punggung, Posisi
   ↓
Buat object Pemain
   ↓
Ambil tim: tournament.getTeam(NomorTim - 1)
   ↓
team.TambahPemain(pemain)
   ↓
Tampilkan "Pemain berhasil ditambahkan ke tim!"
```

Nomor tim dikurangi 1 karena nomor yang dilihat user dimulai dari 1, sedangkan index `ArrayList` dimulai dari 0.

### 3.6 Keluar

Menu 4 mengakhiri program. Karena menu utama menggunakan:

```java
} while (Pilihan != 4);
```

maka program akan terus berjalan selama pilihan bukan 4. Saat user memilih 4, program menampilkan:

```
Sampai Jumpa Di Cosion Volleyball 2026
```

Kemudian `Scanner` ditutup. Jika user memasukkan angka selain 1–4, program menampilkan `Ga ada nomor segitu!!!!` dan kembali ke menu.

---

## 4. Cara Menjalankan

### Java

Pastikan Java/JDK sudah terpasang. Masuk ke folder `java`, lalu compile dan jalankan:

```bash
cd java
javac *.java
java Main
```

### Python

Pastikan Python 3 sudah terpasang. Masuk ke folder `python`, lalu jalankan:

```bash
cd python
python Main.py
```

### C++

Pastikan compiler `g++` sudah terpasang. Masuk ke folder `cpp`, lalu compile dan jalankan:

```bash
cd cpp
g++ Main.cpp -o Main
./Main
```

Setelah dijalankan, program akan menampilkan:

```
============================================
           Cosion Volleyball 2026
============================================
1. Tambah Tim
2. Tampilkan Semua Tim
3. Tambah Pemain
4. Keluar
============================================
Mau Pilih Apa:
```

---

## 5. Dokumentasi Program

Screenshot tersedia di folder `Dokumentasi/` untuk masing-masing bahasa (C++, Java, dan Python).

### 5.1 Menu Utama

Menampilkan seluruh pilihan fitur yang tersedia dalam program.

### 5.2 Tambah Tim

User memasukkan nama tim, nama pelatih, umur pelatih, dan lisensi.

### 5.3 Tampilin Data

Menampilkan seluruh tim beserta pelatih dan pemainnya. Contoh format keluaran satu tim:

```
=========================
       Tim: 1
Nama Tim    : ByteForce
Nama            : Luthfi Aulia Jodi Ukai
Umur            : 42
Lisensi         : Level 999
Daftar Pemain   :
--------------------
       Pemain 1
Nama            : Bintang
Umur            : 19
Nomor Punggung  : 7
Posisi          : Quicker, Trapper, Libero
--------------------
...
=========================
```

### 5.4 Tambah Pemain

User memilih nomor tim, lalu memasukkan nama, umur, nomor punggung, dan posisi pemain.

### 5.5 Keluar

Program menampilkan pesan perpisahan lalu berhenti.

---

## 6. Catatan dan Batasan

### Penanganan Input

| Bagian | Yang Ditangani | Yang Belum Ditangani |
|---|---|---|
| Menu | Pilihan di luar 1–4 menampilkan pesan error dan kembali ke menu | Input huruf pada menu menyebabkan error (`InputMismatchException`) |
| Nomor tim (menu 3) | Nomor dikonversi menjadi index dengan `NomorTim - 1` | Nomor di luar jangkauan menyebabkan `IndexOutOfBoundsException` |
| Input angka | Umur dan nomor punggung menggunakan `int` | Input huruf pada bagian angka dapat menyebabkan error |
| Nama tim | Dapat diisi bebas | Nama tim yang sama tidak dicegah |
| Nomor punggung | Dapat diisi bebas | Nomor punggung kembar dalam satu tim tidak dicegah |
| Pemain | Dapat ditambahkan ke tim mana pun | Belum ada fitur ubah atau hapus pemain/tim |

### Hal Lain yang Perlu Diketahui

- Data hanya disimpan selama program berjalan, tanpa database atau file eksternal.
- Program menggunakan `ArrayList` sehingga kapasitas tidak dibatasi seperti array statis.
- `Pemain`, `Pelatih`, `Team`, dan `Tournament` menggunakan atribut `private`, sedangkan `Person` menggunakan atribut `public` (`Nama`, `Umur`) yang tetap dilengkapi getter dan setter.
- `Pemain` dan `Pelatih` memanggil `getNama()` dan `getUmur()` dari class induk saat menampilkan data.
- Constructor kosong pada `Team` tidak mengisi `Coach`, sehingga `TampilkanTim()` akan error jika `Coach` belum diatur.
- Tim yang baru ditambahkan dari menu 1 belum memiliki pemain sampai ditambahkan lewat menu 3.
- Program menggunakan `Scanner` untuk menerima input dan `do-while` agar menu terus ditampilkan sampai user memilih menu 4.
- Versi Java, Python, dan C++ dibuat dengan struktur class dan keluaran yang sama.
