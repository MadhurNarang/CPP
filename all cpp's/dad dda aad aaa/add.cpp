//  ADD
#include<iostream.h>
void sort(int a[],int n,int b[],int m)
{
 int c[200],i,j,k=0;
 for(i=n-1,j=0;i>=0&&j<m;)
 {
  if(a[i]>b[j])
	 c[k++]=a[i--];
  else
	 c[k++]=b[j++];
 }
 while(i>=0)
  c[k++]=a[i--];
 while(j<m)
  c[k++]=b[j++];
 cout<<"COMBINED SORTED ARRAY IS :  \n";
 for(i=0;i<m+n;i++)
  cout<<c[i]<<" ";
}

void main()
{
 int a[100],b[100],i,n,m;
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>n;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }

 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>m;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<m;i++)
 {
  cin>>b[i];
 }
 sort(a,n,b,m);
}