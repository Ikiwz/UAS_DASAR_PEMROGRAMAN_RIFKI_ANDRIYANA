#include <iostream>
#include <vector>

using namespace std;

struct Produk {
  string nama;
  long harga;
};

vector<Produk> daftarProduk{
  {" Rengginang terasi", 13000},
  {" Rengginang hitam ", 13000},
  {" Rengginang putih ", 13000},
  {" Rengginang manis ", 14000},
  {" Renggining       ", 10000},
  {" Dapros           ", 8000},
  {" Enye original    ", 10000},
  {" Enye pedas       ", 10000},
  {" Enye udang       ", 12000},
};

struct PotonganHarga {
  int minimal;
  float persen;
};

vector<PotonganHarga> daftarPotonganHarga {
  {1000000, .15},
  {750000, .10},
  {500000, .07},
  {250000, .05},
};

void prosesPembelian(Produk produk) {
  int jumlahProduk, subTotal, potonganHarga;

  cout << "======== Rincian Pembelian ========\n\n";
  cout << "Produk \t\t:" << produk.nama << " ~ Rp " << produk.harga << "\n";
  cout << "Jumlah \t\t: "; cin >> jumlahProduk;

  subTotal = produk.harga * jumlahProduk;
  cout << "Sub total \t: Rp " << produk.harga * jumlahProduk << "\n";

  for (int i = 0; i < daftarPotonganHarga.size(); i++) {
    if (subTotal >= daftarPotonganHarga[i].minimal) {
      potonganHarga = subTotal * daftarPotonganHarga[i].persen;
      cout << "Potongan harga \t: Rp " << potonganHarga << "\n";
      break;
    }
  }

  cout << "Total \t\t: Rp " << subTotal - potonganHarga << "\n";
}

int main() {
  int nomorProduk, pilih;

  menuUtama:

  system("cls");

  cout << "+ ================ Toko Rupa Rasa  ================ +\n\n";

  cout << "\nDaftar Produk : ";
  for (int i = 0; i < daftarProduk.size(); i++) {
    cout << (i == 0 ? "" : "\t\t")  << i + 1 << ". " << daftarProduk[i].nama << " : Rp " << daftarProduk[i].harga << "\n";
  }

  cout << "\nPilih produk (1 - " << daftarProduk.size() << ") : "; 
  cin >> nomorProduk;

  system("cls");

  if (nomorProduk > 0 && nomorProduk <= daftarProduk.size()) {
    prosesPembelian(daftarProduk[nomorProduk - 1]);
  } else {
    cout << "Tidak ada pilihan produk! \n";
  }

  menuPilih:

  cout << "\n<=============================================> \n";
  cout << "Ketik 1 untuk kembali ke menu utama \n";
  cout << "Ketik 2 untuk keluar dari aplikasi \n";
  cout << "<=============================================> \n";
  cout << "Pilih  : ";
  cin >> pilih;

  if (pilih == 1){
    goto menuUtama;
  } else if (pilih == 2) {
    cout << "\n<=============================================> \n";
    cout << "                - See You :) -                  \n";
    cout << "<=============================================> \n";
  } else {
    cout << "\n<=============================================> \n";
    cout << "       Tidak ada pilihan menu tersebut          \n";
    cout << "<=============================================> \n";
    goto menuPilih;
  }

  system("cls");
}