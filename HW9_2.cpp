#include<iostream>

using namespace std;

int main()
{
    int t=0;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        int n=0;
        cin>>n;
        int brick[n]={0};
        int h=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>brick[i];
            sum+=brick[i];
        }
        h=sum/n;
        //test
        /*cout<<h<<endl;*/
        //test end

        int steps=0;
        /*while(1)
        {
            int max_index;
            int maximum=-100000;
            int min_index;
            int minimum=100000;
            for(int i=0;i<n;i++)
            {
                if(brick[i])
            }
        }*/

        for(int i=0;i<n;i++)
        {
            if(brick[i]>h)
                steps+=brick[i]-h;
        }

        if(q!=0) cout<<endl;
        cout<<steps;

    }
}
