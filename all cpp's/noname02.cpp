#include<iostream.h>
#include<conio.h>
void insert(int a[],int &s,int element)
{
 int i,p;
 if(element<a[0])
	p=0;
 else
	if(element>a[s-1])
		p=s;
	else
		{for(i=0;i<s;i++)
			{
			 if(element>a[i]&&element<a[i+1])
				{
				 p=i+1;
				 break;
				}
			}
		}
 for(i=s;i>=p;i--)
	a[i]=a[i-1];
 a[p]=element;
 s++;
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
  cout<<"\n\nEnter the element that you want to insert -- ";
  cin>>e;
  insert(ar,size,e);
  cout<<"\nTHE NEW ARRAY IS -- ";
  for(i=0;i<size;i++)
	 cout<<ar[i]<<"  ";
  cout<<"\n\nDo you want to enter more elements -- ";
  cin>>ch;
  clrscr();
 }
 while(ch=='y'||ch=='Y');
}

