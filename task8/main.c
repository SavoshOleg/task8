#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Функція для обчислення факторіалу числа
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Функція для обчислення кількості анаграм
int countAnagrams(char word[]) {
    int length = strlen(word);

    // Масив для зберігання кількостей входжень кожної букви
    int letterCount[26] = {0};

    // Обчислення кількості входжень кожної букви
    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]);  // Перетворення символу на маленьку літеру
        if (isalpha(c)) {  // Перевірка, чи символ є літерою
            int index = c - 'a';  // Індекс букви у масиві letterCount
            letterCount[index]++;
        }
    }

    // Обчислення добутку факторіалів кількостей входжень кожної букви
    int product = 1;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 1) {
            product *= factorial(letterCount[i]);
        }
    }

    // Обчислення кількості анаграм
    int anagramCount = factorial(length) / product;

    return anagramCount;
}

int main() {
setlocale(LC_ALL, "Ukr");
system("chcp 1251"); // Команди для української мови
system("cls");
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    int result = countAnagrams(word);
    printf("Кількість анаграм: %d\n", result);

    return 0;
}
