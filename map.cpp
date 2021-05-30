#include<stdio.h>
#include<graphics.h>//图形库头文件
#include"main_game.h"
#include"map.h"
void MAP::loadmap()//载入图片函数
{
	mciSendString(L"open.//images//Approaching Nirvana - You.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	loadimage(&backImg, L".//images//背景.JPG", 800, 800);//相对地址载入图片
	loadimage(&wallImg, L".//images//墙壁.JPG", 50, 50);
	loadimage(&blankImg, L".//images//空地.JPG", 50, 50);
	loadimage(&boxImg, L".//images//箱子.JPG", 50, 50);
	loadimage(&peoImg, L".//images//人.JPG", 50, 50);
	loadimage(&endImg, L".//images//目的地.JPG", 50, 50);
}
void MAP::drawmap()//绘制地图函数
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
			case 0:putimage(i * 50, j * 50, &blankImg); break;
			case 1:putimage(i * 50, j * 50, &wallImg); break;
			case 3:putimage(i * 50, j * 50, &endImg); break;
			case 4:putimage(i * 50, j * 50, &boxImg); break;
			case 5:putimage(i * 50, j * 50, &peoImg); break;
			case 8:putimage(i * 50, j * 50, &peoImg); break;//人在目的地
			case 7:putimage(i * 50, j * 50, &boxImg); break;//箱子在目的地
			}
		}
		printf("\n");
	}EndBatchDraw();
}
MAP::MAP() {};
MAP::~MAP() {};