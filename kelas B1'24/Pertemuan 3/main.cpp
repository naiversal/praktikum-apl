#include <iostream>
using namespace std;

struct Alamat {
    string jalan;
    // int nomor;
    string kota;

};

struct Mahasiswa {
    string nama;
    string nim;
    // string prodi;
    float ipk;
    // int angkatan;
    Alamat alamat;
};

#define MAX_MAHASISWA 5

int main() {
    int panjang = 0;
    Mahasiswa mhs[MAX_MAHASISWA];
    int pilihan;
    
    do {
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        if (panjang = 0)
            cout << "Blm ad data" << endl;
        else {
            cout << "Data mahasiswa" << endl;
            for (int i= 0; i < panjang; i++) {
                cout << "Nama\t\t: " << mhs[i].nama << endl;
                cout << "NIM\t\t: " << mhs[i].nim << endl;
                cout << "Ipk\t\t: " << mhs[i].ipk << endl;
                cout << "Jalan\t\t: " << mhs[i].alamat.jalan << endl;
                cout << "Nama kota\t: " << mhs[i].alamat.kota << endl;
                cout << "\n" << endl;
            }
        }
            break;
        case 2:
            if (panjang = MAX_MAHASISWA) {
                cout << "Masukkan nama: " << endl;
                getline(cin,mhs[panjang].nama);

                cout << "Masukkan NIM: " << endl;
                getline(cin,mhs[panjang].nim);

                cout << "Masukkan ipk: " << endl;
                cin >> mhs[panjang].ipk;

                cout << "Masukkan nama jalan: " << endl;
                getline(cin,mhs[panjang].alamat.jalan);

                cout << "Masukkan nama kota: " << endl;
                getline(cin,mhs[panjang].alamat.kota);

                panjang++;
                cout << "Mahasiswa berhasil ditambahkan" << endl;

            }
            break;
        case 3:
            break;
        case 4:
            for (int i=0; i < panjang; i++) {
                cout << "Nama\t: " << mhs[i].nama << endl;
            }
            
            int index;
            cout << "Masukkan nomor mahasiswa yang ingin dihapus" << endl;
            cin >> index;

            for (int i = 0; i < panjang -1; i++){
                mhs[i] = mhs[i + 1];
            }

            panjang--;


            break;
        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}
    // }

    // Mahasiswa mhs[5];

    // mhs[0].nama = "Nayo";
    // mhs[0].nim = "068";
    // mhs[0].prodi = "Informatika";
    // mhs[0].ipk = 4.1;
    // mhs[0].angkatan = 2024;
    // mhs[0].alamat.jalan = "M. said";
    // mhs[0].alamat.nomor = 38;
    // mhs[0].alamat.kota = "Samarinda";

    // mhs[1].nama = "Noya";
    // mhs[1].nim = "086";
    // mhs[1].prodi = "Sistem Informasi";
    // mhs[1].ipk = 4.2;
    // mhs[1].angkatan = 2024;
    // mhs[1].alamat.jalan = "M. said";
    // mhs[1].alamat.nomor = 38;
    // mhs[1].alamat.kota = "Samarinda";

    // for (int i = 0; i < 2; i++)
    // {
    // cout << "Nama\t\t: " << mhs[i].nama << endl;
    // cout << "NIM\t\t: " << mhs[i].nim << endl;
    // cout << "Prodi\t\t: " << mhs[i].prodi << endl;
    // cout << "Ipk\t\t: " << mhs[i].ipk << endl;
    // cout << "Angkatan\t: " << mhs[i].angkatan << endl;
    // cout << "Jalan\t\t: " << mhs[i].alamat.jalan << endl;
    // cout << "No. rumah\t: " << mhs[i].alamat.nomor << endl;
    // cout << "Nama kota\t: " << mhs[i].alamat.kota << endl;
    // cout << "\n" << endl;
    // }
    // cout << "Nama\t: " << mhs2.nama << endl;
    // cout << "NIM\t: " << mhs2.nim << endl;
    // cout << "Prodi\t: " << mhs2.prodi << endl;
    // cout << "Ipk\t: " << mhs2.ipk << endl;
    // cout << "Angkatan\t: " << mhs2.angkatan << endl;

    // return 0;
// }