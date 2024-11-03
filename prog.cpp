#include <iostream>
#include <fstream>
#include <string>
#include <map> // Для использования словарей
#include <locale>
#include <cctype> // Для проверки символов (isalpha, isspace)

using namespace std;

void countLettersAndCombos(string &text, map<char, int> &letterCount, map<string, int> &comboCount) {
    for (int i = 0; i < text.size(); i++) {
        char ch = tolower(text[i]); // Для подсчёта букв без учёта регистра

        if (isalpha(ch)) {
            letterCount[ch]++;
        }

        // Подсчет двухбуквенных сочетаний
        if (i < text.size() - 1 && isalpha(ch) && isalpha(tolower(text[i + 1]))) {
            // Условия для отдельно стоящих сочетаний (наличие пробелов или знаков пунктуации)
            if ((i == 0 || isspace(text[i - 1]) || ispunct(text[i - 1])) &&
                (i + 2 == text.size() || isspace(text[i + 2]) || ispunct(text[i + 2]))) {
                comboCount[text.substr(i, 2)]++; // Извлечение символов в подстроку
            }
        }
    }
}

void printCounts(map<char, int> letterCount, map<string, int> comboCount) {
    cout << "Count of letters: " << endl;
    for (auto &entry : letterCount) {
        cout << "Letter " << entry.first << ": " << entry.second << endl;
    }

    cout << "Count of combinations: " << endl;
    for (auto &entry : comboCount) {
        cout << "Combination " << entry.first << ": " << entry.second << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream inputFile("text.txt");  // Ввод из файла

    string text((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>()); //Конструкция для чтения потока из файла в одну строку
    map<char, int> letterCount; // Словарь для подсчета букв
    map<string, int> comboCount; // Словарь для подсчёта сочетаний

    countLettersAndCombos(text, letterCount, comboCount);
    printCounts(letterCount, comboCount);

    return 0;
}
