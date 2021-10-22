#include<iostream.h>
void main()
{
 int b[100],a[10][10],c,f,i;
 cout<<"ENTER NO OF DIGITS  ";cin>>f;
 cout<<"\nENTER 1D ARRAY\n";
 for(i=0;i<f;i++)
  {
	cin>>b[i];
  }
 cout<<"\nENTERED 1D ARRAY IS\n";
 for(i=0;i<f;i++)
  {
	cout<<b[i];
  }
 cout<<"\n\n2D ARRAY IS\n";
 for(i=0;i<f;i++)
 {
 for(c=0;c<f;c++)
 {
  a[i][c]=b[c];
  cout<<a[i][c]<<" ";}cout<<endl;
 }
}
