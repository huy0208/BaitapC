// nhap so co 7 chu so va in ra gia tien

#include <stdio.h>
#include <stdint.h>

void readUnits(uint8_t num) {
    switch (num) {
        case 0:
            printf("khong ");
            break;
        case 1:
            printf("mot ");
            break;
        case 2:
            printf("hai ");
            break;
        case 3:
            printf("ba ");
            break;
        case 4:
            printf("bon ");
            break;
        case 5:
            printf("nam ");
            break;
        case 6:
            printf("sau ");
            break;
        case 7:
            printf("bay ");
            break;
        case 8:
            printf("tam ");
            break;
        case 9:
            printf("chin ");
            break;
        default:
            printf("khong hop le ");
            break;
    }
}

void readDec(uint8_t num) {
    switch (num) {
        case 0:
            printf("trieu ");
            break;
        case 1:
        case 4:
            printf("tram ");
            break;
        case 2:
        case 5:
            printf("muoi ");
            break;
        case 3:
            printf("nghin ");
            break;
    }
}

void readNumber(uint32_t num) {
    uint8_t units[7];
    uint32_t n = num;
    // Lấy từng chữ số trong số và lưu vào mảng units
    for (int i = 6; i >= 0; i--) {
        units[i] = n % 10;
        n /= 10;
    }
    // In ra số theo thứ tự ngược lại
    for (int i = 0; i < 7; i++) {
        readUnits(units[i]);
        if (i == 6) {
            // In ra đơn vị tiền tệ nếu là chữ số đầu tiên
            printf("dong");
        } else {
            readDec(i);
        }
    }
}

int main() {
    uint32_t num;
    printf("Nhap so co 7 chu so: ");
    scanf("%d", &num);
    readNumber(num);
    return 0;
}
