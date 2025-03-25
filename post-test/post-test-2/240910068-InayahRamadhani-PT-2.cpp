#include <iostream>
#include <iomanip>
using namespace std;

string nama = "Inayah Ramadhani";
string nim = "2409106068";
string inputNama, inputNim, pilihan;
int kesempatanLogin = 3;

// Data musuh
string musuh[3][4] = {
    {"Gluttonous Yumkasaur Mountain King", "Yumkasaur", "Wayward Hermetic Spiritspeaker", "Iktomisaurus"},
    {"Solitary Suanni", "Xuanwen Beast", "Tenebrous Mimesis - Ruin Guard", "Tenebrous Mimesis - Secret Source Automaton"},
    {"Biting-Cold Wayob Manifestation", "Construction Specialist Mek - Pneuma", "Tenebrous Papila: Type III", ""}
};

int level[3][4] = {
    {95, 95, 95, 95},
    {98, 98, 98, 98},
    {100, 100, 100, 0}
};

// Data karakter
string karakter[8][4] = {
    {"1", "Arlecchino", "Pyro", "Polearm"},
    {"2", "Furina", "Hydro", "Sword"},
    {"3", "Ororon", "Electro", "Bow"},
    {"4", "Yelan", "Hydro", "Bow"},
    {"5", "Xingqiu", "Hydro", "Sword"},
    {"6", "Chasca", "Anemo", "Bow"},
    {"7", "Bennett", "Pyro", "Sword"},
    {"8", "Xiangling", "Pyro", "Polearm"}
};

string namaTim[2] = {"", ""};
string timKarakter[2][4] = {{"", "", "", ""}, {"", "", "", ""}};

int main() {
    cout << "==========================" << endl;
    cout << "      Selamat Datang" << endl;
    cout << "      Silahkan Login" << endl;
    cout << "==========================" << endl;

    // Fitur Login
    for (int percobaan = 0; percobaan < kesempatanLogin; percobaan++) {
        cout << "Nama: ";
        getline(cin, inputNama);

        cout << "NIM: ";
        cin >> inputNim;

        if (inputNama == nama && inputNim == nim) {
            cout << "Berhasil login!" << endl;
            cin.ignore();
            break;
        } else {
            cout << "Nama atau NIM yang Anda masukkan salah." << endl;
            cout << "Percobaan tersisa " << (kesempatanLogin - 1 - percobaan) << " kali." << endl;
            cin.ignore();
        }

        if (percobaan == kesempatanLogin - 1) {
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
        cout << "\n";

        // Lihat musuh
        if (pilihan == "1") {
            cout << left << setw(10) << "Chamber" << setw(15) << "Half"
                 << setw(50) << "Musuh" << "Lv." << endl;
            cout << string(85, '-') << endl;

            for (int i = 0; i < 3; i++) {
                cout << "Chamber " << i + 1 << endl;

                cout << setw(10) << "" << setw(15) << "First Half";
                cout << setw(50) << musuh[i][0] << level[i][0] << endl;
                cout << setw(10) << "" << setw(15) << "" << setw(50) << musuh[i][1] << level[i][1] << endl;

                cout << setw(10) << "" << setw(15) << "Second Half";
                if (!musuh[i][2].empty()) {
                    cout << setw(50) << musuh[i][2] << level[i][2] << endl;
                }
                if (!musuh[i][3].empty()) {
                    cout << setw(10) << "" << setw(15) << "" << setw(50) << musuh[i][3] << level[i][3] << endl;
                }
                cout << string(85, '-') << endl;
            }
        }

        // Lihat karakter
        else if (pilihan == "2") {
            cout << left << setw(5) << "No" << setw(15) << "Nama"
                 << setw(10) << "Elemen" << setw(10) << "Senjata" << endl;
            cout << string(40, '-') << endl;

            for (int i = 0; i < 8; i++) {
                cout << left << setw(5) << karakter[i][0] << setw(15) << karakter[i][1]
                     << setw(10) << karakter[i][2] << setw(10) << karakter[i][3] << endl;
            }
            cout << "\n";
        }

        // Lihat tim
        else if (pilihan == "3") {
            if (namaTim[0] == "" && namaTim[1] == "") {
                cout << "Belum ada tim yang dibuat." << endl;
            } else {
                for (int i = 0; i < 2; i++) {
                    if (namaTim[i] != "") {
                        cout << "Tim " << namaTim[i] << ": ";
                        for (int j = 0; j < 4; j++) {
                            if (timKarakter[i][j] != "") {
                                cout << timKarakter[i][j] << " ";
                            }
                        }
                        cout << "\n";
                    }
                }
                cout << "\n";
            }
        }

        // Fitur buat tim
        else if (pilihan == "4") {
            int timIndex = (namaTim[0] == "") ? 0 : (namaTim[1] == "") ? 1 : -1;
            if (timIndex == -1) {
                cout << "Sudah ada 2 tim, tidak bisa menambah lagi." << endl;
            } else {
                cout << "Masukkan nama tim: ";
                cin.ignore();
                getline(cin, namaTim[timIndex]);

                cout << "\nDaftar Karakter :" << endl;
                for (int i = 0; i < 8; i++) {
                    cout << karakter[i][0] << ". " << karakter[i][1] << " (" << karakter[i][2] << ", " << karakter[i][3] << ")" << endl;
                }

                cout << "\nMasukkan nomor karakter yang ingin dipilih :" << endl;
                for (int j = 0; j < 4; j++) {
                    int pilihIndex;
                    cout << "Karakter " << j + 1 << ": ";
                    cin >> pilihIndex;
                    if (pilihIndex >= 1 && pilihIndex <= 8) {
                        timKarakter[timIndex][j] = karakter[pilihIndex - 1][1];
                    } else {
                        cout << "Nomor karakter tidak valid." << endl;
                        j--;
                    }
                }
                cout << "Tim " << namaTim[timIndex] << " berhasil dibuat!" << endl;
            }
        }

        // Fitur ubah tim
        else if (pilihan == "5") {
            int pilihTim;
            cout << "Pilih tim yang ingin diubah: " << endl;
            for (int i = 0; i < 2; i++) {
                if (!namaTim[i].empty()) {
                    cout << i + 1 << ". " << namaTim[i] << endl;
                }
            }
            cin >> pilihTim;

            if (pilihTim >= 1 && pilihTim <= 2 && !namaTim[pilihTim - 1].empty()) {
                cout << "Masukkan nama baru untuk tim: ";
                cin.ignore();
                getline(cin, namaTim[pilihTim - 1]);

                cout << "Daftar Karakter: " << endl;
                for (int i = 0; i < 8; i++) {
                    cout << karakter[i][0] << ". " << karakter[i][1] << " (" << karakter[i][2] << ", " << karakter[i][3] << ")" << endl;
                }

                for (int j = 0; j < 4; j++) {
                    int pilihKarakter;
                    cout << "Karakter " << j + 1 << ": ";
                    cin >> pilihKarakter;

                    if (pilihKarakter >= 1 && pilihKarakter <= 8) {
                        timKarakter[pilihTim - 1][j] = karakter[pilihKarakter - 1][1];
                    } else {
                        cout << "Nomor karakter tidak valid." << endl;
                        j--;
                    }
                }
                cout << "Tim berhasil diubah!" << endl;
            } else {
                cout << "Pilihan tim tidak valid." << endl;
            }
        }

        // Fitur hapus tim
        else if (pilihan == "6") {
            int pilihTim;
            cout << "Pilih tim yang ingin dihapus: " << endl;
            for (int i = 0; i < 2; i++) {
                if (!namaTim[i].empty()) {
                    cout << i + 1 << ". " << namaTim[i] << endl;
                }
            }
            cin >> pilihTim;

            if (pilihTim >= 1 && pilihTim <= 2 && !namaTim[pilihTim - 1].empty()) {
                namaTim[pilihTim - 1] = "";
                for (int j = 0; j < 4; j++) {
                    timKarakter[pilihTim - 1][j] = "";
                }
                cout << "Tim berhasil dihapus!" << endl;
            } else {
                cout << "Pilihan tim tidak valid." << endl;
            }
        }

        // Fitur logout
        else if (pilihan == "7") {
            cout << "Logout berhasil." << endl;
            break;
        }

        // Pilihan tidak valid
        else {
            cout << "Pilihan tidak tersedia. Coba lagi." << endl;
            cout << "\n";
        }
    }
    return 0;
}