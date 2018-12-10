#include <bits/stdc++.h>

#define SIZE_NB_NOEUDS 13
#define SIZE_PRECEDENCES 12

using namespace std;

int main()
{
    freopen("data.txt","r",stdin);
    freopen("data.txt","a",stdout);
    cin.ignore(SIZE_NB_NOEUDS,' ');

    int n;
    cin>>n;

    cin.ignore(SIZE_PRECEDENCES,' ');

    vector<pair<int, unordered_set<int> > > V_1(n+1);
    vector<pair<int, unordered_set<int> > > V_2(n+1);

    int x,y;
    while(cin>>x>>y){
        V_1[y].second.insert(x);
    }

    for(int i=1;i<n+1;i++){
        V_1[i].first=V_1[i].second.size();
        for(auto a:V_1[i].second ){
            V_2[i].second.insert(a);
            for(auto b:V_1[a].second){
                V_2[i].second.insert(b);
            }
        }
    }

    for(int i=1;i<n+1;i++){
        V_2[i].first=V_2[i].second.size();
    }

    cout<<"rangs\n";
    vector< set<int> > rangs(n);

    bool visit[n+1];

    for(int i=1;i<n+1;i++){
        visit[i]=false;
    }


    for(int i=1;i<n+1;i++){
        if(!V_2[i].first){
            rangs[0].insert(i);
            visit[i]=true;
        }
    }

    int j=0;

    while(j<n){
        for(int i=1;i<n+1;i++){
            if(visit[i]==false){
                for(auto u: V_1[i].second){
                    for(auto v: rangs[j]){
                        if(u==v){
                            rangs[j+1].insert(i);
                            visit[i]=true;
                            break;
                        }
                    }
                }
            }
        }
        j++;
    }

    for(int i=0;i<n+1;i++){
        if(rangs[i].size()){
            for(auto u: rangs[i]){
                cout<<u<<" ";
            }
            cout<<"\n";
        }
        else break;
    }
    return 0;
}
