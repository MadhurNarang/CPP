#include<iostream.h>
#include<stdio.h>
void main()
{
 char c[100];
 int i,k,n,m,ni,size,di=200;
 cout<<"ENTER THE STRING\n";
 gets(c);
 for(i=0;c[i]!='\0';i++)
 {
  if(c[i]==' ')
  {
	  if((di==200)&&(c[0]!=' '))
	  {int fd=i-1;
	  for(int z=0;z<(i/2);z++,fd--)
	  {

		di=c[z];
		c[z]=c[fd];
		c[fd]=di;
	  }}
	 

	for(k=i+1;c[k]!='\0';k++)
	{
	 if(c[k]==' ')
	 {
	  goto gh;
	 }
	}

 gh: n=i+1;
 m=k-1;
 if((k+i)%2==1)
{ size=((i+k)/2)+1;}
 else
{ size=(i+k)/2; }
 for(;n<size;n++,m--)
 {
  ni=c[n];
  c[n]=c[m];
  c[m]=ni;
 } }
 }
cout<<"\nREVERSED STRING IS  ";puts(c);
}