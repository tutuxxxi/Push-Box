#include "Main.h"
//  �����û������ļ��еĴ����Ͳ�ѯ
#include <direct.h>
#include <io.h>  
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")

void help();

static char id[11], idPass[50], idMap[50], idPlayer[50];

//д��ؿ�����
void write() {
	int a[6] = { 0,0,0,0,0,0 };
	FILE *fp;
	fp = fopen(idPass, "wb");
	fwrite(a, sizeof(int), 6, fp);
	fclose(fp);
}

//���ݿ��������½ע��
bool sign() {
	//   ���ݿ����Ӷ���
	MYSQL *conn;
	//    �����
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
		delay_fps(60); //������ʱ

		while (mousemsg())
		{
			msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
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
		inputbox_getline("��½��", "�����˺�, �����10Ϊ�����ַ���ĸ���", id, 11);
		while (strcmp(id, "") == 0) {
			inputbox_getline("��½��", "���벻��Ϊ��\n\n�����˺�, �����10Ϊ�����ַ���ĸ���", id, 11);
		}
here9:
		inputbox_getline("��½��", "�������룬 �����16λ�����ַ���ĸ���", password, 17);
		while (strcmp(password, "") == 0) {
			inputbox_getline("��½��", "���벻��Ϊ��\n\n�������룬 �����16λ�����ַ���ĸ���", password, 17);
		}
		sprintf(sqlText, "select password from t_info where id=%s", id);
		if(mysql_query(conn, sqlText)){
			//��ֵʧ��
			mysql_close(conn);
			return false;
		}
		else {
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);

			//   �Ƚ�password
			if (row != NULL && strcmp(password, row[0]) == 0) {
				mysql_free_result(res);
				mysql_close(conn);
				return true;
			}
			else {
				mysql_free_result(res);;
				inputbox_getline("��½��", "�˺Ż����������˶Ժ���������\n\n�����˺�, ��ʮλ���ֹ���", id, 11);
				while (strcmp(id, "") == 0) {
					inputbox_getline("��½��", "���벻��Ϊ��\n\n�����˺�, �����10Ϊ�����ַ���ĸ���", id, 11);
				}
				goto here9;
			}
		}
		break;
	case 2:

		inputbox_getline("ע���", "�����˺�, �����10Ϊ�����ַ���ĸ���", id, 11);
		while (strcmp(id, "") == 0) {
			inputbox_getline("��½��", "���벻��Ϊ��\n\n�����˺�, �����10Ϊ�����ַ���ĸ���", id, 11);
		}
here0:
		sprintf(sqlText, "select password from t_info where id=%s", id);
		if (mysql_query(conn, sqlText)) {
			//��ֵʧ��
			mysql_close(conn);
			return false;
		}
		else {
			res = mysql_store_result(conn);

			if ((int)mysql_num_rows(res)) {
				mysql_free_result(res);
				inputbox_getline("ע���", "�˺��ѱ�ռ�ã������������˺�\n\n�����˺�, �����10Ϊ�����ַ���ĸ���", id, 11);
				while (strcmp(id, "") == 0) {
					inputbox_getline("��½��", "���벻��Ϊ��\n\n�����˺�, �����10Ϊ�����ַ���ĸ���", id, 11);
				}
				goto here0;
			}
		}
		inputbox_getline("ע���", "�����16λ�����ַ���ĸ���", password, 17);
		while (strcmp(password, "") == 0) {
			inputbox_getline("��½��", "���벻��Ϊ��\n\n�������룬 �����16λ�����ַ���ĸ���", password, 17);
		}
		inputbox_getline("ע���", "�ٴ�����������ȷ��", password2, 17);
		while (strcmp(password, "") == 0) {
			inputbox_getline("��½��", "���벻��Ϊ��\n\n�������룬 �����16λ�����ַ���ĸ���", password, 17);
		}
		while (strcmp(password, password2) != 0) {
			inputbox_getline("ע���", "�������벻��ͬ������������\n\n�������룬 �����16λ�����ַ���ĸ���", password, 17);
			while (strcmp(password, "") == 0) {
				inputbox_getline("��½��", "���벻��Ϊ��\n\n�������룬 �����16λ�����ַ���ĸ���", password, 17);
			}
			inputbox_getline("ע���", "�ٴ�����������ȷ��", password2, 17);
			while (strcmp(password, "") == 0) {
				inputbox_getline("��½��", "���벻��Ϊ��\n\n�������룬 �����16λ�����ַ���ĸ���", password, 17);
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

	//    ����õ��û��˺Ŷ�Ӧ�Ĵ����ļ�·��д��
	sprintf(idPass, "data\\Info\\%s\\passInfo.bat", id);
	sprintf(idMap, "data\\Info\\%s\\archiveMap.bat", id);
	sprintf(idPlayer, "data\\Info\\%s\\archivePlayer.bat", id);
	
	// �ж�·���Ƿ����
	sprintf(str, "data\\Info\\%s", id);
	
	if (_access(str, 00) != 0){
		//   �������û��������µ��ļ��ļ���
		_mkdir(str);
		write();
	}

	//   ��Ҫ��Ϣ���
	if (checkInfo(id)) {
		return 0;
	}
	
here:
	//  ��ȡ�浵���ñ���
	FILE *fp = NULL, *fq = NULL;
	map *mp = NULL;
	people *pp = NULL;
	people *p = NULL, *q;
	
	int I; //���ؿ�

	int count = 0;// ��¼������ڰ�ťλ��
// �������˵�����ʱ�������Ѿ�������ѭ����ʹ��goto���������¿�ʼѭ��

	mouse_msg msg ={ 0 };



	//   ����Ƿ�ӵ�д浵(�������浵�͵�ͼ�浵)
	if ((fp = fopen(idMap, "rb")) == NULL || (fq = fopen(idPlayer, "rb")) == NULL) {
		//   û�д浵ʱ
		cleardevice();
		printPicture(0, 0, Main1);
		getmouse(); //������������
		do {
			delay_fps(60); //������ʱ


			while (mousemsg())
			{
				msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
			}

			if (msg.y <= 650 && msg.y >= 295) {
				//   λ�ڵ�һ����ť
				if (msg.y >= 295 && msg.y < 389) {
					
					if (count != 1) {
						//   ǰһ��ͼ��Ϊ��ťһ��ͼ
						cleardevice();
						printPicture(0, 0, Main2);
						count = 1;
					}
				}
				//   λ�ڵ�������ť
				else if (msg.y >= 473 && msg.y < 561) {
					
					if (count != 3) {
						cleardevice();
						printPicture(0, 0, Main3);
						count = 3;
					}
				}
				//   λ�ڵ��ĸ���ť
				else if (msg.y >= 561 && msg.y < 650) {
					if (count != 4) {
						cleardevice();
						printPicture(0, 0, Main4);
						count = 4;
					}
				}
				else if (count != 0) {
					//  count != 0 �����Ӱ�ť�Ƴ�
					cleardevice();
					printPicture(0, 0, Main1);
					count = 0;
				}
			}
			else if (count != 0) {
				//  count != 0 �����Ӱ�ť�Ƴ�
				cleardevice();
				printPicture(0, 0, Main1);
				count = 0;
			}

		} while (!msg.is_left() || count == 0);
		// ѭ��������ڿ�ڵ��Ϊֹ

	}
	else {
		//   �д浵ʱ
		cleardevice();
		printPicture(0, 0, Main5);
		getmouse(); //������������
		do {
			delay_fps(60); //������ʱ

			while (mousemsg())
			{
				msg = getmouse();//�������Ϣʱ���������Ϣ�������ṹ
			}

			//cleardevice();//���ǰ��
			if (msg.y >= 295 && msg.y <= 650) {
				//   λ�ڵ�һ����ť
				if (msg.y >= 295 && msg.y < 389) {
					
					if (count != 1) {
						//   ǰһ��ͼ��Ϊ��ťһ��ͼ
						cleardevice();
						printPicture(0, 0, Main6);
						count = 1;
					}
				}
				//   λ�ڵڶ�����ť
				else if (msg.y >= 389 && msg.y < 473) {
					
					if (count != 2) {
						cleardevice();
						printPicture(0, 0, Main7);
						count = 2;
					}
				}
				//   λ�ڵ�������ť
				else if (msg.y >= 473 && msg.y < 561) {
					
					if (count != 3) {
						cleardevice();
						printPicture(0, 0, Main8);
						count = 3;
					}
				}
				//   λ�ڵ��ĸ���ť
				else if (msg.y >= 561 && msg.y < 650) {
					if (count != 4) {
						cleardevice();
						printPicture(0, 0, Main9);
						count = 4;
					}
				}
				else {
					if (count != 0) {
						//  count != 0 �����Ӱ�ť�Ƴ�
						cleardevice();
						printPicture(0, 0, Main5);
						count = 0;
					}
				}
			}
			else if (count != 0) {
				//  count != 0 �����Ӱ�ť�Ƴ�
				cleardevice();
				printPicture(0, 0, Main5);
				count = 0;
			}
		} while (!msg.is_left() || count == 0);
		// ѭ��������ڿ�ڵ��Ϊֹ

	}
	

	switch (count) {
	case 1:
		//����Ϸ
		mapChoice(0);

		// �������˵�
		count = 0;
		getmouse(); //������������
		goto here;
	case 2:
		//������Ϸ
		mp = (map*)malloc(sizeof(map)); 
		//   ��ȡ��ͼ
		fread(&I, sizeof(int), 1, fp);
		fread(mp, sizeof(map), 1, fp);
		fclose(fp);
		//	 ��ӡ��ͼ
		printMap(mp);

		//   ��ȡ����켣����
		while (!feof(fq)) {
			q = (people*)malloc(sizeof(people));
			fread(q, sizeof(people), 1, fq);

			if (feof(fq)) {//����feof�Ķ��嵼��������һ�ڣ�ʹ�ö����жϽ��
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

		// �������˵�
		count = 0;
		getmouse(); //������������
		goto here;
	case 3:
		//��Ϸ����
		help();
		goto here;
		break;
	}


}
