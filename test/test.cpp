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
	time_t timer;//time_t就是long int 类型
	struct tm *tblock;
	timer = time(NULL);//这一句也可以改成time(&timer);
	tblock = localtime(&timer);
	printf("登录时间: %s\n",asctime(tblock));
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
	printf("请选择付款方式:\n");
	printf("1、支付宝;\n2、微信;\n");
	scanf("%d",&select);
	look_somep(select);
}

void print1() {
	{//隐藏光标
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
		CursorInfo.bVisible = false; //隐藏控制台光标  
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态  
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
	{//隐藏光标
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
		CursorInfo.bVisible = false; //隐藏控制台光标  
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态  
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

void PrintChar(char *ch, UINT count, UINT x, UINT y)  //在坐标(x,y)处输出字符串ch,ch里有count个字符
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	ULONG unuse;
	pos.X = x;
	pos.Y = y;
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口缓冲区信息
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
	outtextxy(300,155,"公共检索");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"管理员登录");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"注册");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"退出");
	setcolor(WHITE);
	outtextxy(200,250,"**********************************************");
}

void interface2(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"书刊检索");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"新书通报");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"借阅排名");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"个人中心");
	setcolor(WHITE);
	if (i==5)
		setcolor(GREEN);
	outtextxy(300,215,"退出");
	setcolor(WHITE);
	outtextxy(200,265,"**********************************************");
}

void interface3(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"购买图书");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"借阅图书");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"我的借阅");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"收藏图书");
	setcolor(WHITE);
	if (i==5)
		setcolor(GREEN);
	outtextxy(300,215,"我的收藏");
	setcolor(WHITE);
	if (i==6)
		setcolor(GREEN);
	outtextxy(300,230,"借阅历史");
	setcolor(WHITE);
	if (i==7)
		setcolor(GREEN);
	outtextxy(300,245,"归还图书");
	setcolor(WHITE);
	if (i==8)
		setcolor(GREEN);
	outtextxy(300,260,"图书续借");
	setcolor(WHITE);
	if (i==9)
		setcolor(GREEN);
	outtextxy(300,275,"注销");
	setcolor(WHITE);
	outtextxy(200,325,"**********************************************");
}

void interface4(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"书名");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"作者");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"类别");
	setcolor(WHITE);
	outtextxy(200,235,"**********************************************");
}

void f(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"登录");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"修改密码");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"退出");
	setcolor(WHITE);
	outtextxy(200,235,"**********************************************");
}

void f5(int i)
{
	outtextxy(200,100,"**********************************************");
	setcolor(GREEN);
	if (i!=1)
		setcolor(WHITE);
	outtextxy(300,155,"添加图书");
	setcolor(WHITE);
	if (i==2)
		setcolor(GREEN);
	outtextxy(300,170,"查找图书");
	setcolor(WHITE);
	if (i==3)
		setcolor(GREEN);
	outtextxy(300,185,"删除图书");
	setcolor(WHITE);
	if (i==4)
		setcolor(GREEN);
	outtextxy(300,200,"修改图书信息");
	setcolor(WHITE);
	if (i==5)
		setcolor(GREEN);
	outtextxy(300,215,"查看全部图书");
	setcolor(WHITE);
	if (i==6)
		setcolor(GREEN);
	outtextxy(300,230,"注销");
	setcolor(WHITE);
	outtextxy(200,280,"**********************************************");
}

void f2(int x)//箭头
{
	outtextxy(250,x,"→>>");
}

int f3(int flag)//键盘操作
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

int f4()//箭头移动
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

int interface1move()//箭头移动
{
	initgraph(639,479);
	int x=155,i,flag=1;
	interface1(1);
	f2(x);
	i=f3(2);
	closegraph();
	return i;
}

int interface2move()//箭头移动
{
	initgraph(639,479);
	int x=155,i,flag=1;
	interface2(1);
	f2(x);
	i=f3(3);
	closegraph();
	return i;
}

int interface3move()//箭头移动
{
	initgraph(639,479);
	int x=155,i,flag=1;
	interface3(1);
	f2(x);
	i=f3(4);
	closegraph();
	return i;
}

int interface4move()//箭头移动
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
	printf("请输入书名，作者，类别，新旧，编号，价格，数量，可借数量：(书名为exit结束)\n");
	scanf("%s",s->bkname);
	scanf("%s%s%s%d%d%d%d",s->author,s->cla,s->noro,&s->bknum,&s->price,&s->num,&s->available);
	s->bornum=0;
	while (1){
			s->next=r->next;
			r->next=s;
			r=s;
			s=(Node*)malloc(sizeof(Node));
			printf("请输入书名，作者，类别，新旧，编号，价格，数量，可借数量：(书名为exit结束)\n");
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
	printf("书名		   作者		        类别   编号  价格  总数 可用 浏览数\n");
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
			printf("书名：%s 作者：%s 类别：%s 编号：%d 馆藏数量：%d 可借数量：%d\n",p->bkname,p->author,p->cla,p->bknum,p->num,p->available);
			break;
		}
		else if (strcmp(p->author,name)==0&&k==2){
			flag=1;
			printf("书名：%s 作者：%s 类别：%s 编号：%d 馆藏数量：%d 可借数量：%d\n",p->bkname,p->author,p->cla,p->bknum,p->num,p->available);
			p=p->next;
		}
		else if (strcmp(p->cla,name)==0&&k==3){
			flag=1;
			printf("书名：%s 作者：%s 类别：%s 编号：%d 馆藏数量：%d 可借数量：%d\n",p->bkname,p->author,p->cla,p->bknum,p->num,p->available);
			p=p->next;
		}
		else 
			p=p->next;
	}
	if (flag==0)
		printf("没有找到符合要求的书!");
	//printf("按任意键退出");
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
		printf("没有找到该书!");
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
			printf("书名：%s 作者：%s 类别：%s 价格：%d 馆藏数量：%d 可借数量：%d\n",p->bkname,p->author,p->cla,p->price,p->num,p->available);
			printf("您要修改：1.馆藏数量 2.可借数量 3.价格\n");
			scanf("%d",&x);
			if (x==1){
				m=p->num;
				printf("修改为："); 
				scanf("%d",&p->num);
				n=m-p->num;
				p->available+=n;
			}
			if (x==2){
				printf("修改为：");
				scanf("%d",&p->available);
			}
			if (x==3){
				printf("修改为：");
				scanf("%d",&p->price);
			}
			break;
		}
		else 
			p=p->next;
	}
	if (flag==0)
		printf("没有找到该书!");
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
	char a[N]="无";
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
		printf("读文件出错按任意键退出！");
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
		printf("读文件出错按任意键退出！");
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
			printf("请输入要查找的名称："); 
			PlaySound(TEXT("2.wav"),NULL,SND_FILENAME|SND_SYNC);
			scanf("%s",name);
			if (k==1){
				Seek(L,name,k);
			}
			if (k==2)
				Seek(L,name,k);
			if (k==3)
				Seek(L,name,k);
			result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
			if (result==IDYES)
				system("cls");
			if (result==IDNO)
				break;
		}
	}
	if (j==3){
		while(1){
			memset(name,0,N);
			printf("请输入要删除的姓名："); 
				scanf("%s",name);
			Delete(L,name);
			sort(L);
			savefile(L,1);
			result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
			if (result==IDYES)
				system("cls");
			if (result==IDNO)
				break;
		}
	}
	if (j==4){
		while(1){
			memset(name,0,N);
			printf("请输入想要修改的姓名：\n");
				scanf("%s",name);
			modify(L,name);
			savefile(L,1);
			result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
	char a[N]="无";
	L=(Link)malloc(sizeof(Login));
	s=(Login*)malloc(sizeof (Login));
	L->next=NULL;
	r=L;
	strcpy(s->username,username);
	printf("请输入密码：");
	getpasswd(passwd1);
	strcpy(s->passwd,passwd1);
	printf("请再次输入密码：");
	getpasswd(passwd2);
	printf("请输入密保问题\n您的生日(xx-xx-xx)：");
	scanf("%s",s->ques);
	printf("请输入类别:");
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
			printf("注册成功！\n");
			printf("按任意键返回！\n");
			//getch();
			break;
		}
		else {
			printf("密码错误！\n请重新输入密码：");
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
			printf("请输入密码：");
			PlaySound(TEXT("6.wav"),NULL,SND_FILENAME|SND_SYNC);
				getpasswd(passwd);
			while(1){
				if (strcmp(p->passwd,passwd)==0){
						flag=1;
						break;
				}
				else {
					printf("密码错误！\n请重新输入：");
					PlaySound(TEXT("7.wav"),NULL,SND_FILENAME|SND_SYNC);
					getpasswd(passwd);
				}
			}
			if (flag==1){
				printf("验证码为：\n");
				printf("------");
				printf("\n %4d\n",data);
				printf("------\n");
				printf("请输入验证码：");	 /*验证码*/ 
				PlaySound(TEXT("8.wav"),NULL,SND_FILENAME|SND_SYNC);
					scanf("%d",&guess);
				while (guess != data){
					printf("验证码错误!\n");
					printf("请输入验证码：");
					PlaySound(TEXT("9.wav"),NULL,SND_FILENAME|SND_SYNC);
						scanf("%d",&guess);
				}
				system("cls");
				//time();
				print1();
				PrintChar("登录成功", 8, 36, 7);
				PrintChar("按任意键继续", 12, 34, 8);
				PlaySound(TEXT("10.wav"),NULL,SND_FILENAME|SND_SYNC);
				getch();
			}
			break;
		}
		else 
			p=p->next;
	}
	if (flag==0)
			printf("找不到该用户名!\n");
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
					printf("请输入您的生日(xx-xx-xx):");
					scanf("%s",ques);
					if (strcmp(p->ques,ques)==0)
						break;
				}
				printf("密码修改为：");
				getpasswd(passwd);
				strcpy(p->passwd,passwd);
				printf("请再次输入密码:");
				getpasswd(passwd2);
				while (1){
					if (strcmp(passwd2,p->passwd)==0){
						printf("修改成功！\n");
						printf("按任意键返回！\n");
						getch();
						break;
					}
					else {
						printf("密码错误！\n请重新输入密码：");
							getpasswd(passwd2);
					}
				}
			break;
		}
		else 
			p=p->next;
	}
	if (flag==0)
		printf("找不到该用户名!");
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
						printf("您已成功借书!\n");
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
				printf("该书已被借完!\n");
			break;
		}
		else 
			s=s->next;
	}
	savefile(m,1);
	if (flag==0)
		printf("没有找到该书!\n");
	//printf("按任意键退出");
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
					printf("还书成功!\n");
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
		printf("您没借过该书!");
	//getch();
	savefile(m,1);
	return h;
}
void newbk()
{
	Node *h,*p;
	char a[N]="新";
	system("cls");
	h=readfile();
	p=h->next;
	while (p){
		if (strcmp(p->noro,a)==0){
			printf("书名：%s 作者：%s 类别：%s 馆藏数量：%d 可借数量：%d\n",p->bkname,p->author,p->cla,p->num,p->available);
			p=p->next;
		}
		else 
			p=p->next;
	}
	PlaySound(TEXT("3.wav"),NULL,SND_FILENAME|SND_SYNC);
	printf("\n按任意键继续");
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
	printf("\n按任意键继续");
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
	Node *p=L->next,*q=NULL;							//p指向第一个数据节点
	Node *r;  
	if (p!=NULL)										//单链表有一个或者以上的数据节点
	{
		r=p->next;										//r 保存 *p节点的直接后继节点的指针
		p->next=NULL;									//构造只含有一个数据节点的有序表
		p=r;
		while(p!=NULL)
		{
			r=p->next;									//r 保存*p节点的直接后继节点的指针
			q=L;
			while(q->next!=NULL)
			{

				if(strcmp(q->next->bkname,p->bkname)<0)	
				q=q->next; 
				else break;								//在有序表中查找插入*p的直接前驱节点*q的位置
				
			}	
			p->next=q->next;							//将*p插入到*q之后
			q->next=p;	
			p=r;										//扫描原单链表余下的节点
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
					printf("您已收藏该书!\n");
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
		printf("没有找到该书!\n");
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
	printf("\n按任意键继续");
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
	printf("\n按任意键继续");
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
						printf("您已成功购买图书!\n");
						printf("您应付:%d元\n",s->price);
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
				printf("该书已被借完!\n");
			break;
		}
		else 
			s=s->next;
	}
	savefile(m,1);
	if (flag==0)
		printf("没有找到该书!\n");
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
	PrintChar("按任意键继续", 12, 34, 8);
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
						printf("请输入要查找的名称："); 
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
						result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
								printf("请输入用户名：");
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
											printf("请输入书名");
											PlaySound(TEXT("11.wav"),NULL,SND_FILENAME|SND_SYNC);
												scanf("%s",name);
											h=buybk(username,name);
											saveuserinf(h,3);
											result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
											if (result==IDYES)
												system("cls");
											if (result==IDNO)
												break;
										}
									}
									if (g==2){
										h=readuserinf();
										while(1){
											printf("请输入书名");
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
															printf("您已借过该书\n");
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
											result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
											printf("请输入书名");
												scanf("%s",name);
											h=collect(username,name);
											saveuserinf(h,3);
											result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
											printf("请输入书名");
												scanf("%s",name);
											h=bkbook(username,name);
											saveuserinf(h,3);
											result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
								printf("请输入想要修改的姓名：\n");
									scanf("%s",username);
								modifyuserinf(h,username);
								saveuserinf(h,3);
								result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
				printf("请输入用户名：");
					scanf("%s",username);
				flag=login(h,username,1);
				if (flag==-1){
					printf("您不是管理员!\n");
					result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
						printf("按任意键返回！\n");
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

				printf("请输入用户名:");
					scanf("%s",username);
				while (h){
					flag=1;
					if (strcmp(h->username,username)==0){
						printf("用户名已存在!\n");
						flag=0;
						break;
					}
					else 
						h=h->next;
				}
				if (flag==1)
				h=Creat(username);
				result = MessageBox( NULL , "是否继续？" , "继续或退出", MB_ICONSTOP|MB_YESNO);
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
