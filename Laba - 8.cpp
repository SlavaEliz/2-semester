#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

struct owner {
	string name;
	string surname;
	string patronymic;
	string number;			// Номер авто
	int phone;      // Номер телефона
	int numpas;   // Номер техпаспорта
	void enter_info(string n, string s, string p, string num, int ph, int np) {
		name = n;
		surname = s;
		patronymic = p;
		number = num;
		phone = ph;
		numpas = np;
	}
};

int main() {
	system("chcp 1251 > NULL");

	int kol = 3;                   	// Переменная для количества владельцев
	owner mass[10];             	// Массив для 10 владельцев

	mass[0].enter_info("Иван", "Иванов", "Иванович", "123RUS", +7902, 1212);
	mass[1].enter_info("Петр", "Петров", "Петрович", "456EU", +8922, 2323);
	mass[2].enter_info("Олег", "Олегов", "Олегович", "789RUS", +7919, 3434);

	cout << "Введите номер авто, которого нужно удалить: ";
	bool f = false;
	string dnum;                     // Номер авто, которого нужно удалить 
	int inum;                        // Хранит индекс элемента с указанным номером
	cin >> dnum;
	for (int i = 0; i < kol; i++) {
		if (mass[i].number == dnum) {
			inum = i;
			f = true;
		}
	}
	if (f == true) {			                       // Если f == true, нужно удалить элемент
		for (int i = inum; i <= kol; i++) {
			mass[i] = mass[i + 1];                     // В массиве элементы сдвигаются влево
		}
		kol -= 1;
	}


	f = false;
	int zfam;						// Хранит индекс элемента с указанной фамилией, 
	string fam;     				// перед которым нужно вставить ещё один элемент
	cout << "Введите фамилию человека, перед которым надо поставить 2-х новых: ";
	cin >> fam;
	for (int i = 0; i < kol; i++) {
		if (mass[i].surname == fam) {
			zfam = i;  // В цикле перебираются все элементы для поиска указанной
			f = true;  // фамилии, если такая есть, флаг переворачивается
		}
	}
	if (f == true) {			                       // Если f == true, нужно добавить дополнительный элемент
		kol += 2;
		mass[zfam + 2] = mass[zfam];

		string n1, s1, p1, num1;
		int ph1, np1;

		cout << "Введите ФИО, номер авто, телефон и номер техпаспорта первого владельца" << endl;
		cin >> s1 >> n1 >> p1 >> num1 >> ph1 >> np1;
		mass[zfam].enter_info(n1, s1, p1, num1, ph1, np1);

		string n2, s2, p2, num2;
		int ph2, np2;

		cout << "Введите ФИО, номер авто, телефон и номер техпаспорта второго владельца" << endl;
		cin >> s2 >> n2 >> p2 >> num2 >> ph2 >> np2;
		mass[zfam + 1].enter_info(n2, s2, p2, num2, ph2, np2);
	}


	ofstream f1("f1.txt");        			// Включение файла для записи		   
	for (int i = 0; i < kol; i++) {
			f1 << mass[i].surname << " " << mass[i].name << " " << mass[i].patronymic <<
				" " << mass[i].number << " " << mass[i].phone << " " << mass[i].numpas << endl;
		}				 
	f1.close();
	return 0;
}

// Игорев Игорь Игоревич 234RUS +6902 1313
// Борисов Борис Борисович 567EU +6923 2525

