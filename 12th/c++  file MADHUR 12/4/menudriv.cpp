//MENU DRIVEN CALCULATOR USING FUNCTIONS
#include<iostream.h>
#include<stdlib.h>                        //HEADER FILES INCLUDED
int sum(int c,int d)
{
	int s=c+d;
	return(s);
}
int diff(int c,int d)
{
	 int di=c-d;
	 return(di);
}
int prod(int c,int d)                   //FUNTION RETURNING VALUES
{
	 int p=c*d;
	 return(p);
}
float quo(int c,int d)
{
	 float q=(float)c/d;
	 return(q);
}
void main()
{
	int a,b,c,d,e,f;
	float g;
	char ch;
	do
	  {
		 cout<<"\nENTER THE FIRST NUMBER\n";
		 cin>>a;
		 cout<<"\nENTER THE SECOND NUMBER\n";
		 cin>>b;
		 cout<<"\nPress 1 to add \nPress 2 to subtract \nPress 3 to multiply ";
		 cout<<"\nPress 4 to divide \nPress 5 to exit\n";
		 cin>>c;                                               //MENU
		 if(c==1)
			{
			  d=sum(a,b);                          //FUNCTION CALL(CALL BY VALUE)
			  cout<<"\nSUM OF "<<a<<" & "<<b<<" IS "<<d;
			}
		 else
			 if(c==2)
				{
				  e=diff(a,b);
				  cout<<"\nDIFFERENCE OF "<<a<<" & "<<b<<" IS "<<e;
				}
			 else
				 if(c==3)
					{
					  f=prod(a,b);
					  cout<<"\nPRODUCT OF "<<a<<" & "<<b<<" IS "<<f;
					}
				 else
					 if(c==4)
						 {
							 g=quo(a,b);
							 cout<<"\nQUOTIENT OF "<<a<<" & "<<b<<" IS "<<g;
						 }
					 else
						if(c==5)
							exit(0);
						else
							cout<<"PLEASE CHECK YOUR CHOICE";
		 cout<<"\nDO YOU WANT TO CONTINUE Y/N\t";
		 cin>>ch;
		}while(ch=='Y');                    //MENU DRIVEN CONDITION
}

