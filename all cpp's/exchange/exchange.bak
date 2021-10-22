#include<iostream.h>
void exchange(int a[],int n)
{
 int temp,i,j,small,pos;
 for(i=0;i<n-1;i++)
 {
  small=a[i];
  pos=i;
 for(j=i+1;j<n;j++)
  {
	if(small>a[j])
	 {
	  small=a[j];
	  pos=j;
	 }
  }
 a[pos]=a[i];
 a[i]=small;
 }
}
void main()
{
 int a[100],i,n;
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>n;
 cout<<"ENTER THE ELEMENTS\n";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 exchange(a,n);
 cout<<"BUBBLE SORTED ARRAY IS :  ";
 {
  for(i=0;i<n;i++)
	{
	 cout<<a[i]<<" " ;
	}
 }

}