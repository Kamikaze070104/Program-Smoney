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
    cout << "Menu Smoney :\n";
    cout << "1. Tambah pemasukan/pengeluaran\n";
    cout << "2. Tampilkan data\n";
    cout << "3. Hitung banyak Saldo\n";
    cout << "4. LogOut\n";
    cout << "5. Exit\n";
    cout << "pilih Menu : ";
    cin >> menu;

    switch (menu) {
    case 1: {
        string Tanggal;
        double pemasukan, pengeluaran;

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
        cout << "\n";
        LihatData(head);
        break;
    }
    case 3: {
        double saldo = HitungTotal(head);
        cout << "\nTotal Saldo : " << saldo << endl;
        break;
    }
    case 4: {
        cout << "\nAnda Berhasil LogOut!\n";
        return main();
        break;
    }
    case 5: {
        cout << "\nAnda Berhasil Keluar!\n";
        return 0;
        break;
    }
    default: {
        cout << "\nMaaf, Menu Tidak Ditemukan\n";
        break;
    } 
    }
      cout << "ke menu/log out(y/t) ";
      cin >> ulangi;
  }
    while (ulangi == "y");
    cout << "\nAnda Berhasil Log Out\n";
    return main();
}