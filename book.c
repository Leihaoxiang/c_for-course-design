#include<graphics.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<time.h>
#define N 20
#define MAX_PASSWD_LEN 16

typedef struct login
{
	char username[N];
	char passwd[MAX_PASSWD_LEN];
	char ques[N];
	char cla[N];
	char borrow[N];
	int borbknum;
	struct login *next;
}Login,*Link;

typedef struct node
{
	char bkname[N];
	char author[N];
	char cla[N];
	char noro[N];
	int num;
	int available;
	struct node *next;
}Node,*Linklist;

char passwd1[MAX_PASSWD_LEN + 1] = "";
char passwd2[MAX_PASSWD_LEN + 1] = "";

void SetColor(unsigned short ForeColor,unsigned short BackGroundColor)
{HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));}

void print1() {
	{//���ع��
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
		CursorInfo.bVisible = false; //���ؿ���̨���  
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬  
	}
	int cut = 1;
	while (cut <= 50) {
		system("cls");
		int i = 0;
		int j = 0;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t    ");
		while (i < cut) {
			printf(">");
			i++;
		}
		while (j < 50 - cut) {
			printf("=");
			j++;
		}
		printf("\t%d%%", cut * 2);
		Sleep(5*cut);
		cut++;
	}
	Sleep(500);
}

void PrintChar(char *ch, UINT count, UINT x, UINT y)  //������(x,y)������ַ���ch,ch����count���ַ�
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	ULONG unuse;
	pos.X = x;
	pos.Y = y;
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // ���ڻ�������Ϣ
	GetConsoleScreenBufferInfo(h, &bInfo);
	WriteConsoleOutputCharacterA(h, ch, count, pos, &unuse);
}

void getpasswd (char passwd[MAX_PASSWD_LEN + 1])
{
	unsigned char c;
	int i = 0;
	while ((c=getch())!='\r')
    {
        if (i<MAX_PASSWD_LEN && isprint(c))
        {
            passwd[i++] = c;
            putchar('*');
        }
        else if (i>0 && c=='\b')
        {
            --i;
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
    }
    putchar('\n');
    passwd[i] = '\0';
}

void interface1(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"���ݼ��");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"����ָ��");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"��������");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"����Ա��¼");
	setcolor(WHITE);
	if (i==5)
		setcolor(GREEN);
	outtextxy(300,215,"ע��");
	setcolor(WHITE);
	if (i==6)
		setcolor(GREEN);
	outtextxy(300,230,"�˳�");
	setcolor(WHITE);
	outtextxy(200,280,"**********************************************");
}

void interface2(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"�鿯����");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"����ͨ��");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"�鿯����");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"��������");
	setcolor(WHITE);
	if (i==5)
		setcolor(GREEN);
	outtextxy(300,215,"�˳�");
	setcolor(WHITE);
	outtextxy(200,265,"**********************************************");
}

void interface3(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"��Ҫ����");

	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"�ҵĽ���");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"ͼ������");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"ע��");
	setcolor(WHITE);
	outtextxy(200,250,"**********************************************");
}

void interface4(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"����");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"����");
	setcolor(WHITE);
	outtextxy(200,220,"**********************************************");
}

void f(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"��¼");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"�޸�����");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"�˳�");
	setcolor(WHITE);
	setcolor(WHITE);
	outtextxy(200,235,"**********************************************");
}
void f5(int i)
{
	outtextxy(300,80,"��¼�ɹ�!");
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"���ͼ��");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"����ͼ��");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"ɾ��ͼ��");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"�޸�ͼ����Ϣ");
	setcolor(WHITE);
	if (i==5)
		setcolor(GREEN);
	outtextxy(300,215,"�鿴ȫ��ͼ��");
	setcolor(WHITE);
	if (i==6)
		setcolor(GREEN);
	outtextxy(300,230,"ע��");
	setcolor(WHITE);
	outtextxy(200,280,"**********************************************");
}
void f2(int x)//��ͷ
{
	outtextxy(250,x,"��>>");
}
int f3(int flag)//���̲���
{
	int key=0;
	int i=1,x=155;
	while (key!=77){
		key=getch();
		if (key==72){
			cleardevice();
			i--;
			if (flag==1)
				f(i);
			else if (flag==0)
				f5(i);
			else if (flag==2)
				interface1(i);
			else if (flag==3)
				interface2(i);
			else if (flag==4)
				interface3(i);
			else if (flag==5)
				interface4(i);
			x-=15;
			if (x<155){
				i++;
				x=155;
			}
			f2(x);
		}
		if (key==80){
			cleardevice();	
			i++;
			if (flag==1){
				f(i);
				if (x>170){
					i--;
					x=170;
				}
			}
			else if (flag==0){
				f5(i);
				if (x>215){
					i--;
					x=215;
				}
			}
			else if (flag==2){
				interface1(i);
				if (x>215){
					i--;
					x=215;
				}
			}
			else if (flag==3){
				interface2(i);
				if (x>200){
					i--;
					x=200;
				}
			}
			else if (flag==4){
				interface3(i);
				if (x>185){
					i--;
					x=185;
				}
			}
			else if (flag==5){
				interface4(i);
				if (x>155){
					i--;
					x=155;
				}
			}
			x+=15;
			f2(x);
		}
	}
	return i;
}
int f4()//��ͷ�ƶ�
{
	initgraph(639,479);
	int x=155,i,flag=1;
	f(1);
	f2(x);
	i=f3(1);
	closegraph();
	return i;
}
int f6()
{
	initgraph(639,479);
	int x=155,j;
	f5(1);
	f2(x);
	j=f3(0);
	closegraph();
	return j;
}
int interface1move()//��ͷ�ƶ�
{
	initgraph(639,479);
	int x=155,i,flag=1;
	interface1(1);
	f2(x);
	i=f3(2);
	closegraph();
	return i;
}

int interface2move()//��ͷ�ƶ�
{
	initgraph(639,479);
	int x=155,i,flag=1;
	interface2(1);
	f2(x);
	i=f3(3);
	closegraph();
	return i;
}

int interface3move()//��ͷ�ƶ�
{
	initgraph(639,479);
	int x=155,i,flag=1;
	interface3(1);
	f2(x);
	i=f3(4);
	closegraph();
	return i;
}

int interface4move()//��ͷ�ƶ�
{
	initgraph(639,479);
	int x=155,i,flag=1;
	interface4(1);
	f2(x);
	i=f3(5);
	closegraph();
	return i;
}

Linklist CreatFromHead()
{
	Linklist L;
	char Name[N]="exit";
	Node *s,*r;
	L=(Linklist)malloc(sizeof(Node));
	s=(Node*)malloc(sizeof (Node));
	L->next=NULL;
	r=L;
	printf("���������������ߣ�����¾ɣ��������ɽ�������(����Ϊexit����)\n");
	scanf("%s%s%s%s%d%d",s->bkname,s->author,s->cla,s->noro,&s->num,&s->available);
	while (1){
			s->next=r->next;
			r->next=s;
			r=s;
			s=(Node*)malloc(sizeof(Node));
			printf("���������������ߣ�����¾ɣ��������ɽ�������(����Ϊexit����)\n");
			scanf("%s%s%s%s%d%d",s->bkname,s->author,s->cla,s->noro,&s->num,&s->available);
			if (strcmp(Name,s->bkname)==0){
				free(s);
				break;
			}
	}
	return L;
}
void print(Linklist L)
{
	Node *p;
	p=L->next;
	while (p){
		printf("������%s ���ߣ�%s ���%s �¾ɣ�%s �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->noro,p->num,p->available);
		p=p->next;
	}
	printf("\n");
}
void Seek(Linklist L,char name[],int k)
{
	Node *p;
	p=L->next;
	while (p){
		if (strcmp(p->bkname,name)==0&&k==1){
			printf("������%s ���ߣ�%s ���%s �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->num,p->available);
			break;
		}
		else if (strcmp(p->author,name)==0&&k==2){
			printf("������%s ���ߣ�%s ���%s �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->num,p->available);
			p=p->next;
		}
		else 
			p=p->next;
	}
	printf("��������˳�");
	getch();
}
Linklist Insert(Linklist L)
{
	Node *s,*p;
	p=L->next;
	s=(Node*)malloc(sizeof (Node));
	printf("������Ҫ��������������ߣ�����¾�,�������ɽ�������(����Ϊexit����)\n");
		scanf("%s%s%s%d%d",s->bkname,s->author,s->cla,s->noro,&s->num,&s->available);
	s->next=p;
	L->next=s;
	return L;
}

Linklist Delete(Linklist L,char name[])
{
	Node *pre,*curr;
	curr=pre=L;
	while (strcmp(curr->bkname,name)){
		pre=curr;
		curr=curr->next;
	}
	pre->next=curr->next;
	return L;
}
void modify(Linklist L,char name[])
{
	Node *p;
	int x; 
	p=L->next;
	while (p){
		if (strcmp(p->bkname,name)==0){
			printf("������%s ���ߣ�%s ���%s �¾ɣ�%s �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->noro,p->num,p->available);
			printf("��Ҫ�޸ģ�1.�ݲ����� 2.�ɽ�����\n");
			scanf("%d",&x);
			if (x==1){
				printf("�޸�Ϊ��"); 
				scanf("%d",&p->num);
			}
			if (x==2){
				printf("�޸�Ϊ��");
				scanf("%d",&p->available);
			}
			break;
		}
		else 
			p=p->next;
	}
	print(L);
}

void savefile(Linklist L,int i)
{
	Node *p;
	FILE *fp;
	if (i==4)
		fp=fopen("D://savefile.txt","at");
	if (i==1)
		fp=fopen("D://savefile.txt","wt");
	for (p=L->next;p!=NULL;p=p->next)
		fprintf(fp,"%s %s %s %s %d %d\n",p->bkname,p->author,p->cla,p->noro,p->num,p->available);
		fclose(fp); 
} 
void saveuserinf(Link L,int i)
{
	Login *p;
	FILE *fp;
	if (i==1)
		fp=fopen("D://saveuserinf.txt","at");
	if (i==3)
		fp=fopen("D://saveuserinf.txt","wt");
	for (p=L->next;p!=NULL;p=p->next)
		fprintf(fp,"%s %s %s %s %s %d\n",p->username,p->passwd,p->ques,p->cla,p->borrow,p->borbknum);
		getch();
		fclose(fp); 
}

Linklist readfile()
{
	
	Node *h,*p,*s;
	FILE *fp; 
	if ((fp=fopen("D://savefile.txt","rt"))==NULL){
		printf("���ļ�����������˳���");
		getch();
		exit(1); 
	} 
	h=(Linklist)malloc(sizeof (Node));
	s=(Linklist)malloc(sizeof(Node));
	h->next=NULL;
	p=h;
	while (fscanf(fp,"%s %s %s %s %d %d",s->bkname,s->author,s->cla,s->noro,&s->num,&s->available)!=EOF){
		s->next=p->next;
		p->next=s;
		p=s;
		s=(Linklist)malloc(sizeof(Node));
	}
	p->next=NULL;
	fclose(fp);
	return h; 
}

Link readuserinf()
{
	Login *h,*p,*s;
	FILE *fp; 
	if ((fp=fopen("D://saveuserinf.txt","rt"))==NULL){
		printf("���ļ�����������˳���");
		getch();
		exit(1); 
	} 
	h=(Link)malloc(sizeof (Login));
	s=(Link)malloc(sizeof(Login));
	h->next=NULL;
	p=h;
	while (fscanf(fp,"%s %s %s %s %s %d",s->username,s->passwd,s->ques,s->cla,s->borrow,&s->borbknum)!=EOF){
		s->next=p->next;
		p->next=s;
		p=s;
		s=(Link)malloc(sizeof(Login));
	}
	p->next=NULL;
	free(s);
	fclose(fp);
	return h; 
}

void f7(int j)
{
	int k;
	Linklist L;
	L=readfile();
	char name[N];
	if (j==2){	
		k=interface4move();
		printf("������Ҫ���ҵ�������"); 
		scanf("%s",name);
		if (k==1){
			Seek(L,name,k);
		}
		if (k==2)
			Seek(L,name,k);
	}
	if (j==3){
		memset(name,0,N);
		printf("������Ҫɾ����������"); 
			scanf("%s",name);
		Delete(L,name);
		savefile(L,1);
	}
	if (j==4){
		memset(name,0,N);
		printf("��������Ҫ�޸ĵ�������\n");
			scanf("%s",name);
		modify(L,name);
		savefile(L,1);
	}
	if (j==5){
		print(L);
	}
}
Link Creat(char username[])
{
	Link L;
	Login *s,*r;
	int flag=0;
	char a[N]="��";
	L=(Link)malloc(sizeof(Login));
	s=(Login*)malloc(sizeof (Login));
	L->next=NULL;
	r=L;
	strcpy(s->username,username);
	printf("���������룺");
	getpasswd(passwd1);
	strcpy(s->passwd,passwd1);
	printf("���ٴ��������룺");
	getpasswd(passwd2);
	printf("�������ܱ�����\n��������(xx-xx-xx)��");
	scanf("%s",s->ques);
	printf("���������:");
	scanf("%s",s->cla);
	strcpy(s->borrow,a);
	s->borbknum=0;
	s->next=r->next;
	r->next=s;
	r=s;
	while (1){
		if (strcmp(passwd2,s->passwd)==0){
			printf("ע��ɹ���\n");
			printf("����������أ�\n");
			break;
		}
		else {
			printf("�������\n�������������룺");
				getpasswd(passwd2);
		}
	}
	saveuserinf(L,1);
	return L;
}

int login(Link L,char name[],int i)
{
	Login *p;
	int flag=0,key=0;
	int data,guess;
	char a[N]="root";
	char passwd[MAX_PASSWD_LEN];
	p=L->next;
	while (p){
		srand ((unsigned) time (NULL));  
		data = rand()%9000+1000;
		if (strcmp(p->username,name)==0){
			if (strcmp(p->cla,a)!=0&&i==1){
				flag=-1;
				break;
			}
			printf("���������룺");
				getpasswd(passwd);
			while(1){
				if (strcmp(p->passwd,passwd)==0){
						flag=1;
						break;
				}
				else {
					printf("�������\n���������룺");
					getpasswd(passwd);
				}
			}
			if (flag==1){
				printf("��֤��Ϊ��\n");
				printf("------");
				printf("\n %4d\n",data);
				printf("------\n");
				printf("��������֤�룺");	 /*��֤��*/ 
					scanf("%d",&guess);
				while (guess != data){
					printf("��֤�����!\n");
					printf("��������֤�룺");
						scanf("%d",&guess);
				}
				system("cls");
				print1();
				PrintChar("��¼�ɹ�", 8, 36, 7);
				PrintChar("�����������", 12, 34, 8);
				getch();
			}
			break;
		}
		else 
			p=p->next;
	}
	if (flag==0)
			printf("�Ҳ������û���!\n");
	return flag;
}

void modifyuserinf(Link L,char name[])
{
	Login *p;
	int flag;
	char ques[N];
	char passwd[MAX_PASSWD_LEN+1];
	p=L->next;
	while (p){
		flag=0;
		if (strcmp(p->username,name)==0){
			flag=1;
				while (1){
					printf("��������������(xx-xx-xx):");
					scanf("%s",ques);
					if (strcmp(p->ques,ques)==0)
						break;
				}
				printf("�����޸�Ϊ��");
				getpasswd(passwd);
				strcpy(p->passwd,passwd);
				printf("���ٴ���������:");
				getpasswd(passwd2);
				while (1){
					if (strcmp(passwd2,p->passwd)==0){
						printf("�޸ĳɹ���\n");
						printf("����������أ�\n");
						break;
					}
					else {
						printf("�������\n�������������룺");
							getpasswd(passwd2);
					}
				}
			break;
		}
		else 
			p=p->next;
	}
	if (flag==0)
		printf("�Ҳ������û���!");
}

Link borrowbk(char username[],char name[])
{
	Login *p,*h;
	Node *m,*s;
	int flag;
	h=readuserinf();
	m=readfile();
	p=h->next;
	s=m->next;
	while (m){
		flag=0;
		if (strcmp(s->bkname,name)==0){
			flag=1;
			if (s->available>0){
				while (p){
					if (strcmp(p->username,username)==0){
						strcpy(p->borrow,name);
						printf("���ѳɹ�����!");
						s->available--;
						p->borbknum++;
						break;
					}
					else
						p=p->next;
				}
			}
			else 
				printf("�����ѱ�����!");
			break;
		}
		else 
			s=s->next;
	}
	savefile(m,1);
	if (flag==0)
		printf("û���ҵ�����!");
	return h;
}

void newbk()
{
	Node *h,*p;
	char a[N]="��";
	system("cls");
	h=readfile();
	p=h->next;
	while (p){
		if (strcmp(p->noro,a)==0){
			printf("������%s ���ߣ�%s ���%s �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->num,p->available);
			p=p->next;
		}
		else 
			p=p->next;
	}
	printf("\n�����������");
	getch();
}

void myborbk(char username[])
{
	Login *h,*p;
	system("cls");
	h=readuserinf();
	p=h->next;
	while(p){
		if (strcmp(p->username,username)==0){
			printf("%s",p->borrow);
			break;
		}
		else
			p=p->next;
	}
	printf("\n�����������");
	getch();
}
void f8()
{
	Login *h;
	Linklist L;
	int i,j,k,g;
	int x=155,flag;
	char name[N];
	char username[N];
	h=readuserinf();
	initgraph(639,479);
	while (1){
		system("cls");
		i=interface1move();
		if (i==1){
			
		}
		if (i==2){

		}
		if (i==3){
			while (1){
				system("cls");
				j=interface2move();
				if (j==1){
					k=interface4move();
					L=readfile();
					printf("������Ҫ���ҵ�������"); 
					scanf("%s",name);
					if (k==1){
						Seek(L,name,k);
					}
					if (k==2){
						Seek(L,name,k);
					}
				}
				if (j==2){
					newbk();	
					break;
				}
				if (j==3){

				}
				if (j==4){
					while (1){
						k=f4();
						system("cls");
						if (k==1){
							h=readuserinf();
							system("cls");
							flag=-1;
							while (flag!=1){
								//memset(username,0,N);
								printf("�������û�����");
									scanf("%s",username);
								flag=login(h,username,0);
							}
							if(flag==1){
								system("cls");
								while(1){
									g=interface3move();
									if (g==1){
										printf("����������");
											scanf("%s",name);
										h=borrowbk(username,name);
										saveuserinf(h,i);
									}
									if (g==2){
										myborbk(username);
									}
									/*else
										break;*/
								}
							}
						}

						if (k==2){
							h=readuserinf();
							memset(username,0,N);
							printf("��������Ҫ�޸ĵ�������\n");
								scanf("%s",username);
							modifyuserinf(h,username);
							saveuserinf(h,i);
						}
						if (k==3)
							break;
					}
				}
				if (j==5)
					break;
			}
			
		}
		if (i==4){
			system("cls");
			h=readuserinf();
			flag=-1;
			while (flag!=1){
				memset(username,0,N);
				printf("�������û�����");
					scanf("%s",username);
				flag=login(h,username,1);
				if (flag==-1){
					printf("�����ǹ���Ա!\n�����������");
					getch();
					break;
				}
			}
			if(flag==1){
				cleardevice();
				while(1){
					system("cls");
					j=f6();
					if (j==1){
						L=CreatFromHead();
						print(L);
						savefile(L,i);
						printf("����������أ�\n");
						getch();
					}
					else if (j>=2&&j<6){
						f7(j);
						printf("����������أ�\n");
						getch();
					}
					else
						break;
				}
			}
		}
		if (i==5){
			h=readuserinf();
			while(1){
				printf("�������û���:");
					scanf("%s",username);
				while (h){
					flag=1;
					if (strcmp(h->username,username)==0){
						printf("�û����Ѵ���!\n");
						flag=0;
						break;
					}
					else 
						h=h->next;
				}
				if (flag==1)
					break;
				}
				h=Creat(username);
		}
		if (i==6)
			break;
	}
}
void main()
{
	f8();
}
