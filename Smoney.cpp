#include <iostream>
#include <unistd.h>

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
  int id;
  string nama;
  double pemasukan, pengeluaran;
  Node* next;
};

void DataBaru(Node **head, int id, string nama, double pemasukan, double pengeluaran) {
  Node *Newnode = new Node;
  Newnode->id = id;
  Newnode->nama = nama;
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
    cout << "ID : " << head->id << endl;
    cout << "Name : " << head->nama << endl;
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
}

int main() {
  login login;
  system("cls");
  cout << "===================================================\n";
  cout << "============ Selamat datang di Smoney =============\n";
  cout << "===================================================\n\n";
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
}