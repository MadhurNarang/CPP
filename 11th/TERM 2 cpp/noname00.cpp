#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i=0,x=0;
char c[10]={"012345678"},d[4];
void main()
{
 cout<<"PLAYER 1 = X & PLAYER 2= Y\n";
 puts("       |    |    ");
 cout<<"    "<<c[0]<<"  | "<<c[1]<<"  | "<<c[2]<<"   \n";
 puts("       |    |    ");
 puts("   --- |--- |--- ");
 puts("       |    |    ");
 cout<<"    "<<c[3]<<"  | "<<c[4]<<"  | "<<c[5]<<"   \n";
 puts("       |    |    ");
 puts("   --- |--- |--- ");
 puts("       |    |    ");
 cout<<"    "<<c[6]<<"  | "<<c[7]<<"  | "<<c[8]<<"   \n";
 puts("       |    |    ");
 for(i=0;i<=8;i++)
 {
  int l=0;
 // for(x=0;x<3;x++)
  //{cin>>d[x];}
  gets(d);
  /*for(;l<=8;l++)
	{
	 if(d[0]==c[l]);
	 {break;}
	}*/
	x=(int)d[0];
  c[x]=d[2];
  clrscr();
  cout<<"PLAYER 1 = X & PLAYER 2= Y\n";
  puts("       |    |    ");
  cout<<"    "<<c[0]<<"  | "<<c[1]<<"  | "<<c[2]<<"   \n";
  puts("       |    |    ");
  puts("   --- |--- |--- ");
  puts("       |    |    ");
  cout<<"    "<<c[3]<<"  | "<<c[4]<<"  | "<<c[5]<<"   \n";
  puts("       |    |    ");
  puts("   --- |--- |--- ");
  puts("       |    |    ");
  cout<<"    "<<c[6]<<"  | "<<c[7]<<"  | "<<c[8]<<"   \n";
  puts("       |    |    ");
  //check();
  //if(x!=0)
  //break;
 }


}