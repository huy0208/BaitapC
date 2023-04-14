#include <iostream>
#include <string>
using namespace std;
/*
 *Author: Huynh Huy
 *Date: 14/4/2023
 *Description: Tạo một lớp sách với các thuộc tính tên sách, tác giả, năm xuất bản và số lượng, và các phương thức để in thông tin sách, mượn sách và
trả sách.
*/

class Sach {
private:
    string tenSach;
    string tacGia;
    int namXuatBan;
    int soLuong;
public:
    Sach(string ten, string tg, int nam, int sl) {
        tenSach = ten;
        tacGia = tg;
        namXuatBan = nam;
        soLuong = sl;
    }
    // in ra màn hình 
    void inThongTin() {
        cout << "Ten sach: " << tenSach << endl;
        cout << "Tac gia: " << tacGia << endl;
        cout << "Nam xuat ban: " << namXuatBan << endl;
        cout << "So luong: " << soLuong << endl;
    }
    void muonSach() {
        // số lượng giảm = mượn sách thành công
        if (soLuong > 0) {
            soLuong--;
            cout << "Muon sach thanh cong" << endl;
        }
        else {
            cout << "Sach da het, khong the muon" << endl;
        }
    }
    void traSach() {
        // số lượng tăng = trả sách thành công
        soLuong++;
        cout << "Tra sach thanh cong" << endl;
    }
};

int main() {
    Sach sach1("Toi thay hoa vang tren co xanh", "Nguyen Nhat Anh", 2000, 5);
    sach1.inThongTin();

    sach1.muonSach();
    sach1.inThongTin();

    sach1.traSach();
    sach1.inThongTin();

    return 0;
}
