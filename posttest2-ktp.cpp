#include <iostream>
#include <iomanip>
using namespace std;

class Ktp {
    friend ostream& operator<<(ostream&, const Ktp&);
    friend istream& operator>>(istream&, Ktp&);
    public:
        Ktp(){};
    private:
        struct data{
            string provinsi, kab;
            string nik, nama, tempatL, jk, goldar, alamat, desa, kec, agama, status, kerja, kewarganegaraan, masa;
            int rt, rw, tanggalL, bulanL, tahunL;
        };
        data x;
};

int center(int n, int m){
    return (n-m)/2 + m;
}

istream& operator>>(istream& in, Ktp& m){
    cout << "Masukkan Data Diri Anda\n";
    cout << "Mohon isikan dengan huruf kapital.\n";
    cout << "Masukkan Asal Provinsi\t : ";
    getline(cin, m.x.provinsi);
    cout << "Masukkan Asal Kab/Kota\t : ";
    getline(cin, m.x.kab);
	cout << "Masukkan NIK\t\t : ";
    in >> m.x.nik;
    in.ignore();
	cout << "Masukkan Nama\t\t : "; 
    getline(in, m.x.nama);
	cout << "Masukkan Tempat Lahir\t : ";
    in >> m.x.tempatL; 
	cout << "Masukkan Tanggal Lahir\t : ";
    in >> m.x.tanggalL;
	cout << "Masukkan Bulan Lahir\t : ";
    in >> m.x.bulanL;
	cout << "Masukkan Tahun Lahir\t : ";
    in >> m.x.tahunL;
    in.ignore();
	cout << "Masukkan Jenis Kelamin\t : ";
    getline(in, m.x.jk);
	cout << "Masukkan Golongan Darah\t : ";  
    in >> m.x.goldar;
    in.ignore();
	cout << "Masukkan Alamat\t\t : "; 
    getline(in, m.x.alamat);
	cout << "Masukkan RT \t\t : ";
    in >> m.x.rt;
    cout << "Masukkan RW \t\t : ";
    in >> m.x.rw;
    in.ignore();
	cout << "Masukkan Kel/Desa\t : ";  
    getline(in, m.x.desa);
    cout << "Masukkan Kecamatan\t : ";  
    getline(in, m.x.kec);
    cout << "Masukkan Agama\t\t : ";  
    getline(in, m.x.agama);
    cout << "Masukkan Status Kawin\t : ";  
    getline(in, m.x.status);
    cout << "Masukkan Pekerjaan\t : ";  
    getline(in, m.x.kerja);
    cout << "Masukkan Kewarganegaraan : ";  
    getline(in, m.x.kewarganegaraan);
    cout << "Masukkan Masa Berlaku\t : ";  
    getline(in, m.x.masa);
    cout << endl;
    return in;
}

ostream& operator<<(ostream& out, const Ktp& m) {
    int lebar = 70;
    int pjgp, pjgk;
    pjgp = m.x.provinsi.size();
    pjgk = m.x.kab.size();
    out << "++======================================================================++" << endl; 
    out << "||" << setw(center(lebar, pjgp)) << setfill(' ');
    out << m.x.provinsi << setw(72-center(lebar, pjgp)) << setfill(' ') << "||" << endl;
    out << "||" << setw(center(lebar, pjgk)) << setfill(' ');
    out << m.x.kab << setw(72-center(lebar, pjgk)) << setfill(' ') << "||" << endl;
    out << "++======================================================================++" << endl;
	out << "|| NIK\t\t\t : " << m.x.nik << "\t\t\t\t||" << endl;
	out << "|| Nama\t\t\t : " << m.x.nama << setw(47-m.x.nama.size()) << setfill(' ') << "||" << endl;
	out << "|| Tempat/Tgl Lahir\t : " << m.x.tempatL << ", ";
    out << setfill('0') << setw(2) << m.x.tanggalL << "-";
    out << setfill('0') << setw(2) << m.x.bulanL << "-" << m.x.tahunL;
    out << setw(35-m.x.tempatL.size()) << setfill(' ') << "||" << endl;
	out << "|| Jenis Kelamin\t : " << m.x.jk << "\t  Gol. Darah    : " << m.x.goldar << "\t\t||" << endl;
	out << "|| Alamat\t\t : " << m.x.alamat << setw(47-m.x.alamat.size()) << setfill(' ') << "||" << endl;
	out << "||\tRT/RW\t\t : ";
    out << setfill('0') << setw(3) << m.x.rt << "/";
    out << setfill('0') << setw(3) << m.x.rw << "\t\t\t\t\t||" << endl;
	out << "||\tKel/Desa\t : " << m.x.desa << "\t\t\t\t\t||" << endl;
	out << "||\tKecamatan\t : " << m.x.kec << "\t\t\t\t\t||" << endl;
	out << "|| Agama\t\t : " << m.x.agama << "\t\t\t\t\t||" << endl;
	out << "|| Status Perkawinan\t : " << m.x.status << "\t\t\t\t\t||" << endl;
	out << "|| Pekerjaan\t\t : " << m.x.kerja << "\t\t\t\t||" << endl;
	out << "|| Kewarganegaraan\t : " << m.x.kewarganegaraan << "\t\t\t\t\t\t||" << endl;
	out << "|| Berlaku Hingga\t : " << m.x.masa << "\t\t\t\t\t||" << endl;
	out << "++======================================================================++" << endl << endl;
    return out;
}

int main(){
    int n;
    cout << "Berapa banyak data yang mau dimasukkan : ";
    cin >> n; cin.ignore();
    Ktp orang[n];
    for (int i = 0; i < n; i++){
        cin >> orang[i];
    }
    for (int i = 0; i < n; i++){
        cout << orang[i];
    }
    return 0;
}



/*	
Data input
PROVINSI JAWA TENGAH
KABUPATEN PEKALONGAN
3326130710020002
MUHAMMAD FAKHRUL AMIN
PEKALONGAN
7
10
2002
LAKI-LAKI
A
PEKAJANGAN GANG 29 NO 23
32
15
PEKAJANGAN
KEDUNGWUNI
ISLAM
BELUM KAWIN
PELAJAR/MAHASISWA
WNI
SEUMUR HIDUP
PROVINSI JAWA TENGAH
KABUPATEN BANJARNEGARA
3304042402090900
DEWA PUTRA HERNANDA
BANJARNEGARA
24
2
1995
LAKI-LAKI
O
BRUBAHAN
9
10
PURWANEGARA
PURWONEGORO
ISLAM
BELUM KAWIN
PELAJAR/MAHASISWA
WNI
SEUMUR HIDUP
PROVINSI JAWA TENGAH
KABUPATEN GROBOGAN
3315011210060001
BAGAS ULINUHA
GROBOGAN
12
10
2006
LAKI-LAKI
A
KEDUNGJATI GANG 7
11
10
KEDUNGJATI
KEDUNGJATI
ISLAM
BELUM KAWIN
PELAJAR/MAHASISWA
WNI
SEUMUR HIDUP

*/