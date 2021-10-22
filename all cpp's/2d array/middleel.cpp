#include<iostream.h>
void main()
{
 int a[10][10],r,c,f,i,k;
 cout<<"ENTER NO OF ROWS(odd)<10  ";
 cin>>r;
 cout<<"ENTER NO OF columns(odd)<10  ";
 cin>>c;
 cout<<"NOW INPUT 2D ARRAY\n";
 for( i=0;i<r;i++)
  {
  for( f=0;f<c;f++)
  {cin>>a[i][f];}
  }

  cout<<"\nARRAY 1 ENTERED  IS\n";
  for(i=0;i<r;i++)
  {
  for(f=0;f<c;f++)
  {cout<<a[i][f]<<" ";}cout<<endl;
  }

  cout<<"middle column elements IS\n";
  for( i=0;i<r;i++)
  {

  cout<<a[i][c/2];
  }
	cout<<"\nmiddle elements IS\n";

  for( f=0;f<c;f++)
  {cout<<a[r/2][f];}

}