#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
class employee                              //class tag name
{                                           //private access level starts here
 int empno;
 char name[100],add[100],pin[10];
 double bsal,hrart,dart,pfrt,hra,pf,da,gross,net;
 void calculate()                           //inline function, mutator function
 {
  hra=(hrart*bsal)/100;
  da=(dart*bsal)/100;
  pf=(pfrt*bsal)/100;
  gross=bsal+hra+da;
  net=gross-pf;
 }
public:                                     //public level starts here
	int retempno()                      //inline function, accessor function
		{return empno;}
	void read_data()                         //inline function, mutator function
		{
		 cout<<"\n\nEnter employee number -- ";
		 cin>>empno;
		 cout<<"Enter employee name -- ";
		 gets(name);
		 cout<<"Enter address of employee -- ";
		 gets(add);
		 cout<<"Enter basic salary of employee -- ";
		 cin>>bsal;
		 cout<<"Enter pin code of employee -- ";
		 gets(pin);
		 cout<<"Enter HRA rate of employee -- ";
		 cin>>hrart;
		 cout<<"Enter DA rate of employee -- ";
		 cin>>dart;
		 cout<<"Enter PF rate of employee -- ";
		 cin>>pfrt;
		 calculate();
		}
	void display_data()                     //inline function, mutator function
		{
		 cout<<"\nEmployee number -- "<<empno<<endl;
		 cout<<"\nEmployee name -- "<<name<<endl;
		 cout<<"\nEmployee address -- "<<add<<endl;
		 cout<<"\nEmployee pincode -- "<<pin<<endl;
		 cout<<"\nBasic salary -- "<<bsal<<endl;
		 cout<<"\nHRA -- "<<hra<<endl;
		 cout<<"\nDA -- "<<da<<endl;
		 cout<<"\nPF -- "<<pf<<endl;
		 cout<<"\nGROSS -- "<<gross<<endl;
		 cout<<"\nNet salary -- "<<net<<endl;

		}
};                               //class finishes here
  void main()
{
 employee emp[5];                //object emp declared for employee class type
 int ch,s,i,p,no;
 char c;
 do
 {
 cout<<"PRESS :"<<endl;
 cout<<"1 to enter details "<<endl;
 cout<<"2 to display details "<<endl;
 cout<<"3 to search for an emloyee number"<<endl;
 cout<<"Enter your choice :";
 cin>>ch;
 if(ch==1)
	{
	 clrscr();
	 for(int i=0;i<2;i++)
		{
		 emp[i].read_data();
		}
	}
 else
	if(ch==2)
		{
		 for(i=0;i<2;i++)
			{
			 emp[i].display_data();
			}
		getch();
		}
	else
		if(ch==3)
			{
			  clrscr();
			  cout<<"\n\n Enter employee number to search";
			  cin>>no;
			  for(i=0;i<2;i++)
				{
				 if(no==emp[i].retempno())
					{
					 p=1;
					 s=i;
					 break;
					}
				}
			  if(p==0)
				cout<<"\n\nEmployee number doesnt exist";
			  else
				{
				 cout<<"\n\nEmployee number exist in "<<s+1<<" position";
				 emp[s].display_data();
				}
			}
		else
			cout<<"wrong option";
 cout<<"Do you want to continue -- ";
 cin>>c;
 clrscr();}
 while(c=='y'||c=='Y');

}



