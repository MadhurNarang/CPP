#include<iostream.h>
#include<conio.h>
void delet(int a[],int &s,int element)
{
 int i,p;
 {
  for(i=0;i<s;i++)
	{
	 if(element==a[i])
		{
		 p=i;
		 break;
		}
	}
 }
 for(i=p;i<s;i++)
	a[i]=a[i+1];
 s--;
}
void main()
{
 int ar[100],i=0,size,e;
 char ch;
 cout<<"Enter the size of array -- ";
 cin>>size;
 cout<<"\nEnter the elements in ascending order -- "<<endl;
 for(i=0;i<size;i++)
	cin>>ar[i];
 cout<<"\nEntered array is -- ";
 for(i=0;i<size;i++)
	cout<<ar[i]<<"  ";
 do
 {
  cout<<"\n\nEnter the element that you want to delete -- ";
  cin>>e;
  delet(ar,size,e);
  cout<<"\nTHE NEW ARRAY IS -- ";
  for(i=0;i<size;i++)
	 cout<<ar[i]<<"  ";
  cout<<"\n\nDo you want to delete more elements -- ";
  cin>>ch;
  clrscr();
 }
 while(ch=='y'||ch=='Y');
}

