#include <iostream>
#include <iomanip>
using namespace std;

struct data_ktp{
    string provinsi, kab;
    string nik, nama, tempatL, jk, goldar, alamat, desa, kec, agama, status, kerja, kewarganegaraan, masa;
    int rt, rw, tanggalL, bulanL, tahunL;
    data_ktp* next = NULL;
};

class Ktp {
    public:
        Ktp(){ head = NULL; };
        void inputBelakang();  // ini
        void deleteBelakang(); // ini
        void output();
    private:
        data_ktp *head;
};

int center(int n, int m){
    return (n-m)/2 + m;
}

void Ktp::inputBelakang(){
    data_ktp* newData = new data_ktp;

    cout << "Masukkan Data Diri Anda\n";
    cout << "Mohon isikan dengan huruf kapital.\n";
    cout << "Masukkan Asal Provinsi\t : ";
    getline(cin, newData->provinsi);
    cout << "Masukkan Asal Kab/Kota\t : ";
    getline(cin, newData->kab);
	cout << "Masukkan NIK\t\t : ";
    cin >> newData->nik;
    cin.ignore();
	cout << "Masukkan Nama\t\t : "; 
    getline(cin, newData->nama);
	cout << "Masukkan Tempat Lahir\t : ";
    cin >> newData->tempatL; 
	cout << "Masukkan Tanggal Lahir\t : ";
    cin >> newData->tanggalL;
	cout << "Masukkan Bulan Lahir\t : ";
    cin >> newData->bulanL;
	cout << "Masukkan Tahun Lahir\t : ";
    cin >> newData->tahunL;
    cin.ignore();
	cout << "Masukkan Jenis Kelamin\t : ";
    getline(cin, newData->jk);
	cout << "Masukkan Golongan Darah\t : ";  
    cin >> newData->goldar;
    cin.ignore();
	cout << "Masukkan Alamat\t\t : "; 
    getline(cin, newData->alamat);
	cout << "Masukkan RT \t\t : ";
    cin >> newData->rt;
    cout << "Masukkan RW \t\t : ";
    cin >> newData->rw;
    cin.ignore();
	cout << "Masukkan Kel/Desa\t : ";  
    getline(cin, newData->desa);
    cout << "Masukkan Kecamatan\t : ";  
    getline(cin, newData->kec);
    cout << "Masukkan Agama\t\t : ";  
    getline(cin, newData->agama);
    cout << "Masukkan Status Kawin\t : ";  
    getline(cin, newData->status);
    cout << "Masukkan Pekerjaan\t : ";  
    getline(cin, newData->kerja);
    cout << "Masukkan Kewarganegaraan : ";  
    getline(cin, newData->kewarganegaraan);
    cout << "Masukkan Masa Berlaku\t : ";  
    getline(cin, newData->masa);
    cout << "\n=== DATA TERSIMPAN ===\n\n";
    if(head == NULL){
        head = newData;
        return;
    }
    data_ktp* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newData;
}

void Ktp::deleteBelakang()
{
	data_ktp *del, *temp;

	if (head == NULL) {
		cout << "\n=== DATA KOSONG ==\n\n";
		return;
	}
    if (head->next != NULL){
        temp = head;
        while (temp->next->next!=NULL){
            temp = temp->next;
        }
        del = temp->next;
        temp->next=NULL;
        delete del;
    }else {
        head = NULL;
    }
    cout << "\n=== DATA TERAKHIR BERHASIL DIHAPUS ==\n\n";

}

void Ktp::output(){
    data_ktp* temp = head;
    int lebar = 70, dataKe = 1;
    int pjgp, pjgk;

	// mengecek kalau list kosong.
	if (head == NULL) {
		cout << "\n=== DATA KOSONG ==\n\n";
		return;
	}

	// outputkan list dari awal (head) sampai akhir.
	while (temp != NULL) {
		pjgp = temp->provinsi.size();
        pjgk = temp->kab.size();
        cout << "\n=== DATA KE " << dataKe++ << "===\n";
        cout << "++======================================================================++" << endl; 
        cout << "||" << setw(center(lebar, pjgp)) << setfill(' ');
        cout << temp->provinsi << setw(72-center(lebar, pjgp)) << setfill(' ') << "||" << endl;
        cout << "||" << setw(center(lebar, pjgk)) << setfill(' ');
        cout << temp->kab << setw(72-center(lebar, pjgk)) << setfill(' ') << "||" << endl;
        cout << "++======================================================================++" << endl;
        cout << "|| NIK\t\t\t : " << temp->nik << "\t\t\t\t||" << endl;
        cout << "|| Nama\t\t\t : " << temp->nama << setw(47-temp->nama.size()) << setfill(' ') << "||" << endl;
        cout << "|| Tempat/Tgl Lahir\t : " << temp->tempatL << ", ";
        cout << setfill('0') << setw(2) << temp->tanggalL << "-";
        cout << setfill('0') << setw(2) << temp->bulanL << "-" << temp->tahunL;
        cout << setw(35-temp->tempatL.size()) << setfill(' ') << "||" << endl;
        cout << "|| Jenis Kelamin\t : " << temp->jk << "\t  Gol. Darah    : " << temp->goldar << "\t\t||" << endl;
        cout << "|| Alamat\t\t : " << temp->alamat << setw(47-temp->alamat.size()) << setfill(' ') << "||" << endl;
        cout << "||\tRT/RW\t\t : ";
        cout << setfill('0') << setw(3) << temp->rt << "/";
        cout << setfill('0') << setw(3) << temp->rw << "\t\t\t\t\t||" << endl;
        cout << "||\tKel/Desa\t : " << temp->desa << "\t\t\t\t\t||" << endl;
        cout << "||\tKecamatan\t : " << temp->kec << "\t\t\t\t\t||" << endl;
        cout << "|| Agama\t\t : " << temp->agama << "\t\t\t\t\t||" << endl;
        cout << "|| Status Perkawinan\t : " << temp->status << "\t\t\t\t\t||" << endl;
        cout << "|| Pekerjaan\t\t : " << temp->kerja << "\t\t\t\t||" << endl;
        cout << "|| Kewarganegaraan\t : " << temp->kewarganegaraan << "\t\t\t\t\t\t||" << endl;
        cout << "|| Berlaku Hingga\t : " << temp->masa << "\t\t\t\t\t||" << endl;
        cout << "++======================================================================++" << endl;
    
		temp = temp->next;
	}
    cout << "\n=== KESELURUHAN DATA BERHASIL DICETAK===\n\n";
}

int main(){
    char c;
    Ktp m;
    while(true){
        cout << "++====================++\n";
        cout << "||      MENU KTP      ||\n";
        cout << "++====================++\n";
        cout << " 1. Tambah data\n 2. Hapus data terakhir\n 3. Lihat data\n 4. Keluar\n";
        cout << "=== Masukkan pilihan : ";
        cin >> c; cin.ignore();
        if (c == '1'){
            m.inputBelakang();
        } else if (c == '2'){
            m.deleteBelakang();
        } else if (c == '3'){
            m.output();
        } else if (c == '4'){
            return 0;
        } else {
            cout << "Masukkan pilihan yang sesuai.\n\n";
        }
    }
    return 0;
}



/*	
PROVINSI NUSA TENGGARA TIMUR
KABUPATEN FLORES
6516130710020002
AMIN FAKHRUL
PEKALONGAN
7
10
2002
LAKI-LAKI
A
KOLIPETUNG GANG 29 NO 23
32
15
KOLIPETUNG
ADONARA
ISLAM
BELUM KAWIN
PELAJAR/MAHASISWA
WNI
SEUMUR HIDUP
PROVINSI JAWA TENGAH
KABUPATEN BANJARNEGARA
3304042402960900
PUTRI GINTOKI
BANJARNEGARA
24
2
1996
PEREMPUAN
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
UZUMAKI BAGAS
GROBOGAN
12
10
2003
LAKI-LAKI
A
KALIMARO GANG 7
11
10
KALIMARO
KEDUNGJATI
ISLAM
BELUM KAWIN
PELAJAR/MAHASISWA
WNI
SEUMUR HIDUP

*/