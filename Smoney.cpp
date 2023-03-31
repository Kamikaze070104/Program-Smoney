#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;
/* Aplikasi Smoney kelompok 3
    Faizal Azzriel Gibar 2200482
    Mochammad Hasanudin Ali	2207056
    Zidan Dwi Permana	2202106
*/
struct login {
  string pass, username;
  string usn_true = "kelompok3";
  string pw_true = "smoney";
  int counter = 9;
};

struct Node {
  int tanggal,tahun,bulan;
  double pemasukan, pengeluaran;
  Node* next;
};

void DataBaru(Node **head, int tanggal,int bulan, int tahun, double pemasukan, double pengeluaran) {
  Node *Newnode = new Node;
  Newnode->tanggal = tanggal;
  Newnode->bulan = bulan;
  Newnode->tahun = tahun;
  Newnode->pemasukan = pemasukan;
  Newnode->pengeluaran = pengeluaran;
  Newnode->next = NULL;

  if (*head == NULL) {
    *head = Newnode;
    return;
  }

  Node *last = *head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = Newnode;
}

void LihatData(Node *head) {
  if (head == NULL) {
    cout << " Data tidak ditemukan!" << endl;
    return;
  }

  while (head != NULL) {
    cout << "Tanggal : " << head->tanggal << "/"<<head->bulan<<"/"<<head->tahun << endl;
    cout << "pemasukan : " << head->pemasukan << endl;
    cout << "pengeluaran : " << head->pengeluaran << endl;
    head = head->next;
  }
}

double HitungTotal(Node *head) {
  double saldo = 0;
  while (head != NULL) {
    saldo += head->pemasukan - head->pengeluaran;
    head = head->next;
  }
  return saldo;
}
int main() {
  Node* head = NULL;
  login login;
  system("cls");
  cout << "=================================================\n";
  cout << "============ Selamat datang di Smoney ===========\n";
  cout << "=================================================\n\n";
  for (int i = 2; i >= 0; --i) {
    cout << "Silahkan Login\n";
    cout << "Username: ";
    cin >> login.username;
    cout << "Password: ";
    cin >> login.pass;
    if (login.pass == login.pw_true && login.username == login.usn_true) {
      cout << "berhasil login!\n";
      break;
    } else if (i == 0) {
      while (login.counter >= 1) {
        system("cls");
        cout << "\rAnda tidak diperkenankan masuk, coba lagi dalam: " << login.counter;
        sleep(1);
        login.counter--;
      }
      return main();
      break;
    }
    system("cls");
    cout << "Login salah! Kesempatan Anda " << i << " kali lagi!!\n";
    cout << "===================================================\n\n";
  }
  int menu;
  string ulangi;
  system("cls");
  do {
    cout << "=================================================\n";
    cout << "============== Daftar Menu Smoney ===============\n";
    cout << "=================================================\n\n";
    cout << "1. Tambah pemasukan/pengeluaran\n";
    cout << "2. Tampilkan data\n";
    cout << "3. Hitung banyak Saldo\n";
    cout << "4. LogOut\n";
    cout << "5. Exit\n";
    cout << "pilih Menu : ";
    cin >> menu;
    while (cin.fail()) {
      cin.clear();
      cin.ignore(256, '\n');
      system("cls");
      cout << "maaf, inputan hanya bisa berupa angka yang tertera pada menu\n\n";
      cout << "=================================================\n";
      cout << "============== Daftar Menu Smoney ===============\n";
      cout << "=================================================\n\n";
      cout << "1. Tambah pemasukan/pengeluaran\n";
      cout << "2. Tampilkan data\n";
      cout << "3. Hitung banyak Saldo\n";
      cout << "4. LogOut\n";
      cout << "5. Exit\n";
      cout << "pilih Menu : ";
      cin >> menu;
    }
    switch (menu) {
    case 1: {
      system("cls");
        int tanggal, tahun, bulan;
        double pemasukan, pengeluaran;
        cout << "=================================================\n";
        cout << "========= Tambah Pemasukan/Pengeluaran ==========\n";
        cout << "=================================================\n\n";
        cout << "Masukkan Tanggal : ";
        cin >> tanggal;
         while (tanggal <= 0 || tanggal > 31 || cin.fail()){
          cin.clear();
          cin.ignore(256, '\n');
          if (tanggal > 31) {
            system("cls");
            cout << "Pastikan memasukkan tanggal 1-31!.\n";
          }
        cout << "Tanggal harus berupa angka, dan tidak boleh 0!\n";
        cout << "Masukkan Tanggal : ";
        cin >> tanggal;
         }
         cout << "Masukkan bulan : ";
        cin >> bulan;
         while (bulan <= 0 || bulan > 12 || cin.fail()){
          cin.clear();
          cin.ignore(256, '\n');
          if (bulan > 12) {
            system("cls");
            cout << "Pastikan memasukkan bulanl 1-12!.\n";
          }
        cout << "bulan harus berupa angka, dan tidak boleh 0!\n";
        cout << "Masukkan bulan : ";
        cin >> bulan;
         }
         cout << "Masukkan tahun : ";
         cin >> tahun;
         while (tahun <= 0 || cin.fail()){
         cin.clear();
         cin.ignore(256, '\n');
         cout << "tahun harus berupa angka dan tidak boleh 0!\n";
         cout << "Masukkan tahun : ";
         cin >> tahun;
        }  
        cout << "Masukkan jumlah pemasukan : ";
        cin >> pemasukan;
        while (pemasukan < 0 || cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        system("cls");
        cout << "Maaf, anda harus memasukan angka dan tidak boleh negatif\n";
        cout << "masukan jumlah pemasukan : ";
        cin>> pemasukan;
        }
        cout << "Masukkan jumlah pengeluaran : ";
        cin >> pengeluaran;
        while (pengeluaran < 0 || cin.fail()) {
        system("cls");
        cout << "Maaf, anda harus memasukan angka dan tidak boleh negatif\n";
        cout << "masukan jumlah pengeluaran : ";
        cin>> pengeluaran;
        }

        DataBaru(&head, tanggal,bulan,tahun, pemasukan, pengeluaran);
        cout << "\nData Berhasil Ditambahkan!\n";
        break;
    }
    case 2: {
        system("cls");
        cout << "=================================================\n";
        cout << "============== Menampilkan Data =================\n";
        cout << "=================================================\n\n";
        LihatData(head);
        break;
    }
    case 3: {
        system("cls");
        cout << "=================================================\n";
        cout << "============ Menghitung total Saldo =============\n";
        cout << "=================================================\n\n";
        double saldo = HitungTotal(head);
        cout << "Total Saldo : " << saldo << endl;
        break;
    }
    case 4: {
        system("cls");
        cout << "Anda Telah Berhasil LogOut\n";
        return main();
        break;
    }
    case 5: {
        system("cls");
        cout << "Anda Berhasil Keluar!\n";
        return 0;
        break;
    }
    default: {
        system("cls");
        cout << "Maaf, Menu Tidak Ditemukan\n";
        break;
    } 
    }
      cout << "ke menu/log out(y/t) ";
      cin >> ulangi;
  } while (ulangi == "y");
  system("cls");
  cout << "Anda Berhasil Log Out\n";
    return main();
}