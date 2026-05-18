#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract base class
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;
public:
    RekeningBank(string nama, double saldoAwal)
        : namaNasabah(nama), saldo(saldoAwal) {}

    virtual void potongAdmin() = 0;   // pure virtual function

    double getSaldo() const { return saldo; }
    string getNama()  const { return namaNasabah; }

    virtual ~RekeningBank() {}        // virtual destructor
};

// Rekening Syariah — bebas biaya admin
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        // saldo tetap utuh, tidak ada potongan
    }
};

// Rekening Konvensional — potongan tetap Rp 15.000
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
    }
};

// Rekening Premium — potongan dinamis berdasarkan saldo
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            // saldo di atas Rp 10.000.000 → bebas biaya admin
        } else {
            // saldo <= Rp 10.000.000 → potong Rp 50.000
            saldo -= 50000;
        }
    }
};

int main() {
    // Server bank memproses semua rekening hanya via pointer base class
    vector<RekeningBank*> daftarRekening;
    daftarRekening.push_back(new RekeningSyariah("Ahmad",  5000000));
    daftarRekening.push_back(new RekeningKonvensional("Budi", 5000000));
    daftarRekening.push_back(new RekeningPremium("Citra", 15000000)); // bebas
    daftarRekening.push_back(new RekeningPremium("Dewi",   5000000)); // -50.000

    cout << "=== Sebelum Potong Admin ===\n";
    for (auto r : daftarRekening)
        cout << r->getNama() << ": Rp " << r->getSaldo() << "\n";

    // Polimorfisme: satu loop, banyak perilaku
    for (auto r : daftarRekening) r->potongAdmin();

    cout << "\n=== Setelah Potong Admin ===\n";
    for (auto r : daftarRekening)
        cout << r->getNama() << ": Rp " << r->getSaldo() << "\n";

    for (auto r : daftarRekening) delete r;
    return 0;
}