#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Одномерный массив с названиями предметов
    vector<string> subjects = { "Математика", "Физика", "Химия", "Информатика", "История" };

    // Двумерный массив (вектор векторов) с оценками по предметам
    // Каждый внутренний вектор соответствует предмету с таким же индексом
    vector<vector<int>> grades = {
        {5, 4, 5, 3, 4},   // Оценки по Математике
        {4, 3, 5, 4, 4},   // Оценки по Физике
        {5, 5, 4, 5, 3},   // Оценки по Химии
        {5, 4, 5, 5, 5},   // Оценки по Информатике
        {3, 4, 3, 4, 5}    // Оценки по Истории
    };

    string subjectName;

    cout << "Доступные предметы: ";
    for (const auto& subject : subjects) {
        cout << subject << " ";
    }
    cout << endl << endl;

    cout << "Введите название предмета: ";
    getline(cin, subjectName);

    // Поиск индекса предмета
    int subjectIndex = -1;
    for (int i = 0; i < subjects.size(); i++) {
        if (subjects[i] == subjectName) {
            subjectIndex = i;
            break;
        }
    }

    // Вывод результатов
    if (subjectIndex != -1) {
        cout << "Оценки по предмету \"" << subjectName << "\": ";

        if (grades[subjectIndex].empty()) {
            cout << "оценок нет";
        }
        else {
            for (int grade : grades[subjectIndex]) {
                cout << grade << " ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Предмет \"" << subjectName << "\" не найден!" << endl;
    }

    // Пример альтернативного вывода с подсчетом среднего балла
    cout << endl << "Хотите увидеть средний балл? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (subjectIndex != -1 && !grades[subjectIndex].empty()) {
            double sum = 0;
            for (int grade : grades[subjectIndex]) {
                sum += grade;
            }
            double average = sum / grades[subjectIndex].size();
            cout << "Средний балл по предмету \"" << subjectName << "\": " << average << endl;
        }
    }

    return 0;
}