#pragma once
class MAP
{
public:
	MAP();
	~MAP();
	void drawmap();
	void loadmap();
private:
	IMAGE backImg, wallImg, blankImg, boxImg, darkImg, endImg, peoImg;//ͼƬ��������
};