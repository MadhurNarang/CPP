#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int check(char c[],int x)
{
 if(((c[0]==c[1])&&(c[1]==c[2]))||((c[0]==c[4])&&(c[4]==c[8]))||((c[0]==c[3])&&(c[3]==c[6]))||((c[1]==c[4])&&(c[4]==c[7]))||((c[2]==c[5])&&(c[5]==c[8]))||((c[2]==c[4])&&(c[4]==c[6]))||((c[3]==c[4])&&(c[4]==c[5]))||((c[6]==c[7])&&(c[7]==c[8])))
 {x++;} return(x);
}
int i=0,x=0,che=0;
char choice;
int d;
void main()
{
do{
 char c[10]={'0','1','2','3','4','5','6','7','8'};
 clrscr();
 puts("-----    -----    -----      -----   -----   -----      -----   -----   -----");
 puts("  |        |      |            |    |     |  |            |     |   |   |    ");
 puts("  |        |      |            |    |-----|  |            |     |   |   |----");
 puts("  |        |      |            |    |     |  |            |     |   |   |    ");
 puts("  |      -----    -----        |    |     |  -----        |     -----   -----");
 puts("_____________________________________________________________________________");
 puts("-----------------------------------------------------------------------------");
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
  if(i%2==0)
  {cout<<"PLAYER 1 ENTER YOUR BOX DIGIT  ";
  cin>>d;
  if(!(d<9))
 {while(!(d<9)){cout<<"\nWRONG CHOICE ENTERED ENTER YOUR CHOICE AGAIN  ";cin>>d;}}
  if(c[d]=='Y'||c[d]=='X')
  {while(c[d]=='Y'||c[d]=='X'){cout<<"BOX IS ALREADY USED ENTER VALID CHOICE";cin>>d;}}
  c[d]='X';
  }
  else{cout<<"PLAYER 2 ENTER YOUR BOX DIGIT  ";
  cin>>d;
  if(!(d<9))
  {while(!(d<9)){cout<<"\nWRONG CHOICE ENTERED ENTER YOUR CHOICE AGAIN  ";cin>>d;}}
  if(c[d]=='Y'||c[d]=='X')
  {while(c[d]=='Y'||c[d]=='X'){cout<<"BOX IS ALREADY USED ENTER VALID CHOICE";cin>>d;}}
  c[d]='Y';}
  clrscr();
  puts("-----    -----    -----      -----   -----   -----      -----   -----   -----");
 puts("  |        |      |            |    |     |  |            |     |   |   |    ");
 puts("  |        |      |            |    |-----|  |            |     |   |   |----");
 puts("  |        |      |            |    |     |  |            |     |   |   |    ");
 puts("  |      -----    -----        |    |     |  -----        |     -----   -----");
 puts("_____________________________________________________________________________");
 puts("-----------------------------------------------------------------------------");
  cout<<"PLAYER 1 = X & PLAYER 2= Y \n";
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
  che=check(c,x);
  if(che!=0)
  {if(i%2==0)
	  {cout<<"PLAYER 1 WINS !!! ";goto last;}
	  else{cout<<"PLAYER 2 WINS !!!";goto last;}
  }if(i==8)
	{cout<<"GAME IS DRAW!!!";}
 }
 last:;
 cout<<"\nDO YOU WANT TO PLAY AGAIN Y/N  ";
 cin>>choice;
 }while(choice=='Y');

}
