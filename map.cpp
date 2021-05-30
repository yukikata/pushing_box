#include<stdio.h>
#include<graphics.h>//ͼ�ο�ͷ�ļ�
#include"main_game.h"
#include"map.h"
void MAP::loadmap()//����ͼƬ����
{
	mciSendString(L"open.//images//Approaching Nirvana - You.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	loadimage(&backImg, L".//images//����.JPG", 800, 800);//��Ե�ַ����ͼƬ
	loadimage(&wallImg, L".//images//ǽ��.JPG", 50, 50);
	loadimage(&blankImg, L".//images//�յ�.JPG", 50, 50);
	loadimage(&boxImg, L".//images//����.JPG", 50, 50);
	loadimage(&peoImg, L".//images//��.JPG", 50, 50);
	loadimage(&endImg, L".//images//Ŀ�ĵ�.JPG", 50, 50);
}
void MAP::drawmap()//���Ƶ�ͼ����
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
			case 8:putimage(i * 50, j * 50, &peoImg); break;//����Ŀ�ĵ�
			case 7:putimage(i * 50, j * 50, &boxImg); break;//������Ŀ�ĵ�
			}
		}
		printf("\n");
	}EndBatchDraw();
}
MAP::MAP() {};
MAP::~MAP() {};