class Tournament:
    def __init__(self, NamaTurnamen="", Lokasi=""):
        self.NamaTurnamen = NamaTurnamen
        self.Lokasi = Lokasi
        self.ListTeam = []

    def getNamaTurnamen(self):
        return self.NamaTurnamen

    def setNamaTurnamen(self, NamaTurnamen):
        self.NamaTurnamen = NamaTurnamen

    def getLokasi(self):
        return self.Lokasi

    def setLokasi(self, Lokasi):
        self.Lokasi = Lokasi

    def TambahTeam(self, team):
        self.ListTeam.append(team)

    def getTeam(self, index):
        return self.ListTeam[index]

    def Tampilkan(self):
        print("Nama Turnamen   :", self.NamaTurnamen)
        print("Lokasi          :", self.Lokasi)
        print("Daftar Tim:")

        i = 1

        for team in self.ListTeam:
            print("\n=========================")
            print("       Tim:", i)
            team.TampilkanTim()
            print("=========================")
            i += 1