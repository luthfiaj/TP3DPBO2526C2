public class Person{
    public String Nama;
    public int Umur;

    public Person(String Nama, int Umur){
        this.Nama = Nama;
        this.Umur = Umur;
    }

    public Person(){
    }

    public void setNama(String Nama){
        this.Nama = Nama;
    }

    public String getNama(){
        return Nama;
    }

    public void setUmur(int Umur){
        this.Umur = Umur;
    }

    public int getUmur(){
        return Umur;
    }

    public void Tampilkan(){
        System.out.println("Nama    : " + Nama + ", Umur    : " + Umur);
    }
}