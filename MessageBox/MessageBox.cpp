#include<windows.h>
//�мǣ�������<windows.h>ʱ����Ҫ����MFC����Afx.h)
void messagebox()
{
    int result = MessageBox( NULL , "���ǶԻ���" , "���", MB_ICONSTOP|MB_YESNO);
    switch(result)/*ע�⣡ʹ��UnicodeӦ��TEXT��Χ�ִ�*/
	{
		case IDYES:MessageBox(NULL,TEXT("��ѡ����YES"),TEXT("YES"),MB_OK);break;
		case IDNO:MessageBox(NULL,TEXT("��ѡ����NO"),TEXT("NO"),MB_OK);break;
	}
}

void main()
{
   messagebox();
}
//http://baike.baidu.com/item/MessageBox