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

class Ktp {
    public:
        Ktp(){ head = NULL; };
        void inputDepan();
        void inputBelakang();
        void inputTengah(int);
        void hapusBelakang();
        void output();
    private:
        data_ktp *head, *tail;
};

int center(int n, int m){
    return (n-m)/2 + m;
}

void Ktp::inputDepan(){
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
    if(head == NULL){
        head = tail = curr;
    } else {
        curr->next = head;
        head->prev = curr;
        head = curr;
    }
    head->prev = NULL;
    tail->next = NULL;
}
void Ktp::inputBelakang(){
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
    if(head == NULL){
        head = tail = curr;
    } else {
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }
    head->prev = NULL;
    tail->next = NULL;
}
void Ktp::inputTengah(int y){
    data_ktp *curr = new data_ktp;
    data_ktp *baru = new data_ktp;
    int i = 1;
    curr = head;
    while(curr != NULL){
        curr = curr->next;
        i++;
    }
    if(y > i){
        cout << "\n=== Indeks melewati batas data yang ada\n\n";
        return;
    }
    if(head==NULL) {
		cout << "\n=== DATA KOSONG ==\n\n";
        return;
    }

    cout << "Masukkan Data Diri Anda\n";
    cout << "Mohon isikan dengan huruf kapital.\n";
    cout << "Masukkan Asal Provinsi\t : ";
    getline(cin, baru->provinsi);
    cout << "Masukkan Asal Kab/Kota\t : ";
    getline(cin, baru->kab);
	cout << "Masukkan NIK\t\t : ";
    cin >> baru->nik;
    cin.ignore();
	cout << "Masukkan Nama\t\t : "; 
    getline(cin, baru->nama);
	cout << "Masukkan Tempat Lahir\t : ";
    cin >> baru->tempatL; 
	cout << "Masukkan Tanggal Lahir\t : ";
    cin >> baru->tanggalL;
	cout << "Masukkan Bulan Lahir\t : ";
    cin >> baru->bulanL;
	cout << "Masukkan Tahun Lahir\t : ";
    cin >> baru->tahunL;
    cin.ignore();
	cout << "Masukkan Jenis Kelamin\t : ";
    getline(cin, baru->jk);
	cout << "Masukkan Golongan Darah\t : ";  
    cin >> baru->goldar;
    cin.ignore();
	cout << "Masukkan Alamat\t\t : "; 
    getline(cin, baru->alamat);
	cout << "Masukkan RT \t\t : ";
    cin >> baru->rt;
    cout << "Masukkan RW \t\t : ";
    cin >> baru->rw;
    cin.ignore();
	cout << "Masukkan Kel/Desa\t : ";  
    getline(cin, baru->desa);
    cout << "Masukkan Kecamatan\t : ";  
    getline(cin, baru->kec);
    cout << "Masukkan Agama\t\t : ";  
    getline(cin, baru->agama);
    cout << "Masukkan Status Kawin\t : ";  
    getline(cin, baru->status);
    cout << "Masukkan Pekerjaan\t : ";  
    getline(cin, baru->kerja);
    cout << "Masukkan Kewarganegaraan : ";  
    getline(cin, baru->kewarganegaraan);
    cout << "Masukkan Masa Berlaku\t : ";  
    getline(cin, baru->masa);
    cout << "\n=== DATA TERSIMPAN ===\n\n";
    baru->next = NULL;
    baru->prev = NULL;
    
    curr = head;
    i = 1;
    while(i != y){
        curr=curr->next;
        i++;
    }

    baru->next = curr->next;
    baru->prev = curr;
    curr->next->prev = baru;
    curr->next = baru;
    
}
void Ktp::hapusBelakang(){
    data_ktp *hapus = new data_ktp;
    data_ktp *curr = new data_ktp;

    if(head==NULL)
		cout << "\n=== DATA KOSONG ==\n\n";
    else{
        curr = head;
        while(curr->next->next != NULL)
            curr=curr->next;
        hapus = curr->next;
        curr->next = NULL;
        hapus->prev = NULL;
        delete hapus;
    }
}
// Fungsi untuk mengoutputkan linked list
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
    int i, noData;
    Ktp m;
    while(true){
        cout << "++====================++\n";
        cout << "||      MENU KTP      ||\n";
        cout << "++====================++\n";
        cout << "  1. Input Depan" << endl;
        cout << "  2. Input Belakang" << endl;
        cout << "  3. Input Tengah" << endl;
        cout << "  4. Hapus Data Terakhir" << endl;
        cout << "  5. Tampilkan data" << endl;
        cout << "  6. Keluar dari program" << endl;

        cout << "=== Masukkan pilihan : ";
        cin >> i; cin.ignore();
        if (i == 1){
            m.inputDepan();
        } else if (i == 2){
            m.inputBelakang();
        } else if (i == 3){
            cout << "Ingin memasukkan data setelah urutan ke berapa : ";
            cin >> noData; cin.ignore();
            m.inputTengah(noData);
        } else if (i == 4){
            m.hapusBelakang();
        } else if (i == 5){
            m.output();
        } else if (i == 6){
            return 0;
        } else {
            cout << "Masukkan pilihan yang sesuai.\n\n";
        }
    }
    return 0;
}

/*
"00":"Met Tidur","01":"Met Tidur","02":"Met Tidur","03":"Selamat Pagi","04":"Selamat Pagi","05":"Selamat Pagi","06":"Selamat Pagi","07":"Selamat Pagi","08":"Selamat Pagi","09":"Selamat Pagi","10":"Selamat Pagi","11":"Selamat Pagi","12":"Selamat Siang","13":"Selamat Siang","14":"Selamat Siang","15":"Selamat Siang","16":"Selamat Sore","17":"Selamat Sore","18":"Selamat Sore","19":"Selamat Malam","20":"Selamat Malam","21":"Met Tidur","22":"Met Tidur","23":"Met Tidur"

WishReminder="00":"Waktunya tidur bro.","01":"Waktunya tidur bro.","02":"Waktunya tidur bro.","03":"It's time for bed.I wish you nice dreams.","04":"It's time for bed.I wish you nice dreams.","05":"It's time for bed.I wish you nice dreams.","06":"It's time for bed.I wish you nice dreams.","07":"I hope you slept well.","08":"I hope you slept well.","09":"I hope you slept well.","10":"I hope you slept well.","11":"I hope you slept well.","12":"I wish you a nice and enjoyable day.","13":"I wish you a nice and enjoyable day.","14":"I wish you a nice and enjoyable day.","15":"I wish you a nice and enjoyable day.","16":"I wish you a nice and enjoyable day.","17":"I wish you a nice and enjoyable day.","18":"I wish you a pleasant evening.","19":"I wish you a pleasant evening.","20":"I wish you a pleasant evening.","21":"Waktunya tidur bro.","22":"Waktunya tidur bro.","23":"Waktunya tidur bro."
*/