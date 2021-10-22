#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
  clrscr();
  int a[10][10],i,j,n,m,k,h=0;
  cout<<"\nENTER THE NO OF ROWS AND COLUMNS\n";
  cin>>n>>m;
  cout<<"\nENTER THE 2D ARRAY  \n";
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
    cin>>a[i][j];
  }
 cout<<"\nENTERED 2D ARRAY IS  \n";
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
    cout<<a[i][j];
   cout<<endl;
  }
  cout<<"\nZIG-ZAG PATTERN IS\n";
  for(k=0;k<2*n;k++)
  {
   if(h%2==1)
    {
     for(i=0;i<n;i++)
      {
       for(j=0;j<m;j++)
	 if(i+j==h)
	 cout<<a[i][j];
      }
    }
   else
    {
     for(i=n-1;i>=0;i--)
      {
       for(j=m-1;j>=0;j--)
	 if(i+j==h)
	 cout<<a[i][j];
      }
    }
   h++;
  }
 getch();
}