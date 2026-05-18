#include <iostream>
using namespace std;

class remote.ampu {
private:
    string saklarno[5];
public:
    void setsaklarno(int i, string value) {
        saklarno[i] = value;
    }
    string getsaklarno(int i) {
        return saklarno[i];
    }
};

int main() {
    remotelampu lampurumah;

    lampurumah.setsaklarno(0, "lampu teras rumah");
    lampurumah.setsaklarno(1, "lampu ruang tamu");
    lampurumah.setsaklarno(2, "lampu kamar tidur");
    lampurumah.setsaklarno(3, "lampu dapur");

    cout << lampurumah.getsaklarno(0) << endl;
    cout << lampurumah.getsaklarno(1) << endl;
    cout << lampurumah.getsaklarno(2) << endl;
    cout << lampurumah.getsaklarno(3) << endl;

    return 0;
}