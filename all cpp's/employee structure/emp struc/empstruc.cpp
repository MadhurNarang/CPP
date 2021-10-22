/*IMPLEMENTATION OF STRUCTURE: TO INPUT EMPLOYEE ID,EMPLOYEE NAME,DESIGNATION,
SALARY OF EMPLOYEES,DISPLAY ALL VALUES,SEARCH ACCORDING TO EMPLOYEE DISPLAY ITS
DETAILS,SORT THE DATE ON THE BASIS OF EMPLOYEE ID EVERY TIME VALUES ARE INPUT*/
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct employee
{
  int empid;
  char empname[20];
  char designation[20];
  float salary;
}p[10];
int n=0;
void sort()
{
 employee temp; 
 int i,j;
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<(n-1-i);j++)
  {
	if(p[j].empid>p[j+1].empid)
	 {
	  temp=p[j];
	  p[j]=p[j+1];
	  p[j+1]=temp;
	 }
  }
 }
}
void search()
{
  int checkid,k=-1;
  cout<<"ENTER THE EMPLOYEE ID TO GET ITS DETAILS  \n";
  cin>>checkid;
  for(int i=0;i<n;i++)
	{
	 if(p[i].empid==checkid)
	  {
		k=i;
	  }
	 if(k==-1)
	  cout<<"\nNO EMPLOYEE OF THIS ID\n";
	 else
	  {
		cout<<"\n\n\n";
		cout<<"THE EMPLOYEE ID IS\n";
		cout<<p[k].empid;
		cout<<"\nTHE EMPLOYEE NAME IS\n";
		puts(p[k].empname);
		cout<<"THE EMPLOYEE DESIGNATION IS\n";
		puts(p[k].designation);
		cout<<"THE SALLARY IS\n";
		cout<<p[k].salary<<endl;
	  }
	}
}
void getinfo(employee p[])
{
 char choice='y';
 while(choice=='y')
 {
  cout<<"\n\n\n";
  cout<<"ENTER THE EMPLOYEE ID\n";
  cin>>p[n].empid;
  cout<<"ENTER THE EMPLOYEE NAME\n";
  gets(p[n].empname);
  cout<<"ENTER THE EMPLOYEE DESIGNATION\n";
  gets(p[n].designation);
  cout<<"ENTER THE SALLARY\n";
  cin>>p[n].salary;
  n++;
  cout<<"\n\nDO YOU WANT TO ADD MORE EMPLOYEE INFORMATION y/n    ";
  cin>>choice;
  }
 sort();
}
void output(employee p[],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<"\n\n\n";
  cout<<"THE EMPLOYEE ID IS\n";
  cout<<p[i].empid;
  cout<<"\nTHE EMPLOYEE NAME IS\n";
  puts(p[i].empname);
  cout<<"THE EMPLOYEE DESIGNATION IS\n";
  puts(p[i].designation);
  cout<<"THE SALLARY IS\n";
  cout<<p[i].salary<<endl;
 }
}
void main()
{
	int ch;
	start:
	cout<<"\nPRESS ANY KEY TO CONTINUE    ";
	getch();
	clrscr();
	cout<<"\nPRESS 1 TO ENTER DATA \n\nPRESS 2 TO DISPLAY ALL DATA \n\n";
	cout<<"PRESS 3 TO SEARCH DATA BY ENTERING EMPLOYEE ID \n\nPRESS 4 TO EXIT\n\n";
	cin>>ch;
	 if(ch==1)
	 {
		clrscr();
		cout<<"ENTER THE INFORMATION : \n";
		getinfo(p);
		goto start;
	}

	if(ch==2)
	 {
		clrscr();
		cout<<"ENTERED INFORMATION IS  : \n";
		output(p,n);
		goto start;
	 }
	if(ch==3)
	 {
	  clrscr();
	  search();
	  goto start;
	 }
	if(ch==4)
	 {
	  exit(0);
	 }
}

