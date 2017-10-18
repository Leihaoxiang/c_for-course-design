#include<windows.h>
//切记！当调用<windows.h>时，不要调用MFC！（Afx.h)
void messagebox()
{
    int result = MessageBox( NULL , "这是对话框" , "你好", MB_ICONSTOP|MB_YESNO);
    switch(result)/*注意！使用Unicode应用TEXT包围字串*/
	{
		case IDYES:MessageBox(NULL,TEXT("您选择了YES"),TEXT("YES"),MB_OK);break;
		case IDNO:MessageBox(NULL,TEXT("您选择了NO"),TEXT("NO"),MB_OK);break;
	}
}

void main()
{
   messagebox();
}
//http://baike.baidu.com/item/MessageBox