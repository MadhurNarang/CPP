#include<iostream.h>
void diagsum(int a[][20],int n)
{  int s=0,i,k;
  for(i=0;i<n;i++)
 {
 for(k=0;k<n;k++)
  {if((i==k)||(i+k==n-1))
  s+=a[i][k];
  }
 }
 cout<<"SUM OF DIAG IS"<<s;
}
void main()
{
 int n,i,k,a[20][20];
 cout<<"ENTER NO OF ROWS AND COLUMNS OF 2D ARRAY"<<endl;
 cin>>n;
 cout<<"NOW ENTER THE ARRAY\n";
 for(i=0;i<n;i++)
 {
 for(k=0;k<n;k++)
  {cin>>a[i][k];}
 }     cout<<"ENTERED ARRAY IS\n";
       for(i=0;i<n;i++)
 {
 for(k=0;k<n;k++)
  {cout<<a[i][k]<<" ";}cout<<endl;
 }
 diagsum(a,n);
}





