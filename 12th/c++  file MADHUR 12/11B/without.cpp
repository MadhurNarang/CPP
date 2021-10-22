//COMPARE,CONCATENATE WITHOUT USING LIBRARY FUNCTIONS
#include<stdio.h>
#include<iostream.h>                                    //HEADER FILES INCLUDED
void main()
{
 char str1[50],str2[100],str[200];                           //STRINGS DECALRED
 int i,j,k,m,p=0;
 cout<<"ENTER THE FIRST STRING ";
 gets(str1);                                         //INITIALISING THE STRINGS
 cout<<"ENTER THE SECOND STRING ";
 gets(str2);
 for(i=0;str1[i]!='\0';i++);                        //CALCULATING STRING LENGTH
 for(j=0;str1[j]!='\0';j++);                  //WITHOUT USING LIBRARY FUNCTIONS
 if(i==j)
  {
	for(k=0;k<=i;k++)
	 {
	  if(str1[k]!=str2[k])
		{                                                //COMPARING THE STRINGS
			p=1;
			break;
		}
	 }
  }
 else
	cout<<"\nSTRINGS ARE NOT EQUAL";
 if(p==1)
	 cout<<"\nSTRINGS ARE NOT EQUAL";
 else
	 cout<<"\nSTRINGS ARE EQUAL";                         //RESULT OF COMPARISON
 p=0;
 m=0;
 for(k=0;k<i;k++)
	 str[p++]=str1[k];
 m=p;                                                     //CODE TO CONCATENATE
 for(k=0;k<j;k++)                             //WITHOUT USING LIBRARY FUNCTIONS
	str[m++]=str2[k];
 str[m]='\0';
 cout<<"\n\nCONCATENATED STRING IS ";
 for(i=0;i<m;i++)
	cout<<str[i];                               //DISPLAYING CONCATENATED STRING
}

