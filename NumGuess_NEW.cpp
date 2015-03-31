//文件名：猜数字.cpp
//本程序为一个猜数字游戏

#include <cstdlib> //包含伪随机数生成函数
#include <ctime>   //包含取系统时间的函数
#include <iostream>
using namespace std;

int main()
{ 	int ran[3], count_a=0, count_b=0, times=0, time_win=0, time_fail=0, num[3], i, j, k;
	bool flag;char answer,num_c[3];
  	
	srand(time(NULL));  //随机数种子初始化
	
	for(;;)				
	{do{cout << "需要玩游戏吗（Y/N）？"; cin >>answer;}
	 while(answer!='Y'&&answer!='N');
	 if(answer=='N')break; 
	 else if(answer=='Y')
		{times+=1;flag=false;//用于判断是否赢得游戏和计数 
		 do{ran[0]=rand() * 10 / (RAND_MAX + 1);
			ran[1]=rand() * 10 / (RAND_MAX + 1);
			ran[2]=rand() * 10 / (RAND_MAX + 1);}
		 while(ran[0]==ran[1]||ran[1]==ran[2]||ran[0]==ran[2]); //保证产生三个不同随机数 
		  for(k=1;k<8;++k)	//每局的7次机会 
		    { cout << "请输入你猜测的数字："<<endl;
		      cin >>num_c[0]>>num_c[1]>>num_c[2];
		      while(num_c[0]==num_c[1]||num_c[1]==num_c[2]||num_c[0]==num_c[2]
			    ||num_c[0]<'0'||num_c[0]>'9'||num_c[1]<'0'||num_c[1]>'9'||num_c[2]<'0'||num_c[2]>'9')
			    {cout<<"请正确输入3个不同的小于10的整数："<<endl; 
				  cin >>num_c[0]>>num_c[1]>>num_c[2]; } //保证正确输入
			  for(i=0;i<3;++i) num[i]=num_c[i]-'0'; 
		 	  count_a=0,count_b=0;
		  	  for(j=0;j<3;++j)
		  	    for(i=0;i<3;++i) //判断是否猜对 
			  	  if(num[j] != ran[i])continue;
			      else{if(i==j)count_a+=1;
			  	  	   else count_b+=1;} 
			  cout <<count_a<<"A"<<count_b<<"B"<<endl;
			  if(count_a==3)
			    {cout<<"恭喜，你猜对了"<<endl; 
				 flag=true;time_win+=1;break;}
			} 
		  if (!flag){time_fail+=1;
		  cout <<"很遗憾，你没有在规定次数内猜对。答案是 "<<ran[0]<<ran[1]<<ran[2]<<endl;}}}	  
	cout << "你一共玩了"<<times<<"局，赢了"<<time_win<<"局，输了"<<time_fail<<"局";		  
		  
	return 0;		
 }
