#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#pragma comment(lib, "winmm.lib")
#define N 20
#define MAX_PASSWD_LEN 16


typedef struct login
{
	char username[N];
	char passwd[MAX_PASSWD_LEN];
	char ques[N];
	char cla[N];
	char buy[N][N];
	char borrow[N][N];
	char borhis[N][N];
	char collect[N][N];
	int buybknum;
	int borbknum;
	int collectnum;
	int borhisnum;
	struct login *next;
}Login,*Link;

typedef struct node
{
	char bkname[N];
	char author[N];
	char cla[N];
	char noro[N];
	int bknum;
	int price;
	int num;
	int available;
	int bornum;
	struct node *next;
}Node,*Linklist;

char passwd1[MAX_PASSWD_LEN + 1] = "";
char passwd2[MAX_PASSWD_LEN + 1] = "";
void sort(Linklist L);
void sort1(Linklist L);
void SetColor(unsigned short ForeColor,unsigned short BackGroundColor)
{HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hCon,(ForeColor%16)|(BackGroundColor%16*16));}

int time(void)
{
	time_t timer;//time_t����long int ����
	struct tm *tblock;
	timer = time(NULL);//��һ��Ҳ���Ըĳ�time(&timer);
	tblock = localtime(&timer);
	printf("��¼ʱ��: %s\n",asctime(tblock));
	return 0;
}

void look_somep(int i)
{
	char name[40];
	char pa[60];
	strcpy(pa,"c");
	if (i==1)
	strcpy(name,"1.jpg");
	if (i==2)
	strcpy(name,"2.jpg");
	strcat(pa,"\\");
	strcat(pa,name);
	system(pa);
	printf("\n\n");
}

void select()
{
	int select;
	printf("��ѡ�񸶿ʽ:\n");
	printf("1��֧����;\n2��΢��;\n");
	scanf("%d",&select);
	look_somep(select);
}

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
		if (cut==50)
			time();
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

void print2() {
	{//���ع��
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
		CursorInfo.bVisible = false; //���ؿ���̨���  
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬  
	}
	int cut = 1;
	while (cut <= 3) {
		system("cls");
		/*if (cut==50)
			time();*/
		int i = 0;
		int j = 0;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    ");
		printf("Loading");
		while (i < cut) {
			printf(".");
			i++;
		}
		while (j < 3- cut) {
			printf(" ");
			j++;
		}
		Sleep(300*cut);
		cut++;
	}
	//Sleep(500);
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
	outtextxy(300,155,"��������");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"����Ա��¼");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"ע��");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"�˳�");
	setcolor(WHITE);
	outtextxy(200,250,"**********************************************");
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
	outtextxy(300,185,"��������");
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
	outtextxy(300,155,"����ͼ��");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"����ͼ��");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"�ҵĽ���");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"�ղ�ͼ��");
	setcolor(WHITE);
	if (i==5)
		setcolor(GREEN);
	outtextxy(300,215,"�ҵ��ղ�");
	setcolor(WHITE);
	if (i==6)
		setcolor(GREEN);
	outtextxy(300,230,"������ʷ");
	setcolor(WHITE);
	if (i==7)
		setcolor(GREEN);
	outtextxy(300,245,"�黹ͼ��");
	setcolor(WHITE);
	if (i==8)
		setcolor(GREEN);
	outtextxy(300,260,"ͼ������");
	setcolor(WHITE);
	if (i==9)
		setcolor(GREEN);
	outtextxy(300,275,"ע��");
	setcolor(WHITE);
	outtextxy(200,325,"**********************************************");
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
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"���");
	setcolor(WHITE);
	outtextxy(200,235,"**********************************************");
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
	outtextxy(200,235,"**********************************************");
}

void f5(int i)
{
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
				if (x>185){
					i--;
					x=185;
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
				if (x>260){
					i--;
					x=260;
				}
			}
			else if (flag==5){
				interface4(i);
				if (x>170){
					i--;
					x=170;
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
	printf("���������������ߣ�����¾ɣ���ţ��۸��������ɽ�������(����Ϊexit����)\n");
	scanf("%s",s->bkname);
	scanf("%s%s%s%d%d%d%d",s->author,s->cla,s->noro,&s->bknum,&s->price,&s->num,&s->available);
	s->bornum=0;
	while (1){
			s->next=r->next;
			r->next=s;
			r=s;
			s=(Node*)malloc(sizeof(Node));
			printf("���������������ߣ�����¾ɣ���ţ��۸��������ɽ�������(����Ϊexit����)\n");
			scanf("%s",s->bkname);
			if (strcmp(Name,s->bkname)==0){
				free(s);
				break;
			}
			scanf("%s%s%s%d%d%d",s->author,s->cla,s->noro,&s->bknum,&s->price,&s->num,&s->available);
			s->bornum=0;
	}
	return L;
}

void print(Linklist L)
{
	Node *p;
	p=L->next;
	printf("����		   ����		        ���   ���  �۸�  ���� ���� �����\n");
	printf("---------------------------------------------------------------------------\n");
	while (p){
		printf("%-18s %-20s %-6s %4d %4d %4d %4d %4d\n",p->bkname,p->author,p->cla,p->bknum,p->price,p->num,p->available,p->bornum);
		printf("---------------------------------------------------------------------------\n");
		p=p->next;
	}
	printf("\n");
}

void Seek(Linklist L,char name[],int k)
{
	int flag=0;
	Node *p;
	p=L->next;
	while (p){
		if (strcmp(p->bkname,name)==0&&k==1){
			flag=1;
			printf("������%s ���ߣ�%s ���%s ��ţ�%d �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->bknum,p->num,p->available);
			break;
		}
		else if (strcmp(p->author,name)==0&&k==2){
			flag=1;
			printf("������%s ���ߣ�%s ���%s ��ţ�%d �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->bknum,p->num,p->available);
			p=p->next;
		}
		else if (strcmp(p->cla,name)==0&&k==3){
			flag=1;
			printf("������%s ���ߣ�%s ���%s ��ţ�%d �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->bknum,p->num,p->available);
			p=p->next;
		}
		else 
			p=p->next;
	}
	if (flag==0)
		printf("û���ҵ�����Ҫ�����!");
	//printf("��������˳�");
	//getch();
}

Linklist Delete(Linklist L,char name[])
{
	Node *pre,*curr;
	int flag=0;
	curr=pre=L;
	while (curr){   
		if (strcmp(curr->bkname,name)==0){
			flag=1;
			//pre=curr;
			break;
		}
		else {
			pre=curr;
			curr=curr->next;
		}
	}
	if (flag==0)
		printf("û���ҵ�����!");
	else
		pre->next=curr->next;
	return L;
}

void modify(Linklist L,char name[])
{
	Node *p;
	int x,m,n,flag; 
	p=L->next;
	while (p){
		flag=m=n=0;
		if (strcmp(p->bkname,name)==0){
			flag=1;
			printf("������%s ���ߣ�%s ���%s �۸�%d �ݲ�������%d �ɽ�������%d\n",p->bkname,p->author,p->cla,p->price,p->num,p->available);
			printf("��Ҫ�޸ģ�1.�ݲ����� 2.�ɽ����� 3.�۸�\n");
			scanf("%d",&x);
			if (x==1){
				m=p->num;
				printf("�޸�Ϊ��"); 
				scanf("%d",&p->num);
				n=m-p->num;
				p->available+=n;
			}
			if (x==2){
				printf("�޸�Ϊ��");
				scanf("%d",&p->available);
			}
			if (x==3){
				printf("�޸�Ϊ��");
				scanf("%d",&p->price);
			}
			break;
		}
		else 
			p=p->next;
	}
	if (flag==0)
		printf("û���ҵ�����!");
	else 
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
		fprintf(fp,"%s %s %s %s %d %d %d %d %d\n",p->bkname,p->author,p->cla,p->noro,p->bknum,p->price,p->num,p->available,p->bornum);
		fclose(fp); 
} 

void saveuserinf(Link L,int i)
{
	Login *p;
	FILE *fp;
	int j;
	char a[N]="��";
	if (i==1)
		fp=fopen("D://saveuserinf.txt","at");
	if (i==3)
		fp=fopen("D://saveuserinf.txt","wt");
	for (p=L->next;p!=NULL;p=p->next){
		fprintf(fp,"\n%s %s %s %s %d %d %d %d",p->username,p->passwd,p->ques,p->cla,p->borbknum,p->collectnum,p->borhisnum,p->buybknum);
		if (p->borbknum==1){
			strcpy(p->borrow[0],a);
			for (j=0;j<p->borbknum;j++)
				fprintf(fp," %s",p->borrow[j]);
		}
		else {
			for (j=0;j<p->borbknum-1;j++)
				fprintf(fp," %s",p->borrow[j]);
		}
		if (p->collectnum==1){
			for (j=0;j<p->collectnum;j++)
				fprintf(fp," %s",p->collect[j]);
		}
		else {
			for (j=0;j<p->collectnum-1;j++)
				fprintf(fp," %s",p->collect[j]);
		}
		if (p->borhisnum==1){
			for (j=0;j<p->borhisnum;j++)
				fprintf(fp," %s",p->borhis[j]);
		}
		else {
			for (j=0;j<p->borhisnum-1;j++)
				fprintf(fp," %s",p->borhis[j]);
		}
		if (p->buybknum==1){
			for (j=0;j<p->buybknum;j++)
				fprintf(fp," %s",p->buy[j]);
		}
		else {
			for (j=0;j<p->buybknum-1;j++)
				fprintf(fp," %s",p->buy[j]);
		}
	}
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
	while (fscanf(fp,"%s %s %s %s %d %d %d %d %d",s->bkname,s->author,s->cla,s->noro,&s->bknum,&s->price,&s->num,&s->available,&s->bornum)!=EOF){
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
	int j;
	if ((fp=fopen("D://saveuserinf.txt","rt"))==NULL){
		printf("���ļ�����������˳���");
		getch();
		exit(1); 
	} 
	h=(Link)malloc(sizeof (Login));
	s=(Link)malloc(sizeof(Login));
	h->next=NULL;
	p=h;
	while (fscanf(fp,"%s %s %s %s %d %d %d %d",s->username,s->passwd,s->ques,s->cla,&s->borbknum,&s->collectnum,&s->borhisnum,&s->buybknum)!=EOF){
		if (s->borbknum==1){
			for (j=0;j<s->borbknum;j++)
				fscanf(fp," %s\n",s->borrow[j]);
		}
		else {
			for (j=0;j<s->borbknum-1;j++)
				fscanf(fp," %s\n",s->borrow[j]);
		}
		if (s->collectnum==1){
			for (j=0;j<s->collectnum;j++)
				fscanf(fp," %s\n",s->collect[j]);
		}
		else {
			for (j=0;j<s->collectnum-1;j++)
				fscanf(fp," %s\n",s->collect[j]);
		}
		if (s->borhisnum==1){
			for (j=0;j<s->borhisnum;j++)
				fscanf(fp," %s\n",s->borhis[j]);
		}
		else {
			for (j=0;j<s->borhisnum-1;j++)
				fscanf(fp," %s\n",s->borhis[j]);
		}
		if (s->buybknum==1){
			for (j=0;j<s->buybknum;j++)
				fscanf(fp," %s\n",s->buy[j]);
		}
		else {
			for (j=0;j<s->buybknum-1;j++)
				fscanf(fp," %s\n",s->buy[j]);
		}
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
	int k,result;
	Linklist L;
	L=readfile();
	char name[N];
	if (j==2){	
		k=interface4move();
		while(1){
			printf("������Ҫ���ҵ����ƣ�"); 
			PlaySound(TEXT("2.wav"),NULL,SND_FILENAME|SND_SYNC);
			scanf("%s",name);
			if (k==1){
				Seek(L,name,k);
			}
			if (k==2)
				Seek(L,name,k);
			if (k==3)
				Seek(L,name,k);
			result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
			if (result==IDYES)
				system("cls");
			if (result==IDNO)
				break;
		}
	}
	if (j==3){
		while(1){
			memset(name,0,N);
			printf("������Ҫɾ����������"); 
				scanf("%s",name);
			Delete(L,name);
			sort(L);
			savefile(L,1);
			result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
			if (result==IDYES)
				system("cls");
			if (result==IDNO)
				break;
		}
	}
	if (j==4){
		while(1){
			memset(name,0,N);
			printf("��������Ҫ�޸ĵ�������\n");
				scanf("%s",name);
			modify(L,name);
			savefile(L,1);
			result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
			if (result==IDYES)
				system("cls");
			if (result==IDNO)
				break;
		}
	}
	if (j==5){
		print(L);
		getch();
	}
}

Link Creat(char username[])
{
	Link L;
	Login *s,*r;
	int flag=0,i,j,k;
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
	s->borbknum=1;
	s->collectnum=1;
	s->borhisnum=1;
	s->buybknum=1;
	i=s->borbknum-1;
	j=s->collectnum-1;
	k=s->buybknum-1;
	strcpy(s->borrow[i],a);
	strcpy(s->collect[j],a);
	strcpy(s->borhis[i],a);
	strcpy(s->buy[k],a);
	s->next=r->next;
	r->next=s;
	r=s;
	while (1){
		if (strcmp(passwd2,s->passwd)==0){
			printf("ע��ɹ���\n");
			printf("����������أ�\n");
			//getch();
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
			PlaySound(TEXT("6.wav"),NULL,SND_FILENAME|SND_SYNC);
				getpasswd(passwd);
			while(1){
				if (strcmp(p->passwd,passwd)==0){
						flag=1;
						break;
				}
				else {
					printf("�������\n���������룺");
					PlaySound(TEXT("7.wav"),NULL,SND_FILENAME|SND_SYNC);
					getpasswd(passwd);
				}
			}
			if (flag==1){
				printf("��֤��Ϊ��\n");
				printf("------");
				printf("\n %4d\n",data);
				printf("------\n");
				printf("��������֤�룺");	 /*��֤��*/ 
				PlaySound(TEXT("8.wav"),NULL,SND_FILENAME|SND_SYNC);
					scanf("%d",&guess);
				while (guess != data){
					printf("��֤�����!\n");
					printf("��������֤�룺");
					PlaySound(TEXT("9.wav"),NULL,SND_FILENAME|SND_SYNC);
						scanf("%d",&guess);
				}
				system("cls");
				//time();
				print1();
				PrintChar("��¼�ɹ�", 8, 36, 7);
				PrintChar("�����������", 12, 34, 8);
				PlaySound(TEXT("10.wav"),NULL,SND_FILENAME|SND_SYNC);
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
						getch();
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
	int flag,i,j;
	h=readuserinf();
	m=readfile();
	p=h->next;
	s=m->next;
	while (s){
		flag=0;
		if (strcmp(s->bkname,name)==0){
			flag=1;
			if (s->available>0){
				while (p){
					if (strcmp(p->username,username)==0){
						i=p->borbknum-1;
						j=p->borhisnum-1;
						strcpy(p->borrow[i],name);
						strcpy(p->borhis[j],name);
						printf("���ѳɹ�����!\n");
						s->available--;
						s->bornum++;
						p->borbknum++;
						p->borhisnum++;
						break;
					}
					else
						p=p->next;
				}
			}
			else 
				printf("�����ѱ�����!\n");
			break;
		}
		else 
			s=s->next;
	}
	savefile(m,1);
	if (flag==0)
		printf("û���ҵ�����!\n");
	//printf("��������˳�");
	//getch();
	return h;
}

Link bkbook(char username[],char name[])
{
	int i,j,flag;
	Login *p,*h;
	Node *m,*s;
	h=readuserinf();
	m=readfile();
	p=h->next;
	s=m->next;
	while (p){
		flag=0;
		if (strcmp(p->username,username)==0){
			for (i=0;i<p->borbknum;i++){
				if (strcmp(p->borrow[i],name)==0){
					flag=1;
					strcpy(p->borrow[i]," ");
					for (j=i;j<p->borbknum;j++)
						strcpy(p->borrow[j],p->borrow[j+1]);
					printf("����ɹ�!\n");
					p->borbknum--;
					while (s){
						if (strcmp(s->bkname,name)==0){
							s->available++;
							break;
						}
						else 
							s=s->next;
					}
					//getch();
					break;
				}
			}
			break;
		}
		else 
			p=p->next;
	}
	if (flag==0)
		printf("��û�������!");
	//getch();
	savefile(m,1);
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
	PlaySound(TEXT("3.wav"),NULL,SND_FILENAME|SND_SYNC);
	printf("\n�����������");
	getch();
}

void myborbk(char username[])
{
	Login *h,*p;
	int j;
	system("cls");
	h=readuserinf();
	p=h->next;
	while(p){
		if (strcmp(p->username,username)==0){
			if (p->borbknum==1){
				for (j=0;j<p->borbknum;j++)
				printf("%s\n",p->borrow[j]);
			}
			else {
				for (j=0;j<p->borbknum-1;j++)
				printf("%s\n",p->borrow[j]);	
			}
			break;
		}
		else
			p=p->next;
	}
	printf("\n�����������");
	getch();
}

void ranking()
{
	Node *h;
	h=readfile();
	sort1(h);
	PlaySound(TEXT("4.wav"),NULL,SND_FILENAME|SND_SYNC);
	getch();
}

void sort (Linklist L)
{
	Node *p=L->next,*q=NULL;							//pָ���һ�����ݽڵ�
	Node *r;  
	if (p!=NULL)										//��������һ���������ϵ����ݽڵ�
	{
		r=p->next;										//r ���� *p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
		p->next=NULL;									//����ֻ����һ�����ݽڵ�������
		p=r;
		while(p!=NULL)
		{
			r=p->next;									//r ����*p�ڵ��ֱ�Ӻ�̽ڵ��ָ��
			q=L;
			while(q->next!=NULL)
			{

				if(strcmp(q->next->bkname,p->bkname)<0)	
				q=q->next; 
				else break;								//��������в��Ҳ���*p��ֱ��ǰ���ڵ�*q��λ��
				
			}	
			p->next=q->next;							//��*p���뵽*q֮��
			q->next=p;	
			p=r;										//ɨ��ԭ���������µĽڵ�
		}
	}
	//print(L);
	savefile(L,1);
}

void sort1 (Linklist L)
{
	Node *p=L->next,*q=NULL;
	Node *r;  
	int i;
	if (p!=NULL)                                    
	{
		r=p->next;                      
		p->next=NULL;           
		p=r;
		while(p!=NULL)
		{
			r=p->next;                
			q=L;
			while(q->next!=NULL)
			{
				
					if(q->next->bornum>p->bornum)	
					q=q->next; 
					else break;   
				
			}	
			p->next=q->next;                  
			q->next=p;
			p=r;                               
		}
	}
	p=L->next;
	for (i=0;i<5;i++){
		printf("%d. %s\n",i+1,p->bkname);
		p=p->next;
	}
}

Link collect(char username[],char name[])
{
	Login *p,*h;
	Node *m,*s;
	int flag,i;
	h=readuserinf();
	m=readfile();
	p=h->next;
	s=m->next;
	while (s){
		flag=0;
		if (strcmp(s->bkname,name)==0){
			flag=1;
			while (p){
				if (strcmp(p->username,username)==0){
					i=p->collectnum-1;
					strcpy(p->collect[i],name);
					printf("�����ղظ���!\n");
					p->collectnum++;
					break;
				}
				else
					p=p->next;
			}
			break;
		}
		else 
			s=s->next;
	}
	savefile(m,1);
	if (flag==0)
		printf("û���ҵ�����!\n");
	return h;
}

void mycollect(char username[])
{
	Login *h,*p;
	int j;
	system("cls");
	h=readuserinf();
	p=h->next;
	while(p){
		if (strcmp(p->username,username)==0){
			if (p->collectnum==1){
				for (j=0;j<p->collectnum;j++)
				printf("%s\n",p->collect[j]);
			}
			else {
				for (j=0;j<p->collectnum-1;j++)
				printf("%s\n",p->collect[j]);	
			}
			break;
		}
		else
			p=p->next;
	}
	printf("\n�����������");
	getch();
}

void hisbk(char username[])
{
	Login *h,*p;
	int j;
	system("cls");
	h=readuserinf();
	p=h->next;
	while(p){
		if (strcmp(p->username,username)==0){
			if (p->borhisnum==1){
				for (j=0;j<p->borhisnum;j++)
				printf("%s\n",p->borhis[j]);
			}
			else {
				for (j=0;j<p->borhisnum-1;j++)
				printf("%s\n",p->borhis[j]);	
			}
			break;
		}
		else
			p=p->next;
	}
	printf("\n�����������");
	getch();
}

Link buybk(char username[],char name[])
{
	Login *p,*h;
	Node *m,*s;
	int flag,i,j;
	h=readuserinf();
	m=readfile();
	p=h->next;
	s=m->next;
	while (s){
		flag=0;
		if (strcmp(s->bkname,name)==0){
			flag=1;
			if (s->available>0){
				while (p){
					if (strcmp(p->username,username)==0){
						i=p->buybknum-1;
						j=p->borhisnum-1;
						strcpy(p->buy[i],name);
						strcpy(p->borhis[j],name);
						printf("���ѳɹ�����ͼ��!\n");
						printf("��Ӧ��:%dԪ\n",s->price);
						s->available--;
						s->bornum++;
						p->buybknum++;
						p->borhisnum++;
						select();
						break;
					}
					else
						p=p->next;
				}
			}
			else 
				printf("�����ѱ�����!\n");
			break;
		}
		else 
			s=s->next;
	}
	savefile(m,1);
	if (flag==0)
		printf("û���ҵ�����!\n");
	return h;
}
void f8()
{
	Login *h;
	Linklist L;
	int i,j,k,g,m;
	int x=155,flag,result;
	char name[N];
	char username[N];
	h=readuserinf();
	L=readfile();
	sort(L);
	for (i=0;i<3;i++)
		print2();
	PrintChar("Welcome to my book store!", 25, 30, 7);
	PrintChar("�����������", 12, 34, 8);
	PlaySound(TEXT("1.wav"),NULL,SND_FILENAME|SND_SYNC);
	getch();
	initgraph(639,479);
	while (1){
		system("cls");
		i=interface1move();
		if (i==1){
			while (1){
				system("cls");
				j=interface2move();
				if (j==1){
					k=interface4move();
					while (1){
						L=readfile();
						printf("������Ҫ���ҵ����ƣ�"); 
						PlaySound(TEXT("2.wav"),NULL,SND_FILENAME|SND_SYNC);
						scanf("%s",name);
						if (k==1){
							Seek(L,name,k);
						}
						if (k==2){
							Seek(L,name,k);
						}
						if (k==3){
							Seek(L,name,k);
						}
						result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
						if (result==IDYES)
							system("cls");
						if (result==IDNO)
							break;
					}
				}
				if (j==2){
					newbk();	
					break;
				}
				if (j==3){
					ranking();
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
								PlaySound(TEXT("5.wav"),NULL,SND_FILENAME|SND_SYNC);
									scanf("%s",username);
								flag=login(h,username,0);
							}
							if(flag==1){
								while(1){
									system("cls");
									g=interface3move();
									if (g==1){
										while(1){
											printf("����������");
											PlaySound(TEXT("11.wav"),NULL,SND_FILENAME|SND_SYNC);
												scanf("%s",name);
											h=buybk(username,name);
											saveuserinf(h,3);
											result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
											if (result==IDYES)
												system("cls");
											if (result==IDNO)
												break;
										}
									}
									if (g==2){
										h=readuserinf();
										while(1){
											printf("����������");
											PlaySound(TEXT("12.wav"),NULL,SND_FILENAME|SND_SYNC);
												scanf("%s",name);
											while (h){
												flag=1;
												if (strcmp(h->username,username)==0){
													if (h->borbknum==1)
														m=h->borbknum;
													else
														m=h->borbknum-1;
													for (i=0;i<m;i++){
														if (strcmp(h->borrow[i],name)==0){
															flag=0;
															printf("���ѽ������\n");
															PlaySound(TEXT("13.wav"),NULL,SND_FILENAME|SND_SYNC);
														//	getch();
															break;
														}
													}
													break;
												}
												else 
													h=h->next;
											}
											if (flag==1){
												h=borrowbk(username,name);
												saveuserinf(h,3);
											}
											result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
											if (result==IDYES)
												system("cls");
											if (result==IDNO)
												break;
										}
									}
									if (g==3){
										myborbk(username);
									}
									if (g==4){
										while(1){
											printf("����������");
												scanf("%s",name);
											h=collect(username,name);
											saveuserinf(h,3);
											result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
											if (result==IDYES)
												system("cls");
											if (result==IDNO)
												break;
										}
									}
									if (g==5){
										mycollect(username);
									}
									if (g==6){
										hisbk(username);
									}
									if (g==7){
										while(1){
											printf("����������");
												scanf("%s",name);
											h=bkbook(username,name);
											saveuserinf(h,3);
											result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
											if (result==IDYES)
												system("cls");
											if (result==IDNO)
												break;
										}
									}
									if (g==8){

									}
									if (g==9)
										break;
								}
							}
						}

						if (k==2){
							h=readuserinf();
							while(1){
								memset(username,0,N);
								printf("��������Ҫ�޸ĵ�������\n");
									scanf("%s",username);
								modifyuserinf(h,username);
								saveuserinf(h,3);
								result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
								if (result==IDYES)
									system("cls");
								if (result==IDNO)
									break;
							}
						}
						if (k==3)
							break;
					}
				}
				if (j==5)
					break;
			}
			
		}
		if (i==2){
			system("cls");
			h=readuserinf();
			flag=-1;

			while(1){
				printf("�������û�����");
					scanf("%s",username);
				flag=login(h,username,1);
				if (flag==-1){
					printf("�����ǹ���Ա!\n");
					result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
					if (result==IDYES)
						system("cls");
					if (result==IDNO){
						system("cls");
						break;
					}
				}
				if (flag==1)
					break;
			}

			if(flag==1){
				cleardevice();
				while(1){
					system("cls");
					j=f6();
					if (j==1){
						L=CreatFromHead();
						savefile(L,4);
						print(L);
						L=readfile();
						sort(L);
						printf("����������أ�\n");
						getch();
					}
					else if (j>=2&&j<6){
						f7(j);
					}
					else
						break;
				}
			}
		}
		if (i==3){
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
				h=Creat(username);
				result = MessageBox( NULL , "�Ƿ������" , "�������˳�", MB_ICONSTOP|MB_YESNO);
				if (result==IDYES)
					system("cls");
				if (result==IDNO)
					break;

			}
		}
		if (i==4)
			break;
	}
}

void main()
{
	f8();
}
