#include<iostream.h>
void transform(int a[][20],int n,int m)
{ int v,k;

 for(k=0;k<m;k++)
 {
  v=a[0][k];
  a[0][k]=a[n-1][k];
  a[n-1][k]=v;
 }


}
void main()
{
 int n,i,m,k,a[20][20];
 cout<<"ENTER NO OF ROWS OF 2D ARRAY"<<endl;
 cin>>n;
  cout<<"ENTER NO COLUMNS OF 2D ARRAY"<<endl;
  cin>>m;
 cout<<"NOW ENTER THE ARRAY\n";
 for(i=0;i<n;i++)
 {
 for(k=0;k<m;k++)
  {cin>>a[i][k];}
 }     cout<<"ENTERED ARRAY IS\n";
		 for(i=0;i<n;i++)
 {
 for(k=0;k<m;k++)
  {cout<<a[i][k]<<" ";}cout<<endl;
 }
 transform(a,n,m);
 cout<<"\nswapped ARRAY IS\n";
		 for(i=0;i<n;i++)
 {
 for(k=0;k<m;k++)
  {cout<<a[i][k]<<" ";}cout<<endl;
 }
}




