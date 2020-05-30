#include "menu.h"

int main() {
	setlocale(0, "");
	int amount = 0;
	kidGarden* objects = new kidGarden[amount];
	menu(objects, amount);
	delete[] objects;
}



