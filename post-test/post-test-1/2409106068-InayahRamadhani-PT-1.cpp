#include <iostream>
using namespace std;

int main() {
    string pin = "6068";
    string inputPin, pilihan;
    int saldo = 0;
    int kesempatanLogin = 3;
    int nominalSetor, nominalTarik;

    cout << "==========================" << endl;
    cout << "      Selamat Datang" << endl;
    cout << "==========================" << endl;

    // fitur login
    for (int percobaan = 0; percobaan < kesempatanLogin; percobaan++) {
        cout << "Masukkan PIN Anda: ";
        cin >> inputPin;

        if (inputPin == pin) {
            cout << "Berhasil login!" << endl;
            cout << "\n";
            break;
        } else {
            cout << "PIN yang Anda masukkan salah." << endl;
            cout << "Percobaan tersisa " << (kesempatanLogin - 1 - percobaan) << " kali." << endl;
            cout << "\n";
        }
    }

    if (inputPin != pin) {
        cout << "Anda telah salah memasukkan PIN 3 kali." << endl;
        cout << "Program telah berhenti.";
        return 0;
    }

    // fitur menu ATM
    while(true) {
        cout << "==========================" << endl;
        cout << "         Menu ATM" << endl;
        cout << "==========================" << endl;
        cout << "[1] Cek Saldo" << endl;
        cout << "[2] Setor Tunai" << endl;
        cout << "[3] Tarik Tunai" << endl;
        cout << "[4] Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << "\n";

        // fitur cek saldo
        if (pilihan == "1") {
            cout << "==========================" << endl;
            cout << "        Cek Saldo" << endl;
            cout << "==========================" << endl;
            cout << "Saldo anda: Rp" << saldo << endl;
            cout << "\n";
        }

        // fitur setor tunai
        else if (pilihan == "2") {
            cout << "==========================" << endl;
            cout << "        Setor tunai" << endl;
            cout << "==========================" << endl;
            cout << "Masukkan nominal yang ingin disetor: Rp";
            cin >> nominalSetor;
            saldo += nominalSetor;
            cout << "Setor tunai berhasil!" << endl;
            cout << "Saldo anda saat ini: Rp" << saldo << endl;
            cout << "\n";
        }

        // fitur tarik tunai
        else if (pilihan == "3") {
            cout << "==========================" << endl;
            cout << "       Tarik Tunai" << endl;
            cout << "==========================" << endl;
            cout << "Masukkan nominal yang ingin ditarik: Rp";
            cin >> nominalTarik;
            
            if (saldo <= nominalTarik) {
                cout << "Saldo anda tidak mencukupi.";
                cout << "\n" << endl;
            }
            else {
                saldo -= nominalTarik;
                cout << "Tarik tunai berhasil!" << endl;
                cout << "Saldo anda saat ini: Rp" << saldo << endl;
                cout << "\n";
            }
        }

        // fitur keluar dari program
        else if (pilihan == "4") {
            cout << "Terima kasih telah menggunakan ATM ini!" << endl;
            break;
        }
        else {
            cout << "Pilihan tidak tersedia. Coba lagi." << endl;
            cout << "\n"; 
        }
    }
    
    return 0;
}