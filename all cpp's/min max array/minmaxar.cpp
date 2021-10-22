//DISPLAY GREATEST AND LOWEST NUMBER FOR AN ARRAY
#include<iostream.h>
void minmax(int a[20],int n)
{
 int i,min,max;
 min=a[0];
 max=a[0];
 for(i=0;i<n;i++)
 {
	 if(a[i]>max)
		max=a[i];
	 else
		if(a[i]<min)
			min=a[i];
 }
 cout<<"MINIMUM NUMBER IN ARRAY IS  :"<<min<<endl;
 cout<<"MAXIMUM NUMBER IN ARRAY IS  :"<<max<<endl;

}
void main()
{
 int a[20],i,n;
 cout<<"ENTER THE NUMBER OF ELEMENTS  :   \n";
 cin>>n;
 cout<<"ENTER THE ELEMENTS   :  \n";
 for(i=0;i<n;i++)
 {
	cin>>a[i];
 }
 minmax(a,n);
}