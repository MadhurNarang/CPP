//TIE UP QUES:SWAP BINARY ARRAY ELEMENTS USING SINGLE ITERATION
#include<iostream.h>
#include<conio.h>
void main()
{
   clrscr();
   int a[50],i,n,k;
   cout<<"\nENTER THE NUMBER OF ELEMENTS\n";
   cin>>n;
   cout<<"\nENTER THE BINARY ARRAY\n";
   for(i=0;i<n;i++)
   {
     cin>>a[i];
   }
    cout<<"\nBINARY ARRAY ENTERED IS\n";
   for(i=0;i<n;i++)
   {
     cout<<a[i];
   }
   for(i=0,k=n-1;i<k;)
   {
      if(a[i]==1&&a[k]==0)
       {
	 a[i]=0;
	 a[k]=1;
       }
      else
	if(a[i]==0)
	 i++;
	else
	 if(a[k]==1)
	  k--;
   }
   cout<<"\nNOW THE BINARY ARRAY IS\n";
   for(i=0;i<n;i++)
   {
     cout<<a[i];
   }
 getch();
}