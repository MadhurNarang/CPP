#include<iostream>
using namespace std;

void arrinput(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void intersection(int arr1[],int n,int arr2[],int m)
{
     int i,j,status[100]={0};

     for (i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
             if(arr1[i]==arr2[j])
                if(status[j]==0)
                 {
                     cout<<arr1[i]<<" "; 
                     status[j]=1; 
                     break;
                 }
         }
     }
}

int main()
{
    int arr1[100],arr2[100],t,n,m;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;;
        arrinput(arr1,n);
        cin>>m;
        arrinput(arr2,m);

        intersection(arr1,n,arr2,m);
        cout<<endl;
    }
    return 0;
}