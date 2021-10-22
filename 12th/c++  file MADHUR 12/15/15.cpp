//FINDING HCF AND LCM OF TWO NUMBERS
#include<iostream.h>                            //HEADER FILES INCLUDED
void main()
{
 int no1,no2,n,i,lcm,hcf;
 cout<<"ENTER THE NUMBERS TO FIND THEIR HCF AND LCM";
 cin>>no1>>no2;
 if(no1>no2)
	n=no1;
 else
	n=no2;
 for(i=1;i<n;i++)
  {
	if((no1%i==0)&&(no2%i==0))                 //USING LOGICAL OPERATORS
	  hcf=i;
  }
  cout<<"HCF IS "<<hcf<<endl;
  for(i=1;i<=no1*no2;i++)
	{
	 if((i%no1==0)&&(i%no2==0))
	  {
		 lcm=i;
		 break;                                //USING JUMPING STATEMENT
	  }
	}
  cout<<"LCM IS "<<lcm;
}

