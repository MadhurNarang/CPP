//TO CHECK IF A NUMBER IS EVEN,ODD,PRIME
#include<iostream.h>                              //HEADER FILES INCLUDED
void main()
{
 int a,i,k=0;
 cout<<"ENTER THE NUMBER TO BE CHECKED FOR EVEN OR ODD AND PRIME  :\n";
 cin>>a;
 if(a%2==0)
  cout<<a<<" IS EVEN NUMBER\n";                    //CASCADING OPERATORS USED
 else
  cout<<a<<" IS ODD NUMBER\n";
  for(i=2;i<a/2;i++)
	{
	  if(a%i==0)
		k=1;
		break;                             //JUMPING STATEMENT TO SAVE TIME
	}
  if(k==0)
	 cout<<a<<" IS PRIME NUMBER";
  else
	 cout<<a<<"IS A COMPOSITE NUMBER";
}