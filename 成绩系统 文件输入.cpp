#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include <conio.h>
#include <stdlib.h> 
using namespace std;
void menu()
{  cout<<"欢迎使用学生成绩管理系统2.0\n";
	cout << "    1. 输出学生的成绩表\n";
	cout << "    2. 求每人的平均分\n";
	cout << "    3. 求每门课的平均分\n";
	cout << "    4. 导出到文件\n";
	cout << "    0. 退出\n\n";
	cout << "请输入你的选择(0-4)：\n" ;
}

void input(int a[][4] ,int m,int n)
{
int  i, j;
ifstream infile;
infile.open("cj1.txt"); 
 for(i=0; i<m-1; i++)        // i 控制行数 
    {    
	for(j=0; j<n-1; j++)     // j 控制列数 
        infile >> a[i][j];   //  文件数据读入到内存a[i][j] 
     }  
      infile.close();
}

void output(int a[][4] ,int m,int n)
{
  for(int i=0; i<m; i++)      
    {    for(int j=0; j<n; j++) 
              cout << a[i][j]<<" ";  
		cout<<endl;   
     }	
	
}

void fun2(int a[][4])
{
	cout<<"功能2：求每人的平均分\n";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
			a[i][3]+=a[i][j];
		a[i][3]/=3;
	}				
}
void fun3(int a[][4])
{
	cout<<"功能3：求每门课的平均分\n";
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<4;i++)
			a[4][j]+=a[i][j];
		a[4][j]/=4;
	}
}
void fun4(int a[][4])
{
	ofstream outfile;
	cout<<"功能4: 导出到文件\n";
	outfile.open("cj2.txt");
 	for(int i=0; i<5; i++)      
    {    
		for(int j=0; j<4; j++) 
            outfile << a[i][j]<<" ";  
		outfile<<endl;   
    }
    outfile.close();
}

int main()
{
	int cj[5][4]={0};    //int cj[5][4] ={ {89, 78, 56},{88,99,100},{72,80,61}, {60,70,75}};
	int  i, j;
	int choose;
	input(cj,5,4);
	menu();
    cin >> choose;
	while (choose != 0) // if(choose==0) break;
	{
  		switch (choose) 
 		{
			case 1:output(cj,5,4); break;
    		case 2:fun2(cj); break;
    		case 3:fun3(cj); break;
    		case 4:fun4(cj); break;
		}
	system("pause");		 //getchar();
 	system("CLS");
 	menu(); 
 	cin >> choose;
	}
	
	return 0;
}

