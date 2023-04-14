#include <iostream>
using namespace std;

/*
 *Author: Huynh Huy
 *Date: 14/4/2023
 *Description: Tạo một lớp phân số với các thuộc tính tử số và mẫu số và các phương thức để tính toán các phép tính toán cơ bản như cộng, trừ, nhân và
chia.
*/

class PhanSo {
private:
    int tuSo, mauSo;

public:
    // Constructor
    PhanSo(int ts, int ms) {
        tuSo = ts;
        mauSo = ms;
    }

    // Getters
    int getTuSo() const {
        return tuSo;
    }

    int getMauSo() const {
        return mauSo;
    }

    // Phuong thuc cong 2 phan so
    PhanSo cong(PhanSo ps) {
        int ts = tuSo * ps.getMauSo() + ps.getTuSo() * mauSo;
        int ms = mauSo * ps.getMauSo();
        return PhanSo(ts, ms).rutGon();
    }

    // Phuong thuc tru 2 phan so
    PhanSo tru(PhanSo ps) {
        int ts = tuSo * ps.getMauSo() - ps.getTuSo() * mauSo;
        int ms = mauSo * ps.getMauSo();
        return PhanSo(ts, ms).rutGon();
    }

    // Phuong thuc nhan 2 phan so
    PhanSo nhan(PhanSo ps) {
        int ts = tuSo * ps.getTuSo();
        int ms = mauSo * ps.getMauSo();
        return PhanSo(ts, ms).rutGon();
    }

    // Phuong thuc chia 2 phan so
    PhanSo chia(PhanSo ps) {
        int ts = tuSo * ps.getMauSo();
        int ms = mauSo * ps.getTuSo();
        return PhanSo(ts, ms).rutGon();
    }

    // Rut gon phan so
    PhanSo rutGon() {
        int a = tuSo, b = mauSo, tmp;
        while (b != 0) {
            tmp = a % b;
            a = b;
            b = tmp;
        }
        return PhanSo(tuSo / a, mauSo / a);
    }

    // In phan so
    void inPhanSo() {
        cout << tuSo << "/" << mauSo << endl;
    }
};

int main() {
    PhanSo ps1();
    PhanSo ps2();
    PhanSo psTong = ps1.cong(ps2);
    PhanSo psHieu = ps1.tru(ps2);
    PhanSo psTich = ps1.nhan(ps2);
    PhanSo psThuong = ps1.chia(ps2);

    psTong.inPhanSo();
    psHieu.inPhanSo();
    psTich.inPhanSo();
    psThuong.inPhanSo();

    return 0;
}
