#include <iostream>
#include "Array.h"

enum {push = 1, pop, replace};
using namespace std;

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main() {
	size_t n;
	cout << "Choose the range of your array:" << endl;
	cin >> n;

	vector v;
	cout << "Enter " << n << " elements:" << endl;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		v.push(v.getSize(), val);
	}

	cout << "Current array: " << v << endl;
	cout << "Choose method: " << push << " - add(push) element, " << pop << " - remove(pop) element, " << replace << " - replace element" << endl;
	int choice;
	cin >> choice;

	switch (choice) {
		case push: {
			int idx, val;
			cout << "Enter index and value to add: " << endl;
			cin >> idx >> val;
			v.push(idx, val);
			break;
		}
		case pop: {
			size_t idx;
			cout << "Enter index to remove: " << endl;
			cin >> idx;
			v.pop(idx);
			break;
		}
		case replace: {
			size_t idx;
			int val;
			cout << "Enter index and new value: " << endl;
			cin >> idx >> val;
			v.replace(idx, val);
			break;
		}
		default:
			cout << "Invalid choice." << endl;
			return 1;
	}
	cout << "New array: " << v << endl;
	if (!v.isEmpty()) cout << "First element is: " << v[0] << endl; //пример разыменовывания
	return 0;
}
