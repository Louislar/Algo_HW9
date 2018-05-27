#include<iostream>

using namespace std;

int main()
{
    int t=0;

    while(1)
    {
        cin>>t;
        if(t==0) break;

        int maximum[t];
        for(int i=0;i<t;i++) maximum[i]=-100000;

        for(int q=0;q<t;q++)
        {
            int w=0;
            int h=0;
            cin>>w>>h;

            if(h>=w/4)
            {
                maximum[q]=max(maximum[q], w/4);
            }
            if(w>=h*4)
            {
                maximum[q]=max(maximum[q], h);
            }
            if(w>=h/4)
            {
                maximum[q]=max(maximum[q], h/4);
            }
            if(h>=w*4)
            {
                maximum[q]=max(maximum[q], w);
            }
            if(h>=w/2*2)
            {
                maximum[q]=max(maximum[q], w/2);
            }
            if(w>=h/2*2)
            {
                maximum[q]=max(maximum[q], h/2);
            }
        }// for q end

        int max_index=-1;
        int m=-100000;
        for(int i=0;i<t;i++)
            if(maximum[i]>m)
            {
                m=maximum[i];
                max_index=i;
            }

        cout<<max_index+1<<endl;
    }


}
