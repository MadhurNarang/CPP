//IMPLEMENTATION OF INHERITANCE
#include<iostream.h>
#include<stdio.h>
class person
{
  char name[30],address[30],phone[15];
 public:
  void get()
  {
	cout<<"\nENTER THE NAME\t";
	gets(name);
	cout<<"\nENTER THE ADDRESS";
	gets(address);
	cout<<"\nENTER THE PHONE NUMBER\t";
	cin>>phone;
  }
  void show()
  {
	cout<<"\nNAME:\t"<<name;
	cout<<"\nADDRESS:\t"<<address;
	cout<<"\nPHONE NUMBER:\t"<<phone;
  }
};
class student:public person
{
  int admno;
  char clas[3],section[2];
 public:
  void getdata()
  {
	get();
	cout<<"\nENTER ADMISSION NUMBER\t";
	cin>>admno;
	cout<<"\nENTER THE CLASS\t";
	cin>>clas;
	cout<<"\nENTER THE SECTION\t";
	cin>>section;
 }
  void showdata()
  {
	show();
	cout<<"\nADMISSSION NUMBER:\t"<<admno;
	cout<<"\nCLASS:\t"<<clas;
	cout<<"\nSECTION:\t"<<section;
  }
};
void main()
{
  student s[2];
  int i;
  for(i=0;i<2;i++)
  s[i].getdata();
  for(i=0;i<2;i++)
  s[i].showdata();
}
