#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// ������� ��� ���������� ��������� �����
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// ������� ��� ���������� ������� �������
int countAnagrams(char word[]) {
    int length = strlen(word);

    // ����� ��� ��������� ��������� �������� ����� �����
    int letterCount[26] = {0};

    // ���������� ������� �������� ����� �����
    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);  // ������������ ������� �� �������� �����
        if (isalpha(c)) {  // ��������, �� ������ � ������
            int index = c - 'a';  // ������ ����� � ����� letterCount
            letterCount[index]++;
        }
    }

    // ���������� ������� ��������� ��������� �������� ����� �����
    int product = 1;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 1) {
            product *= factorial(letterCount[i]);
        }
    }

    // ���������� ������� �������
    int anagramCount = factorial(length) / product;

    return anagramCount;
}

int main() {
setlocale(LC_ALL, "Ukr");
system("chcp 1251"); // ������� ��� ��������� ����
system("cls");
    char word[15];
    printf("������ �����: ");
    scanf("%s", word);

    int result = countAnagrams(word);
    printf("ʳ������ �������: %d\n", result);

    return 0;
}
