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
	cout << "������Ҫ�������Щ���ƻ��Ķ���" << endl;
		_getch();
	return 0;
}
int devil::activity() {
	cout << "���Ͱ��Ͱ��Ͱ��� " << endl;
		_getch();
	return 0;
}