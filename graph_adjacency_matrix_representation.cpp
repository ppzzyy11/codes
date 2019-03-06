//Graph Adjacency Representation
//就进行了2次测试, 可以对断点进行处理
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Graph{
    private:
        vector<vector<int>> g;
    public:
        Graph(int n)
        {
            g.resize(n,vector<int>(n,0));
        }
        Graph(vector<vector<int>> &nums)
        {
            g=nums;
        }
        bool editEdge(int s,int e,int val)
        {
            if(s<0||s>=g.size()) return 0;
            if(e<0||e>=g.size()) return 0;

            g[s][e]=val;
            return 1;
        }
        void BFS()
        {
            vector<bool> visited(g.size(),0);
            int cnt=0;
            for(int i=0;i<g.size();i++)
            {
                if(visited[i]==0)
                {
                    cout<<i<<" ";
                    visited[i]=1;
                    cnt++;
                }
                for(int j=0;j<g[i].size();j++)
                {
                    if(g[i][j]!=0&&visited[j]==0)
                    {
                        visited[j]=1;
                        cout<<j<<" ";
                        cnt++;
                    }
                }
                if(cnt==g.size()) return;
            }
        }
        void DFS()
        {
            int cnt=0;
            int i=0;
            vector<bool> visited(g.size(),0);
            stack<int> st;
            for(int i=g.size()-1;i>=0;i--)
                st.push(i);
            while(cnt<g.size())
            {
                i=st.top();
                st.pop();
                if(visited[i]==0)
                {
                    cout<<i<<" ";
                    visited[i]=1;
                    for(int j=g.size()-1;j>=0;j--)
                    {
                        if(g[i][j]!=0&&visited[j]==0)
                        {
                            st.push(j);
                        }
                    }
                    cnt++;
                    if(cnt==g.size()) return ;
                }
            }
        }

};
int main()
{
    vector<vector<int>> nums=
    {
        {0,1,0,0,2},
        {1,0,3,0,4},
        {0,1,0,0,0},
        {0,0,0,0,0},
        {1,1,0,0,0}
    };

    Graph gh(nums);
    gh.BFS();
    cout<<endl;
    gh.DFS();
    return 0;
}
