#include<iostream>
using namespace std;

int main()
{
    int pre , cur , i , n ;
    bool inc=false,dec=false,ans=true;
    cin>>n; 
    cin>>pre;
    for(i=2;i<=n;i++)
    {
        cin>>cur;

        if(pre==cur)
            ans = false;

        if(cur>pre)
        {
            inc= true;
            dec=false;
        }
        else
            dec=true;

        if(inc&&dec)
            ans = false;
        
        pre=cur;
    }

    if(ans)
        cout<<"TRUE";
    else
        cout<<"FALSE";
}