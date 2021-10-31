class Solution {
    
int my_solve(vector<int> &vec)
{
    int n = vec.size();
    
    stack<int> stk;
    stk.push(-1);
    
    int ret = 0;
    
    for(int i=0; i<n; i++)
    {
        while(stk.top()!=-1 && vec[stk.top()]>vec[i])
        {
            int tp = stk.top();
            stk.pop();
            int h = vec[tp];
            int w = i-stk.top()-1;
            ret = max(ret, h*w);
        }
        stk.push(i);
    }
    
    while(stk.top()!=-1)
    {
        int tp = stk.top();
        stk.pop();
        int h = vec[tp];
        int w = n-stk.top()-1;
        ret = max(ret, h*w);
    }
    return ret;
}
    
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size();
        
        if(n==0)
            return 0;
        
        int m = mat[0].size();
        
        vector<int> vec(m, 0);
        
        int ret = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]=='1')
                    vec[j]+=1;
                else
                    vec[j] = 0;
            }
            ret = max(ret, my_solve(vec));
        }
        return ret;
    }
};