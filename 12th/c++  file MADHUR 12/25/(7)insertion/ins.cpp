//INSERTION IN SORTED ARRAY
#include<iostream.h>                         //HEADER FILES INCLUDED
#include<conio.h>
void insert(int a[],int &s,int element)      //FUNCTION FOR INSERTION IN ARRAY
{
 int i,p;
 if(element<a[0])                            //FUNCTION DEFINITION
	p=0;
 else
	if(element>a[s-1])
		p=s;
	else                                      //CODE FOR INSERTING AN ELEMENT
		{
		 for(i=0;i<s;i++)
			{
			 if(element>a[i]&&element<a[i+1])
				{
				 p=i+1;
				 break;
				}
			}
		}
 for(i=s;i>=p;i--)
  {
	a[i]=a[i-1];
  }
 a[p]=element;
 s++;
}
void main()
{
 int ar[100],i=0,size,e;                          //INTEGER ARRAY DECLARED
 char ch;
 cout<<"ENTER THE NUMBER OF ELEMENTS\n";
 cin>>size;
 cout<<"ENTER THE ELEMENTS IN ASCENDING ORDER"<<endl;
 for(i=0;i<size;i++)
  {
	cin>>ar[i];                                   //INITIALISATION OF ARRAY
  }
 cout<<"\nENTERED ARRAY IS \n";
 for(i=0;i<size;i++)
  {
	cout<<ar[i]<<"  ";                           //DISPLAYING THE ENTERED ARRAY
  }
 do
 {
  cout<<"\n\nENTER THE ELEMENT THAT YOU WANT TO INSERT";
  cin>>e;
  insert(ar,size,e);                           //FUNCTION CALL
  cout<<"\nTHE NEW ARRAY IS\n";
  for(i=0;i<size;i++)
	{
	 cout<<ar[i]<<" ";                          //DISPLAYING THE RESULTING ARRAY
	}
  cout<<"\n\nDO YOU ENTER MORE ELEMENTS";
  cin>>ch;
  clrscr();
 }
 while(ch=='y'||ch=='Y');                      //MENU DRIVEN CONDITION
}

