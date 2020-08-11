#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int discs,total_steps,temp,Total_Moves=0;;
    float condition;
    char source,dest;

    cout<<"Enter number of discs = ";
    cin>>discs;

    int arr[discs],multiple[discs];
    for(int i=0;i<discs;i++)
    {
        arr[i]=1;
        multiple[i]=0;
    }

   if(discs%2==0)  //temp=0 for starting from A to B
   {temp=0;}
   else
   {temp=1;}    //temp=1 for starting from A to C

//////////////////////////////////////////////
    total_steps=pow(2,discs)-1;

    for(int i=1;i<=total_steps;i++)
    {
        for(int x=0;x<discs;x++)
        {
            condition=pow(2,x)+multiple[x]*pow(2,x+1);

            if(i==condition)
            {
                multiple[x]++;

                if(x%2==temp && x+1!=temp)
                {
                    if(arr[x]==1)
                    {
                        source='A';     dest='B';
                        arr[x]=2;
                    }
                    else if(arr[x]==2)
                    {
                        source='B';     dest='C';
                        arr[x]=3;
                    }
                    else if(arr[x]==3)
                    {
                        source='C';     dest='A';
                        arr[x]=1;
                    }
                }
                else
                {
                    if(arr[x]==1)
                    {
                        source='A';     dest='C';
                        arr[x]=2;
                    }
                    else if(arr[x]==2)
                    {
                        source='C';     dest='B';
                        arr[x]=3;
                    }
                    else if(arr[x]==3)
                    {
                        source='B';     dest='A';
                        arr[x]=1;
                    }
                }

                cout<<"Move disc "<<x+1<<" from "<<source<<" to "<<dest<<endl;      Total_Moves++;
                continue;
            }
        }

    }
    cout<<endl<<"Total number of moves are : "<<Total_Moves<<endl;

    return 0;
}
