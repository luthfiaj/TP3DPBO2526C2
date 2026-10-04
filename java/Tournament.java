import java.util.ArrayList;
import java.util.List;

class Tournament {
    private String NamaTurnamen;
    private String Lokasi;
    private List<Team> ListTeam = new ArrayList<>();

    public Tournament(String NamaTurnamen, String Lokasi) {
        this.NamaTurnamen = NamaTurnamen;
        this.Lokasi = Lokasi;
        this.ListTeam = new ArrayList<>();
    }

    public Tournament() {
    }

    public String getNamaTurnamen() {
        return NamaTurnamen;
    }

    public void setNamaTurnamen(String NamaTurnamen) {
        this.NamaTurnamen = NamaTurnamen;
    }

    public String getLokasi() {
        return Lokasi;
    }

    public void setLokasi(String Lokasi) {
        this.Lokasi = Lokasi;
    }

    public void TambahTeam(Team team) {
        ListTeam.add(team);
    }

    public Team getTeam(int index) {
    return ListTeam.get(index);
}

    public void Tampilkan() {
        System.out.println("Nama Turnamen   : " + NamaTurnamen);
        System.out.println("Lokasi          : " + Lokasi);
        System.out.println("Daftar Tim:");
        int i = 1;
        for (Team team : ListTeam) {
            System.out.println("\n=========================");
            System.out.println("       Tim: " + i);
            team.TampilkanTim();
            System.out.println("=========================");
            i++;
        }
    }
}