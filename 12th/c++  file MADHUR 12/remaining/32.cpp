//IMPLEMENTATION OF CALSS USING DIFFERENT CONSTRUCTORS
#include<iostream.h>
#include<stdio.h>
#include<string.h>
class stud
{
  int roll;
  char name[20];
  float per;
 public:
  stud()
  {
	roll=0;
	strcpy(name,"NULL");
	per=0.0;
  }
  stud(int r ,char n[],float p)
  {
	roll=r;
	strcpy(name,n);
	per=p;
  }
  stud(stud &x)
  {
	roll=x.roll;
	strcpy(name,x.name);
	per=x.per;
  }
  void enter()
  {
	cout<<"\nENTER THE ROLL NUMBER\n";
	cin>>roll;
	cout<<"ENTER NAME \t\t";
	gets(name);
	cout<<"ENTER PERCENTAGE";
	cin>>per;
  }
  void disp()
  {
	cout<<"\nROLL NUMBER\t"<<roll;
	cout<<"\nNAME\t\t"<<name;
	cout<<"\nPERCENATGE\t\t"<<per;
  }
};
void main()
{
  stud s,u;
  s.disp();
  cout<<endl;
  u.enter();
  cout<<endl;
  u.disp();
  cout<<endl;
  stud v(9,"SAM",96);
  v.disp();
  cout<endl;
  stud w(v);
  w.disp();
}
