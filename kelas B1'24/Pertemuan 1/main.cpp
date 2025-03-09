#include <iostream>
using namespace std;

// int main()
// {
//     string nama;
//     cout << "Masukkan nama :";
//     // cin >> nama;
//     getline(cin, nama);
//     cout <<"Nama saya adalah " << nama;
    
//     return 0;
// }

// int main()
// {
//     int umur = 20;
//     int sumbuY = -45;
//     float berat_badan = 50.5;
//     double tinggi_badan = 170.5;
//     char jenis_kelamin = 'L';
//     bool is_menikah = false;
    
//     cout << umur << endl;
//     cout << jenis_kelamin << endl;
//     cout << is_menikah << endl;
    
//     int angka[5] = {1, 2, 3, 4, 5};
//     string nama = "udin";
//     nama[1];
    
//     return 0;
// } 

// int main()
// {
//     struct Mahasiswa {
//         string nama;
//         int umur;
//         float ipk;
//         };
//         Mahasiswa mhs = {"Raana", 20, 3.5};

//         string firstName; // camelCaseHelloWorld
//         string last_name; // snake_case_hello_world
//         string FullName; // PascalCaseHelloWorld
        
//         // tipeData namavariabel; null
//         string nama = "nayo";
//         firstName = "nayo";
//         last_name = "ramadhani";
// return 0;
// } 

// int main()
// {
//     bool sudahMenikah = true;
//     string status = sudahMenikah ? "Sudah menikah" : "Belum menikah";
//     cout << status << endl;
// return 0;
// }

// int main()
// {
//     bool malas = false;
//     bool lapar = true;
//     if (malas) {
//     cout << "Saya scroll fesbuk";
//     }
//     else if (lapar)
//         cout << "Saya makan";
//     else
//     {
//     cout << "Saya belajar";
//     }
// return 0;
// }

// int main()
// {
//     int nilaiUjian = 100;
//     switch(nilaiUjian) {
//     case 100:
//         cout << "Nilai sempurna";
//         break;
//     case 90:
//         cout << "Nilai sangat baik";
//         break;
//     default:
//         cout << "Nilai tidak valid";
//     }
// return 0;
// }

// int main()
// {
//     bool malas = true;
//     bool lapar = true;

//     if (malas) {
//         if (lapar) {
//             cout << "Saya makan";
//         }
//     } else {
//         cout << "Gak ngapa-ngapain";
//     }
// return 0;
// }

int main()
// {
// for (int i = 0; i < 5; i++) 
// {
//     cout << i << endl;
// }
// return 0;
// }

// {
//     int i = 0;
//     while (i < 5) {
//         cout << i << endl;
//         i++;
//     }

//     return 0;
// }

// {
//     int i = 0;
//     char yes = 'n';
//     do {
//         cout << i << endl;
//         i++;
//         cout << "Apakah ingin mengulangi program? (y/n)" << endl;
//         cin >> yes;
//     } while (yes != 'n');
//     return 0;
// }

{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int x : arr)
    {
        cout << x << endl;
    }
}