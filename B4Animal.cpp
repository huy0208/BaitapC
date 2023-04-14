#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

/*
 *Author: Huynh Huy
 *Date: 14/4/2023
 *Description: Tạo một lớp động vật với các thuộc tính tên, tuổi và trọng lượng, và các phương thức để tính chỉ số BMI, so sánh tuổi và trọng lượng của các
động vật khác nhau.
*/

// Tạo lớp gồm các thuộc tính như trên
class Animal {
    private:
        char name[50];
        int age;
        float weight;
    public:
        void setName(char* n) {
            strcpy(name, n);
        }
        char* getName() {
            return name;
        }
        void setAge(int a) {
             do {
        if (a >= 0){
            age = a;
            break;
        } else {
            printf("Gia tri khong hop le. Moi ban nhap lai: ");
            scanf("%d", &a);
        }
    } while (true);
}
        int getAge() {
            return age;
        }
        void setWeight(float w) {
            do {
        if (w >= 0){
            weight = w;
            break;
        } else {
            printf("Gia tri khong hop le. Moi ban nhap lai: ");
            scanf("%f", &w);
        }
    } while (true);
}
        float getWeight() {
            return weight;
        }
        float getBMI() {
            float height ;
            return weight / (height * height);
        }
        bool isOlderThan(Animal a) {
            return age > a.getAge();
        }
        bool isHeavierThan(Animal a) {
            return weight > a.getWeight();
        }
};

int main() {
    Animal a1, a2;

    // Nhập thông tin cho động vật 1
    char name1[50];
    int age1;
    float weight1;

    printf("Nhap ten dong vat 1: ");
    scanf("%s", name1);
    a1.setName(name1);

    printf("Nhap tuoi dong vat 1: ");
    scanf("%d", &age1);
    a1.setAge(age1);

    printf("Nhap can nang dong vat 1: ");
    scanf("%f", &weight1);
    a1.setWeight(weight1);

    // Nhập thông tin cho động vật 2
    char name2[50];
    int age2;
    float weight2;

    printf("Nhap ten dong vat 2: ");
    scanf("%s", name2);
    a2.setName(name2);

    printf("Nhap tuoi dong vat 2: ");
    scanf("%d", &age2);
    a2.setAge(age2);

    printf("Nhap can nang dong vat 2: ");
    scanf("%f", &weight2);
    a2.setWeight(weight2);

    // In ra kết quả
    printf("Thong tin dong vat 1:\n");
    printf("Ten: %s\n", a1.getName());
    printf("Tuoi: %d\n", a1.getAge());
    printf("Can nang: %0.2f\n", a1.getWeight());
    printf("BMI: %0.2f\n", a1.getBMI());

    printf("Thong tin dong vat 2:\n");
    printf("Ten: %s\n", a2.getName());
    printf("Tuoi: %d\n", a2.getAge());
    printf("Can nang: %0.2f\n", a2.getWeight());
    printf("BMI: %0.2f\n", a2.getBMI());

    if (a1.isOlderThan(a2)) {
        printf("Dong vat 1 lon tuoi hon dong vat 2.\n");
    } else {
        printf("Dong vat 2 lon tuoi hon dong vat 1.\n");
    }

    if (a1.isHeavierThan(a2)){
        printf("Dong vat 1 nang hon dong vat 2.\n");
    }else{
        printf("Dong vat 2 nang hon dong vat 1.\n");
    }
    return 0;
}
