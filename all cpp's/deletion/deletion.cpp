//deletion of element in sorted array
#include<iostream.h>
void del(int a[],int &s,int element)
{
 int i,p=-1;
 for(i=0;i<s;i++)
	 {
	  if(element==a[i])
		{
		 p=i;
		 break;
		}
	 }
 if(p==-1)
  cout<<"\nELEMENT NOT FOUND.\n\n";
 else
 {
  for(i=p;i<s-1;i++)
	 a[i]=a[i+1];
  s--;
 }
}
void main()
{
 int a[20],i,n,element;
 cout<<"ENTER THE NUMBER OF ELEMENTS  :   \n";
 cin>>n;
 cout<<"ENTER THE ELEMENTS IN SORTED WAY AND IN ASCENDING ORDER  :  \n";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<"ENTERED ARRAY IS :\n";
 for(i=0;i<n;i++)
 {
	cout<<a[i]<<" ";
 }
 cout<<"\nENTER THE ELEMENT TO BE DELETED    ";
 cin>>element;
 del(a,n,element);
 cout<<"NOW THE ARRAY IS :\n";
 for(i=0;i<n;i++)
 {
	cout<<a[i]<<" ";
 }
}
