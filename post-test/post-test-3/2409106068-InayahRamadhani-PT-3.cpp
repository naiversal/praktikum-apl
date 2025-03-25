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
    string index;
    string nama;
    string elemen;
    string senjata;
};

struct Tim {
    string namaTim;
    string karakter[MAX_KARAKTER];
};

int main() {
    User user;
    string inputNama, inputNim, pilihan;

    // Data musuh
    Musuh musuh[3][4] = {
        {
            {"Gluttonous Yumkasaur Mountain King", 95},
            {"Yumkasaur", 95},
            {"Wayward Hermetic Spiritspeaker", 95},
            {"Iktomisaurus", 95}
        },
        {
            {"Solitary Suanni", 98},
            {"Xuanwen Beast", 98},
            {"Tenebrous Mimesis - Ruin Guard", 98},
            {"Tenebrous Mimesis - Secret Source Automaton", 98}
        },
        {
            {"Biting-Cold Wayob Manifestation", 100},
            {"Construction Specialist Mek - Pneuma", 100},
            {"Tenebrous Papila: Type III", 100},
            {"", 0}
        }
    };

    // Data karakter
    Karakter karakter[8] = {
        {"1", "Arlecchino", "Pyro", "Polearm"},
        {"2", "Furina", "Hydro", "Sword"},
        {"3", "Ororon", "Electro", "Bow"},
        {"4", "Yelan", "Hydro", "Bow"},
        {"5", "Xingqiu", "Hydro", "Sword"},
        {"6", "Chasca", "Anemo", "Bow"},
        {"7", "Bennett", "Pyro", "Sword"},
        {"8", "Xiangling", "Pyro", "Polearm"}
    };

    // Data tim
    Tim tim[MAX_TIM];
    for (int i = 0; i < MAX_TIM; i++) {
        tim[i].namaTim = "";
        for (int j = 0; j < MAX_KARAKTER; j++) {
            tim[i].karakter[j] = "";
        }
    }

    // Fitur Login
    cout << "==========================" << endl;
    cout << "      Selamat Datang" << endl;
    cout << "      Silahkan Login" << endl;
    cout << "==========================" << endl;

    for (int percobaan = 0; percobaan < user.kesempatanLogin; percobaan++) {
        cout << "Nama: ";
        getline(cin, inputNama);

        cout << "NIM: ";
        cin >> inputNim;

        if (inputNama == user.nama && inputNim == user.nim) {
            cout << "Berhasil login!" << endl;
            cout << "\n";
            cout << "Tekan Enter untuk masuk ke menu utama";
            cin.ignore();
            cin.get();
            system("clear");
            break;
        } else {
            cout << "Nama atau NIM yang Anda masukkan salah." << endl;
            cout << "Percobaan tersisa " << (user.kesempatanLogin - 1 - percobaan) << " kali." << endl;
            cin.ignore();
        }

        if (percobaan == user.kesempatanLogin - 1) {
            cout << "Anda telah salah memasukkan Nama atau NIM 3 kali." << endl;
            cout << "Program telah berhenti." << endl;
            return 0;
        }
    }

    // Menu utama
    while (true) {
        cout << "====================================" << endl;
        cout << "     Manajemen Tim Spiral Abyss" << endl;
        cout << "====================================" << endl;
        cout << "[1] Lihat Musuh" << endl;
        cout << "[2] Lihat Karakter" << endl;
        cout << "[3] Lihat Tim" << endl;
        cout << "[4] Buat Tim" << endl;
        cout << "[5] Edit Tim" << endl;
        cout << "[6] Hapus Tim" << endl;
        cout << "[7] Logout" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << "Tekan Enter untuk lanjut";
        cin.get();
        cin.ignore();
        system("clear");

        // Lihat musuh
        if (pilihan == "1") {
            cout << left << setw(10) << "Chamber" << setw(15) << "Half"
                 << setw(50) << "Musuh" << "Level" << endl;
            cout << string(85, '-') << endl;

            for (int i = 0; i < 3; i++) {
                cout << "Chamber " << i + 1 << endl;

                cout << setw(10) << "" << setw(15) << "First Half";
                cout << setw(50) << musuh[i][0].nama << musuh[i][0].level << endl;
                cout << setw(10) << "" << setw(15) << "" << setw(50) << musuh[i][1].nama << musuh[i][1].level << endl;

                cout << setw(10) << "" << setw(15) << "Second Half";
                if (musuh[i][2].nama != "") {
                    cout << setw(50) << musuh[i][2].nama << musuh[i][2].level << endl;
                }
                if (musuh[i][3].nama != "") {
                    cout << setw(10) << "" << setw(15) << "" << setw(50) << musuh[i][3].nama << musuh[i][3].level << endl;
                }
                cout << string(85, '-') << endl;
            }
            cout << "Tekan Enter untuk lanjut";
            cin.get();
            system("clear");
        }

        // Lihat karakter
        else if (pilihan == "2") {
            cout << left << setw(5) << "No" << setw(15) << "Nama"
                 << setw(10) << "Elemen" << setw(10) << "Senjata" << endl;
            cout << string(40, '-') << endl;

            for (int i = 0; i < 8; i++) {
                cout << left << setw(5) << karakter[i].index << setw(15) << karakter[i].nama
                     << setw(10) << karakter[i].elemen << setw(10) << karakter[i].senjata << endl;
            }
            cout << "\n";
            cout << "Tekan Enter untuk lanjut";
            cin.get();
            system("clear");
        }

        // Lihat tim
        else if (pilihan == "3") {
            if (tim[0].namaTim == "" && tim[1].namaTim == "") {
                cout << "Belum ada tim yang dibuat." << endl;
                cout << "\n";
            } else {
                for (int i = 0; i < MAX_TIM; i++) {
                    if (tim[i].namaTim != "") {
                        cout << "Tim " << tim[i].namaTim << ": ";
                        for (int j = 0; j < MAX_KARAKTER; j++) {
                            if (tim[i].karakter[j] != "") {
                                cout << tim[i].karakter[j] << " ";
                            }
                        }
                        cout << "\n";
                    }
                }
            }
            cout << "Tekan Enter untuk lanjut";
            cin.ignore();
            cin.get();
            system("clear"); 
        }

        // Buat tim
        else if (pilihan == "4") {
            int timIndex = -1;
            for (int i = 0; i < MAX_TIM; i++) {
                if (tim[i].namaTim == "") {
                    timIndex = i;
                    break;
                }
            }
            
            if (timIndex == -1) {
                cout << "Sudah ada " << MAX_TIM << " tim, tidak bisa menambah lagi." << endl;
            } else {
                cout << "Masukkan nama tim: ";
                getline(cin, tim[timIndex].namaTim);

                cout << "\nDaftar Karakter :" << endl;
                cout << left << setw(5) << "No" << setw(15) << "Nama"
                    << setw(10) << "Elemen" << setw(10) << "Senjata" << endl;
                cout << string(40, '-') << endl;

                for (int i = 0; i < 8; i++) {
                    cout << left << setw(5) << karakter[i].index << setw(15) << karakter[i].nama
                        << setw(10) << karakter[i].elemen << setw(10) << karakter[i].senjata << endl;
                }

                cout << "\nMasukkan nomor " << MAX_KARAKTER << " karakter yang ingin dipilih:" << endl;
                for (int j = 0; j < MAX_KARAKTER; j++) {
                    int pilihIndex;
                    cout << "Karakter " << j + 1 << ": ";
                    cin >> pilihIndex;
                    if (pilihIndex >= 1 && pilihIndex <= 8) {
                        tim[timIndex].karakter[j] = karakter[pilihIndex - 1].nama;
                    } else {
                        cout << "Nomor karakter tidak valid (1-8)." << endl;
                        j--;
                    }
                }
                cout << "Tim " << tim[timIndex].namaTim << " berhasil dibuat!" << endl;
            }
            cout << "Tekan Enter untuk lanjut";
            cin.ignore();
            cin.get();
            system("clear");
        }

        // Edit tim
        else if (pilihan == "5") {
            int pilihTim;
            for (int i = 0; i < MAX_TIM; i++) {
                if (tim[i].namaTim != "") {
                    cout << i + 1 << ". " << tim[i].namaTim << endl;
                }
            }
            cout << "Pilih tim yang ingin diubah: ";
            cin >> pilihTim;

            if (pilihTim >= 1 && pilihTim <= MAX_TIM && tim[pilihTim - 1].namaTim != "") {
                cout << "Masukkan nama baru untuk tim: ";
                cin.ignore();
                getline(cin, tim[pilihTim - 1].namaTim);

                cout << "Daftar Karakter: " << endl;
                cout << left << setw(5) << "No" << setw(15) << "Nama"
                    << setw(10) << "Elemen" << setw(10) << "Senjata" << endl;
                cout << string(40, '-') << endl;

                for (int i = 0; i < 8; i++) {
                    cout << left << setw(5) << karakter[i].index << setw(15) << karakter[i].nama
                        << setw(10) << karakter[i].elemen << setw(10) << karakter[i].senjata << endl;
                }

                for (int j = 0; j < MAX_KARAKTER; j++) {
                    int pilihKarakter;
                    cout << "Karakter " << j + 1 << ": ";
                    cin >> pilihKarakter;

                    if (pilihKarakter >= 1 && pilihKarakter <= 8) {
                        tim[pilihTim - 1].karakter[j] = karakter[pilihKarakter - 1].nama;
                    } else {
                        cout << "Nomor karakter tidak valid (1-8)." << endl;
                        j--;
                    }
                }
                cout << "Tim berhasil diubah!" << endl;
            } else {
                cout << "Pilihan tim tidak valid." << endl;
            }
            cout << "Tekan Enter untuk lanjut";
            cin.ignore();
            cin.get();
            system("clear");
        }

        // Hapus tim
        else if (pilihan == "6") {
            int pilihTim;
            for (int i = 0; i < MAX_TIM; i++) {
                if (tim[i].namaTim != "") {
                    cout << i + 1 << ". " << tim[i].namaTim << endl;
                }
            }
            cout << "Pilih tim yang ingin dihapus: " << endl;
            cin >> pilihTim;
            
            if (pilihTim >= 1 && pilihTim <= MAX_TIM && tim[pilihTim - 1].namaTim != "") {
                for (int i = pilihTim - 1; i < MAX_TIM - 1; i++) {
                    tim[i] = tim[i + 1];
                }
                
                tim[MAX_TIM - 1].namaTim = "";
                for (int j = 0; j < MAX_KARAKTER; j++) {
                    tim[MAX_TIM - 1].karakter[j] = "";
                }
                cout << "Tim berhasil dihapus!" << endl;
            } else {
                cout << "Pilihan tim tidak valid." << endl;
            }
            cout << "Tekan Enter untuk lanjut";
            cin.ignore();
            cin.get();
            system("clear");
        }

        // Logout
        else if (pilihan == "7") {
            cout << "Logout berhasil." << endl;
            break;
        } 

        // Pilihan tidak valid
        else {
            cout << "Pilihan tidak tersedia. Coba lagi." << endl;
            cout << "Tekan Enter untuk lanjut";
            cin.get();
            system("clear");
        }
    }
    return 0;
}