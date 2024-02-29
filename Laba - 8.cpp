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
	setlocale(LC_ALL, "RU");
	system("chcp 1275");
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol;                   	// Переменная для количества владельцев
	owner mass[10];             	// Массив для 10 владельцев
	cout << "Введите количество владельцев: ";
	cin >> kol;
	for (int i = 0; i < kol; i++) {
		string n, s, p, num;
		int ph, np;					
		cout << "Введите ФИО, номер авто, телефон и номер техпаспорта" << i + 1 << endl;
		cin >> n >> s >> p >> num >> ph >> np;
		mass[i].enter_info(n, s, p, num, ph, np);
	}
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
		kol -= 1
	}
	
	bool f = false;
	int zfam;						// Хранит индекс элемента с указанной фамилией, 
	string fam;     				// перед которым нужно вставить ещё один элемент
	cout << "Введите фамилию человека, перед которым надо поставить 2-х новых: ";
	cin >> fam;
	for (int i = 0; i < kol_st; i++) {
		if (mass[i].surname == fam) {
			zfam = i;  // В цикле перебираются все элементы для поиска указанной
			f = true;  // фамилии, если такая есть, флаг переворачивается
		}
	}
	if (f == true) {			                       // Если f == true, нужно добавить дополнительный элемент
	    kol += 2;
		for (int i = kol; i > zfam; i--) {
			mass[i] = mass[i - 2];                     // В массиве элементы сдвигаются вправо, остаётся место
		}			                                   // перед элементом с нужной фамилией, его занимает 
		string n1, s1, p1, num1;
		int ph1, np1;	
	
		cout << "Введите ФИО, номер авто, телефон и номер техпаспорта первого владельца" << endl;
		cin >> s1 >> n1 >> p1 >> num1 >> ph1 >> np1;
		mass[zfam].enter_info(n1, s1, p1, num1, ph1, np1);
		
		string n2, s2, p2, num2;
		int ph2, np2;	
	
		cout << "Введите ФИО, номер авто, телефон и номер техпаспорта второго владельца" << endl;
		cin >> s2 >> n2 >> p2 >> num2 >> ph2 >> np2;
		mass[zfam+1].enter_info(n2, s2, p2, num2, ph2, np2);
	}
	
	ofstream f1("f1.txt");        			// Включение файла для записи		   
	for (int i = 0; i < kol_st; i++) {
		bool fl = true;						// Флаг, нужно ли удалять элемент
		for (int j = 0; j < k; j++) {
			if (i == zmass[j]) {  		    // Если индекс элемента находится в zmass, флаг 
				fl = false;					// переворачивается, чтобы не пропустить элемент в файл 
			}
		}
		if (fl) {
			f1 << mass[i].surname << " " << mass[i].name << " " << mass[i].patronymic <<
				" " << mass[i].number << " " << mass[i].phone << " " << mass[i].numpas << endl;
		}
	}  					   // Если флаг не перевернулся, элемент записывается в файл
	f1.close();
	return 0;
}
