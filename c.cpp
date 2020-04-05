#include <iostream>
#include <vector>
using namespace std;

struct Task{
    int s, e;
};

bool comp(Task t1, Task t2)
{
    return t1.s <= t2.s;
}

vector<int> fill_mins(vector<int>vec, Task t)
{
    for(int i = t.s; i <= t.e; i++)
        vec[i] = 1;
    return vec;
}
int main()
{
    freopen("cin.txt", "r", stdin);
    int n, a, b, c, ca=1;
    cin>>n;
    while(n--)
    {
        vector<Task>tasks;
        cin>>c;
        while(c--)
        {
            Task t;
            cin>>t.s>>t.e;
            tasks.push_back(t);
        }
        // sort(tasks.begin(), tasks.end(), comp);
        vector<int>solved(tasks.size(), 0);
        vector<int>mins1(24*60, 0);
        vector<int>mins2(24*60, 0);

        int p = 1;
        bool flag;        
        for(int i = 0; i < tasks.size(); i++)
        {       
            flag = true;     
            for(int j = tasks[i].s; j <= tasks[i].e; j++)
            {
                if(mins1[j] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(int j = tasks[i].s; j < tasks[i].e; j++)
                    mins1[j] = 1;
                solved[i] = 1;

            }
        }
        for(int i = 0; i < tasks.size(); i++)
        {  
            if(solved[i]==1)
                continue;     
            flag = true;     
            for(int j = tasks[i].s; j <= tasks[i].e; j++)
            {
                if(mins2[j] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(int j = tasks[i].s; j < tasks[i].e; j++)
                    mins2[j] = 1;
                solved[i] = 2;

            }
        }
        flag = true;
        for(int i = 0; i < tasks.size(); i++)
            if(solved[i] == 0)
                flag = false;
        
        printf("Case #%d: ", ca);
        ca += 1;

        if(flag)
        {
            for(int i = 0; i < tasks.size(); i++)
                cout << ((solved[i] == 1) ? 'C' : 'J');   
        }
        else
        {
            cout<<"IMPOSSIBLE";
        }      
        cout<<endl;
        
    }
    return 0;
}