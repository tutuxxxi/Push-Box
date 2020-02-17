
#include<graphics.h>   //egeͼ�ο�ͷ�ļ�
#include <ege.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

 //��ӡͼƬ��ö������
enum Picture {   
	Floor, //�ذ�
	Box,   //����
	RedBox, //������
	FinishPoint, //��
	Wall,  //ǽ
	Forward, //��ǰ
	Behind,  //���
	Left,  //����
	Right,  //����
	ForwardPush,  //��ǰ��
	BehindPush,   //�����
	LeftPush,   //������
	RightPush,   //������
	BackGround,  //����
	Main1,  //���˵�1
	Main2,  //���˵�1-1
	Main3,  //���˵�1-2 
	Main4,  //���˵�1-4
	Pause1,
	Pause2,
	Pause3,
	Main5,  //���˵�2
	Main6,  //���˵�2-1
	Main7,  //���˵�2-2
	Main8,  //���˵�2-3
	Main9,  //���˵�2-4
	// ѡ��ͼƬ
	Pass123456,
	Pass123456_1,
	Pass123456_2,
	Pass123456_3,
	Pass123456_4,
	Pass123456_5,
	Pass123456_6,

	Pass12345,
	Pass12345_1,
	Pass12345_2,
	Pass12345_3,
	Pass12345_4,
	Pass12345_5,

	Pass1234,
	Pass1234_1,
	Pass1234_2,
	Pass1234_3,
	Pass1234_4,

	Pass123,
	Pass123_1,
	Pass123_2,
	Pass123_3,

	Pass12,
	Pass12_1,
	Pass12_2,

	Pass1,
	Pass1_1,

	Pause4,
	Pause5,

	Save1,
	Save2,
	Save3,
	Save4,
	Save5,
	Back1,
	Back2,
	Back3,
	Back4,
	Back5,
	Back6,
	User1,
	User2,
	User3,
	User4,
	End1,
	End2,
	End3,
	Help1,
	Help2
};


typedef struct People {
	int x;    //x,y����
	int y;

	int isPush;   //��һ���Ƿ��ƶ�����

	//   ����isPushΪ1ʱʹ��
	int beforPushX;
	int beforPushY;

	int afterPushX;
	int afterPushY;

	struct People *next;  //�������ڼ�¼·��
}people;

typedef struct Box {
	int x;    //x,y����
	int y;

}box;

typedef struct Finish {
	int x;    //x,y����
	int y;

}finish;


typedef struct Map {
	int gameMap[10][10];   //10(*4)*10(*4)�ĵ�ͼ�洢�ռ�
	
	int count;   //��¼�յ�(����)����

	finish finishPoint[5];   //��ӵ�еĵ�ͼ���5���յ�

	people player;   //һ���û����

	box object[5];   // ��ӵ�еĵ�ͼ���5������  
}map;


void printPicture(int x, int y, Picture a);  //��ӡͼƬ
void printMap(map *m);  //��ӡ��ͼ
void mapChoice(int idx);    //��ͼѡ��(����Ϸ)
void gameStart(map *mp, people *pp, int I);   //��ʼ��Ϸ
bool checkInfo(char id[]);     // �����Ϸ��Ϣ����
