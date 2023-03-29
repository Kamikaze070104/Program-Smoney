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

int main() {
  login login;
  system("cls");
  cout << "===================================================\n";
  cout << "========== Selamat datang di Smoney ===============\n";
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