#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_TIM 2
#define MAX_KARAKTER 4

struct User {
    string nama = "Inayah Ramadhani";
    string nim = "2409106068";
    int kesempatanLogin = 3;
};

struct Musuh {
    string nama;
    int level;
};

struct Karakter {
    string level;  // Diubah dari index menjadi level
    string nama;
    string elemen;
    string senjata;
};

struct Tim {
    string namaTim;
    string karakter[MAX_KARAKTER];
};

// Fungsi-fungsi sorting
void sortingNamaDescending(Karakter *karakter, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (karakter[j].nama < karakter[j+1].nama) {
                Karakter temp = karakter[j];
                karakter[j] = karakter[j+1];
                karakter[j+1] = temp;
            }
        }
    }
}

void sortingLevelAscending(Karakter *karakter, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (karakter[j].level > karakter[j+1].level) {
                Karakter temp = karakter[j];
                karakter[j] = karakter[j+1];
                karakter[j+1] = temp;
            }
        }
    }
}

void sortingElemenAscending(Karakter *karakter, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (karakter[j].elemen > karakter[j+1].elemen) {
                Karakter temp = karakter[j];
                karakter[j] = karakter[j+1];
                karakter[j+1] = temp;
            }
        }
    }
}

void tampilkanMenu() {
    cout << "========================================" << endl;
    cout << "       Manajemen Tim Spiral Abyss" << endl;
    cout << "========================================" << endl;
    cout << "[1] Lihat Musuh" << endl;
    cout << "[2] Lihat Karakter" << endl;
    cout << "[3] Lihat Tim" << endl;
    cout << "[4] Buat Tim" << endl;
    cout << "[5] Edit Tim" << endl;
    cout << "[6] Hapus Tim" << endl;
    cout << "[7] Logout" << endl;
    cout << "Pilih menu: ";
}

void lihatMusuh(Musuh (*musuh)[4], int chamber, int perChamber) {
    cout << left << setw(10) << "Chamber" << setw(15) << "Half" << setw(50) << "Musuh" << "Level" << endl;
    cout << string(85, '-') << endl;

    for (int i = 0; i < chamber; i++) {
        cout << "Chamber " << i + 1 << endl;
        cout << setw(10) << "" << setw(15) << "First Half";
        cout << setw(50) << (*(musuh+i))[0].nama << (*(musuh+i))[0].level << endl;
        cout << setw(10) << "" << setw(15) << "" << setw(50) << (*(musuh+i))[1].nama << (*(musuh+i))[1].level << endl;

        cout << setw(10) << "" << setw(15) << "Second Half";
        if ((*(musuh+i))[2].nama != "") cout << setw(50) << (*(musuh+i))[2].nama << (*(musuh+i))[2].level << endl;
        if ((*(musuh+i))[3].nama != "") cout << setw(10) << "" << setw(15) << "" << setw(50) << (*(musuh+i))[3].nama << (*(musuh+i))[3].level << endl;

        cout << string(85, '-') << endl;
    }
}

void daftarKarakter(Karakter *karakter, int jumlah) {
    cout << left << setw(5) << "No" << setw(8) << "Level" << setw(20) << "Nama" 
         << setw(12) << "Elemen" << setw(12) << "Senjata" << endl;
    cout << string(57, '-') << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(5) << i+1 << setw(8) << (karakter + i)->level
             << setw(20) << (karakter + i)->nama 
             << setw(12) << (karakter + i)->elemen 
             << setw(12) << (karakter + i)->senjata << endl;
    }
}

void lihatKarakter(Karakter *karakter, int jumlah) {
    cout << "========================================" << endl;
    cout << "             Lihat Karakter" << endl;
    cout << "========================================" << endl;
    cout << "[1] Tampilkan Semua Karakter" << endl;
    cout << "[2] Cari Karakter berdasarkan nama" << endl;
    cout << "[3] Cari Karakter berdasarkan elemen" << endl;
    cout << "[4] Urutkan berdasarkan nama" << endl;
    cout << "[5] Urutkan berdasarkan level" << endl;
    cout << "[6] Urutkan berdasarkan elemen" << endl;
    cout << "Pilihan: ";
    
    string pilihan;
    cin >> pilihan;
    cout << "\n";

    if (pilihan == "1") daftarKarakter(karakter, jumlah);

    else if (pilihan == "2") {
        string namaCari;
        cin.ignore();
        cout << "Masukkan nama karakter: ";
        getline(cin, namaCari);

        int ditemukan = 0;
        for (int i = 0; i < jumlah; i++) {
            if ((karakter + i)->nama == namaCari) {
                cout << "Karakter Ditemukan:\n";
                cout << string(40, '-') << endl;
                cout << "Nama   : " << (karakter + i)->nama << "\n";
                cout << "Level  : " << (karakter + i)->level << "\n";
                cout << "Elemen : " << (karakter + i)->elemen << "\n";
                cout << "Senjata: " << (karakter + i)->senjata << "\n";
                ditemukan = 1;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Karakter dengan nama '" << namaCari << "' tidak ditemukan." << endl;
        }
    }    
    else if (pilihan == "3") {
        string elemenCari;
        cout << "Masukkan elemen yang dicari: ";
        cin >> elemenCari;

        int ditemukan = 0;
        cout << "Karakter dengan elemen " << elemenCari << ":\n";
        cout << left << setw(5) << "No" << setw(8) << "Level" << setw(20) << "Nama" 
             << setw(12) << "Elemen" << setw(12) << "Senjata" << endl;
        cout << string(57, '-') << endl;
        
        int count = 1;
        for (int i = 0; i < jumlah; i++) {
            if ((karakter + i)->elemen == elemenCari) {
                cout << left << setw(5) << count++ << setw(8) << (karakter + i)->level
                     << setw(20) << (karakter + i)->nama
                     << setw(12) << (karakter + i)->elemen
                     << setw(12) << (karakter + i)->senjata << endl;
                ditemukan = 1;
            }
        }

        if (!ditemukan) {
            cout << "Tidak ada karakter dengan elemen " << elemenCari << endl;
        }
    }
    else if (pilihan == "4") {
        Karakter karakterSort[jumlah];
        for (int i = 0; i < jumlah; i++) {
            karakterSort[i] = karakter[i];
        }
        
        sortingNamaDescending(karakterSort, jumlah);
        cout << "Urutan karakter berdasarkan Nama (Descending):\n";
        daftarKarakter(karakterSort, jumlah);
    }
    else if (pilihan == "5") {
        Karakter karakterSort[jumlah];
        for (int i = 0; i < jumlah; i++) {
            karakterSort[i] = karakter[i];
        }
        
        sortingLevelAscending(karakterSort, jumlah);
        cout << "Urutan karakter berdasarkan Level (Ascending):\n";
        daftarKarakter(karakterSort, jumlah);
    }
    else if (pilihan == "6") {
        Karakter karakterSort[jumlah];
        for (int i = 0; i < jumlah; i++) {
            karakterSort[i] = karakter[i];
        }
        
        sortingElemenAscending(karakterSort, jumlah);
        cout << "Urutan karakter berdasarkan Elemen (Ascending):\n";
        daftarKarakter(karakterSort, jumlah);
    }
    else {
        cout << "Pilihan tidak valid." << endl;
    }    
}

void lihatTim(Tim *tim, int jumlahTim) {
    cout << "========================================" << endl;
    cout << "               Lihat Tim" << endl;
    cout << "========================================" << endl;
    int adaTim = 0;
    for (int i = 0; i < jumlahTim; i++) {
        if ((tim + i)->namaTim != "") {
            adaTim = 1;
            cout << "Tim " << (tim + i)->namaTim << ": ";
            for (int j = 0; j < MAX_KARAKTER; j++) {
                if ((tim + i)->karakter[j] != "") cout << (tim + i)->karakter[j] << " ";
            }
            cout << endl;
        }
    }
    if (adaTim == 0) cout << "Belum ada tim yang dibuat.\n";
}

void buatTim(Tim *tim, int jumlahTim, Karakter *karakter, int jumlahKarakter) {
    cout << "========================================" << endl;
    cout << "               Buat Tim" << endl;
    cout << "========================================" << endl;
    int timIndex = -1;
    for (int i = 0; i < jumlahTim; i++) {
        if ((tim + i)->namaTim == "") {
            timIndex = i;
            break;
        }
    }
    if (timIndex == -1) {
        cout << "Sudah ada " << jumlahTim << " tim, tidak bisa menambah lagi.\n";
    } else {
        cout << "Masukkan nama tim: ";
        getline(cin, (tim + timIndex)->namaTim);
        cout << "\nDaftar Karakter:\n";
        daftarKarakter(karakter, jumlahKarakter);
        cout << "\nMasukkan nomor " << MAX_KARAKTER << " karakter yang ingin dipilih:\n";
        for (int j = 0; j < MAX_KARAKTER; j++) {
            int pilihIndex;
            cout << "Karakter " << j + 1 << ": ";
            cin >> pilihIndex;
            if (pilihIndex >= 1 && pilihIndex <= jumlahKarakter) {
                (tim + timIndex)->karakter[j] = (karakter + pilihIndex - 1)->nama;
            } else {
                cout << "Nomor tidak valid.\n";
                j--;
            }
        }
        cout << "Tim " << (tim + timIndex)->namaTim << " berhasil dibuat!\n";
    }
}

void editTim(Tim *tim, int jumlahTim, Karakter *karakter, int jumlahKarakter) {
    cout << "========================================" << endl;
    cout << "                Edit Tim" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < jumlahTim; i++) {
        if ((tim + i)->namaTim != "") cout << i + 1 << ". " << (tim + i)->namaTim << endl;
    }
    int pilihTim;
    cout << "Pilih tim yang ingin diubah: ";
    cin >> pilihTim;
    if (pilihTim >= 1 && pilihTim <= jumlahTim && (tim + pilihTim - 1)->namaTim != "") {
        cin.ignore();
        cout << "\nMasukkan nama baru untuk tim: ";
        getline(cin, (tim + pilihTim - 1)->namaTim);
        cout << "Daftar Karakter:\n";
        daftarKarakter(karakter, jumlahKarakter);

        for (int j = 0; j < MAX_KARAKTER; j++) {
            int pilihKarakter;
            cout << "Karakter " << j + 1 << ": ";
            cin >> pilihKarakter;
            if (pilihKarakter >= 1 && pilihKarakter <= jumlahKarakter) {
                (tim + pilihTim - 1)->karakter[j] = (karakter + pilihKarakter - 1)->nama;
            } else {
                cout << "Nomor tidak valid.\n";
                j--;
            }
        }
        cout << "Tim berhasil diubah!\n";
    } else {
        cout << "Pilihan tim tidak valid.\n";
    }
}

void hapusTim(Tim *tim, int jumlahTim) {
    cout << "========================================" << endl;
    cout << "              Hapus Tim" << endl;
    cout << "========================================" << endl;
    for (int i = 0; i < jumlahTim; i++) {
        if ((tim + i)->namaTim != "") cout << i + 1 << ". " << (tim + i)->namaTim << endl;
    }
    int pilihTim;
    cout << "Pilih tim yang ingin dihapus: ";
    cin >> pilihTim;
    if (pilihTim >= 1 && pilihTim <= jumlahTim && (tim + pilihTim - 1)->namaTim != "") {
        for (int i = pilihTim - 1; i < jumlahTim - 1; i++) {
            *(tim + i) = *(tim + i + 1);
        }
        (tim + jumlahTim - 1)->namaTim = "";
        for (int j = 0; j < MAX_KARAKTER; j++) {
            (tim + jumlahTim - 1)->karakter[j] = "";
        }
        cout << "Tim berhasil dihapus!" << endl;
    } else {
        cout << "Pilihan tim tidak valid" << endl;
    }
}

int hitungTotalKarakter(Tim *tim, int idx) {
    if (idx < 0) return 0;
    int jumlah = 0;
    for (int i = 0; i < MAX_KARAKTER; i++) {
        if ((tim + idx)->karakter[i] != "") jumlah++;
    }
    return jumlah + hitungTotalKarakter(tim, idx - 1);
}

int main() {
    User user;
    string inputNama, inputNim, pilihan;

    Musuh musuh[3][4] = {
        {{"Gluttonous Yumkasaur Mountain King", 95}, {"Yumkasaur", 95}, {"Wayward Hermetic Spiritspeaker", 95}, {"Iktomisaurus", 95}},
        {{"Solitary Suanni", 98}, {"Xuanwen Beast", 98}, {"Tenebrous Mimesis - Ruin Guard", 98}, {"Tenebrous Mimesis - Secret Source Automaton", 98}},
        {{"Biting-Cold Wayob Manifestation", 100}, {"Construction Specialist Mek - Pneuma", 100}, {"Tenebrous Papila: Type III", 100}, {"", 0}}
    };

    Karakter karakter[8] = {
        {"90", "Arlecchino", "Pyro", "Polearm"},
        {"87", "Furina", "Hydro", "Sword"},
        {"80", "Ororon", "Electro", "Bow"},
        {"90", "Yelan", "Hydro", "Bow"},
        {"85", "Xingqiu", "Hydro", "Sword"},
        {"88", "Chasca", "Anemo", "Bow"},
        {"81", "Bennett", "Pyro", "Sword"},
        {"70", "Xiangling", "Pyro", "Polearm"}
    };

    Tim tim[MAX_TIM];
    for (int i = 0; i < MAX_TIM; i++) {
        tim[i].namaTim = "";
        for (int j = 0; j < MAX_KARAKTER; j++) {
            tim[i].karakter[j] = "";
        }
    }

    // Login
    system("cls");
    cout << "========================================" << endl;
    cout << "             Selamat Datang" << endl;
    cout << "             Silahkan Login" << endl;
    cout << "========================================" << endl;
    for (int percobaan = 0; percobaan < user.kesempatanLogin; percobaan++) {
        cout << "Nama\t: ";
        getline(cin, inputNama);
        cout << "NIM\t: ";
        cin >> inputNim;
        cin.ignore();

        if (inputNama == user.nama && inputNim == user.nim) {
            cout << "Berhasil login!\nTekan Enter untuk masuk ke menu utama";
            cin.get();
            system("cls");
            break;
        } else {
            cout << "Nama atau NIM yang Anda masukkan salah." << endl;
            cout << "Percobaan tersisa " << (user.kesempatanLogin - percobaan - 1) << " kali.\n" << endl;
        }

        if (percobaan == user.kesempatanLogin - 1) {
            cout << "Anda telah salah memasukkan Nama atau NIM 3 kali." << endl;
            cout << "Program telah berhenti." << endl;
            return 0;
        }
    }

    // Menu utama
    while (true) {
        string pilihanMenu;

        tampilkanMenu();
        cin >> pilihanMenu;
        cout << "Tekan Enter untuk lanjut";
        cin.get();
        cin.ignore();
        system("cls");

        if (pilihanMenu == "1") lihatMusuh(musuh, 3, 4);
        else if (pilihanMenu == "2") lihatKarakter(karakter, 8);
        else if (pilihanMenu == "3") lihatTim(tim, MAX_TIM);
        else if (pilihanMenu == "4") buatTim(tim, MAX_TIM, karakter, 8);
        else if (pilihanMenu == "5") editTim(tim, MAX_TIM, karakter, 8);
        else if (pilihanMenu == "6") hapusTim(tim, MAX_TIM);
        else if (pilihanMenu == "7") {
            int total = hitungTotalKarakter(tim, MAX_TIM - 1);
            cout << "Total karakter yang telah digunakan: " << total << endl;
            cout << "Logout berhasil.";
            return 0;
        } else cout << "Pilihan tidak valid." << endl;
        cout << "Tekan Enter untuk lanjut";
        cin.get();
        cin.ignore();
        system("cls");
    }
    return 0;
}