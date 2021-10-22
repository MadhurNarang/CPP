#include<iostream.h>
#include<stdio.h>
#include<conio.h>
struct employee
{
  int empid;
  char empname[20];
  char designation[20];
  float salary;
}p1;
void getinfo()
{
 cout<<"ENTER THE EMPLOYEE ID\n";
 cin>>p1.empid;
 cout<<"ENTER THE EMPLOYEE NAME\n";
 gets(p1.empname);
 cout<<"ENTER THE EMPLOYEE DESIGNATION\n";
 gets(p1.designation);
 cout<<"ENTER THE SALLARY\n";
 cin>>p1.salary;
}
void output()
{
 cout<<"THE EMPLOYEE ID IS\n";
 cout<<p1.empid;
 cout<<"\nTHE EMPLOYEE NAME IS\n";
 puts(p1.empname);
 cout<<"THE EMPLOYEE DESIGNATION IS\n";
 puts(p1.designation);
 cout<<"THE SALLARY IS\n";
 cout<<p1.salary;
}
void main()
{
  cout<<"ENTER THE INFORMATION : \n";
  getinfo();
  clrscr();
  cout<<"ENTERED INFORMATION IS  : \n";
  output();
}
