#include <iostream>
#include "Items.h"
#include "Inventory.h"
using namespace std;

int main() {
	inventory test;
	test.display();
	test.addItem(1, 1);
	test.display();
}