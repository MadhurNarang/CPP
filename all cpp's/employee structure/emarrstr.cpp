#include<iostream.h>
#include<stdio.h>
#include<conio.h>
struct employee
{
  int empid;
  char empname[20];
  char designation[20];
  float salary;
};
void getinfo(employee p[],int n)
{
 for(int i=0;i<n;i++)
 {
 cout<<"\n\n\n";
 cout<<"ENTER THE EMPLOYEE ID OF EMPLOYEE "<<i+1<<"\n";
 cin>>p[i].empid;
 cout<<"ENTER THE EMPLOYEE NAME OF EMPLOYEE "<<i+1<<"\n";
 gets(p[i].empname);
 cout<<"ENTER THE EMPLOYEE DESIGNATION OF EMPLOYEE "<<i+1<<"\n";
 gets(p[i].designation);
 cout<<"ENTER THE SALLARY OF EMPLOYEE "<<i+1<<"\n";
 cin>>p[i].salary;
 }
}
void output(employee p[],int n)
{
 for(int i=0;i<n;i++)
 {
 cout<<"\n\n\n";
 cout<<"THE EMPLOYEE ID OF EMPLOYEE "<<i+1<<" IS\n";
 cout<<p[i].empid;
 cout<<"\nTHE EMPLOYEE NAME OF EMPLOYEE "<<i+1<<" IS\n";
 puts(p[i].empname);
 cout<<"THE EMPLOYEE DESIGNATION OF EMPLOYEE "<<i+1<<" IS\n";
 puts(p[i].designation);
 cout<<"THE SALLARY OF EMPLOYEE "<<i+1<<" IS\n";
 cout<<p[i].salary;
 }
}
void main()
{
  employee p[10];
  int n;
  cout<<"ENTER THE NUMBER OF ENTRIES  :\n";
  cin>>n;
  clrscr();
  cout<<"ENTER THE INFORMATION : \n";
  getinfo(p,n);
  clrscr();
  cout<<"ENTERED INFORMATION IS  : \n";
  output(p,n);
}
