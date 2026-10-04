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

![Uploading class-diagram.svg…]()<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 1020 1366" width="1020" height="1366" xmlns:c2pa="http://c2pa.org/manifest"><metadata><c2pa:manifest>AAAWgmp1bWIAAAAeanVtZGMycGEAEQAQgAAAqgA4m3EDYzJwYQAAABZcanVtYgAAAEdqdW1kYzJtYQARABCAAACqADibcQN1cm46YzJwYTplMmRmNTU5Ny0xMTgwLTQ3NzgtODExOC03MDMxZTZkYzA4OTUAAAADl2p1bWIAAAApanVtZGMyYXMAEQAQgAAAqgA4m3EDYzJwYS5hc3NlcnRpb25zAAAAALxqdW1iAAAARGp1bWRjYm9yABEAEIAAAKoAOJtxE2MycGEuaW5ncmVkaWVudC52MwAAAAAYYzJzaNe6MxOv7XwLclReBMxI/UkAAABwY2JvcqNpZGM6Zm9ybWF0bWltYWdlL3N2Zyt4bWxqaW5zdGFuY2VJRHgseG1wOmlpZDphZWNhMTM3OS03NzUwLTQ5ZGQtYTAxOC1mZThjZDQyOTQ1ZmRscmVsYXRpb25zaGlwaHBhcmVudE9mAAAB4mp1bWIAAABBanVtZGNib3IAEQAQgAAAqgA4m3ETYzJwYS5hY3Rpb25zLnYyAAAAABhjMnNostP5yDlunii3jX6Cplx3YwAAAZljYm9yomdhY3Rpb25zgqJmYWN0aW9ua2MycGEub3BlbmVkanBhcmFtZXRlcnOha2luZ3JlZGllbnRzgaJjdXJseC1zZWxmI2p1bWJmPWMycGEuYXNzZXJ0aW9ucy9jMnBhLmluZ3JlZGllbnQudjNkaGFzaFggYmjjPD1FEchmJzR7v8Fvdrt7A54TxuBZdAnMaW6tD9+kZmFjdGlvbngdY29tLmFudGhyb3BpYy5jbGF1ZGUucHJvdmlkZWRqcGFyYW1ldGVyc6F4H2NvbS5hbnRocm9waWMub3JpZ2luLWNvbmZpZGVuY2VndW5rbm93bmtkZXNjcmlwdGlvbnhmQ2xhdWRlIHByb3ZpZGVkIHRoaXMgZmlsZSBhdCB0aGUgcmVxdWVzdCBvZiBhIHVzZXIgYW5kIG1heSBoYXZlIGNyZWF0ZWQgb3IgbW9kaWZpZWQgdGhlIGZpbGUgY29udGVudHMubXNvZnR3YXJlQWdlbnShZG5hbWVmQ2xhdWRlcmFsbEFjdGlvbnNJbmNsdWRlZPUAAADIanVtYgAAAEBqdW1kY2JvcgARABCAAACqADibcRNjMnBhLmhhc2guZGF0YQAAAAAYYzJzaFmw6/go3QJ87KcDVfAA5v8AAACAY2JvcqVjYWxnZnNoYTI1NmNwYWRNAAAAAAAAAAAAAAAAAGRoYXNoWCCzma1E981KbRLsCFKFZ8sxSgVWGXXSpR+muDak2UrSyGRuYW1lbmp1bWJmIG1hbmlmZXN0amV4Y2x1c2lvbnOBomVzdGFydBiaZmxlbmd0aBkeBAAAAj5qdW1iAAAAJ2p1bWRjMmNsABEAEIAAAKoAOJtxA2MycGEuY2xhaW0udjIAAAACD2Nib3KlY2FsZ2ZzaGEyNTZpc2lnbmF0dXJleE1zZWxmI2p1bWJmPS9jMnBhL3VybjpjMnBhOmUyZGY1NTk3LTExODAtNDc3OC04MTE4LTcwMzFlNmRjMDg5NS9jMnBhLnNpZ25hdHVyZWppbnN0YW5jZUlEeCx4bXA6aWlkOjYxZGQxM2UyLTQ4YmItNDQ4Yi05MzdhLTgwMTAzNzdmZDZhZHJjcmVhdGVkX2Fzc2VydGlvbnODomN1cmx4LXNlbGYjanVtYmY9YzJwYS5hc3NlcnRpb25zL2MycGEuaW5ncmVkaWVudC52M2RoYXNoWCBiaOM8PUURyGYnNHu/wW92u3sDnhPG4Fl0Ccxpbq0P36JjdXJseCpzZWxmI2p1bWJmPWMycGEuYXNzZXJ0aW9ucy9jMnBhLmFjdGlvbnMudjJkaGFzaFggKtI7N3odf3l9W4Qg1NkU56N9hkvzIfqSHnB4kOrpIOyiY3VybHgpc2VsZiNqdW1iZj1jMnBhLmFzc2VydGlvbnMvYzJwYS5oYXNoLmRhdGFkaGFzaFggilgDjsrMfC03zUPlEn4n2c7RBRCSht9XPVrSh5tJmwZ0Y2xhaW1fZ2VuZXJhdG9yX2luZm+jZG5hbWVvQW50aHJvcGljIEZpbGVzZ3ZlcnNpb25lMS4wLjBrc3BlY1ZlcnNpb25lMi40LjAAABA4anVtYgAAAChqdW1kYzJjcwARABCAAACqADibcQNjMnBhLnNpZ25hdHVyZQAAABAIY2JvctKEWQISogEmGCFZAgowggIGMIIBjaADAgECAhRA5aAK7sI50L64g/oGQgU9Z1UTADAKBggqhkjOPQQDAzBJMRcwFQYDVQQKEw5BbnRocm9waWMsIFBCQzEuMCwGA1UEAxMlQW50aHJvcGljIENvbnRlbnQgQ3JlZGVudGlhbHMgUm9vdCBDQTAeFw0yNjA4MDcxODQzNTZaFw0yODA4MDYxOTQzNTZaMEQxFzAVBgNVBAoTDkFudGhyb3BpYywgUEJDMSkwJwYDVQQDEyBBbnRocm9waWMgQ2xhdWRlIENvbnRlbnQgU2lnbmluZzBZMBMGByqGSM49AgEGCCqGSM49AwEHA0IABJh6CmvLUBgFFNU0vUKlOVtE6djd17L5SuwX0LemFisBM3dkd/3cyjxFA3Qo5S46fX0/ihY0VZ7mfb9KF703t5OjWDBWMA4GA1UdDwEB/wQEAwIHgDAVBgNVHSUEDjAMBgorBgEEAYPoXgIBMAwGA1UdEwEB/wQCMAAwHwYDVR0jBBgwFoAUzlHiBIFOZFsj+OPEz5o+nMHXXMIwCgYIKoZIzj0EAwMDZwAwZAIwMXMdFJ4BetLLVY7ORuE9noqbbAZOZn/aArXyTwFAZfKrPzxF2vPoJNf1+UCdg1XGAjBwX1zd9WGqYkqmL5SFqw1QySjr1zJfpJM9+1rdDwSPLMOPOjKuiXjoU/pUUeG9RwmhY3BhZFkNngAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAPZYQGLE9yfIyhYLbupervdLgfFV/VckrZxbDiFEhfAWW6zZoQatNFezuIS/+7SCIeorC6Op4s7VAtwdb9rShNr/teo=</c2pa:manifest></metadata>
<defs>
<marker id="tri" viewBox="0 0 14 14" refX="13" refY="7" markerWidth="14" markerHeight="14" markerUnits="userSpaceOnUse" orient="auto"><path d="M0,1 L13,7 L0,13 z" fill="#fff" stroke="#222" stroke-width="1.5"/></marker>
<marker id="arr" viewBox="0 0 12 12" refX="11" refY="6" markerWidth="12" markerHeight="12" markerUnits="userSpaceOnUse" orient="auto"><path d="M1,1 L11,6 L1,11" fill="none" stroke="#222" stroke-width="1.5"/></marker>
</defs>
<rect width="1020" height="1366" fill="#ffffff"/>
<path d="M220,975 V1074 H510 V1124" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter" marker-end="url(#tri)"/>
<path d="M800,1029 V1074 H510" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter"/>
<polygon points="510,404 502,416 510,428 518,416" fill="#fff" stroke="#222" stroke-width="1.5"/>
<path d="M510,428 V474" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter"/>
<text x="520" y="466" font-family="Arial, sans-serif" font-size="12" text-anchor="start" fill="#222" >0..*</text>
<text x="520" y="420" font-family="Arial, sans-serif" font-size="11" text-anchor="start" fill="#222" font-style="italic">ListTeam</text>
<path d="M430,722 V767 H220 V817" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter" marker-end="url(#arr)"/>
<text x="228" y="809" font-family="Arial, sans-serif" font-size="12" text-anchor="start" fill="#222" >1</text>
<text x="242" y="761" font-family="Arial, sans-serif" font-size="11" text-anchor="start" fill="#222" font-style="italic">Coach</text>
<polygon points="590,722 582,734 590,746 598,734" fill="#fff" stroke="#222" stroke-width="1.5"/>
<path d="M590,746 V767 H800 V817" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter"/>
<text x="808" y="809" font-family="Arial, sans-serif" font-size="12" text-anchor="start" fill="#222" >0..*</text>
<text x="740" y="761" font-family="Arial, sans-serif" font-size="11" text-anchor="start" fill="#222" font-style="italic">ListPemain</text>
<path d="M510,78 V138" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter" stroke-dasharray="7 5" marker-end="url(#arr)"/>
<text x="520" y="112" font-family="Arial, sans-serif" font-size="11" text-anchor="start" fill="#222" >«uses»</text>
<path d="M340,55 H20 V862 H50" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter" stroke-dasharray="7 5" marker-end="url(#arr)"/>
<text x="28" y="48" font-family="Arial, sans-serif" font-size="11" text-anchor="start" fill="#222" >«create»</text>
<path d="M680,55 H1000 V862 H970" fill="none" stroke="#222" stroke-width="1.5" stroke-linejoin="miter" stroke-dasharray="7 5" marker-end="url(#arr)"/>
<text x="992" y="48" font-family="Arial, sans-serif" font-size="11" text-anchor="end" fill="#222" >«create»</text>
<rect x="340" y="20" width="340" height="58" fill="#fff" stroke="#222" stroke-width="1.5"/>
<rect x="340" y="20" width="340" height="30" fill="#e1d5e7" stroke="#222" stroke-width="1.5"/>
<text x="510.0" y="40" font-family="Arial, sans-serif" font-size="15" text-anchor="middle" fill="#222" font-weight="bold">Main</text>
<text x="350" y="67" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+main(args: String[]): void</text>
<rect x="340" y="138" width="340" height="266" fill="#fff" stroke="#222" stroke-width="1.5"/>
<rect x="340" y="138" width="340" height="30" fill="#dae8fc" stroke="#222" stroke-width="1.5"/>
<text x="510.0" y="158" font-family="Arial, sans-serif" font-size="15" text-anchor="middle" fill="#222" font-weight="bold">Tournament</text>
<text x="350" y="185" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-NamaTurnamen: String</text>
<text x="350" y="203" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-Lokasi: String</text>
<text x="350" y="221" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-ListTeam: List&lt;Team&gt;</text>
<line x1="340" y1="232" x2="680" y2="232" stroke="#222" stroke-width="1.5"/>
<text x="350" y="249" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Tournament(NamaTurnamen, Lokasi)</text>
<text x="350" y="267" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Tournament()</text>
<text x="350" y="285" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getNamaTurnamen(): String</text>
<text x="350" y="303" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setNamaTurnamen(NamaTurnamen)</text>
<text x="350" y="321" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getLokasi(): String</text>
<text x="350" y="339" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setLokasi(Lokasi)</text>
<text x="350" y="357" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+TambahTeam(team: Team)</text>
<text x="350" y="375" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getTeam(index: int): Team</text>
<text x="350" y="393" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Tampilkan(): void</text>
<rect x="340" y="474" width="340" height="248" fill="#fff" stroke="#222" stroke-width="1.5"/>
<rect x="340" y="474" width="340" height="30" fill="#dae8fc" stroke="#222" stroke-width="1.5"/>
<text x="510.0" y="494" font-family="Arial, sans-serif" font-size="15" text-anchor="middle" fill="#222" font-weight="bold">Team</text>
<text x="350" y="521" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-NamaTim: String</text>
<text x="350" y="539" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-Coach: Pelatih</text>
<text x="350" y="557" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-ListPemain: List&lt;Pemain&gt;</text>
<line x1="340" y1="568" x2="680" y2="568" stroke="#222" stroke-width="1.5"/>
<text x="350" y="585" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Team(NamaTim, Coach)</text>
<text x="350" y="603" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Team()</text>
<text x="350" y="621" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getNamaTim(): String</text>
<text x="350" y="639" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setNamaTim(NamaTim)</text>
<text x="350" y="657" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getCoach(): Pelatih</text>
<text x="350" y="675" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setCoach(Coach)</text>
<text x="350" y="693" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+TambahPemain(pemain: Pemain)</text>
<text x="350" y="711" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+TampilkanTim(): void</text>
<rect x="50" y="817" width="340" height="158" fill="#fff" stroke="#222" stroke-width="1.5"/>
<rect x="50" y="817" width="340" height="30" fill="#d5e8d4" stroke="#222" stroke-width="1.5"/>
<text x="220.0" y="837" font-family="Arial, sans-serif" font-size="15" text-anchor="middle" fill="#222" font-weight="bold">Pelatih</text>
<text x="60" y="864" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-Lisensi: String</text>
<line x1="50" y1="875" x2="390" y2="875" stroke="#222" stroke-width="1.5"/>
<text x="60" y="892" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Pelatih(Nama, Umur, Lisensi)</text>
<text x="60" y="910" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Pelatih()</text>
<text x="60" y="928" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getLisensi(): String</text>
<text x="60" y="946" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setLisensi(Lisensi)</text>
<text x="60" y="964" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Tampilkan(): void</text>
<rect x="630" y="817" width="340" height="212" fill="#fff" stroke="#222" stroke-width="1.5"/>
<rect x="630" y="817" width="340" height="30" fill="#d5e8d4" stroke="#222" stroke-width="1.5"/>
<text x="800.0" y="837" font-family="Arial, sans-serif" font-size="15" text-anchor="middle" fill="#222" font-weight="bold">Pemain</text>
<text x="640" y="864" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-NomorPunggung: int</text>
<text x="640" y="882" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">-Posisi: String</text>
<line x1="630" y1="893" x2="970" y2="893" stroke="#222" stroke-width="1.5"/>
<text x="640" y="910" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Pemain(Nama, Umur, NomorPunggung, Posisi)</text>
<text x="640" y="928" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Pemain()</text>
<text x="640" y="946" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getNomorPunggung(): int</text>
<text x="640" y="964" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setNomorPunggung(NomorPunggung)</text>
<text x="640" y="982" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getPosisi(): String</text>
<text x="640" y="1000" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setPosisi(Posisi)</text>
<text x="640" y="1018" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Tampilkan(): void</text>
<rect x="340" y="1124" width="340" height="212" fill="#fff" stroke="#222" stroke-width="1.5"/>
<rect x="340" y="1124" width="340" height="30" fill="#fff2cc" stroke="#222" stroke-width="1.5"/>
<text x="510.0" y="1144" font-family="Arial, sans-serif" font-size="15" text-anchor="middle" fill="#222" font-weight="bold">Person</text>
<text x="350" y="1171" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Nama: String</text>
<text x="350" y="1189" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Umur: int</text>
<line x1="340" y1="1200" x2="680" y2="1200" stroke="#222" stroke-width="1.5"/>
<text x="350" y="1217" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Person(Nama, Umur)</text>
<text x="350" y="1235" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Person()</text>
<text x="350" y="1253" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setNama(Nama)</text>
<text x="350" y="1271" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getNama(): String</text>
<text x="350" y="1289" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+setUmur(Umur)</text>
<text x="350" y="1307" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+getUmur(): int</text>
<text x="350" y="1325" font-family="Consolas, 'Courier New', monospace" font-size="12" fill="#222">+Tampilkan(): void</text>
</svg>

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
