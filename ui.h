#pragma once
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//图形库头文件
#include<mmsystem.h>
#include"main_game.h"

class UIproduce {
public:
	UIproduce();
	~UIproduce();
	void startimage(); //开始界面
	void story();  //剧情
	void introduction();//介绍
	void breakgame();//结束游戏
};
