
#include<graphics.h>   //ege图形库头文件
#include <ege.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

 //打印图片的枚举类型
enum Picture {   
	Floor, //地板
	Box,   //箱子
	RedBox, //红箱子
	FinishPoint, //点
	Wall,  //墙
	Forward, //向前
	Behind,  //向后
	Left,  //向左
	Right,  //向右
	ForwardPush,  //向前推
	BehindPush,   //向后推
	LeftPush,   //向左推
	RightPush,   //向右推
	BackGround,  //背景
	Main1,  //主菜单1
	Main2,  //主菜单1-1
	Main3,  //主菜单1-2 
	Main4,  //主菜单1-4
	Pause1,
	Pause2,
	Pause3,
	Main5,  //主菜单2
	Main6,  //主菜单2-1
	Main7,  //主菜单2-2
	Main8,  //主菜单2-3
	Main9,  //主菜单2-4
	// 选关图片
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
	int x;    //x,y坐标
	int y;

	int isPush;   //这一步是否推动箱子

	//   仅在isPush为1时使用
	int beforPushX;
	int beforPushY;

	int afterPushX;
	int afterPushY;

	struct People *next;  //链表用于记录路径
}people;

typedef struct Box {
	int x;    //x,y坐标
	int y;

}box;

typedef struct Finish {
	int x;    //x,y坐标
	int y;

}finish;


typedef struct Map {
	int gameMap[10][10];   //10(*4)*10(*4)的地图存储空间
	
	int count;   //记录终点(箱子)个数

	finish finishPoint[5];   //所拥有的地图最多5个终点

	people player;   //一个用户起点

	box object[5];   // 所拥有的地图最多5个物体  
}map;


void printPicture(int x, int y, Picture a);  //打印图片
void printMap(map *m);  //打印地图
void mapChoice(int idx);    //地图选择(新游戏)
void gameStart(map *mp, people *pp, int I);   //开始游戏
bool checkInfo(char id[]);     // 检查游戏信息函数
