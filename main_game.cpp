#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>//ͼ�ο�ͷ�ļ�
#include<mmsystem.h>
#include"ui.h"
#include"main_game.h"
#include"new_character.h"
void GAME::GameInit()//����ͼƬ����
{
	mciSendString(L"open.//images//Approaching Nirvana - You.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	loadimage(&backImg, L".//images//����.JPG", 800, 800);//��Ե�ַ����ͼƬ
	loadimage(&wallImg, L".//images//ǽ��.JPG", 50, 50);
	loadimage(&blankImg, L".//images//�յ�.JPG", 50, 50);
	loadimage(&boxImg, L".//images//����.JPG", 50, 50);
	loadimage(&peoImg, L".//images//��.JPG", 50, 50);
	loadimage(&endImg, L".//images//Ŀ�ĵ�.JPG", 50, 50);
	loadimage(&boxendImg, L".//images//������Ŀ�ĵ�.JPG", 50, 50);
	loadimage(&nunendImg, L".//images//��ʹ.JPG", 50, 50);
	loadimage(&devilendImg, L".//images//����.JPG", 50, 50);
}
void GAME::drawmap()//���Ƶ�ͼ����
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
			case 0:putimage(i * 50, j * 50, &blankImg); break;//�յ�
			case 1:putimage(i * 50, j * 50, &wallImg); break;//ǽ
			case 3:putimage(i * 50, j * 50, &endImg); break;//Ŀ�ĵ�
			case 4:putimage(i * 50, j * 50, &boxImg); break;//����
			case 5:putimage(i * 50, j * 50, &peoImg); break;//��
			case 8:putimage(i * 50, j * 50, &peoImg); break;//����Ŀ�ĵ�
			case 7:putimage(i * 50, j * 50, &boxendImg); break;//������Ŀ�ĵ�
			case 9:putimage(i * 50, j * 50, &nunendImg); break;//��ʹ
			case 10:putimage(i * 50, j * 50, &devilendImg); break;//��ħ
			}
		}
		printf("\n");
	}EndBatchDraw();
}
void GAME::playgame()//���̲�������
{
	char ch, ch0;
	int i, j;
	for (i = 0; i < 13; i++)//�����˵�λ��
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
	ch = _getch();//���ܼ�����Ϣ
	switch (ch)
	{
	case 'W':
	case 'w':
	case 72:
		if (map1[i][j - 1] == 0 || map1[i][j - 1] == 3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{

			map1[i][j - 1] += 5;
			map1[i][j] -= 5;

		}
		else if ((map1[i][j - 1] == 4 || map1[i][j - 1] == 7) && (map1[i][j - 2] != 1) && (map1[i][j - 2] != 4 )&& (map1[i][j - 2] != 7))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
		{

			map1[i][j - 2] += 4;
			map1[i][j - 1] += 1;
			map1[i][j] -= 5;


		}
		break;
	case 'S':
	case 's':
 	case 80:
		if (map1[i][j + 1] == 0 || map1[i][j + 1] == 3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{

			map1[i][j + 1] += 5;
			map1[i][j] -= 5;
		}
		else if ((map1[i][j + 1] == 4 || map1[i][j + 1] == 7) && (map1[i][j + 2] != 1) && (map1[i][j + 2] != 4) && (map1[i][j + 2] != 7))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
		{

			map1[i][j + 2] += 4;
			map1[i][j + 1] += 1;
			map1[i][j] -= 5;

		}
		break;
	case 'A':
	case 'a':
	case 75:
		if (map1[i - 1][j] == 0 || map1[i - 1][j] == 3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{

			map1[i - 1][j] += 5;
			map1[i][j] -= 5;

		}
		else if ((map1[i - 1][j] == 4 || map1[i - 1][j] == 7) && (map1[i - 2][j] != 1) && (map1[i - 2][j] != 4)&& (map1[i - 2][j] != 7))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
		{

			map1[i - 2][j] += 4;
			map1[i - 1][j] += 1;
			map1[i][j] -= 5;

		}
		else if ((map1[i - 1][j] == 9))//��һ�ط���Ů
		{
			NUN.activity();

		}
		else if ((map1[i - 1][j] == 10))//��һ�ط��Ƕ�ħ
		{
			DEVIL.activity();
		}
		break;
	case 'd':
	case 'D':
	case 77:
		if (map1[i + 1][j] == 0 || map1[i + 1][j] == 3)//��һ���ط��ǿյػ���Ŀ�ĵ�
		{

			map1[i + 1][j] += 5;
			map1[i][j] -= 5;

		}
		else if ((map1[i + 1][j] == 4 || map1[i + 1][j] == 7) && (map1[i + 2][j] != 1) && (map1[i + 2][j] != 4) && (map1[i + 2][j] != 7))//��һ�ط������ӣ������¸��ط��������ӻ���ǽ��
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