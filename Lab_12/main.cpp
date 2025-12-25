#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>;

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
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
					// Проверяем, есть ли вообще предметы
					if (numSubjects <= 0) {
						cout << "Нет данных для построения графика!" << endl;
						break;
					}

					// Рассчитываем средние баллы для каждого предмета
					double* averages = new double[numSubjects];
					for (int i = 0; i < numSubjects; i++) {
						if (gradesCount[i] > 0 && grades[i] != nullptr) {
							int sum = 0;
							for (int j = 0; j < gradesCount[i]; j++) {
								sum += grades[i][j];
							}
							averages[i] = (double)sum / gradesCount[i];
						}
						else {
							averages[i] = 0.0;
						}
					}

					// Находим максимальный средний балл для масштабирования графика
					double maxAvg = 0.0;
					for (int i = 0; i < numSubjects; i++) {
						if (averages[i] > maxAvg) {
							maxAvg = averages[i];
						}
					}

					// Если все средние баллы равны 0
					if (maxAvg == 0.0) {
						cout << "Нет данных для построения графика (все средние баллы равны 0)!" << endl;
						delete[] averages;
						break;
					}

					// Определяем высоту графика (например, 10 строк)
					const int HEIGHT = 10;

					// Создаем массив для меток (первые уникальные буквы/символы предметов)
					string* labels = new string[numSubjects];

					// Генерируем метки для каждого предмета
					for (int i = 0; i < numSubjects; i++) {
						string label = "";
						// Начинаем с первого символа
						for (int len = 1; len <= subjects[i].length(); len++) {
							label = subjects[i].substr(0, len);
							bool isUnique = true;

							// Проверяем уникальность этой метки
							for (int j = 0; j < i; j++) {
								if (j != i && labels[j] == label) {
									isUnique = false;
									break;
								}
							}

							if (isUnique) {
								break;
							}
						}
						labels[i] = label;
					}

					// Построение вертикального графика сверху вниз
					cout << "\n=================================================" << endl;
					cout << "ГРАФИК СРЕДНИХ БАЛЛОВ ПО ПРЕДМЕТАМ" << endl;
					cout << "=================================================\n" << endl;

					// Построение графика сверху вниз
					for (int level = HEIGHT; level > 0; level--) {
						// Вычисляем порог для текущей строки
						double threshold = (maxAvg / HEIGHT) * level;

						// Выводим левую метку уровня
						if (level == HEIGHT) {
							cout << setw(5) << fixed << setprecision(1) << maxAvg << "-| ";
						}
						else if (level == 1) {
							cout << "  0.0-| ";
						}
						else {
							cout << "      | ";
						}

						// Выводим столбцы для каждого предмета с расстоянием между ними
						for (int i = 0; i < numSubjects; i++) {
							if (averages[i] >= threshold) {
								cout << "***";  // Столбец
							}
							else {
								cout << "     ";  // Пустое место
							}

							// Добавляем пробел между столбцами (расстояние)
							if (i < numSubjects - 1) {
								cout << " ";
							}
						}
						cout << endl;
					}

					// Линия под графиком
					cout << "      |-";
					for (int i = 0; i < numSubjects; i++) {
						cout << "------";
						if (i < numSubjects - 1) {
							cout << "-";  // Добавляем дополнительный символ для расстояния
						}
					}
					cout << endl;

					// Подписи под графиком
					cout << "        ";
					for (int i = 0; i < numSubjects; i++) {
						// Выводим метку предмета с выравниванием
						int labelLength = labels[i].length();

						if (labelLength == 1) {
							cout << " " << labels[i] << "  ";
						}
						else if (labelLength == 2) {
							cout << labels[i] << " ";
						}
						else {
							// Обрезаем до 3 символов и добавляем пробел
							string shortLabel = labels[i];
							if (shortLabel.length() > 3) {
								shortLabel = shortLabel.substr(0, 3);
							}
							cout << shortLabel;

							// Добавляем выравнивающие пробелы
							if (shortLabel.length() == 1) {
								cout << "  ";
							}
							else if (shortLabel.length() == 2) {
								cout << " ";
							}
						}
					}
					cout << endl;

					// Расшифровка меток
					cout << "\n=================================================" << endl;
					cout << "Расшифровка меток:" << endl;
					for (int i = 0; i < numSubjects; i++) {
						cout << labels[i] << " = " << subjects[i] << " (ср. балл: "
							<< fixed << setprecision(2) << averages[i] << ")" << endl;
					}
					cout << "=================================================" << endl;

					// Очистка памяти
					delete[] averages;
					delete[] labels;
					break;
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