//BUBBLE SORT USING STRUCTURE ARRAY
#include<iostream.h>
#include<stdio.h>                                       //HEADER FILES INCLUDED
#include<stdlib.h>
#include<conio.h>
struct student                                             //STRUCTURE DECLARED
{
 int rn;
 char name[25];                                             //STRUCTURE MEMBERS
 float avg,s1,s2,s3;
};
void main()
{
 int i,n,j;
 student a[10],temp;                     //STRUCTURE VARIABLE AS ARRAY DECLARED
 cout<<"ENTER THE NUMBER OF STUDENTS   ";
 cin>>n;
 for(i=0;i<n;i++)
  {
	 cout<<"\nENTER THE DEATILS OF STUDENT "<<(i+1)<<endl;
	 cout<<"\nENTER THE ROLL NO\n";
	 cin>>a[i].rn;
	 cout<<"ENTER THE NAME\n";
	 gets(a[i].name);                               //INITIALISING MEMBER VALUES
	 cout<<"ENTER THE MARKS IN PHYSICS\n";
	 cin>>a[i].s1;
	 cout<<"ENTER THE MARKS IN CHEMISTRY\n";
	 cin>>a[i].s2;
	 cout<<"ENTER THE MARKS IN MATHEMATICS\n";
	 cin>>a[i].s3;
	 a[i].avg=(a[i].s1+a[i].s2+a[i].s3)/3;
  }
 for(i=0;i<n-1;i++)
  {
	for(j=0;j<n-1-i;j++)
	 {
	  if(a[j].rn>a[j+1].rn)
		{
		  temp=a[j];                                       //CODE FOR BUBBLE SORT
		  a[j]=a[j+1];
		  a[j+1]=temp;
		}
	 }
 clrscr();
 getch();
 gotoxy(10,10);                         //GOTOXY USED TO PRINT VALUES IN REPORT
 cout<<"ROLL NO";
 gotoxy(30,10);
 cout<<"NAME";
 gotoxy(50,10);
 cout<<"PERCENTAGE";
 for(i=0;i<n;i++)
  {
	 gotoxy(10,i+12);
	 cout<<a[i].rn;
	 gotoxy(30,i+12);
	 cout<<a[i].name;
	 gotoxy(50,i+12);
	 cout<<a[i].avg<<endl;}
	 getch();
	 clrscr();
  }
}
