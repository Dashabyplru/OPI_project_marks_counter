#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	// Запрашиваем количество предметов
	int numSubjects;
	cout << "Введите количество предметов: ";
	cin >> numSubjects;
	cin.ignore();

	if (numSubjects <= 0) {
		cout << "Количество предметов должно быть положительным!" << endl;
		return 1;
	}

	// Динамические массивы
	string* subjects = new string[numSubjects];
	int* gradesCount = new int[numSubjects];
	int** grades = new int* [numSubjects];  // Это массив указателей для динамического многомерного массива
	// Ввод данных
	for (int i = 0; i < numSubjects; i++) {
		cout << "\nПредмет #" << i + 1 << ":\n";

		// Ввод названия
		cout << "Введите название предмета: ";
		getline(cin, subjects[i]);

		// Ввод количества оценок
		cout << "Введите количество оценок для предмета '" << subjects[i] << "': ";
		cin >> gradesCount[i];
		cin.ignore();

		if (gradesCount[i] <= 0) {
			cout << "Количество оценок должно быть положительным! Установлено значение 0.\n";
			gradesCount[i] = 0;
			grades[i] = nullptr;
			continue;
		}
		// Выделение памяти под оценки
		grades[i] = new int[gradesCount[i]];

		// Ввод оценок
		cout << "Введите " << gradesCount[i] << " оценок:\n";
		for (int j = 0; j < gradesCount[i]; j++) {
			cout << "Оценка " << j + 1 << ": ";
			int num;
			cin >> num;
			if (num < 1 || num > 10) {
				std::cout << "Оценка должна быть от 1 до 10"<<std::endl;
			}
			else {
				grades[i][j] = num;
			}

		}
		cin.ignore();
	}
	std::cout << "1.Продолжить работу\n";
	std::cout << "2.Выход\n";
	int choice;
	cin >> choice;
	switch(choice){
		case 1: {
			std::cout << "Введите название предмета\n";
			string searchSubject;
			cin >> searchSubject;

			// Поиск предмета
			int foundIndex = -1;
			for (int i = 0; i < numSubjects; i++) {
				if (subjects[i] == searchSubject) {
					foundIndex = i;
					break;
				}
			}


			std::cout << "1.Cредний балл";
			std::cout << "2.Подсчитать,как можно изменить средний балл";
			std::cout << "3.График";
			std::cout << "4.Лучший/Худший среедний балл";
			std::cout << "5.Общий средний балл";
			std::cout << "6.Выход";
			int choice1;
			cin >> choice1;
			switch (choice1) {
				case 1: {
					
				}
				case 2: {
					//Analyse.cpp
				}
				case 3: {

				}
				case 4: {

				}
				case 5: {

				}
				case 6: {
					std::cout << "Конец программы" << std::endl;
				}
			}
		}
		case 2: {
			std::cout << "Конец программы" << std::endl;
		}
	}
}