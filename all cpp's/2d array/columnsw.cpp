#include<iostream.h>
void main()
{
 int a[10][10],r,c,f,i,k;
 cout<<"ENTER NO OF ROWS<10  ";
 cin>>r;
 cout<<"ENTER NO OF columns<10  ";
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
  for(f=0;f<c;f++)
  {
	k=a[0][f];
	a[0][f]=a[r-1][f];
	a[r-1][f]=k;
  } cout<<"SWAPEED COLUMN IS\n";
  for( i=0;i<r;i++)
  {
  for( f=0;f<c;f++)
  {cout<<a[i][f]<<" ";}cout<<endl;
  }
}