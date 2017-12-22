#include "TList.h"
#include <cstdlib>
#include <locale>
#include <time.h>

int main(){
	setlocale(LC_ALL, "Russian");
	TList<int> a;
	cout << "1. Добавить элемент" << endl;
	cout << "2. Удалить элемент" << endl;
	cout << "3. Вывести список на экран" << endl;
	cout << "4. Выйти" << endl;
	int k;
	while (1) {
		cin >> k;
		switch (k)
		{
		case 1:
			int elem;
			cout << "Введите значение элемента, которое необходимо добавить - ";
			cin >> elem;
			a.sortInput(elem);
			break;
		case 2:
			int posElem;
			cout << "Введите номер позиции элемента, который необходимо удалить - ";
			cin >> posElem;
			if (posElem > a.getsize() || posElem < 0) {
				cout << endl << "Элемента с таким номером не существует " << endl;
				break;
			}
			else {
				if (posElem == 0)
					a.deleteFirst();
				else
					if (posElem == a.getsize())
						a.delLast();
					else {
						a.Reset();
						while (a.getpos() != posElem)
							a.goNext();
						a.delCurr();
					}
			}
			break;
		case 3:
			cout << "Ваш список - ";
			for (a.Reset(); !a.isEnd(); a.goNext()){ cout << a.getElelm() << " "; }
			cout << endl;
			break;
		case 4:
			return 0;
		default:
			break;
		}
	}
}