class Person:
    def __init__(self, Nama="", Umur=0):
        self.Nama = Nama
        self.Umur = Umur

    def setNama(self, Nama):
        self.Nama = Nama

    def getNama(self):
        return self.Nama

    def setUmur(self, Umur):
        self.Umur = Umur

    def getUmur(self):
        return self.Umur

    def Tampilkan(self):
        print("Nama    :", self.Nama, ", Umur    :", self.Umur)