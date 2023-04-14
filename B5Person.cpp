#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
 *Author: Huynh Huy
 *Date: 14/4/2023
 *Description: Tạo một lớp người với các thuộc tính tên, tuổi và địa chỉ, và các
phương thức để in thông tin của người đó và tính tuổi của người đó.
*/

class Person {
    private:
    char name[50];
        int age;
        char address[100];
    public:
        void setName(char* n) {
            strcpy(name, n);
        }
        char* getName() {
            return name;
        }
        int getAge() {
            return age;
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
        void setAddress(char* a) {
            strcpy(address, a);
        }
        char* getAddress() {
            return address;
        }
        void printInfo() {
            printf("Ten: %s\n", name);
            printf("Tuoi: %d\n", age);
            printf("Dia chi: %s\n", address);
        }
};
int main(){
    Person p;

    // Nhập thông tin người
    char name[50];
    int age;
    char address[100];

    printf("Nhap ten: ");
    scanf("%s", name);
    p.setName(name);

    printf("Nhap tuoi: ");
    scanf("%d", &age);
    p.setAge(age);

    printf("Nhap dia chi: ");
    scanf("%s", address);
    p.setAddress(address);

    // In ra thông tin và tuổi của người
    printf("Thong tin nguoi:\n");
    p.printInfo();
    return 0;
}
