#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // freopen("bin.txt", "r", stdin);
    int ca=1,n;
    string s;
    cin>>n;
    while(n--)
    {        
        vector<string> vs;
        vector<int>vi;
        cin>>s;
        char prev = s[0];
        string grp;
        grp += s[0];
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] != prev)
            {
                vs.push_back(grp);
                vi.push_back(grp[0]-'0');
                grp = s[i];
            }                
            else
            {
                grp += s[i];
            }
            prev = s[i];
        }
        vs.push_back(grp);
        vi.push_back(grp[0]-'0');

        while (true)
        {
            int maxv = *max_element(vi.begin(), vi.end());
            if (maxv == 0)
                break;
            for(int i = 0; i < vi.size(); i++)
            {
                if(vi[i] == maxv)
                {
                    vi[i] -= 1;
                    vs[i] = "("+vs[i]+")";                    
                }
            }

            int pi = vi[0];
            grp = vs[0];
            vector<string>vstmp;
            vector<int>vitmp;
            vitmp.push_back(pi);
            for(int i = 1; i < vi.size(); i++)
            {
                if(vi[i]==pi)
                {
                    grp += vs[i];
                }
                else
                {
                    vstmp.push_back(grp);
                    grp = vs[i];
                    vitmp.push_back(vi[i]);
                }                
                pi = vi[i];
            }
            vstmp.push_back(grp);

            vi = vitmp;
            vs = vstmp;

           


        }

        printf("Case #%d: ", ca);
        ca += 1;
        for(int i = 0; i < vs.size(); i++)
            cout<<vs[i];
        cout<<endl;
        
        
    }
    return 0;
}