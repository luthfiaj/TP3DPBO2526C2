from Person import Person


class Pemain(Person):
    def __init__(self, Nama="", Umur=0, NomorPunggung=0, Posisi=""):
        super().__init__(Nama, Umur)
        self.NomorPunggung = NomorPunggung
        self.Posisi = Posisi

    def getNomorPunggung(self):
        return self.NomorPunggung

    def setNomorPunggung(self, NomorPunggung):
        self.NomorPunggung = NomorPunggung

    def getPosisi(self):
        return self.Posisi

    def setPosisi(self, Posisi):
        self.Posisi = Posisi

    def Tampilkan(self):
        print("Nama            :", self.getNama())
        print("Umur            :", self.getUmur())
        print("Nomor Punggung  :", self.NomorPunggung)
        print("Posisi          :", self.Posisi)