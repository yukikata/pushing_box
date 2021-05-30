#pragma once
#ifndef __ui_h__
#define __ui_h__

#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//图形库头文件
#include<mmsystem.h>
#include"ui.h"
#include"new_character.h"

class GAME
{
public:
	GAME();
	~GAME();
	void playgame();
	void GameInit();
	void drawmap();
private:
	IMAGE backImg, wallImg, blankImg, boxImg, darkImg, endImg, peoImg, boxendImg, nunendImg, devilendImg;//图片定义类型
	int map1[13][14] = {
{0,0,0,0,1,1,1,1,1,1,0,0,0,0},
{0,0,0,0,1,0,0,0,0,1,0,0,0,0},
{0,1,1,1,1,0,0,4,0,1,1,1,1,1},
{0,1,0,0,0,1,0,0,0,1,0,0,0,1},
{0,1,0,4,0,0,0,4,0,0,0,4,0,1},
{0,1,0,0,0,1,1,0,1,1,1,1,1,1},
{1,1,1,1,0,1,1,0,0,0,0,10,9,1},
{1,0,0,0,4,0,1,0,0,0,5,0,0,1},
{1,0,0,0,0,0,1,0,1,1,1,1,1,1},
{1,1,4,0,4,0,1,0,1,3,3,3,1,0},
{0,1,0,1,1,0,0,0,0,0,3,3,1,0},
{0,1,0,0,0,0,1,0,0,0,3,3,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,0},
	};//地图
protected:
//	UIproduce GAME_ui;
	nun NUN;
	devil DEVIL;
};
#endif