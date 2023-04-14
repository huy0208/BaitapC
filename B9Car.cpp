#include <iostream>
using namespace std;
/*
 *Author: Huynh Huy
 *Date: 14/4/2023
 *Description: Tạo một lớp xe hơi với các thuộc tính màu sắc, kiểu động cơ và số km đã đi, và các phương thức để tính toán chi phí bảo trì, kiểm tra số km
đã đi và in thông tin về xe
*/

class Car {
    private:
        string color;
        string engineType;
        double kmDriven;

    public:
        Car(string color, string engineType, double kmDriven) {
            this->color = color;
            this->engineType = engineType;
            this->kmDriven = kmDriven;
        }

        double maintenanceCost() {
            double cost = 0;
            if (this->engineType == "gasoline") { // kiểu động cơ = gasoline
                cost = 100 + (this->kmDriven / 1000) * 50;
            } else if (this->engineType == "diesel") { // kiểu động cơ = diesel
                cost = 150 + (this->kmDriven / 1000) * 70;
            }
            return cost;
        }

        void printInfo() {
            cout << "Color: " << this->color << endl;
            cout << "Engine Type: " << this->engineType << endl;
            cout << "Km Driven: " << this->kmDriven << endl;
        }

        void checkKmDriven() {
            if (this->kmDriven > 100000) {
                cout << "Can duoc bao duong" << endl;
            } else {
                cout << "Xe van con chay tot" << endl;
            }
        }
};

int main() {
    Car myCar("blue", "diesel", 65000);
    myCar.printInfo();
    cout << "Maintenance cost: " << myCar.maintenanceCost() << endl;
    myCar.checkKmDriven();
    return 0;
}
