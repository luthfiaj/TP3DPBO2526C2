class Pelatih extends Person{
    private String Lisensi;

    public Pelatih(String Nama, int Umur, String Lisensi){
        super(Nama, Umur);
        this.Lisensi = Lisensi;
    }

    public Pelatih(){
    }

    public String getLisensi() {
        return Lisensi;
    }

    public void setLisensi(String Lisensi) {
        this.Lisensi = Lisensi;
    }

    @Override
    public void Tampilkan(){
        System.out.println("Nama            : " + getNama());
        System.out.println("Umur            : " + getUmur());
        System.out.println("Lisensi         : " + Lisensi);
    }
}