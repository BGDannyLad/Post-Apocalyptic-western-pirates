#pragma once
#include <iostream>
using namespace std; 

Class Player() {
Private:
	int Health = 100;
	int Strength = 100;
	int Intel = 100;

Public:
	int getHealth() {
		return Health;
	};

	void setHealth(int k) {
		Health = k;
	};

	int getStrength() {
		return Strength;
	};

	void setStrength(int k) {
		Strength = k;
	};

	int getIntel() {
		return Intel;
	};

	void setIntel(int k) {
		Intel = k;
	};
};