#include "file.h"
#include "interface.h"

void input(kidGarden*& objects, int& amount, char* fileName) {
	amount = 0;
	int N;
	int Grade;
	cout << "������� ���������� ����� >>> ";
	cin >> N;
	cin.ignore();
	amount += N;
	kidGarden* temp = new kidGarden[amount];
	for (int i = 0; i < amount - N; i++)
		temp[i] = objects[i];
	objects = new kidGarden[amount];
	for (int i = 0; i < amount - N; i++)
		objects[i] = temp[i];
	delete[] temp;
	for (int i = 0; i < amount; i++) {
		cout << endl << "������� ���� ������ >>> ";
		cin.getline(objects[i].cipher, 15);
		cout << "������� ���������� ����� � ������ >>> ";
		cin >> objects[i].numKids;
		cin.ignore();
		cout << "������� ������� ����������� >>> ";
		cin.getline(objects[i].surname, 20);
		cout << "������� ������(1 - �������, 2 - �������, 3 - �������, 4 - ����������������) >>> ";
		cin >> Grade;
		switch (Grade) {
		case(objects[i].Younger):
			strcpy_s(objects[i].grd, "Younger");
			break;

		case(objects[i].Middle):
			strcpy_s(objects[i].grd, "Middle");
			break;
		case(objects[i].Older):
			strcpy_s(objects[i].grd, "Older");
			break;
		case(objects[i].Preparatory):
			strcpy_s(objects[i].grd, "Preparatory");
			break;
		default:
			cout << "�������� ����!" << endl;
			strcpy_s(objects[i].grd, "�� �������");
			break;
		}
		cout << "������ ������ �������� �����������?(1 - ��, 2- ���) >>> ";
		cin >> objects[i].forGrp.numfG;
		if (objects[i].forGrp.numfG == 1)
			objects[i].forGrp.namefG = '+';
		else if (objects[i].forGrp.numfG == 2)
			objects[i].forGrp.namefG = '-';
		else {
			cout << "�������� ����!";
			objects[i].forGrp.namefG = '?';
			cout << endl;
		}
		cin.ignore();
	}
	txtOutput(objects, amount, fileName);
}

void add(kidGarden*& objects, int& amount, char* fileName) {
	ofstream out(fileName, ios_base::app);
	int amountOfGroups;
	cout << "������� ����� ��������? >>> ";
	cin >> amountOfGroups;
	kidGarden* groupsToAdd = new kidGarden[amountOfGroups];
	for (int i = 0; i < amountOfGroups; i++) {
		cout << endl << "������� ���� ������ >>> ";
		cin.ignore();
		cin.getline(groupsToAdd[i].cipher, 15);
		cout << "������� ���������� ����� � ������ >>> ";
		cin >> groupsToAdd[i].numKids;
		cin.ignore();
		cout << "������� ������� ����������� >>> ";
		cin.getline(groupsToAdd[i].surname, 20);
		cout << "������� ������(1 - �������, 2 - �������, 3 - �������, 4 - ����������������) >>> ";
		int Grade;
		cin >> Grade;
		switch (Grade) {
		case(groupsToAdd[i].Younger):
			strcpy_s(groupsToAdd[i].grd, "Younger");
			break;
		case(groupsToAdd[i].Middle):
			strcpy_s(groupsToAdd[i].grd, "Middle");
			break;
		case(groupsToAdd[i].Older):
			strcpy_s(groupsToAdd[i].grd, "Older");
			break;
		case(groupsToAdd[i].Preparatory):
			strcpy_s(groupsToAdd[i].grd, "Preparatory");
			break;
		default:
			cout << "�������� ����!" << endl;
			strcpy_s(groupsToAdd[i].grd, "�� �������");
			break;
		}
		cout << "������ ������ �������� �����������?(1 - ��, 2- ���) >>> ";
		cin >> groupsToAdd[i].forGrp.numfG;
		if (groupsToAdd[i].forGrp.numfG == 1)
			groupsToAdd[i].forGrp.namefG = '+';
		else if (groupsToAdd[i].forGrp.numfG == 2)
			groupsToAdd[i].forGrp.namefG = '-';
		else {
			cout << "�������� ����!";
			groupsToAdd[i].forGrp.namefG = '?';
			cout << endl;
		}
		out << setw(5) << left << amount + 1;
		out << setw(15) << left << groupsToAdd[i].cipher;
		out << setw(20) << left << groupsToAdd[i].numKids;
		out << setw(20) << left << groupsToAdd[i].surname;
		out << setw(17) << left << groupsToAdd[i].grd;
		out << setw(14) << left << groupsToAdd[i].forGrp.namefG << endl;
		amount++;
	}
	out.close();
	txtInput(objects, amount, fileName);
}

void output(kidGarden* objects, int amount) {
	cout << setw(5) << left << "#" << setw(15) << left << "���� ������" << setw(20) << left << "���������� �����" << setw(20) << left << "�������������" << setw(17) << left << "������" << setw(14) << "��. ������" << endl;
	for (int i = 0; i < amount; i++) {
		cout << setw(5) << left << i + 1;
		cout << setw(15) << left << objects[i].cipher;
		cout << setw(20) << left << objects[i].numKids;
		cout << setw(20) << left << objects[i].surname;
		cout << setw(17) << left << objects[i].grd;
		cout << setw(14) << left << objects[i].forGrp.namefG;
		cout << endl;
	}
}

void sort(kidGarden* objects, int amount, char* fileName) {
	int choice;
	cout << "\n����������\n\n1)���������� ����� � ������ �� �����������\n2)���������� ����� � ������ �� ��������\n3)����� ������������ �� ��������\n";
	cout << endl << "�������� ��� ���������� >>> ";
	cin >> choice;
	switch (choice) {
	case(1):
		for (int i = 0; i < amount - 1; i++) {
			for (int k = i; k < amount; k++) {
				if (objects[k].numKids < objects[i].numKids)
					swap(objects[i], objects[k]);
			}
		}
		break;
	case(2):
		for (int i = 0; i < amount - 1; i++) {
			for (int k = i; k < amount; k++) {
				if (objects[k].numKids > objects[i].numKids)
					swap(objects[i], objects[k]);
			}
		}
		break;
	case(3):
		for (int i = 0; i < amount - 1; i++) {
			for (int k = i; k < amount; k++) {
				if (strcmp(objects[k].surname, objects[i].surname) < 0)
					swap(objects[i], objects[k]);
			}
		}
		break;
	default:
		cout << "�������� ����!" << endl;
		break;
	}
	txtOutput(objects, amount, fileName);
}

void cipher_del(kidGarden* objects, int& amount, char* fileName) {
	char cipher_to_del[15];
	cout << endl << "� ����� ������ ��������� �� ������ �������? >>> ";
	cin.ignore();
	cin.getline(cipher_to_del, 20);
	for (int i = 0; i < amount; i++) {
		if (strcmp(objects[i].cipher, cipher_to_del) == 0) {
			amount--;
			for (int k = i; k < amount; k++)
				objects[k] = objects[k + 1];
			i--;
		}
	}
	txtOutput(objects, amount, fileName);
}

void condition_del(kidGarden* objects, int& amount, char* fileName) {
	int choice;
	cout << "\n1)���� ������\n2)���������� �����\n3)������� �����������\n4)������\n5)����������� ������\n";
	cout << endl;
	cout << "�������� ������� >>> ";
	cin >> choice;
	if (choice == 1) {
		char cipher_to_del[15];
		cout << endl << "� ����� ������ ��������� �� ������ �������? >>> ";
		cin.ignore();
		cin.getline(cipher_to_del, 20);
		for (int i = 0; i < amount; i++) {
			if (strcmp(objects[i].cipher, cipher_to_del) == 0) {
				amount--;
				for (int k = i; k < amount; k++)
					objects[k] = objects[k + 1];
				i--;
			}
		}
	}
	else if (choice == 2) {
		int numKids_to_del;
		cout << endl << "� ����� ����������� ����� ��������� �� ������ �������? >>> ";
		cin >> numKids_to_del;
		for (int i = 0; i < amount; i++) {
			if (objects[i].numKids == numKids_to_del) {
				amount--;
				for (int k = i; k < amount; k++)
					objects[k] = objects[k + 1];
				i--;
			}
		}
	}
	else if (choice == 3) {
		char surname_to_del[20];
		cout << endl << "� ����� �������������� ��������� �� ������ �������? >>> ";
		cin.ignore();
		cin.getline(surname_to_del, 20);
		for (int i = 0; i < amount; i++) {
			if (strcmp(objects[i].surname, surname_to_del) == 0) {
				amount--;
				for (int k = i; k < amount; k++)
					objects[k] = objects[k + 1];
				i--;
			}
		}
	}
	else if (choice == 4) {
		char group_to_del[20];
		cout << endl << "� ����� ������� ��������� �� ������ ������� >>> ";
		cin.ignore();
		cin.getline(group_to_del, 20);
		for (int i = 0; i < amount; i++) {
			if (strcmp(objects[i].grd, group_to_del) == 0) {
				amount--;
				for (int k = i; k < amount; k++)
					objects[k] = objects[k + 1];
				i--;
			}
		}
	}
	else if (choice == 5) {
		char fG_to_del;
		cout << endl << "�������� ������� ��������� ����������� ������('+' - ��, '-' - ���)? >>> ";
		cin >> fG_to_del;
		for (int i = 0; i < amount; i++) {
			if (objects[i].forGrp.namefG == fG_to_del) {
				amount--;
				for (int k = i; k < amount; k++)
					objects[k] = objects[k + 1];
				i--;
			}
		}
	}
	else
		cout << endl << "�������� ����!";
	txtOutput(objects, amount, fileName);
}

void fieldCorrection(kidGarden*& objects, int amount, char* fileName) {
	cout << "������� ���� ������, ������� ���� ���������������� >>> ";
	char cipherToCorrect[15];
	cin.ignore();
	cin.getline(cipherToCorrect, 15);
	for (int i = 0; i < amount; i++) {
		if (strcmp(cipherToCorrect, objects[i].cipher) == 0) {
			int choice = 0;
			while (choice != 6) {
				cout << endl << "�������� ��������:\n1)���������������� ����\n2)���������������� ���������� ����� � ������\n3)���������������� ������� �������������\n4)���������������� ����� ������\n5)��������������� �������������� ������ � �����������\n6)�����\n�������� �������� >>> ";
				cin >> choice;
				if (choice == 1) {
					cout << "������� ����� ���� ��������� >>> ";
					char newCipher[15];
					cin.ignore();
					cin.getline(newCipher, 15);
					strcpy_s(objects[i].cipher, newCipher);
				}
				else if (choice == 2) {
					cout << "������� ����� ���������� ����� � ������ >>> ";
					int newNumKids;
					cin >> newNumKids;
					objects[i].numKids = newNumKids;
				}
				else if (choice == 3) {
					cout << "������� ����� ������� ������������� >>> ";
					char newSurname[20];
					cin.ignore();
					cin.getline(newSurname, 20);
					strcpy_s(objects[i].surname, newSurname);
				}
				else if (choice == 4) {
					cout << "������� ����� ����� ������(1 - �������, 2 - �������, 3 - �������, 4 - ����������������) >>> ";
					int newGrade;
					cin >> newGrade;
					switch (newGrade) {
					case(objects[i].Younger):
						strcpy_s(objects[i].grd, "Younger");
						break;

					case(objects[i].Middle):
						strcpy_s(objects[i].grd, "Middle");
						break;
					case(objects[i].Older):
						strcpy_s(objects[i].grd, "Older");
						break;
					case(objects[i].Preparatory):
						strcpy_s(objects[i].grd, "Preparatory");
						break;
					default:
						cout << "�������� ����!" << endl;
						strcpy_s(objects[i].grd, "�� �������");
						break;
					}
				}
				else if (choice == 5) {
					cout << "������ �������� �����������?(1 - ��, 2 - ���) >>> ";
					int forChoice;
					cin >> forChoice;
					objects[i].forGrp.numfG = forChoice;
					if (objects[i].forGrp.numfG == 1)
						objects[i].forGrp.namefG = '+';
					else if (objects[i].forGrp.numfG == 2)
						objects[i].forGrp.namefG = '-';
					else {
						cout << "�������� ����!";
						objects[i].forGrp.namefG = '?';
						cout << endl;
					}
				}
				else if (choice < 1 || choice > 6) cout << endl << "�������� ����!" << endl;
			}
			txtOutput(objects, amount, fileName);
			return;
		}
	}
	cout << endl << "��������� � ����� ������ �� ����������!" << endl;
}

void fieldReplace(kidGarden*& objects, int amount, char* fileName) {
	cout << "������� ���� ���������, ������� ������ �������� >>> ";
	char cipherToReplace[15];
	cin.ignore();
	cin.getline(cipherToReplace, 15);
	for (int i = 0; i < amount; i++) {
		if (strcmp(objects[i].cipher, cipherToReplace) == 0) {
			cout << endl << "������� ���������� ����� ������:" << endl;
			cout << endl << "������� ���� ������ >>> ";
			cin.getline(objects[i].cipher, 15);
			cout << "������� ���������� ����� � ������ >>> ";
			cin >> objects[i].numKids;
			cin.ignore();
			cout << "������� ������� ����������� >>> ";
			cin.getline(objects[i].surname, 20);
			cout << "������� ������(1 - �������, 2 - �������, 3 - �������, 4 - ����������������) >>> ";
			int Grade;
			cin >> Grade;
			switch (Grade) {
			case(objects[i].Younger):
				strcpy_s(objects[i].grd, "Younger");
				break;

			case(objects[i].Middle):
				strcpy_s(objects[i].grd, "Middle");
				break;
			case(objects[i].Older):
				strcpy_s(objects[i].grd, "Older");
				break;
			case(objects[i].Preparatory):
				strcpy_s(objects[i].grd, "Preparatory");
				break;
			default:
				cout << "�������� ����!" << endl;
				strcpy_s(objects[i].grd, "�� �������");
				break;
			}
			cout << "������ ������ �������� �����������?(1 - ��, 2- ���) >>> ";
			cin >> objects[i].forGrp.numfG;
			if (objects[i].forGrp.numfG == 1)
				objects[i].forGrp.namefG = '+';
			else if (objects[i].forGrp.numfG == 2)
				objects[i].forGrp.namefG = '-';
			else {
				cout << "�������� ����!";
				objects[i].forGrp.namefG = '?';
				cout << endl;
			}
			txtOutput(objects, amount, fileName);
			return;
		}
	}
	cout << endl << "��������� � ����� ������ �� ����������!" << endl;
}