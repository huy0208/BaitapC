#include <iostream>
using namespace std;

/*
 *Author: Huynh Huy
 *Date: 14/4/2023
 *Description: Tạo một lớp hình tròn với bán kính và các phương thức để tính chu vi
và diện tích của hình tròn
*/

class Circle {
   private:
    float radius;

   public:
    Circle(float r) {
        radius = r;
    }

    float getRadius() {
        return radius;
    }

    void setRadius(float r) {
        if (r >= 0) { // Kiểm tra giá trị bán kính nhập vào có lớn hơn hoặc bằng 0 hay không
            radius = r;
        } else {
            printf("Gia tri khong hop le. Moi ban nhap lai");

        }
    }

    float getArea() {
        return 3.14 * radius * radius;
    }

    float getCircumference() {
        return 2 * 3.14 * radius;
    }
};

int main() {
    float r;
    printf("Nhap ban kinh hinh tron: ");
    scanf ("%f", &r);

    Circle c(r);

    // Kiểm tra giá trị bán kính nhập vào có lớn hơn hoặc bằng 0 hay không
    while (c.getRadius() < 0) {
        printf("Gia tri khong hop le. Moi nhap lai");
        printf("\nBan kinh hinh tron: ");
        scanf ("%f", &r);
        c.setRadius(r);
    }

    printf("Dien tich hinh tron: %f\n", c.getArea());
    printf("Chu vi hinh tron: %f\n", c.getCircumference());

    return 0;
}
