#include <iostream>
#include <iomanip>
using namespace std;

struct data_ktp{
    string provinsi, kab;
    string nik, nama, tempatL, jk, goldar, alamat, desa, kec, agama, status, kerja, kewarganegaraan, masa;
    int rt, rw, tanggalL, bulanL, tahunL;
    data_ktp* next = NULL;
    data_ktp* prev;
};

// Kelas KTP Queue
class KtpQueue {
    public:
        KtpQueue(){ depan = belakang = NULL; };
        void enQueue();         // input belakang (data mengantre ke belakang seperti pada antrean)
        data_ktp* deQueue();    // hapus depan (menghapus data yg lebih dahulu dimasukkan seperti pada antrean)
        void output();
    private:
        data_ktp *depan, *belakang;
};

// fungsi untuk memberikan hasil center pada penulisan provinsi dan kab. pada ktp
int center(int n, int m){
    return (n-m)/2 + m;
}

// fungsi untuk memasukkan data dari belakang, seperti pada antrean
void KtpQueue::enQueue(){
    data_ktp *curr = new data_ktp;
    cout << "Masukkan Data Diri Anda\n";
    cout << "Mohon isikan dengan huruf kapital.\n";
    cout << "Masukkan Asal Provinsi\t : ";
    getline(cin, curr->provinsi);
    cout << "Masukkan Asal Kab/Kota\t : ";
    getline(cin, curr->kab);
	cout << "Masukkan NIK\t\t : ";
    cin >> curr->nik;
    cin.ignore();
	cout << "Masukkan Nama\t\t : "; 
    getline(cin, curr->nama);
	cout << "Masukkan Tempat Lahir\t : ";
    cin >> curr->tempatL; 
	cout << "Masukkan Tanggal Lahir\t : ";
    cin >> curr->tanggalL;
	cout << "Masukkan Bulan Lahir\t : ";
    cin >> curr->bulanL;
	cout << "Masukkan Tahun Lahir\t : ";
    cin >> curr->tahunL;
    cin.ignore();
	cout << "Masukkan Jenis Kelamin\t : ";
    getline(cin, curr->jk);
	cout << "Masukkan Golongan Darah\t : ";  
    cin >> curr->goldar;
    cin.ignore();
	cout << "Masukkan Alamat\t\t : "; 
    getline(cin, curr->alamat);
	cout << "Masukkan RT \t\t : ";
    cin >> curr->rt;
    cout << "Masukkan RW \t\t : ";
    cin >> curr->rw;
    cin.ignore();
	cout << "Masukkan Kel/Desa\t : ";  
    getline(cin, curr->desa);
    cout << "Masukkan Kecamatan\t : ";  
    getline(cin, curr->kec);
    cout << "Masukkan Agama\t\t : ";  
    getline(cin, curr->agama);
    cout << "Masukkan Status Kawin\t : ";  
    getline(cin, curr->status);
    cout << "Masukkan Pekerjaan\t : ";  
    getline(cin, curr->kerja);
    cout << "Masukkan Kewarganegaraan : ";  
    getline(cin, curr->kewarganegaraan);
    cout << "Masukkan Masa Berlaku\t : ";  
    getline(cin, curr->masa);
    cout << "\n=== DATA TERSIMPAN ===\n\n";
    if(depan == NULL){
        depan = belakang = curr;
    } else {
        curr->prev = belakang;
        belakang->next = curr;
        belakang = curr;
    }
    depan->prev = NULL;
    belakang->next = NULL;
}

// fungsi untuk menghapus data dari depan, seperti pada antrean, lalu memberikan nilai return data yg dihapus
data_ktp* KtpQueue::deQueue(){
    data_ktp *hapus = new data_ktp;

    if(depan==NULL){
		cout << "\n=== DATA KOSONG ==\n\n";
        hapus = depan;
    } else {
        if(depan == belakang){
            hapus = depan;
            depan = NULL;
        } else {
            hapus = depan;
            depan = depan->next;
            depan->prev = NULL;
        }
    }
    return hapus;
}

// Fungsi untuk mengoutputkan linked list Queue
void KtpQueue::output(){
    data_ktp* temp = depan;
    int lebar = 70, dataKe = 1;
    int pjgp, pjgk;

	// mengecek kalau list kosong.
	if (depan == NULL) {
		cout << "\n=== DATA KOSONG ==\n\n";
		return;
	}

	// outputkan list dari awal (depan) sampai akhir.
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
    int i, noData;
    KtpQueue m;
    while(true){
        cout << "++====================++\n";
        cout << "||      MENU KTP      ||\n";
        cout << "++====================++\n";
        cout << "  1. EnQueue" << endl;
        cout << "  2. DeQueue" << endl;
        cout << "  3. Tampilkan data" << endl;
        cout << "  4. Keluar dari program" << endl;

        cout << "=== Masukkan pilihan : ";
        cin >> i; cin.ignore();
        if (i == 1){
            m.enQueue();
        } else if (i == 2){
            data_ktp * deQueued = m.deQueue();
            if (deQueued != NULL){
                int pjgp = deQueued->provinsi.size();
                int pjgk = deQueued->kab.size();
                cout << "\n=== DATA YANG DIHAPUS ===\n";
                cout << "++======================================================================++" << endl; 
                cout << "||" << setw(center(70, pjgp)) << setfill(' ');
                cout << deQueued->provinsi << setw(72-center(70, pjgp)) << setfill(' ') << "||" << endl;
                cout << "||" << setw(center(70, pjgk)) << setfill(' ');
                cout << deQueued->kab << setw(72-center(70, pjgk)) << setfill(' ') << "||" << endl;
                cout << "++======================================================================++" << endl;
                cout << "|| NIK\t\t\t : " << deQueued->nik << "\t\t\t\t||" << endl;
                cout << "|| Nama\t\t\t : " << deQueued->nama << setw(47-deQueued->nama.size()) << setfill(' ') << "||" << endl;
                cout << "|| deQueuedat/Tgl Lahir\t : " << deQueued->tempatL << ", ";
                cout << setfill('0') << setw(2) << deQueued->tanggalL << "-";
                cout << setfill('0') << setw(2) << deQueued->bulanL << "-" << deQueued->tahunL;
                cout << setw(35-deQueued->tempatL.size()) << setfill(' ') << "||" << endl;
                cout << "|| Jenis Kelamin\t : " << deQueued->jk << "\t  Gol. Darah    : " << deQueued->goldar << "\t\t||" << endl;
                cout << "|| Alamat\t\t : " << deQueued->alamat << setw(47-deQueued->alamat.size()) << setfill(' ') << "||" << endl;
                cout << "||\tRT/RW\t\t : ";
                cout << setfill('0') << setw(3) << deQueued->rt << "/";
                cout << setfill('0') << setw(3) << deQueued->rw << "\t\t\t\t\t||" << endl;
                cout << "||\tKel/Desa\t : " << deQueued->desa << "\t\t\t\t\t||" << endl;
                cout << "||\tKecamatan\t : " << deQueued->kec << "\t\t\t\t\t||" << endl;
                cout << "|| Agama\t\t : " << deQueued->agama << "\t\t\t\t\t||" << endl;
                cout << "|| Status Perkawinan\t : " << deQueued->status << "\t\t\t\t\t||" << endl;
                cout << "|| Pekerjaan\t\t : " << deQueued->kerja << "\t\t\t\t||" << endl;
                cout << "|| Kewarganegaraan\t : " << deQueued->kewarganegaraan << "\t\t\t\t\t\t||" << endl;
                cout << "|| Berlaku Hingga\t : " << deQueued->masa << "\t\t\t\t\t||" << endl;
                cout << "++======================================================================++" << endl << endl;
            }
        } else if (i == 3){
            m.output();
        } else if (i == 4){
            return 0;
        } else {
            cout << "Masukkan pilihan yang sesuai.\n\n";
        }
    }
    return 0;
}
