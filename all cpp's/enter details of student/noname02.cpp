
#include<iostream.h>
#include<stdio.h>
	class student
		{int roll;
		 char name[25];
		 float eng, maths, science, per;
		 public:
		  void enter()
				{cout<<"\n  Enter name of student\n\t";
					gets(name);
				 cout<<"\n  Enter roll no. of student\n\t";
					cin>>roll;
				 cout<<"\n  Enter marks\n";
				 cout<<"\n  English ";
					cin>>eng;
				 cout<<"\n  Maths ";
					cin>>maths;
				 cout<<"\n  Science ";
					cin>>science;
				}
		  void calc()
			{
			  per=(eng+maths+science)/3;
			}
		  void display()
			  {
				cout<<"\n  "<<roll<<'\t'<<name<<'\t'<<per<<'\t';
			  }
		 }x[2];
void main()
{ int i;
  for(i=0;i<2;i++)
	{x[i].enter();
	 x[i].calc();
	}
  for(i=0;i<2;i++)
	{cout<<"\n  Roll No.\t  Name\t  Percentage";
	 x[i].display();
	}
}

