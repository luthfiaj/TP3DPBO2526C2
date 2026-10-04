class Pemain extends Person{
    private int NomorPunggung;
    private String Posisi;

    public Pemain(String Nama, int Umur, int NomorPunggung, String Posisi){
        super(Nama, Umur);
        this.NomorPunggung = NomorPunggung;
        this.Posisi = Posisi;
    }

    public Pemain(){
    }

    public int getNomorPunggung() {
        return NomorPunggung;
    }

    public void setNomorPunggung(int NomorPunggung) {
        this.NomorPunggung = NomorPunggung;
    }

    public String getPosisi() {
        return Posisi;
    }

    public void setPosisi(String Posisi) {
        this.Posisi = Posisi;
    }

    @Override
    public void Tampilkan(){
        System.out.println("Nama            : " + getNama());
        System.out.println("Umur            : " + getUmur());
        System.out.println("Nomor Punggung  : " + NomorPunggung);
        System.out.println("Posisi          : " + Posisi);
    }
}