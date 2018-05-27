#include<iostream>

using namespace std;

int main()
{
    int targetStage;
    int next[11]={0};
    int w[11][11];
    for(int i=0;i<11;i++)
        for(int j=0;j<11;j++)
            w[i][j]=0;
    //input
    for(int i=0;i<=0;i++)
    {
        for(int j=1;j<=3;j++)
        {
            int temp=0;
            cin>>temp;
            w[i][j]=temp;
            w[j][i]=temp;
        }
    }

    for(int i=1;i<=3;i++)
    {
        for(int j=4;j<=6;j++)
        {
            int temp=0;
            cin>>temp;
            w[i][j]=temp;
            w[j][i]=temp;
        }
    }

    for(int i=4;i<=6;i++)
    {
        for(int j=7;j<=9;j++)
        {
            int temp=0;
            cin>>temp;
            w[i][j]=temp;
            w[j][i]=temp;
        }
    }
    for(int i=7;i<=9;i++)
    {
        int j=10;
        int temp=0;
        cin>>temp;
        w[i][j]=temp;
        w[j][i]=temp;
    }

    cin>>targetStage;
    //input end

    //input test
    /*for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
            cout<<w[i][j];
        cout<<endl;
    }*/
    //input test end


    //stage 2
    int f_stage2[3]={0};
    for(int i=1;i<=3;i++)
    {
        f_stage2[i-1]=min(w[i][4], min(w[i][5], w[i][6]))+w[0][i];
    }

    //test stage 2
    /*for(int i=0;i<3;i++) cout<<f_stage2[i]<<" ";*/
    //test stage 2 end


    //stage 3
    int f_stage3[3]={0};
    int g_stage3[3];
    for(int i=0;i<3;i++) g_stage3[i]=100000;
    for(int i=1;i<=3;i++)
    {
        for(int j=4;j<=6;j++)
        {
            g_stage3[j-4]=min(g_stage3[j-4], w[0][i]+w[i][j]);
        }
    }

    for(int i=4;i<=6;i++)
    {
        f_stage3[i-4]=min(w[i][7], min(w[i][8], w[i][9]))+g_stage3[i-4];
    }

    //test stage 3
    /*for(int i=0;i<3;i++) cout<<f_stage3[i]<<" ";*/
    //test stage 3 end


    //stage 4
    int f_stage4[3]={0};
    int g_stage4[3];
    for(int i=0;i<3;i++) g_stage4[i]=100000;

    for(int i=1;i<=3;i++)
        for(int j=4;j<=6;j++)
            for(int k=7;k<=9;k++)
            {
                g_stage4[k-7]=min(g_stage4[k-7], w[0][i]+w[i][j]+w[j][k]);
            }

    for(int i=7;i<=9;i++)
    {
        f_stage4[i-7]=g_stage4[i-7]+w[i][10];
    }

    //test stage 4
    /*for(int i=0;i<3;i++) cout<<f_stage4[i]<<" ";*/
    //test stage 4 end


    //output
    if(targetStage==2)
    {
        int output=100000;
        for(int i=0;i<3;i++)
        {
            output=min(output, f_stage2[i]);
        }
        cout<<output;
    }
    else if(targetStage==3)
    {
        int output=100000;
        for(int i=0;i<3;i++)
        {
            output=min(output, f_stage3[i]);
        }
        cout<<output;
    }
    else if(targetStage==4)
    {
        int output=100000;
        for(int i=0;i<3;i++)
        {
            output=min(output, f_stage4[i]);
        }
        cout<<output;
    }

    //output end

}
