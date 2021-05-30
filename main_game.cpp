#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//图形库头文件
#include<mmsystem.h>
#include"ui.h"
#include"main_game.h"
#include"new_character.h"
void GAME::GameInit()//载入图片函数
{
	mciSendString(L"open.//images//Approaching Nirvana - You.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	loadimage(&backImg, L".//images//背景.JPG", 800, 800);//相对地址载入图片
	loadimage(&wallImg, L".//images//墙壁.JPG", 50, 50);
	loadimage(&blankImg, L".//images//空地.JPG", 50, 50);
	loadimage(&boxImg, L".//images//箱子.JPG", 50, 50);
	loadimage(&peoImg, L".//images//人.JPG", 50, 50);
	loadimage(&endImg, L".//images//目的地.JPG", 50, 50);
	loadimage(&boxendImg, L".//images//箱子在目的地.JPG", 50, 50);
	loadimage(&nunendImg, L".//images//天使.JPG", 50, 50);
	loadimage(&devilendImg, L".//images//幽灵.JPG", 50, 50);
}
void GAME::drawmap()//绘制地图函数
{
	BeginBatchDraw();
	putimage(0, 0, &backImg);
	int i, j;
		for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 14; j++)
		{
			switch (map1[i][j])
			{
			case 0:putimage(i * 50, j * 50, &blankImg); break;//空地
			case 1:putimage(i * 50, j * 50, &wallImg); break;//墙
			case 3:putimage(i * 50, j * 50, &endImg); break;//目的地
			case 4:putimage(i * 50, j * 50, &boxImg); break;//箱子
			case 5:putimage(i * 50, j * 50, &peoImg); break;//人
			case 8:putimage(i * 50, j * 50, &peoImg); break;//人在目的地
			case 7:putimage(i * 50, j * 50, &boxendImg); break;//箱子在目的地
			case 9:putimage(i * 50, j * 50, &nunendImg); break;//天使
			case 10:putimage(i * 50, j * 50, &devilendImg); break;//恶魔
			}
		}
		printf("\n");
	}EndBatchDraw();
}
void GAME::playgame()//键盘操作函数
{
	char ch, ch0;
	int i, j;
	for (i = 0; i < 13; i++)//定义人的位置
	{
		for (j = 0; j < 14; j++)
		{
			if (map1[i][j] == 5 || map1[i][j] == 8)
				break;
		}
		if (map1[i][j] == 5 || map1[i][j] == 8)
			break;
	}
	printf("%d  %d", i, j);
	//ch0 = ch;
	ch = _getch();//接受键盘信息
	switch (ch)
	{
	case 'W':
	case 'w':
	case 72:
		if (map1[i][j - 1] == 0 || map1[i][j - 1] == 3)//下一个地方是空地或者目的地
		{

			map1[i][j - 1] += 5;
			map1[i][j] -= 5;

		}
		else if ((map1[i][j - 1] == 4 || map1[i][j - 1] == 7) && (map1[i][j - 2] != 1) && (map1[i][j - 2] != 4 )&& (map1[i][j - 2] != 7))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{

			map1[i][j - 2] += 4;
			map1[i][j - 1] += 1;
			map1[i][j] -= 5;


		}
		break;
	case 'S':
	case 's':
 	case 80:
		if (map1[i][j + 1] == 0 || map1[i][j + 1] == 3)//下一个地方是空地或者目的地
		{

			map1[i][j + 1] += 5;
			map1[i][j] -= 5;
		}
		else if ((map1[i][j + 1] == 4 || map1[i][j + 1] == 7) && (map1[i][j + 2] != 1) && (map1[i][j + 2] != 4) && (map1[i][j + 2] != 7))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{

			map1[i][j + 2] += 4;
			map1[i][j + 1] += 1;
			map1[i][j] -= 5;

		}
		break;
	case 'A':
	case 'a':
	case 75:
		if (map1[i - 1][j] == 0 || map1[i - 1][j] == 3)//下一个地方是空地或者目的地
		{

			map1[i - 1][j] += 5;
			map1[i][j] -= 5;

		}
		else if ((map1[i - 1][j] == 4 || map1[i - 1][j] == 7) && (map1[i - 2][j] != 1) && (map1[i - 2][j] != 4)&& (map1[i - 2][j] != 7))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{

			map1[i - 2][j] += 4;
			map1[i - 1][j] += 1;
			map1[i][j] -= 5;

		}
		else if ((map1[i - 1][j] == 9))//下一地方是女
		{
			NUN.activity();

		}
		else if ((map1[i - 1][j] == 10))//下一地方是恶魔
		{
			DEVIL.activity();
		}
		break;
	case 'd':
	case 'D':
	case 77:
		if (map1[i + 1][j] == 0 || map1[i + 1][j] == 3)//下一个地方是空地或者目的地
		{

			map1[i + 1][j] += 5;
			map1[i][j] -= 5;

		}
		else if ((map1[i + 1][j] == 4 || map1[i + 1][j] == 7) && (map1[i + 2][j] != 1) && (map1[i + 2][j] != 4) && (map1[i + 2][j] != 7))//下一地方是箱子，但下下个地方不是箱子或者墙壁
		{
			map1[i + 2][j] += 4;
			map1[i + 1][j] += 1;
			map1[i][j] -= 5;
		}
		break;
		ch0 = ch;
/*	case 'b':
	case 'B':
		GAME_ui.breakgame();
		break;*/

	}
}
GAME::GAME() {};
GAME::~GAME() {};