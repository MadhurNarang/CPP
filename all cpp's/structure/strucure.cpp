// STRUCTURES
//INPUT DATA OF STUDENTS AND SEARCH FOR ROLL NUMBER AND SHOW ALL DATA IN TABULAR FORM
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct student
{
 int rollno;
 char name[25];
 float eng,maths,science,avg;
};

void main()
{
 start :int no,i,rollsearch,found=0,choice;
 char choice2;
 student a[10];
 cout<<"ENTER NUMBER OF STUDENTS\n";
 cin>>no;
 for(i=0;i<no;i++)
 {
  cout<<"\nENTER DETAILS OF STUDENT "<<(i+1)<<"\n\n";
  cout<<"ENTER NAME OF STUDENT "<<(i+1)<<'\n';
  gets(a[i].name);
  cout<<"ENTER ROLL NO OF STUDENT "<<(i+1)<<'\n';
  cin>>a[i].rollno;
  cout<<"ENTER ENGLISH MARKS OF STUDENT "<<(i+1)<<'\n';
  cin>>a[i].eng;
  cout<<"ENTER MATHS MARKS OF STUDENT "<<(i+1)<<'\n';
  cin>>a[i].maths;
  cout<<"ENTER SCIENCE MARKS OF STUDENT "<<(i+1)<<'\n';
  cin>>a[i].science;
  a[i].avg=(a[i].eng+a[i].maths+a[i].science)/3;
 }
 cout<<"\nPRESS ANY KEY TO CONTINUE";
 getch();
 clrscr();
mid: cout<<"PRESS 1 TO SHOW ALL ENTERED DETAILS \nPRESS 2 TO SEARCH DETAILS BY ENTERING ROLL NO\nPRESS 3 TO EXIT\n";
 cin>>choice;
 if(choice==1)
 {
  clrscr();
  cout<<"\n\nENTERED DETAILS ARE :  \n";
  cout<<"ROLL NO     NAME       ENG     MATHS     SCIENCE   AVERAGE\n";
  cout<<"-------     ----       ---     -----     -------   -------\n";
  for(i=0;i<no;i++)
  {
	cout<<"  "<<a[i].rollno<<"\t  ";
	cout<<(a[i].name)<<"\t";
	cout<<a[i].eng<<"\t";
	cout<<a[i].maths<<"\t ";
	cout<<a[i].science<<"\t  ";
	cout<<a[i].avg<<"\n";
  }
  cout<<"\nPRESS ANY KEY TO CONTINUE";
  getch();
  clrscr();
  goto mid;
 }
  if(choice==2)
  {
	clrscr();
	cout<<"ENTER THE ROLL NO OF STUDENT TO DISPLAY ITS DETAILS   ";
	cin>>rollsearch;
	for(i=0;i<no;i++)
	{
	 if(a[i].rollno==rollsearch)
	 {
	  found=1;
	  break;
	 }
	}
	if(found==1)
	{
	cout<<"ROLL NO     NAME       ENG     MATHS     SCIENCE   AVERAGE\n";
	cout<<"-------     ----       ---     -----     -------   -------\n";
	cout<<"  "<<a[i].rollno<<"\t  ";
	cout<<(a[i].name)<<"\t";
	cout<<a[i].eng<<"\t";
	cout<<a[i].maths<<"\t ";
	cout<<a[i].science<<"\t  ";
	cout<<a[i].avg<<"\n";
  }
  else
	cout<<"ROLL NUMBER NOT FOUND";
  cout<<"\nPRESS ANY KEY TO CONTINUE";
  getch();
  clrscr();
  goto mid;
 }
 if(choice==3)
 {
  exit(0);
 }

 else
  {
	cout<<"\nWRONG CHOICE ENTERED\tENTER CHOICE AGAIN";
	goto mid;
  }
}