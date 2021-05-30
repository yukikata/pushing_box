#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"main_game.h"
#include"new_character.h"
using namespace std;
int characters::activity() {
	return 0;
};
characters::characters() {};
characters::~characters() {};
nun::nun() {};
nun::~nun() {};
devil::devil() {};
devil::~devil() {};
int nun::activity() {
	cout << "我们需要修理好这些被破坏的东西" << endl;
		_getch();
	return 0;
}
int devil::activity() {
	cout << "阿巴阿巴阿巴阿巴 " << endl;
		_getch();
	return 0;
}