//REVERSE THE STRING
#include<iostream.h>                         //HEADER FILES INCLUDED
#include<stdio.h>
int stlen(char c[])                         //FUNCTION RETURNINHG INTEGER VALUE
{
	int i,len=0;
	for(i=0;c[i]!='\0';i++)
	 {
		len++;                               //FUNCTION DEFINITION
	 }
	return(len);
}
void rev(char c[],int l)                  //FUNCTION NOT RETURNING ANY VALUES
{
	int i,j;
	char k;
	for(i=0,j=l-1;i<l/2;i++,j--)
	 {
		k=c[i];
		c[i]=c[j];
		c[j]=k;
	}
}
void main()
{
	int length=0;
	char c[50];
	cout<<"\nENTER THE STRING"<<endl;
	gets(c);
	length=stlen(c);             //FUNCTION CALL(CALL BY REFERNCE(STRING))
	rev(c,length);               //FUNCTION CALL(CALL BY REFERNCE(STRING))
	cout<<"\nREVERSED STRING IS"<<endl;
	puts(c);
}

