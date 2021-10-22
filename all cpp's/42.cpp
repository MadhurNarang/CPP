//CIRCULAR QUEUE USING ARRAYS
#include<iostream.h>
#include<stdlib.h>
#define size 3
class queue
{
  int ar[size],front,rear;
 public:
  queue()
  {
	 front=rear=-1;
  }
  void ins(),del(),disp();
};
void queue::ins()
{
  int b;
  if(rear==size-1&&front==0||front==rear+1)
		cout<<"QUEUE OVERFLOW";
  else
  {
	 cout<<"\nENTER THE ELEMENTS TO INSERT\t";
	 cin>>b;
	 if(rear==size-1&&front!=0)
	 {
		rear=0;
	 }
	 else
		 if(rear==-1)
			 rear=front=0;
		 else
			 rear++;
	 ar[rear]=b;
  }
}
void queue::del()
{
  if(front==-1)
	  cout<<"\nQUEUE UNDERFLOW";
  else
	 if(front==rear)
		 rear=front=-1;
	 else
	 {
		 if(front==size-1)
			 front=0;
		 else
			 front++;
		 cout<<"\nLAST ELEMENT IN QUEUE DELETED\n";
	 }
}
void queue::disp()
{
  if(front==-1)
	  cout<<"\nQUEUE UNDERFLOW";
  else
  {
	while(front!=rear)
	{
		cout<<ar[front]<<" ";
		if(front==size-1)
			front=0;
		else
			front++;
	}
	cout<<endl;
  }
}
void main()
{
  int c;
  char ch;
  queue s;
  do
	{
		cout<<"ENTER \n1 TO INSERT\n2 TO DELETE\n3 TO DISPLAY \t";
`		cin>>c;
		switch(c)
		{
			case 1: s.ins();break;
			case 2: s.del();break;
			case 3: s.disp();break;
			default: cout<<"\nINVALID ENTRY";break;
		}
  cout<<"\nDO YOU WANT TO CONTINUE Y/N\t";
  cin>>ch;
 }while((ch=='y')||(ch=='Y'));
}
