#include "Main.h"
//  用于用户数据文件夹的创建和查询
#include <direct.h>
#include <io.h>  
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")

void help();

static char id[11], idPass[50], idMap[50], idPlayer[50];

//写入关卡进度
void write() {
	int a[6] = { 0,0,0,0,0,0 };
	FILE *fp;
	fp = fopen(idPass, "wb");
	fwrite(a, sizeof(int), 6, fp);
	fclose(fp);
}

//数据库操作：登陆注册
bool sign() {
	//   数据库连接对象
	MYSQL *conn;
	//    结果集
	MYSQL_RES *res;
	MYSQL_ROW row;
	char sqlText[100];
	char password[17], password2[17];
	int count = 0;
	mouse_msg msg = { 0 };

	if ((conn = mysql_init((MYSQL*)0)) &&
		(mysql_options(conn, MYSQL_SET_CHARSET_NAME, "gbk") == 0) &&
		mysql_real_connect(conn, "localhost", "root", "1144225588", "test", 3306, NULL, 0));
	else
		return false;
	
	printPicture(0, 0, User1);
	do {
		delay_fps(60); //设置延时

		while (mousemsg())
		{
			msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
		}

		if (msg.y >= 383 && msg.y <= 651) {
			if (msg.y < 475) {
				if (count != 1) {
					count = 1;
					cleardevice();
					printPicture(0, 0, User2);
				}
			}
			else if(msg.y < 561){
				if (count != 2) {
					count = 2;
					cleardevice();
					printPicture(0, 0, User3);
				}
			}
			else {
				if (count != 3) {
					count = 3;
					cleardevice();
					printPicture(0, 0, User4);
				}
			}
		}
		else {
			if (count != 0) {
				count = 0;
				cleardevice();
				printPicture(0, 0, User1);
			}
		}
	}while (!msg.is_left() || count == 0);
	
	switch (count) {
	case 1:
		inputbox_getline("登陆框", "输入账号, 最多由10为数字字符字母组成", id, 11);
		while (strcmp(id, "") == 0) {
			inputbox_getline("登陆框", "输入不能为空\n\n输入账号, 最多由10为数字字符字母组成", id, 11);
		}
here9:
		inputbox_getline("登陆框", "输入密码， 最多由16位数字字符字母组成", password, 17);
		while (strcmp(password, "") == 0) {
			inputbox_getline("登陆框", "输入不能为空\n\n输入密码， 最多由16位数字字符字母组成", password, 17);
		}
		sprintf(sqlText, "select password from t_info where id=%s", id);
		if(mysql_query(conn, sqlText)){
			//读值失败
			mysql_close(conn);
			return false;
		}
		else {
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);

			//   比较password
			if (row != NULL && strcmp(password, row[0]) == 0) {
				mysql_free_result(res);
				mysql_close(conn);
				return true;
			}
			else {
				mysql_free_result(res);;
				inputbox_getline("登陆框", "账号或密码错误，请核对后重新输入\n\n输入账号, 由十位数字构成", id, 11);
				while (strcmp(id, "") == 0) {
					inputbox_getline("登陆框", "输入不能为空\n\n输入账号, 最多由10为数字字符字母组成", id, 11);
				}
				goto here9;
			}
		}
		break;
	case 2:

		inputbox_getline("注册框", "输入账号, 最多由10为数字字符字母组成", id, 11);
		while (strcmp(id, "") == 0) {
			inputbox_getline("登陆框", "输入不能为空\n\n输入账号, 最多由10为数字字符字母组成", id, 11);
		}
here0:
		sprintf(sqlText, "select password from t_info where id=%s", id);
		if (mysql_query(conn, sqlText)) {
			//读值失败
			mysql_close(conn);
			return false;
		}
		else {
			res = mysql_store_result(conn);

			if ((int)mysql_num_rows(res)) {
				mysql_free_result(res);
				inputbox_getline("注册框", "账号已被占用，请重新输入账号\n\n输入账号, 最多由10为数字字符字母组成", id, 11);
				while (strcmp(id, "") == 0) {
					inputbox_getline("登陆框", "输入不能为空\n\n输入账号, 最多由10为数字字符字母组成", id, 11);
				}
				goto here0;
			}
		}
		inputbox_getline("注册框", "最多由16位数字字符字母组成", password, 17);
		while (strcmp(password, "") == 0) {
			inputbox_getline("登陆框", "输入不能为空\n\n输入密码， 最多由16位数字字符字母组成", password, 17);
		}
		inputbox_getline("注册框", "再次输入密码以确认", password2, 17);
		while (strcmp(password, "") == 0) {
			inputbox_getline("登陆框", "输入不能为空\n\n输入密码， 最多由16位数字字符字母组成", password, 17);
		}
		while (strcmp(password, password2) != 0) {
			inputbox_getline("注册框", "两次密码不相同，请重新输入\n\n输入密码， 最多由16位数字字符字母组成", password, 17);
			while (strcmp(password, "") == 0) {
				inputbox_getline("登陆框", "输入不能为空\n\n输入密码， 最多由16位数字字符字母组成", password, 17);
			}
			inputbox_getline("注册框", "再次输入密码以确认", password2, 17);
			while (strcmp(password, "") == 0) {
				inputbox_getline("登陆框", "输入不能为空\n\n输入密码， 最多由16位数字字符字母组成", password, 17);
			}
		}
		
		sprintf(sqlText, "insert into t_info values (%s,%s)", id, password);

		if (mysql_query(conn, sqlText)) {
			mysql_close(conn);
			return false;
		}
		else {
			mysql_close(conn);
			return true;

		}
		break;
	case 3:
		return false;
	}
	return true;
}

int main()
{


	FILE *aa;
	aa = fopen("data\\map\\map1.bat", "rb");
	map *m = (map*)malloc(sizeof(map));
	fread(m, sizeof(map), 1, aa);

	initgraph(500, 750);
	printPicture(0, 0, BackGround);
	char str[26];

	if (!sign()) {
		return 0;
	}

	//    将获得的用户账号对应的储存文件路径写死
	sprintf(idPass, "data\\Info\\%s\\passInfo.bat", id);
	sprintf(idMap, "data\\Info\\%s\\archiveMap.bat", id);
	sprintf(idPlayer, "data\\Info\\%s\\archivePlayer.bat", id);
	
	// 判断路径是否存在
	sprintf(str, "data\\Info\\%s", id);
	
	if (_access(str, 00) != 0){
		//   不存在用户，创建新的文件文件夹
		_mkdir(str);
		write();
	}

	//   重要信息检测
	if (checkInfo(id)) {
		return 0;
	}
	
here:
	//  读取存档所用变量
	FILE *fp = NULL, *fq = NULL;
	map *mp = NULL;
	people *pp = NULL;
	people *p = NULL, *q;
	
	int I; //读关卡

	int count = 0;// 记录鼠标所在按钮位置
// 返回主菜单功能时，程序已经跳出此循环，使用goto到这里重新开始循环

	mouse_msg msg ={ 0 };



	//   检测是否拥有存档(检查人物存档和地图存档)
	if ((fp = fopen(idMap, "rb")) == NULL || (fq = fopen(idPlayer, "rb")) == NULL) {
		//   没有存档时
		cleardevice();
		printPicture(0, 0, Main1);
		getmouse(); //清除鼠标区缓存
		do {
			delay_fps(60); //设置延时


			while (mousemsg())
			{
				msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
			}

			if (msg.y <= 650 && msg.y >= 295) {
				//   位于第一个按钮
				if (msg.y >= 295 && msg.y < 389) {
					
					if (count != 1) {
						//   前一张图不为按钮一的图
						cleardevice();
						printPicture(0, 0, Main2);
						count = 1;
					}
				}
				//   位于第三个按钮
				else if (msg.y >= 473 && msg.y < 561) {
					
					if (count != 3) {
						cleardevice();
						printPicture(0, 0, Main3);
						count = 3;
					}
				}
				//   位于第四个按钮
				else if (msg.y >= 561 && msg.y < 650) {
					if (count != 4) {
						cleardevice();
						printPicture(0, 0, Main4);
						count = 4;
					}
				}
				else if (count != 0) {
					//  count != 0 即鼠标从按钮移出
					cleardevice();
					printPicture(0, 0, Main1);
					count = 0;
				}
			}
			else if (count != 0) {
				//  count != 0 即鼠标从按钮移出
				cleardevice();
				printPicture(0, 0, Main1);
				count = 0;
			}

		} while (!msg.is_left() || count == 0);
		// 循环到鼠标在框口点击为止

	}
	else {
		//   有存档时
		cleardevice();
		printPicture(0, 0, Main5);
		getmouse(); //清除鼠标区缓存
		do {
			delay_fps(60); //设置延时

			while (mousemsg())
			{
				msg = getmouse();//有鼠标信息时，将鼠标信息存入鼠标结构
			}

			//cleardevice();//清空前景
			if (msg.y >= 295 && msg.y <= 650) {
				//   位于第一个按钮
				if (msg.y >= 295 && msg.y < 389) {
					
					if (count != 1) {
						//   前一张图不为按钮一的图
						cleardevice();
						printPicture(0, 0, Main6);
						count = 1;
					}
				}
				//   位于第二个按钮
				else if (msg.y >= 389 && msg.y < 473) {
					
					if (count != 2) {
						cleardevice();
						printPicture(0, 0, Main7);
						count = 2;
					}
				}
				//   位于第三个按钮
				else if (msg.y >= 473 && msg.y < 561) {
					
					if (count != 3) {
						cleardevice();
						printPicture(0, 0, Main8);
						count = 3;
					}
				}
				//   位于第四个按钮
				else if (msg.y >= 561 && msg.y < 650) {
					if (count != 4) {
						cleardevice();
						printPicture(0, 0, Main9);
						count = 4;
					}
				}
				else {
					if (count != 0) {
						//  count != 0 即鼠标从按钮移出
						cleardevice();
						printPicture(0, 0, Main5);
						count = 0;
					}
				}
			}
			else if (count != 0) {
				//  count != 0 即鼠标从按钮移出
				cleardevice();
				printPicture(0, 0, Main5);
				count = 0;
			}
		} while (!msg.is_left() || count == 0);
		// 循环到鼠标在框口点击为止

	}
	

	switch (count) {
	case 1:
		//新游戏
		mapChoice(0);

		// 返回主菜单
		count = 0;
		getmouse(); //清除鼠标区缓存
		goto here;
	case 2:
		//继续游戏
		mp = (map*)malloc(sizeof(map)); 
		//   读取地图
		fread(&I, sizeof(int), 1, fp);
		fread(mp, sizeof(map), 1, fp);
		fclose(fp);
		//	 打印地图
		printMap(mp);

		//   读取人物轨迹链表
		while (!feof(fq)) {
			q = (people*)malloc(sizeof(people));
			fread(q, sizeof(people), 1, fq);

			if (feof(fq)) {//由于feof的定义导致他会多读一节，使用二次判断解决
				free(q);
				break;
			}
			if (pp == NULL) {
				pp = p = q;
			}
			else {
				p->next = q;
				p = q;
			}
		}
		gameStart(mp, pp, I);

		// 返回主菜单
		count = 0;
		getmouse(); //清除鼠标区缓存
		goto here;
	case 3:
		//游戏帮助
		help();
		goto here;
		break;
	}


}
