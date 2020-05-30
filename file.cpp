#include "file.h"
#include "interface.h"

void txtOutput(kidGarden* objects, int amount, char* fileName) {
	ofstream out(fileName);
	out << setw(5) << left << "#" << setw(15) << left << "Шифр группы" << setw(20) << left << "Количество детей" << setw(20) << left << "Преподаватель" << setw(17) << left << "Группа" << setw(14) << "Ин. Группа" << endl;
	for (int i = 0; i < amount; i++) {
		out << setw(5) << left << i + 1;
		out << setw(15) << left << objects[i].cipher;
		out << setw(20) << left << objects[i].numKids;
		out << setw(20) << left << objects[i].surname;
		out << setw(17) << left << objects[i].grd;
		out << setw(14) << left << objects[i].forGrp.namefG << endl;
	}
	out.close();
}

void txtInput(kidGarden*& objects, int& amount, char* fileName) {
	amount = 0;
	ifstream in(fileName);
	if (in.peek() == EOF) {
		cout << endl << "Текстовый файл пуст!" << endl << endl;
		input(objects, amount, fileName);
	}
	else {
		cout << endl << "Текстовый файл существует - данные будут считаны" << endl;
		int count;
		char temp[256];
		in.getline(temp, 256);
		for (int i = 0; !in.eof(); i++) {
			amount++;
			kidGarden* tmp = new kidGarden[amount - 1];
			for (int k = 0; k < amount - 1; k++)
				tmp[k] = objects[k];
			objects = new kidGarden[amount];
			for (int k = 0; k < amount - 1; k++)
				objects[k] = tmp[k];
			delete[] tmp;
			in >> count >> objects[i].cipher >> objects[i].numKids >> objects[i].surname >> objects[i].grd >> objects[i].forGrp.namefG;
		}
		amount -= 1;
		in.close();
	}
}