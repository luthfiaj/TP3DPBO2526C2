from Person import Person


class Pelatih(Person):
    def __init__(self, Nama="", Umur=0, Lisensi=""):
        super().__init__(Nama, Umur)
        self.Lisensi = Lisensi

    def getLisensi(self):
        return self.Lisensi

    def setLisensi(self, Lisensi):
        self.Lisensi = Lisensi

    def Tampilkan(self):
        print("Nama            :", self.getNama())
        print("Umur            :", self.getUmur())
        print("Lisensi         :", self.Lisensi)