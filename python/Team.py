class Team:
    def __init__(self, NamaTim="", Coach=None):
        self.NamaTim = NamaTim
        self.Coach = Coach
        self.ListPemain = []

    def getNamaTim(self):
        return self.NamaTim

    def setNamaTim(self, NamaTim):
        self.NamaTim = NamaTim

    def getCoach(self):
        return self.Coach

    def setCoach(self, Coach):
        self.Coach = Coach

    def TambahPemain(self, pemain):
        self.ListPemain.append(pemain)

    def TampilkanTim(self):
        print("Nama Tim    :", self.getNamaTim())
        self.Coach.Tampilkan()

        print("Daftar Pemain   :")

        i = 1

        for pemain in self.ListPemain:
            print("--------------------")
            print("       Pemain", i)
            pemain.Tampilkan()
            print("--------------------")
            i += 1