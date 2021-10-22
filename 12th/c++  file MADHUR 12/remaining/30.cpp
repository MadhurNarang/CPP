//PROGRAM TO ENTER AND SEARCH DETAILS OF STUDENTS
#include<iostream.h>
#include<stdio.h>
class stud
{
  int roll;
  char name[30];
  float per;
 public:
  void in()
  {
	cout<<"\nENTER THE ROLL NUMBER\t";
	cin>>roll;
	cout<<"ENTER THE NAME\t\t";
	gets(name);
	cout<<"ENTER THE PERCENTAGE\t";
	cin>>per;
  }
  int getroll()
  {
	return roll;
  }
  void disp()
  {
	cout<<"\nROLL NUMBER:\t" <<roll;
	cout<<"\nNAME\t\t"<<name;
	cout<<"\nPERCENTAGE\t"<<per;
  }
}x[3];
void search()
{
 cout<<"\n ENTER THE ROLL NUMBER TO SEARCH \t";
 int s,i,j=-1;
 cin>>s;
 for(i=0;i<3;i++)
	 if(x[i].getroll()==3)
 j=i;
 if(j==-1)
	 cout<<"\nROLL NUMBER NOT FOUND!";
 else
	 x[j].disp();
}
void main()
{
  cout<<"ENTER THE DETAILS OF STUDENTS";
  for(int i=0;i<3;i++)
		 x[i].in();
  search();
}
