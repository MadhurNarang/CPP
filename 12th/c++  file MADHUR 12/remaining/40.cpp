//STACK USING ARRAYS
#include<iostream.h>
#define size 3
class stack
{
  int ar[size],top;
 public:
  stack()
  {
	top=-1;
  }
  void push(),pop(),disp();
};
void stack::push()
{
  int n;
  if(top==size-1)
	  cout<<"STACK OVERFLOW";
  else
  {
	 cout<<"\nENTER THE ELEMENTS TO INSERT\t";
	 cin>>n;
	 top++;
	 ar[top]=n;
  }
}
void stack::pop()
{
  if(top==-1)
	  cout<<"\nSTACK UNDERFLOW";
  else
  {
	 int  n;
	 n =ar[top];
	 cout<<"THE ELEMENT DELETED IS "<<n;
	 top--;
  }
}
void stack::disp()
{
  if(top==-1)
	  cout<<"\nSTACK UNDERFLOW";
  else
  {
	 cout<<"\nTHE ARRAY IS \t";
	 for(int i=top;i>=0;i--)
		  cout<<ar[i]<<'\t';
  }
}
void main()
{
  int a;
  char t;
  stack v;
  do
  {
	cout<<"ENTER \n1 TO INSERT\n2 TO DELETE\n3 TO DISPLAY \t";
	cin>>a;
	switch(a)
	 {
		case 1: v.push();break;
		case 2: v.pop();break;
		case 3: v.disp();break;
		default: cout<<"\nINVAlid ENTRY";break;
	 }
  cout<<"\nDO YOU WANT TO CONTINUE Y/N\t";
  cin>>t;
  }while((t=='y')||(t=='Y'));
}
