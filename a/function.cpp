#include "Main.h"

static char id[11], idPass[50], idMap[50], idPlayer[50];

int passInfo[6];

//����ı�����
int move[4][2] = {      
	{0,-1},  //�� 72
	{1, 0},  //�� 77
	{0, 1},  //�� 80
	{-1,0}   //�� 75
};




//   �����������꣬��������
int idxFind(int x, int y, map *mp) {
	for (int i = 0; i < mp->count; i++) {
		if (x == mp->object[i].x  &&  y == mp->object[i].y)
			return i;
	}
	return -1;
}


//  ���յ��غ��жϣ� ���غϷ���1��
int judgeCover(int x, int y, map *p)
{
	for (int i = 0; i < p->count; i++)
	{
		if (x == p->finishPoint[i].x && y == p->finishPoint[i].y)
			return 1;
	}
	return 0;
}


//    �������ӵ��غ��ж�, �����㷵��1
int judgeAllCover(map *mp) {
	for (int i = 0; i < mp->count; i++) {
		if (judgeCover(mp->object[i].x, mp->object[i].y, mp) != 1) {
			return 0;    //  ����������һ����������δ����
		}
	}
	return 1;
}


//   ��ӡͼƬ����
void printPicture(int x, int y, Picture a)
{
	PIMAGE picture;
	picture = newimage();
	switch (a)
	{
	case 0:
		getimage(picture, "data/pic/floor.png");
		break;
	case 1:
		getimage(picture, "data/pic/box.png");
		break;
	case 2:
		getimage(picture, "data/pic/redbox.png");
		break;
	case 3:
		getimage(picture, "data/pic/finishpoint.png");
		break;
	case 4:
		getimage(picture, "data/pic/wall.png");
		break;
	case 5:
		getimage(picture, "data/pic/forward.png");
		break;
	case 6:
		getimage(picture, "data/pic/behind.png");
		break;
	case 7:
		getimage(picture, "data/pic/left.png");
		break;
	case 8:
		getimage(picture, "data/pic/right.png");
		break;
	case 9:
		getimage(picture, "data/pic/forwardpush.png");
		break;
	case 10:
		getimage(picture, "data/pic/behindpush.png");
		break;
	case 11:
		getimage(picture, "data/pic/leftpush.png");
		break;
	case 12:
		getimage(picture, "data/pic/rightpush.png");
		break;
	case 13:
		getimage(picture, "data/pic/background.jpg");
		break;
	case 14:
		getimage(picture, "data/pic/main11.jpg");   
		break;
	case 15:
		getimage(picture, "data/pic/main12.jpg");   
		break;
	case 16:
		getimage(picture, "data/pic/main13.jpg");   
		break;
	case 17:
		getimage(picture, "data/pic/main14.jpg");
		break;
	case 18:
		getimage(picture, "data/pic/pause1.jpg");  
		break;
	case 19:
		getimage(picture, "data/pic/pause2.jpg");
		break;
	case 20:
		getimage(picture, "data/pic/pause3.jpg");
		break;
	case 21:
		getimage(picture, "data/pic/main21.jpg");
		break;
	case 22:
		getimage(picture, "data/pic/main22.jpg");
		break;
	case 23:
		getimage(picture, "data/pic/main23.jpg");
		break;
	case 24:
		getimage(picture, "data/pic/main24.jpg");
		break;
	case 25:
		getimage(picture, "data/pic/main25.jpg");
		break;
	case 26:
		getimage(picture, "data/pic/pass.jpg");
		break;
	case 27:
		getimage(picture, "data/pic/pass-1.jpg");
		break;
	case 28:
		getimage(picture, "data/pic/pass-2.jpg");
		break;
	case 29:
		getimage(picture, "data/pic/pass-3.jpg");
		break;
	case 30:
		getimage(picture, "data/pic/pass-4.jpg");
		break;
	case 31:
		getimage(picture, "data/pic/pass-5.jpg");
		break;
	case 32:
		getimage(picture, "data/pic/pass-6.jpg");
		break;
	case 33:
		getimage(picture, "data/pic/pass12345.jpg");
		break;
	case 34:
		getimage(picture, "data/pic/pass12345-1.jpg");
		break;
	case 35:
		getimage(picture, "data/pic/pass12345-2.jpg");
		break;
	case 36:
		getimage(picture, "data/pic/pass12345-3.jpg");
		break;
	case 37:
		getimage(picture, "data/pic/pass12345-4.jpg");
		break;
	case 38:
		getimage(picture, "data/pic/pass12345-5.jpg");
		break;
	case 39:
		getimage(picture, "data/pic/pass1234.jpg");
		break;
	case 40:
		getimage(picture, "data/pic/pass1234-1.jpg");
		break;
	case 41:
		getimage(picture, "data/pic/pass1234-2.jpg");
		break;
	case 42:
		getimage(picture, "data/pic/pass1234-3.jpg");
		break;
	case 43:
		getimage(picture, "data/pic/pass1234-4.jpg");
		break;
	case 44:
		getimage(picture, "data/pic/pass123.jpg");
		break;
	case 45:
		getimage(picture, "data/pic/pass123-1.jpg");
		break;
	case 46:
		getimage(picture, "data/pic/pass123-2.jpg");
		break;
	case 47:
		getimage(picture, "data/pic/pass123-3.jpg");
		break;
	case 48:
		getimage(picture, "data/pic/pass12.jpg");
		break;
	case 49:
		getimage(picture, "data/pic/pass12-1.jpg");
		break;
	case 50:
		getimage(picture, "data/pic/pass12-2.jpg");
		break;
	case 51:
		getimage(picture, "data/pic/nopass.jpg");
		break;
	case 52:
		getimage(picture, "data/pic/nopass-1.jpg");
		break;
	case 53:
		getimage(picture, "data/pic/pause4.jpg");
		break;
	case 54:
		getimage(picture, "data/pic/pause5.jpg");
		break;
	case 55:
		getimage(picture, "data/pic/save1.jpg");
		break;
	case 56:
		getimage(picture, "data/pic/save2.jpg");
		break;
	case 57:
		getimage(picture, "data/pic/save3.jpg");
		break;
	case 58:
		getimage(picture, "data/pic/save4.jpg");
		break;
	case 59:
		getimage(picture, "data/pic/save5.jpg");
		break;
	case 60:
		getimage(picture, "data/pic/back1.jpg");
		break;
	case 61:
		getimage(picture, "data/pic/back2.jpg");
		break;
	case 62:
		getimage(picture, "data/pic/back3.jpg");
		break;
	case 63:
		getimage(picture, "data/pic/back4.jpg");
		break;
	case 64:
		getimage(picture, "data/pic/back5.jpg");
		break;
	case 65:
		getimage(picture, "data/pic/back6.jpg");
		break;
	case 66:
		getimage(picture, "data/pic/user1.jpg");
		break;
	case 67:
		getimage(picture, "data/pic/user2.jpg");
		break;
	case 68:
		getimage(picture, "data/pic/user3.jpg");
		break;
	case 69:
		getimage(picture, "data/pic/user4.jpg");
		break;
	case 70:
		getimage(picture, "data/pic/end1.jpg");
		break;
	case 71:
		getimage(picture, "data/pic/end2.jpg");
		break;
	case 72:
		getimage(picture, "data/pic/end3.jpg");
		break;
	case 73:
		getimage(picture, "data/pic/help1.jpg");
		break;
	case 74:
		getimage(picture, "data/pic/help2.jpg");
		break;
	}

	putimage(x, y, picture);
}


//  ��ͼ��ӡ
void printMap(map *m)
{
	cleardevice();
	printPicture(0, 0, BackGround);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (m->gameMap[i][j] == 1)
				printPicture(i*50, j*50 + 110, Wall);
			if (m->gameMap[i][j] == 2)
				printPicture(i * 50, j * 50 + 110, Floor);
		}
	}
	
	//��ӡ�յ�
	for (int i = 0; i < m->count; i++) {
		printPicture(m->finishPoint[i].x*50, m->finishPoint[i].y * 50 + 110, FinishPoint);
	}
	
	//��ӡ����
	for (int i = 0; i < m->count; i++) {
		if (judgeCover(m->object[i].x, m->object[i].y, m)) {
			printPicture(m->object[i].x * 50, m->object[i].y * 50 + 110, RedBox);
		}
		else {
			printPicture(m->object[i].x * 50, m->object[i].y * 50 + 110, Box);
		}
	}
	
//	setfont(-50,0,"����", 0,0 ,1000000, false, false, false);
	//setbkmode(0);
//	outtextxy(200, 700, "�ؿ�1");

	//��ӡ����
	printPicture(m->player.x * 50, m->player.y * 50 + 110, Forward);
}


//   ��ͼѡ���� idx = 0ʱΪ�û����룬��Ϊ0ʱΪָ���ؿ�
void mapChoice(int idx)
{
	FILE *fp;

	fp = fopen(idPass, "rb");
	fread(passInfo, sizeof(int), 6, fp);
	fclose(fp);

	people *pp;
	pp = (people *)malloc(sizeof(people));
	map *mp;
	mp = (map *)malloc(sizeof(map));


	mouse_msg msg = { 0 };
	getmouse(); //������������

	int count = 0;// ��¼������ڰ�ťλ��

	if (idx == 0) {
		

		//  ͨ��ǰ���
		if (passInfo[4] == 1) {

			cleardevice();
			printPicture(0, 0, Pass123456);
			count = 0;
			do {
				delay_fps(60); //������ʱ

				while (mousemsg())
				{
					msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
				}

				if (msg.y >= 29 && msg.y <= 709) {
					if (msg.y >= 29 && msg.y < 119) {
						if (count != 1) {
							cleardevice();
							printPicture(0, 0, Pass123456_1);
							count = 1;
						}
					}
					else if (msg.y >= 119 && msg.y < 206) {
						if (count != 2) {
							cleardevice();
							printPicture(0, 0, Pass123456_2);
							count = 2;
						}
					}
					else if (msg.y >= 206 && msg.y < 296) {
						if (count != 3) {
							cleardevice();
							printPicture(0, 0, Pass123456_3);
							count = 3;
						}
					}
					else if (msg.y >= 296 && msg.y < 383) {
						if (count != 4) {
							cleardevice();
							printPicture(0, 0, Pass123456_4);
							count = 4;
						}
					}
					else if (msg.y >= 383 && msg.y < 474) {
						if (count != 5) {
							cleardevice();
							printPicture(0, 0, Pass123456_5);
							count = 5;
						}
					}
					else if (msg.y >= 474 && msg.y <= 561) {
						if (count != 6) {
							cleardevice();
							printPicture(0, 0, Pass123456_6);
							count = 6;
						}
					}
					else if (msg.y >= 619 && msg.y <= 709) {
						if (count != 7) {
							cleardevice();
							printPicture(0, 0, Back6);
							count = 7;
						}
					}
					else {
						if (count != 0) {
							//  count != 0 �����Ӱ�ť�Ƴ�
							cleardevice();
							printPicture(0, 0, Pass123456);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Pass123456);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  ͨ��ǰ�Ĺ�
		else if (passInfo[3] == 1) {

			cleardevice();
			printPicture(0, 0, Pass12345);
			count = 0;
			do {
				delay_fps(60); //������ʱ

				while (mousemsg())
				{
					msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
				}

				if (msg.y >= 29 && msg.y <= 709) {
					if (msg.y >= 29 && msg.y < 119) {
						if (count != 1) {
							cleardevice();
							printPicture(0, 0, Pass12345_1);
							count = 1;
						}
					}
					else if (msg.y >= 119 && msg.y < 206) {
						if (count != 2) {
							cleardevice();
							printPicture(0, 0, Pass12345_2);
							count = 2;
						}
					}
					else if (msg.y >= 206 && msg.y < 296) {
						if (count != 3) {
							cleardevice();
							printPicture(0, 0, Pass12345_3);
							count = 3;
						}
					}
					else if (msg.y >= 296 && msg.y < 383) {
						if (count != 4) {
							cleardevice();
							printPicture(0, 0, Pass12345_4);
							count = 4;
						}
					}
					else if (msg.y >= 383 && msg.y < 474) {
						if (count != 5) {
							cleardevice();
							printPicture(0, 0, Pass12345_5);
							count = 5;
						}
					}
					else if (msg.y >= 619 && msg.y <= 709) {
						if (count != 7) {
							cleardevice();
							printPicture(0, 0, Back5);
							count = 7;
						}
					}
					else {
						if (count != 0) {
							//  count != 0 �����Ӱ�ť�Ƴ�
							cleardevice();
							printPicture(0, 0, Pass12345);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Pass12345);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  ͨ��ǰ����
		else if (passInfo[2] == 1) {
			cleardevice();
			printPicture(0, 0, Pass1234);
			count = 0;
			do {
				delay_fps(60); //������ʱ

				while (mousemsg())
				{
					msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
				}

				if (msg.y >= 29 && msg.y <= 709) {
					if (msg.y >= 29 && msg.y < 119) {
						if (count != 1) {
							cleardevice();
							printPicture(0, 0, Pass1234_1);
							count = 1;
						}
					}
					else if (msg.y >= 119 && msg.y < 206) {
						if (count != 2) {
							cleardevice();
							printPicture(0, 0, Pass1234_2);
							count = 2;
						}
					}
					else if (msg.y >= 206 && msg.y < 296) {
						if (count != 3) {
							cleardevice();
							printPicture(0, 0, Pass1234_3);
							count = 3;
						}
					}
					else if (msg.y >= 296 && msg.y < 383) {
						if (count != 4) {
							cleardevice();
							printPicture(0, 0, Pass1234_4);
							count = 4;
						}
					}
					else if (msg.y >= 619 && msg.y <= 709) {
						if (count != 7) {
							cleardevice();
							printPicture(0, 0, Back4);
							count = 7;
						}
					}
					else {
						if (count != 0) {
							//  count != 0 �����Ӱ�ť�Ƴ�
							cleardevice();
							printPicture(0, 0, Pass1234);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Pass1234);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  ͨ��ǰ����
		else if (passInfo[1] == 1) {
			cleardevice();
			printPicture(0, 0, Pass123);
			count = 0;
			do {
				delay_fps(60); //������ʱ

				while (mousemsg())
				{
					msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
				}

				if (msg.y >= 29 && msg.y <= 709) {
					if (msg.y >= 29 && msg.y < 119) {
						if (count != 1) {
							cleardevice();
							printPicture(0, 0, Pass123_1);
							count = 1;
						}
					}
					else if (msg.y >= 119 && msg.y < 206) {
						if (count != 2) {
							cleardevice();
							printPicture(0, 0, Pass123_2);
							count = 2;
						}
					}
					else if (msg.y >= 206 && msg.y < 296) {
						if (count != 3) {
							cleardevice();
							printPicture(0, 0, Pass123_3);
							count = 3;
						}
					}
					else if (msg.y >= 619 && msg.y <= 709) {
						if (count != 7) {
							cleardevice();
							printPicture(0, 0, Back3);
							count = 7;
						}
					}
					else {
						if (count != 0) {
							//  count != 0 �����Ӱ�ť�Ƴ�
							cleardevice();
							printPicture(0, 0, Pass123);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Pass123);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  ͨ��ǰһ��
		else if (passInfo[0] == 1) {
			cleardevice();
			printPicture(0, 0, Pass12);
			count = 0;
			do {
				delay_fps(60); //������ʱ

				while (mousemsg())
				{
					msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
				}

				if (msg.y >= 29 && msg.y <= 709) {
					if (msg.y >= 29 && msg.y < 119) {
						if (count != 1) {
							cleardevice();
							printPicture(0, 0, Pass12_1);
							count = 1;
						}
					}
					else if (msg.y >= 119 && msg.y < 206) {
						if (count != 2) {
							cleardevice();
							printPicture(0, 0, Pass12_2);
							count = 2;
						}
					}
					else if (msg.y >= 619 && msg.y <= 709) {
						if (count != 7) {
							cleardevice();
							printPicture(0, 0, Back2);
							count = 7;
						}
					}
					else {
						if (count != 0) {
							//  count != 0 �����Ӱ�ť�Ƴ�
							cleardevice();
							printPicture(0, 0, Pass12);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Pass12);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  δͨ��
		else {
			cleardevice();
			printPicture(0, 0, Pass1);
			count = 0;
			do {
				delay_fps(60); //������ʱ

				while (mousemsg())
				{
					msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
				}

				if (msg.y >= 29 && msg.y <= 709) {
					if (msg.y >= 29 && msg.y < 119) {
						if (count != 1) {
							cleardevice();
							printPicture(0, 0, Pass1_1);
							count = 1;
						}
					}
					else if (msg.y >= 619 && msg.y <= 709) {
						if (count != 7) {
							cleardevice();
							printPicture(0, 0, Back1);
							count = 7;
						}
					}
					else {
						if (count != 0) {
							//  count != 0 �����Ӱ�ť�Ƴ�
							cleardevice();
							printPicture(0, 0, Pass1);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Pass1);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
	}
	else {
		count = idx;
	}
	
	//  ����countѡ��ؿ�
	switch (count) {
	case 1:
		fp = fopen("data\\map\\map1.bat", "rb");
		fread(mp, sizeof(map), 1, fp);
		*pp = mp->player;
		pp->next = NULL;
		pp->isPush = 0;
		printMap(mp);
		fclose(fp);
		gameStart(mp, pp, 0);
		return;
	case 2:
		fp = fopen("data\\map\\map2.bat", "rb");
		fread(mp, sizeof(map), 1, fp);
		*pp = mp->player;
		pp->next = NULL;
		pp->isPush = 0;
		printMap(mp);
		fclose(fp);
		gameStart(mp, pp, 1);
		return;
	case 3:
		fp = fopen("data\\map\\map3.bat", "rb");
		fread(mp, sizeof(map), 1, fp);
		*pp = mp->player;
		pp->next = NULL;
		pp->isPush = 0;
		printMap(mp);
		fclose(fp);
		gameStart(mp, pp, 2);
		return;
	case 4:
		fp = fopen("data\\map\\map4.bat", "rb");
		fread(mp, sizeof(map), 1, fp);
		*pp = mp->player;
		pp->next = NULL;
		pp->isPush = 0;
       		printMap(mp);
		fclose(fp);
		gameStart(mp, pp, 3);
		return;
	case 5:
		fp = fopen("data\\map\\map5.bat", "rb");
		fread(mp, sizeof(map), 1, fp);
		*pp = mp->player;
		pp->next = NULL;
		pp->isPush = 0;
		printMap(mp);
		fclose(fp);
		gameStart(mp, pp, 4);
		return;
	case 6:
		fp = fopen("data\\map\\map6.bat", "rb");
		fread(mp, sizeof(map), 1, fp);
		*pp = mp->player;
		pp->next = NULL;
		pp->isPush = 0;
		printMap(mp);
		fclose(fp);
		gameStart(mp, pp, 5);
		return;
	}
}



//  ����Ƿ�ʧ����.����д��id���û���Ϣ  1�Ƕ�ʧ��0Ϊδ��ʧ
bool checkInfo(char ch[])
{
	FILE *fp;
	strcpy(id, ch);

	sprintf(idPass, "data\\Info\\%s\\passInfo.bat", id);
	sprintf(idMap, "data\\Info\\%s\\archiveMap.bat", id);
	sprintf(idPlayer, "data\\Info\\%s\\archivePlayer.bat", id);

	//  ��ͼ���ݼ��

	if ((fp = fopen("data\\map\\map1.bat", "rb")) == NULL)
		return true;
	else
		fclose(fp);

	if ((fp = fopen("data\\map\\map2.bat", "rb")) == NULL)
		return true;
	else
		fclose(fp);

	if ((fp = fopen("data\\map\\map3.bat", "rb")) == NULL)
		return true;
	else
		fclose(fp);

	if ((fp = fopen("data\\map\\map4.bat", "rb")) == NULL)
		return true;
	else
		fclose(fp);

	if ((fp = fopen("data\\map\\map5.bat", "rb")) == NULL)
		return true;
	else
		fclose(fp);

	if ((fp = fopen("data\\map\\map6.bat", "rb")) == NULL)
		return true;
	else
		fclose(fp);



	if ((fp = fopen(idPass, "rb")) == NULL)
		return true;
	else
		fclose(fp);

	return false;
}


//   ������һ���ж�(���жϲ��ı�ֵ)�� int ��ʾ����  0�� 1�� 2�� 3��  ����ֵ
int judgePlayerNext(int a,map *mp, people *pp) {
	for (int i = 0; i < mp->count; i++) {
		if (pp->x + move[a][0] == mp->object[i].x && pp->y + move[a][1] == mp->object[i].y)
			return 1;   //��һ��������
	}
	
	if (mp->gameMap[pp->x + move[a][0]][pp->y + move[a][1]] == 1)
		return 0;    //��һ����ǽ

	return 2;   //��һ��Ϊ��
}



//   ������һ���ж�(���жϲ��ı�ֵ)�� ���� 1���ϰ� ����0���ϰ�
int judgeBoxNext(int a, map *mp, people *pp) {
	for (int i = 0; i < mp->count; i++) {
		if (pp->x + 2 * move[a][0] == mp->object[i].x && pp->y + 2 * move[a][1] == mp->object[i].y)
			return 1;   //��һ��������
	}
	
	if (mp->gameMap[pp->x + 2 * move[a][0]][pp->y + 2 * move[a][1]] == 1)
		return 1;    //��һ����ǽ
	return 0;    //��һ��Ϊ��
}


//   �ж���һ������һ����λ�ù�ϵ  ����ֵΪmove����
int judgeDir(people *pp) {
	int x = pp->x - pp->next->x;
	int y = pp->y - pp->next->y;

	for (int i = 0; i < 4; i++){
		if (x == move[i][0] && y == move[i][1])
			return i;
	}
	return -1;
}


//   �浵����
void gameSave(map *mp, people *pp, int I) {
	FILE *fp;
	
	//    �����ϴδ浵
	fp = fopen(idMap, "wb+");

	fwrite(&I, sizeof(int), 1, fp);  //д�뵱ǰ�ؿ���

	fwrite(mp, sizeof(map), 1, fp);

	fclose(fp);


	fp = fopen(idPlayer, "wb+");

	people *p;

	p = pp;
	while (p != NULL) {
		fwrite(p, sizeof(people), 1, fp);
		p = p->next;
	}

	fclose(fp);
}

//   ����ѡ����
void endChoice(int idx) {
	int count = 0;
	mouse_msg msg = { 0 };
	printPicture(0, 250, End1);

	getmouse();
	do {
		delay_fps(60);

		while (mousemsg()) {
			msg = getmouse();
		}

		if (msg.y >= 368 && msg.y <= 450) {
			if (msg.x >= 0 && msg.x <= 250) {
				if (count != 1) {
					printPicture(0, 250, End2);
					count = 1;
				}
			}
			if (msg.x > 250 && msg.x <= 500) {
				if (count != 2) {
					printPicture(0, 250,End3);
					count = 2;
				}
			}
		}
		else if (count != 0) {
			printPicture(0, 250, End1);
			count = 0;
		}

	} while (!msg.is_left() || count == 0);

	switch (count) {
	case 1:
		mapChoice(0);
		return;
	case 2:
		mapChoice(idx + 2);
		return;
	}
}

//    help�˵�����
void help() {
	mouse_msg msg = { 0 };
	int count = 0;
	printPicture(0, 0, Help1);
	do {
		delay_fps(60);

		while (mousemsg())
		{
			msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
		}

		if (msg.y > 650) {
			if (count != 1) {
				count = 1;
				printPicture(0, 0, Help2);
			}
		}
		else {
			if (count != 0) {
				count = 0;
				printPicture(0, 0, Help1);
			}
		}

	} while (!msg.is_left() || count == 0);
}

//  ��Ϸ�������庯��  �����������������˵��ж�   //IΪ��ǰ�ؿ���
void gameStart(map *mp, people *pp, int I)
{
	people *p;

	while (1)
	{
	here2:	
		char ch;
		ch = getch();

		//    �ƶ�
		switch (ch)
		{
		case 38: //�� 
			switch (judgePlayerNext(0, mp, pp))
				{
				case 0:  //��һ����ǽ
					break;
				case 1:  //��һ��������
					//  �ٴ��ж�
					switch (judgeBoxNext(0, mp, pp))
					{
					case 0:    //���ϰ�,����ƶ�
						// �����½�㣬������Ϣ
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[0][0];
						p->y = pp->y + move[0][1];

						p->isPush = 1;  //�ƶ�����

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //��������ԭλ��

						p->afterPushX = p->x + move[0][0];
						p->afterPushY = p->y + move[0][1];  //�������Ӷ�֮���λ��

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // �޸�mp�е�����λ��
						//  ��������������
						p->next = pp;
						pp = p; 
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//��ӡ��λ��
						printPicture(pp->x * 50, pp->y * 50 + 110, BehindPush);
						//��ԭԭλ��
						if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   ��Ϸ�����ж�
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//д�뵱ǰ�ؿ����
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //�ͷ�ռ�ÿռ�
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					case 1:
						break;  //���ϰ�
					}
					break;
				case 2:  //��һ��Ϊ��
					//  �����½ڵ㣬 �洢��Ϣ
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[0][0];
					p->y = pp->y + move[0][1];
					p->isPush = 0;  //δ������
					//  ��������������
					p->next = pp;
					pp = p;
					p = p->next;
					//��ӡ��λ��
					printPicture(pp->x * 50, pp->y * 50 + 110, Behind);
					//��ԭԭλ��
					if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}

			break;
		case 39: //��
			switch (judgePlayerNext(1, mp, pp))
				{
				case 0:  //��һ����ǽ
					break;
				case 1:  //��һ��������
					//  �ٴ��ж�
					switch (judgeBoxNext(1, mp, pp))
					{
					case 0:    //���ϰ�,����ƶ�
						// �����½�㣬������Ϣ
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[1][0];
						p->y = pp->y + move[1][1];

						p->isPush = 1;  //�ƶ�����

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //��������ԭλ��

						p->afterPushX = p->x + move[1][0];
						p->afterPushY = p->y + move[1][1];  //�������Ӷ�֮���λ��

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // �޸�mp�е�����λ��


						//  ��������������
						p->next = pp;
						pp = p;
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//��ӡ��λ��
						printPicture(pp->x * 50, pp->y * 50 + 110, RightPush);
						//��ԭԭλ��
						if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   ��Ϸ�����ж�
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//д�뵱ǰ�ؿ����
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //�ͷ�ռ�ÿռ�
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					}
					break;
				case 2:  //��һ��Ϊ��
						//  �����½ڵ㣬 �洢��Ϣ
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[1][0];
					p->y = pp->y + move[1][1];
					p->isPush = 0;  //δ������
					//  ��������������
					p->next = pp;
					pp = p;
					p = p->next;
					//��ӡ��λ��
					printPicture(pp->x * 50, pp->y * 50 + 110, Right);
					//��ԭԭλ��
					if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}
				
			break;
		case 40: //��
			switch (judgePlayerNext(2, mp, pp))
				{
				case 0:  //��һ����ǽ
					break;
				case 1:  //��һ��������
					//  �ٴ��ж�
					//  �ٴ��ж�
					switch (judgeBoxNext(2, mp, pp))
					{
					case 0:    //���ϰ�,����ƶ�
						// �����½�㣬������Ϣ
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[2][0];
						p->y = pp->y + move[2][1];

						p->isPush = 1;  //�ƶ�����

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //��������ԭλ��

						p->afterPushX = p->x + move[2][0];
						p->afterPushY = p->y + move[2][1];  //�������Ӷ�֮���λ��

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // �޸�mp�е�����λ��

						//  ��������������
						p->next = pp;
						pp = p;
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//��ӡ��λ��
						printPicture(pp->x * 50, pp->y * 50 + 110, ForwardPush);
						//��ԭԭλ��
						if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   ��Ϸ�����ж�
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//д�뵱ǰ�ؿ����
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //�ͷ�ռ�ÿռ�
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					case 1:
						break;  //���ϰ�
					}
					break;
				case 2:  //��һ��Ϊ��
					//  �����½ڵ㣬 �洢��Ϣ
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[2][0];
					p->y = pp->y + move[2][1];
					p->isPush = 0;  //δ������
					//  ��������������
					p->next = pp;
					pp = p;
					p = p->next;
					//��ӡ��λ��
					printPicture(pp->x * 50, pp->y * 50 + 110, Forward);
					//��ԭԭλ��
					if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}
	
			break;
		case 37: //��
			switch (judgePlayerNext(3, mp, pp))
				{
				case 0:  //��һ����ǽ
					break;
				case 1:  //��һ��������
					//  �ٴ��ж�
					//  �ٴ��ж�
					switch (judgeBoxNext(3, mp, pp))
					{
					case 0:    //���ϰ�,����ƶ�
						// �����½�㣬������Ϣ
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[3][0];
						p->y = pp->y + move[3][1];

						p->isPush = 1;  //�ƶ�����

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //��������ԭλ��

						p->afterPushX = p->x + move[3][0];
						p->afterPushY = p->y + move[3][1];  //�������Ӷ�֮���λ��

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // �޸�mp�е�����λ��

						//  ��������������
						p->next = pp;
						pp = p;
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//��ӡ��λ��
						printPicture(pp->x * 50, pp->y * 50 + 110, LeftPush);
						//��ԭԭλ��
						if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   ��Ϸ�����ж�
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//д�뵱ǰ�ؿ����
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //�ͷ�ռ�ÿռ�
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					case 1:
						break;  //���ϰ�
					}
					break;
				case 2:  //��һ��Ϊ��
					//  �����½ڵ㣬 �洢��Ϣ
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[3][0];
					p->y = pp->y + move[3][1];
					p->isPush = 0;  //δ������
					//  ��������������
					p->next = pp;
					pp = p;
					p = p->next;
					//��ӡ��λ��
					printPicture(pp->x * 50, pp->y * 50 + 110, Left);
					//��ԭԭλ��
					if (judgeCover(p->x, p->y, mp)) {  //ԭλ��Ϊ�յ�
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}

			break;
		}

		//    ����˵�   ����������������ʱ����
		if (ch == 27) {
			mp->player.x = pp->x;
			mp->player.y = pp->y;    //�����λ����ʱ�����mp��
			
			
			getmouse(); //������������
			int count = 0;// ��¼������ڰ�ťλ��
// ʹ�洢����ʾ����ѡ���ܻص��˵�
here:		
			mouse_msg msg = { 0 };
			cleardevice();
			printPicture(0, 0, Pause1);

			do {
				delay_fps(60); //������ʱ

				while (mousemsg())
				{
					msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
				}

				//cleardevice();//���ǰ��
				if (msg.y >= 147 && msg.y <= 502) {
					//   λ�ڵ�һ����ť
					if (msg.y >= 147 && msg.y < 238) {

						if (count != 1) {
							//   ǰһ��ͼ��Ϊ��ťһ��ͼ
							cleardevice();
							printPicture(0, 0, Pause2);
							count = 1;
						}
					}
					//   λ�ڵڶ�����ť
					else if (msg.y >= 238 && msg.y < 323) {

						if (count != 2) {
							cleardevice();
							printPicture(0, 0, Pause3);
							count = 2;
						}
					}
					//   λ�ڵ�������ť
					else if (msg.y >= 323 && msg.y < 416) {

						if (count != 3) {
							cleardevice();
							printPicture(0, 0, Pause4);
							count = 3;
						}
					}
					//   λ�ڵ��ĸ���ť
					else if (msg.y >= 416 && msg.y <= 502) {
						if (count != 4) {
							cleardevice();
							printPicture(0, 0, Pause5);
							count = 4;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Pause1);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
			// ѭ��������ڿ�ڵ��Ϊֹ

			FILE *fp = NULL, *fq = NULL;

			switch (count) {
			case 1:   //������Ϸ
				printMap(mp);   //��ӡ��ͼ
				goto here2;
			case 2:
				
				if ((fp = fopen(idMap, "rb")) == NULL || (fq = fopen(idPlayer, "rb")) == NULL) {
					//�д浵
					gameSave(mp, pp, I);
					msg = { 0 };
					count = 0;// ��¼������ڰ�ťλ��

					printPicture(0, 250, Save1);
					getmouse();
					do {
						delay_fps(60);

						while (mousemsg()) {
							msg = getmouse();
						}

						if (msg.y >= 368 && msg.y <= 450) {
							if (count != 1) {
								printPicture(0, 250, Save2);
								count = 1;
							}
						}
						else if (count != 0) {
							printPicture(0, 250, Save1);
							count = 0;
						}

					} while (!msg.is_left() || count == 0);

					
				}
				else {
					//�޴浵
					msg = { 0 };
					count = 0;// ��¼������ڰ�ťλ��

					printPicture(0, 250, Save3);
					getmouse();
					do {
						delay_fps(60);

						while (mousemsg()) {
							msg = getmouse();
						}

						if (msg.y >= 368 && msg.y <= 450) {
							if (msg.x >= 0 && msg.x <= 250) {
								if (count != 1) {
									printPicture(0, 250, Save4);
									count = 1;
								}
							}
							if (msg.x > 250 && msg.x <= 500) {
								if (count != 2) {
									printPicture(0, 250, Save5);
									count = 2;
								}
							}
						}
						else if (count != 0) {
							printPicture(0, 250, Save3);
							count = 0;
						}

					} while (!msg.is_left() || count == 0);

					if (count == 1) {
						gameSave(mp, pp, I);
						msg = { 0 };
						count = 0;// ��¼������ڰ�ťλ��

						printPicture(0, 250, Save1);
						getmouse();
						do {
							delay_fps(60);

							while (mousemsg()) {
								msg = getmouse();
							}

							if (msg.x >= 133 && msg.x <= 365) {
								if (msg.y >= 395 && msg.y <= 448) {
									if (count != 1) {
										printPicture(0, 250, Save2);
										count = 1;
									}
								}
							}
							else if (count != 0) {
								printPicture(0, 250, Save1);
								count = 0;
							}

						} while (!msg.is_left() || count == 0);
					}
				}
				
				//������ɺ󷵻ر��˵�
				getmouse(); //��ջ���
				msg = { 0 };
				count = 0;
				goto here;
				break;  //������Ϸ����
			case 3:
				//������ɺ󷵻ر��˵�
				help();
				getmouse(); //��ջ���
				msg = { 0 };
				count = 0;
				goto here;
				break;  //������Ϸ����
			case 4:
				free(mp);   //�ͷ�ռ�ÿռ�
				free(pp);
				return;
			}
		}
		
	
		//  ��һ��
		if (ch == 32) {
			if (pp->next != NULL) {

				//  �жϵ�ǰ��һ���Ƿ��ƶ�����  ��Ϊ�ƶ�
				if (pp->isPush == 1) {
				if (judgeCover(pp->afterPushX, pp->afterPushY, mp)){
					//    ��ǰ����λ��Ϊ������
					printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, FinishPoint);
				}
				else {
					//    ��ǰ����λ��Ϊ������
					printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Floor);
				}

				if (judgeCover(pp->beforPushX, pp->beforPushY, mp)) {
					//    ǰһ������λ��Ϊ������
					printPicture(pp->beforPushX * 50, pp->beforPushY * 50 + 110, RedBox);
				}
				else {
					//    ǰһ������λ��Ϊ������
					printPicture(pp->beforPushX * 50, pp->beforPushY * 50 + 110, Box);
				}

				mp->object[idxFind(pp->afterPushX, pp->afterPushY, mp)].x = pp->beforPushX;
				mp->object[idxFind(pp->beforPushX, pp->afterPushY, mp)].y = pp->beforPushY;  //��mp�иı�����λ��

				switch (judgeDir(pp)) {
				case 0:  
					printPicture(pp->next->x * 50, pp->next->y * 50 + 110, BehindPush);
					break;
				case 1:
					printPicture(pp->next->x * 50, pp->next->y * 50 + 110, RightPush);
					break;
				case 2:
					printPicture(pp->next->x * 50, pp->next->y * 50 + 110, ForwardPush);
					break;
				case 3:
					printPicture(pp->next->x * 50, pp->next->y * 50 + 110, LeftPush);
					break;
				}
				people *p;
				p = pp;
				pp = pp->next;
				p->next = NULL;  //��p���ֱ�ͷ

				free(p);   //�ͷ��ڴ�
			}


				//   δ�ƶ�����
				else {
					if (judgeCover(pp->x, pp->y, mp)) {
						printPicture(pp->x * 50, pp->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(pp->x * 50, pp->y * 50 + 110, Floor);
					}

					switch (judgeDir(pp)) {
					case 0:
						printPicture(pp->next->x * 50, pp->next->y * 50 + 110, Behind);
						break;
					case 1:
						printPicture(pp->next->x * 50, pp->next->y * 50 + 110, Right);
						break;
					case 2:
						printPicture(pp->next->x * 50, pp->next->y * 50 + 110, Forward);
						break;
					case 3:
						printPicture(pp->next->x * 50, pp->next->y * 50 + 110, Left);
						break;
					}
					people *p;
					p = pp;
					pp = pp->next;
					p->next = NULL;  //��p���ֱ�ͷ

					free(p);   //�ͷ��ڴ�
				}
			}
		}
	
	}
}
