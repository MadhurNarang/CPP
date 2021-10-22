#include<iostream.h>
void main()
{
 int a[100],n,i,min,max;
 cout<<"ENTER NO OF INTEGERS  ";
 cin>>n;
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 max=a[0];
 min=a[0];
 for(i=1;i<n;i++)
 {
  if(a[i]<min)
  {min=a[i];}
  if(a[i]>max)
  {max=a[i];}

 }
 cout<<"MINIMUM VALUE IS :"<<min<<"\n";
 cout<<"MAXIMUM VALUE IS :"<<max<<"\n";
}