//bubble sort and binary search menu driven program
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void bubblesort(int a[],int n)
{
 int temp,i,j;
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<(n-1-i);j++)
  {
	if(a[j]>a[j+1])
	 {
	  temp=a[j];
	  a[j]=a[j+1];
	  a[j+1]=temp;
	 }
  }
 }
}
void main()
{
 int a[50],size,i,choice,check=0;
 char menu;
	 start: clrscr();
	 cout<<"ENTER THE NO OF ARRAY ELEMENTS   :";
	 cin>>size;
	 cout<<"ENTER THE ARRAY \n";
	 for(i=0;i<size;i++)
	  {
		cin>>a[i];
	  }
	 cout<<"ENTERED ARRAY IS  :  ";
	 for(i=0;i<size;i++)
	 {
	  cout<<a[i]<<" ";
	 }
 lb:	cout<<"\n\nPRESS 1 TO BUBBLE SORT \nPRESS 2 TO BINARY SEARCH AN ELEMENT \nPRESS 3 TO ENTER ELEMENTS AGAIN \nPRESS 4 TO EXIT\n\n";
	cin>>choice;
	if(choice==1)
	{
	  check=1;
	  bubblesort(a,size);
	  cout<<"BUBBLE SORTED ARRAY IS :  ";
	  for(i=0;i<size;i++)
		{
		 cout<<a[i]<<" " ;
		}
		goto lb;
	}
  else
	if(choice==2)
	{
	if(check==1)
	{
	 int beg,last,mid,p,s,element;
	 cout<<"ENTER ELEMENT TO SEARCH   ";
	 cin>>element;
	 beg=0;
	 last=size-1;
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
		  cout<<"ELEMENT NOT FOUND";goto lb;
	}
	else
	 {cout<<"PLEASE SORT THE ARRAY FIRST FOR BINARY SEARCH(IF NOT SORTED)\n\n";goto lb;}
	}
	else
	 if(choice==3)
	 goto start;
	 if(choice==4)
	 exit(0);
	else
	{ cout<<"WRONG CHOICE";goto lb;}
  cout<<"\nDO YOU WANT TO CONTINUE Y/N    ";
  cin>>menu;
}
