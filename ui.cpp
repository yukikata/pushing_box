#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//ͼ�ο�ͷ�ļ�
#include<mmsystem.h>
#include"ui.h"
using namespace std;
UIproduce::UIproduce() {};
UIproduce::~UIproduce() {};
void UIproduce::startimage() {
	initgraph(650, 700);
	settextstyle(130, 70, _T("Consolas"));
	outtextxy(180, 30, _T("������"));//������������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//�������屳��͸��
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 175, _T("����ģʽ"));
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 335, _T("��Ϸ˵��"));
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 415, _T("�˳���Ϸ"));
	srand(time(0));
};
void UIproduce::breakgame() {
	closegraph();
};
void UIproduce::introduction() {
	initgraph(650, 700);
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 175, _T("û�м��"));
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(600, 650, _T("����"));
};
void UIproduce::story() {};