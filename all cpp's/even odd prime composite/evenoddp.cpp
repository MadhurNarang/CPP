//EVEN ODD AND PRIME IDENTIFICATION
#include<iostream.h>
void main()
{
 int a,i,k=0;
 cout<<"ENTER THE NUMBER TO BE CHECKED FOR EVEN OR ODD AND PRIME  :\n";
 cin>>a;
 if(a%2==0)
  cout<<a<<" IS EVEN NUMBER\n";
 else
  cout<<a<<" IS ODD NUMBER\n";
 for(i=2;i<a/2;i++)                //IT WILL SHOW 2 AS PRIME ONLY 
	{
	  if(a%i==0)
		k=1;
		break;
	}
  if(k==0)
	 cout<<a<<" IS PRIME NUMBER";
  else
    cout<<a<<"IS A COMPOSITE NUMBER";    
}