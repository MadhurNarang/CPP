#include<iostream.h>
void main()
{
 int a[10][10],b[10][10],d[10][10],r,c,f,i;
 cout<<"ENTER NO OF ROWS<10  ";
 cin>>r;
 cout<<"ENTER NO OF columns<10  ";
 cin>>c;
 cout<<"NOW INPUT 2D ARRAY  1\n";
 for( i=0;i<r;i++)
  {
  for( f=0;f<c;f++)
  {cin>>a[i][f];}
  }
	cout<<"NOW INPUT 2D ARRAY  2\n";
 for( i=0;i<r;i++)
  {
  for( f=0;f<c;f++)
  {cin>>b[i][f];}
  }
  cout<<"\nARRAY 1 ENTERED  IS\n";
  for(i=0;i<r;i++)
  {
  for(f=0;f<c;f++)
  {cout<<a[i][f]<<" ";}cout<<endl;
  }cout<<"\nARRAY  2 ENTERED IS\n";
  for(i=0;i<r;i++)
  {
  for(f=0;f<c;f++)
  {cout<<b[i][f]<<" ";}cout<<endl;
  }

  cout<<"\nARRAY SUM IS\n";
  for(i=0;i<r;i++)
  {
  for(f=0;f<c;f++)
  {d[i][f]=a[i][f]+b[i][f];
  cout<<d[i][f]<<" ";}cout<<endl;
  }


}
