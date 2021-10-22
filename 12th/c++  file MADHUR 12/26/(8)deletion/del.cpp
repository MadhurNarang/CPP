//DELETION IN SORTED ARRAY
#include<iostream.h>                            //HEADER FILES INCLUDED
#include<conio.h>
void delet(int a[],int &s,int element)          //FUNCTION FOR DELETION
{
 int i,p;
 {
  for(i=0;i<s;i++)
	{
	 if(element==a[i])                           //FUNCTION DEFINITION
		{
		  p=i;
		  break;
		}                                      //CODE FOR DELETIUON OF AN ELEMENT
	}
 }
 for(i=p;i<s;i++)
  {
	 a[i]=a[i+1];
  }
 s--;
}
void main()
{
 int ar[100],i=0,size,e;                        //INTEGER ARRAY DECLARED
 char ch;
 cout<<"ENTER THE NUMBER OF ELEMENTS\n";
 cin>>size;
 cout<<"\nENTER THE ELEMENTS IN ASCENDING ORDER"<<endl;
 for(i=0;i<size;i++)
  {
	cin>>ar[i];                                  //INTIALISING THE ARRAY
  }
 cout<<"\nENTERED ARRAY IS ";
 for(i=0;i<size;i++)
  {
	 cout<<ar[i]<<"  ";                          //DISPLAYING THE ENETERED ARRAY
  }
 do
 {
  cout<<"\n\nENTER THE ELEMENT THAT YOU WANT TO DELETE\n";
  cin>>e;
  delet(ar,size,e);                             //FUNCTION CALL
  cout<<"\nTHE NEW ARRAY IS ";
  for(i=0;i<size;i++)
	{
	  cout<<ar[i]<<"  ";                        //DISPLAYING THE RESULTING ARRAY
	}
  cout<<"\n\nDO YOU WANT TO DELETE MORE ELEMENTS";
  cin>>ch;
  clrscr();
 }
 while(ch=='y'||ch=='Y');                       //MENU DRIVEN CONDITION
}

