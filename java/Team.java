import java.util.ArrayList;
import java.util.List;

class Team{
    private String NamaTim;
    private Pelatih Coach;
    private List<Pemain> ListPemain = new ArrayList<>();

    public Team(String NamaTim,Pelatih Coach){
        this.NamaTim = NamaTim;
        this.Coach = Coach;
    }

    public Team(){
    }

    public String getNamaTim() {
        return NamaTim;
    }

    public void setNamaTim(String NamaTim) {
        this.NamaTim = NamaTim;
    }

    public Pelatih getCoach() {
        return Coach;
    }

    public void setCoach(Pelatih Coach) {
        this.Coach = Coach;
    }

    public void TambahPemain(Pemain pemain){
        ListPemain.add(pemain);
    }
    
    public void TampilkanTim(){
        System.out.println("Nama Tim    : " + getNamaTim());
        Coach.Tampilkan();
        System.out.println("Daftar Pemain   :");
        int i = 1;
        for (Pemain pemain : ListPemain) {
            System.out.println("--------------------");
            System.out.println("       Pemain " + i );
            pemain.Tampilkan();
            System.out.println("--------------------");
            i++;
        }
    }
}