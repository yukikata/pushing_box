#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//图形库头文件
#include<mmsystem.h>
#include"ui.h"
using namespace std;
UIproduce::UIproduce() {};
UIproduce::~UIproduce() {};
void UIproduce::startimage() {
	initgraph(650, 700);
	settextstyle(130, 70, _T("Consolas"));
	outtextxy(180, 30, _T("推箱子"));//设置字体坐标
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//设置字体背景透明
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 175, _T("单人模式"));
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 335, _T("游戏说明"));
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 415, _T("退出游戏"));
	srand(time(0));
};
void UIproduce::breakgame() {
	closegraph();
};
void UIproduce::introduction() {
	initgraph(650, 700);
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(235, 175, _T("没有简介"));
	settextstyle(45, 0, _T("Consolas"));
	outtextxy(600, 650, _T("返回"));
};
void UIproduce::story() {};