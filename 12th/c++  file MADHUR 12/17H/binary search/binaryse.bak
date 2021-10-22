#include<iostream.h>
void main()
{
 int a[100],i,n,beg,mid,last,element,s=0,p;
 cout<<"ENTER NUMBER OF INTEGERS   ";
 cin>>n;
 cout<<"ENTER THE NUMBERS IN ASCENDING ORDER\n";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<"ENTER ELEMENT TO SEARCH   ";
 cin>>element;
 beg=0;
 last=n-1;
 while(beg<=last)
 {
  mid=(beg+last)/2;
  if(a[mid]==element)
	 {p=mid;s=1;break;}
  else
	if(a[mid]>element)
	 {last=mid-1;}
	else
	 beg=mid+1;
 }
 if(s==1)
	cout<<"\nPOSITION OF ELEMENT \""<<element<<"\" IS : "<<(p+1);
 else
  cout<<"ELEMENT NOT FOUND";
}