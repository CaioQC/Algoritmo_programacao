#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int value(char r) {
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
    return -1;
}

int romanToDecimal(char *num) {
    int res = 0;
    int i;

    for (i = 0; i < strlen(num); i++) {
        int s1 = value(num[i]);

        if (i + 1 < strlen(num)) {
            int s2 = value(num[i + 1]);

            if (s1 >= s2) {
                res = res + s1;
            } else {
                res = res + s2 - s1;
                i++;
            }
        } else {
            res = res + s1;
            i++;
        }
    }
    return res;
}

void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);
    }
    printf("%d", n % 2);
}

void printHexadecimal(int n) {
    char *hexaDeciNum = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        } else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexaDeciNum[j]);
    }
}

int main() {
    char roman[1000];
    printf("Digite um número romano: ");
    scanf("%s", roman);
    int decimal = romanToDecimal(roman);

    printf("%s na base 2: ", roman);
    printBinary(decimal);
    printf("\n%s na base 10: %d\n", roman, decimal);
    printf("%s na base 16: ", roman);
    printHexadecimal(decimal);
    printf("\n");

    return 0;
}
