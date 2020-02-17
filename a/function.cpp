#include "Main.h"

static char id[11], idPass[50], idMap[50], idPlayer[50];

int passInfo[6];

//方向改变数组
int move[4][2] = {      
	{0,-1},  //上 72
	{1, 0},  //右 77
	{0, 1},  //下 80
	{-1,0}   //左 75
};




//   输入箱子坐标，返回索引
int idxFind(int x, int y, map *mp) {
	for (int i = 0; i < mp->count; i++) {
		if (x == mp->object[i].x  &&  y == mp->object[i].y)
			return i;
	}
	return -1;
}


//  与终点重合判断， 若重合返回1，
int judgeCover(int x, int y, map *p)
{
	for (int i = 0; i < p->count; i++)
	{
		if (x == p->finishPoint[i].x && y == p->finishPoint[i].y)
			return 1;
	}
	return 0;
}


//    所有箱子的重合判断, 都满足返回1
int judgeAllCover(map *mp) {
	for (int i = 0; i < mp->count; i++) {
		if (judgeCover(mp->object[i].x, mp->object[i].y, mp) != 1) {
			return 0;    //  遍历，若有一个不符合则还未结束
		}
	}
	return 1;
}


//   打印图片函数
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


//  地图打印
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
	
	//打印终点
	for (int i = 0; i < m->count; i++) {
		printPicture(m->finishPoint[i].x*50, m->finishPoint[i].y * 50 + 110, FinishPoint);
	}
	
	//打印箱子
	for (int i = 0; i < m->count; i++) {
		if (judgeCover(m->object[i].x, m->object[i].y, m)) {
			printPicture(m->object[i].x * 50, m->object[i].y * 50 + 110, RedBox);
		}
		else {
			printPicture(m->object[i].x * 50, m->object[i].y * 50 + 110, Box);
		}
	}
	
//	setfont(-50,0,"黑体", 0,0 ,1000000, false, false, false);
	//setbkmode(0);
//	outtextxy(200, 700, "关卡1");

	//打印人物
	printPicture(m->player.x * 50, m->player.y * 50 + 110, Forward);
}


//   地图选择函数 idx = 0时为用户输入，不为0时为指定关卡
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
	getmouse(); //清除鼠标区缓存

	int count = 0;// 记录鼠标所在按钮位置

	if (idx == 0) {
		

		//  通过前五关
		if (passInfo[4] == 1) {

			cleardevice();
			printPicture(0, 0, Pass123456);
			count = 0;
			do {
				delay_fps(60); //设置延时

				while (mousemsg())
				{
					msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
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
							//  count != 0 即鼠标从按钮移出
							cleardevice();
							printPicture(0, 0, Pass123456);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
					cleardevice();
					printPicture(0, 0, Pass123456);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  通过前四关
		else if (passInfo[3] == 1) {

			cleardevice();
			printPicture(0, 0, Pass12345);
			count = 0;
			do {
				delay_fps(60); //设置延时

				while (mousemsg())
				{
					msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
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
							//  count != 0 即鼠标从按钮移出
							cleardevice();
							printPicture(0, 0, Pass12345);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
					cleardevice();
					printPicture(0, 0, Pass12345);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  通过前三关
		else if (passInfo[2] == 1) {
			cleardevice();
			printPicture(0, 0, Pass1234);
			count = 0;
			do {
				delay_fps(60); //设置延时

				while (mousemsg())
				{
					msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
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
							//  count != 0 即鼠标从按钮移出
							cleardevice();
							printPicture(0, 0, Pass1234);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
					cleardevice();
					printPicture(0, 0, Pass1234);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  通过前二关
		else if (passInfo[1] == 1) {
			cleardevice();
			printPicture(0, 0, Pass123);
			count = 0;
			do {
				delay_fps(60); //设置延时

				while (mousemsg())
				{
					msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
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
							//  count != 0 即鼠标从按钮移出
							cleardevice();
							printPicture(0, 0, Pass123);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
					cleardevice();
					printPicture(0, 0, Pass123);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  通过前一关
		else if (passInfo[0] == 1) {
			cleardevice();
			printPicture(0, 0, Pass12);
			count = 0;
			do {
				delay_fps(60); //设置延时

				while (mousemsg())
				{
					msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
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
							//  count != 0 即鼠标从按钮移出
							cleardevice();
							printPicture(0, 0, Pass12);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
					cleardevice();
					printPicture(0, 0, Pass12);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
		}
		//  未通关
		else {
			cleardevice();
			printPicture(0, 0, Pass1);
			count = 0;
			do {
				delay_fps(60); //设置延时

				while (mousemsg())
				{
					msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
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
							//  count != 0 即鼠标从按钮移出
							cleardevice();
							printPicture(0, 0, Pass1);
							count = 0;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
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
	
	//  根据count选择关卡
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



//  检查是否丢失数据.并且写死id等用户信息  1是丢失，0为未丢失
bool checkInfo(char ch[])
{
	FILE *fp;
	strcpy(id, ch);

	sprintf(idPass, "data\\Info\\%s\\passInfo.bat", id);
	sprintf(idMap, "data\\Info\\%s\\archiveMap.bat", id);
	sprintf(idPlayer, "data\\Info\\%s\\archivePlayer.bat", id);

	//  地图数据检测

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


//   人物下一步判断(仅判断不改变值)， int 表示方向  0上 1右 2下 3左  返回值
int judgePlayerNext(int a,map *mp, people *pp) {
	for (int i = 0; i < mp->count; i++) {
		if (pp->x + move[a][0] == mp->object[i].x && pp->y + move[a][1] == mp->object[i].y)
			return 1;   //下一步有箱子
	}
	
	if (mp->gameMap[pp->x + move[a][0]][pp->y + move[a][1]] == 1)
		return 0;    //下一步有墙

	return 2;   //下一步为空
}



//   箱子下一步判断(仅判断不改变值)， 返回 1有障碍 返回0无障碍
int judgeBoxNext(int a, map *mp, people *pp) {
	for (int i = 0; i < mp->count; i++) {
		if (pp->x + 2 * move[a][0] == mp->object[i].x && pp->y + 2 * move[a][1] == mp->object[i].y)
			return 1;   //下一步有箱子
	}
	
	if (mp->gameMap[pp->x + 2 * move[a][0]][pp->y + 2 * move[a][1]] == 1)
		return 1;    //下一步有墙
	return 0;    //下一步为空
}


//   判断上一步与这一步的位置关系  返回值为move索引
int judgeDir(people *pp) {
	int x = pp->x - pp->next->x;
	int y = pp->y - pp->next->y;

	for (int i = 0; i < 4; i++){
		if (x == move[i][0] && y == move[i][1])
			return i;
	}
	return -1;
}


//   存档函数
void gameSave(map *mp, people *pp, int I) {
	FILE *fp;
	
	//    覆盖上次存档
	fp = fopen(idMap, "wb+");

	fwrite(&I, sizeof(int), 1, fp);  //写入当前关卡数

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

//   结束选择函数
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

//    help菜单函数
void help() {
	mouse_msg msg = { 0 };
	int count = 0;
	printPicture(0, 0, Help1);
	do {
		delay_fps(60);

		while (mousemsg())
		{
			msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
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

//  游戏运作主体函数  返回数用作返回主菜单判断   //I为当前关卡数
void gameStart(map *mp, people *pp, int I)
{
	people *p;

	while (1)
	{
	here2:	
		char ch;
		ch = getch();

		//    移动
		switch (ch)
		{
		case 38: //上 
			switch (judgePlayerNext(0, mp, pp))
				{
				case 0:  //下一步有墙
					break;
				case 1:  //下一步有箱子
					//  再次判断
					switch (judgeBoxNext(0, mp, pp))
					{
					case 0:    //无障碍,则均移动
						// 创建新结点，储存信息
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[0][0];
						p->y = pp->y + move[0][1];

						p->isPush = 1;  //推动箱子

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //储存箱子原位置

						p->afterPushX = p->x + move[0][0];
						p->afterPushY = p->y + move[0][1];  //储存箱子动之后的位置

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // 修改mp中的箱子位置
						//  将结点放在链表首
						p->next = pp;
						pp = p; 
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//打印新位置
						printPicture(pp->x * 50, pp->y * 50 + 110, BehindPush);
						//还原原位置
						if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   游戏结束判读
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//写入当前关卡完成
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //释放占用空间
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					case 1:
						break;  //有障碍
					}
					break;
				case 2:  //下一步为空
					//  创建新节点， 存储信息
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[0][0];
					p->y = pp->y + move[0][1];
					p->isPush = 0;  //未推箱子
					//  将结点放在链表首
					p->next = pp;
					pp = p;
					p = p->next;
					//打印新位置
					printPicture(pp->x * 50, pp->y * 50 + 110, Behind);
					//还原原位置
					if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}

			break;
		case 39: //右
			switch (judgePlayerNext(1, mp, pp))
				{
				case 0:  //下一步有墙
					break;
				case 1:  //下一步有箱子
					//  再次判断
					switch (judgeBoxNext(1, mp, pp))
					{
					case 0:    //无障碍,则均移动
						// 创建新结点，储存信息
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[1][0];
						p->y = pp->y + move[1][1];

						p->isPush = 1;  //推动箱子

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //储存箱子原位置

						p->afterPushX = p->x + move[1][0];
						p->afterPushY = p->y + move[1][1];  //储存箱子动之后的位置

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // 修改mp中的箱子位置


						//  将结点放在链表首
						p->next = pp;
						pp = p;
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//打印新位置
						printPicture(pp->x * 50, pp->y * 50 + 110, RightPush);
						//还原原位置
						if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   游戏结束判读
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//写入当前关卡完成
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //释放占用空间
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					}
					break;
				case 2:  //下一步为空
						//  创建新节点， 存储信息
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[1][0];
					p->y = pp->y + move[1][1];
					p->isPush = 0;  //未推箱子
					//  将结点放在链表首
					p->next = pp;
					pp = p;
					p = p->next;
					//打印新位置
					printPicture(pp->x * 50, pp->y * 50 + 110, Right);
					//还原原位置
					if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}
				
			break;
		case 40: //下
			switch (judgePlayerNext(2, mp, pp))
				{
				case 0:  //下一步有墙
					break;
				case 1:  //下一步有箱子
					//  再次判断
					//  再次判断
					switch (judgeBoxNext(2, mp, pp))
					{
					case 0:    //无障碍,则均移动
						// 创建新结点，储存信息
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[2][0];
						p->y = pp->y + move[2][1];

						p->isPush = 1;  //推动箱子

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //储存箱子原位置

						p->afterPushX = p->x + move[2][0];
						p->afterPushY = p->y + move[2][1];  //储存箱子动之后的位置

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // 修改mp中的箱子位置

						//  将结点放在链表首
						p->next = pp;
						pp = p;
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//打印新位置
						printPicture(pp->x * 50, pp->y * 50 + 110, ForwardPush);
						//还原原位置
						if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   游戏结束判读
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//写入当前关卡完成
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //释放占用空间
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					case 1:
						break;  //有障碍
					}
					break;
				case 2:  //下一步为空
					//  创建新节点， 存储信息
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[2][0];
					p->y = pp->y + move[2][1];
					p->isPush = 0;  //未推箱子
					//  将结点放在链表首
					p->next = pp;
					pp = p;
					p = p->next;
					//打印新位置
					printPicture(pp->x * 50, pp->y * 50 + 110, Forward);
					//还原原位置
					if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}
	
			break;
		case 37: //左
			switch (judgePlayerNext(3, mp, pp))
				{
				case 0:  //下一步有墙
					break;
				case 1:  //下一步有箱子
					//  再次判断
					//  再次判断
					switch (judgeBoxNext(3, mp, pp))
					{
					case 0:    //无障碍,则均移动
						// 创建新结点，储存信息
						p = (people*)malloc(sizeof(people));
						p->x = pp->x + move[3][0];
						p->y = pp->y + move[3][1];

						p->isPush = 1;  //推动箱子

						p->beforPushX = p->x;
						p->beforPushY = p->y;   //储存箱子原位置

						p->afterPushX = p->x + move[3][0];
						p->afterPushY = p->y + move[3][1];  //储存箱子动之后的位置

						mp->object[idxFind(p->beforPushX, p->beforPushY, mp)].x = p->afterPushX;
						mp->object[idxFind(p->afterPushX, p->beforPushY, mp)].y = p->afterPushY;  // 修改mp中的箱子位置

						//  将结点放在链表首
						p->next = pp;
						pp = p;
						p = p->next;

						if (judgeCover(pp->afterPushX, pp->afterPushY, mp)) {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, RedBox);
						}
						else {
							printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Box);
						}

						//打印新位置
						printPicture(pp->x * 50, pp->y * 50 + 110, LeftPush);
						//还原原位置
						if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
							printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
						}
						else {
							printPicture(p->x * 50, p->y * 50 + 110, Floor);
						}

						//   游戏结束判读
						if (judgeAllCover(mp) == 1) {
							for (int i = 0; i <= I; i++) {
								passInfo[i] = 1;
							}

							FILE *fp;//写入当前关卡完成
							fp = fopen(idPass, "wb");
							fwrite(passInfo, sizeof(int), 6, fp);
							fclose(fp);

							free(mp);   //释放占用空间
							free(pp);
							
							endChoice(I);
							return;
						}

						break;
					case 1:
						break;  //有障碍
					}
					break;
				case 2:  //下一步为空
					//  创建新节点， 存储信息
					p = (people*)malloc(sizeof(people));
					p->x = pp->x + move[3][0];
					p->y = pp->y + move[3][1];
					p->isPush = 0;  //未推箱子
					//  将结点放在链表首
					p->next = pp;
					pp = p;
					p = p->next;
					//打印新位置
					printPicture(pp->x * 50, pp->y * 50 + 110, Left);
					//还原原位置
					if (judgeCover(p->x, p->y, mp)) {  //原位置为终点
						printPicture(p->x * 50, p->y * 50 + 110, FinishPoint);
					}
					else {
						printPicture(p->x * 50, p->y * 50 + 110, Floor);
					}
					break;
				}

			break;
		}

		//    进入菜单   场上所有数据需暂时储存
		if (ch == 27) {
			mp->player.x = pp->x;
			mp->player.y = pp->y;    //将玩家位置暂时保存进mp中
			
			
			getmouse(); //清除鼠标区缓存
			int count = 0;// 记录鼠标所在按钮位置
// 使存储和提示两个选项能回到菜单
here:		
			mouse_msg msg = { 0 };
			cleardevice();
			printPicture(0, 0, Pause1);

			do {
				delay_fps(60); //设置延时

				while (mousemsg())
				{
					msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
				}

				//cleardevice();//清空前景
				if (msg.y >= 147 && msg.y <= 502) {
					//   位于第一个按钮
					if (msg.y >= 147 && msg.y < 238) {

						if (count != 1) {
							//   前一张图不为按钮一的图
							cleardevice();
							printPicture(0, 0, Pause2);
							count = 1;
						}
					}
					//   位于第二个按钮
					else if (msg.y >= 238 && msg.y < 323) {

						if (count != 2) {
							cleardevice();
							printPicture(0, 0, Pause3);
							count = 2;
						}
					}
					//   位于第三个按钮
					else if (msg.y >= 323 && msg.y < 416) {

						if (count != 3) {
							cleardevice();
							printPicture(0, 0, Pause4);
							count = 3;
						}
					}
					//   位于第四个按钮
					else if (msg.y >= 416 && msg.y <= 502) {
						if (count != 4) {
							cleardevice();
							printPicture(0, 0, Pause5);
							count = 4;
						}
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
					cleardevice();
					printPicture(0, 0, Pause1);
					count = 0;
				}
			} while (!msg.is_left() || count == 0);
			// 循环到鼠标在框口点击为止

			FILE *fp = NULL, *fq = NULL;

			switch (count) {
			case 1:   //继续游戏
				printMap(mp);   //打印地图
				goto here2;
			case 2:
				
				if ((fp = fopen(idMap, "rb")) == NULL || (fq = fopen(idPlayer, "rb")) == NULL) {
					//有存档
					gameSave(mp, pp, I);
					msg = { 0 };
					count = 0;// 记录鼠标所在按钮位置

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
					//无存档
					msg = { 0 };
					count = 0;// 记录鼠标所在按钮位置

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
						count = 0;// 记录鼠标所在按钮位置

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
				
				//保存完成后返回本菜单
				getmouse(); //清空缓存
				msg = { 0 };
				count = 0;
				goto here;
				break;  //储存游戏进度
			case 3:
				//操作完成后返回本菜单
				help();
				getmouse(); //清空缓存
				msg = { 0 };
				count = 0;
				goto here;
				break;  //储存游戏进度
			case 4:
				free(mp);   //释放占用空间
				free(pp);
				return;
			}
		}
		
	
		//  退一步
		if (ch == 32) {
			if (pp->next != NULL) {

				//  判断当前这一步是否推动箱子  此为推动
				if (pp->isPush == 1) {
				if (judgeCover(pp->afterPushX, pp->afterPushY, mp)){
					//    当前箱子位置为红箱子
					printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, FinishPoint);
				}
				else {
					//    当前箱子位置为白箱子
					printPicture(pp->afterPushX * 50, pp->afterPushY * 50 + 110, Floor);
				}

				if (judgeCover(pp->beforPushX, pp->beforPushY, mp)) {
					//    前一步箱子位置为红箱子
					printPicture(pp->beforPushX * 50, pp->beforPushY * 50 + 110, RedBox);
				}
				else {
					//    前一步箱子位置为白箱子
					printPicture(pp->beforPushX * 50, pp->beforPushY * 50 + 110, Box);
				}

				mp->object[idxFind(pp->afterPushX, pp->afterPushY, mp)].x = pp->beforPushX;
				mp->object[idxFind(pp->beforPushX, pp->afterPushY, mp)].y = pp->beforPushY;  //在mp中改变箱子位置

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
				p->next = NULL;  //由p接手表头

				free(p);   //释放内存
			}


				//   未推动箱子
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
					p->next = NULL;  //由p接手表头

					free(p);   //释放内存
				}
			}
		}
	
	}
}
