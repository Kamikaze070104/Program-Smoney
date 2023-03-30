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
  string Tanggal;
  double pemasukan, pengeluaran;
  Node* next;
};

void DataBaru(Node **head, string Tanggal, double pemasukan, double pengeluaran) {
  Node *Newnode = new Node;
  Newnode->Tanggal = Tanggal;
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
    cout << "Tanggal : " << head->Tanggal << endl;
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
    cout << "Silahkan Login\n\n";

    cout << "Username: ";
    cin >> login.username;
    cout << "Password: ";
    cin >> login.pass;
    system("cls");
    if (login.pass == login.pw_true && login.username == login.usn_true) {
      cout << "berhasil login!\n";
      break;
    } else if (i == 0) {
      while (login.counter >= 1) {
        cout << "\rAnda tidak diperkenankan masuk, coba lagi dalam: " << login.counter;
        sleep(1);
        login.counter--;
      }
      return main();
      break;
    }
    cout << "Login salah! Kesempatan Anda " << i << " kali lagi!!\n";
    cout << "===================================================\n\n";
  }
  int menu;
  string ulangi;
  do {
    system("cls");
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

    switch (menu) {
    case 1: {
      system("cls");
        string Tanggal;
        double pemasukan, pengeluaran;
        cout << "=================================================\n";
        cout << "========= Tambah Pemasukan/Pengeluaran ==========\n";
        cout << "=================================================\n\n";

        cout << "Masukkan Tanggal : ";
        cin.ignore();
        getline(cin, Tanggal);
        cout << "Masukkan jumlah pemasukan : ";
        cin >> pemasukan;
        cout << "Masukkan jumlah pengeluaran : ";
        cin >> pengeluaran;

        DataBaru(&head, Tanggal, pemasukan, pengeluaran);
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
        cout << "=================================================\n";
        cout << "=========== Anda Telah Berhasil LogOut ==========\n";
        cout << "=================================================\n\n";
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