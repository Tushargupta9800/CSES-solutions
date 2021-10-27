class Solution
{
public:
    int largestRectangleArea(vector<int> &vec)
    {

        int n = vec.size();

        stack<int> stk;
        stk.push(-1);

        int ret = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            while (stk.top() != -1 && vec[stk.top()] > vec[i])
            {
                int tp = stk.top();
                stk.pop();

                int h = vec[tp];
                int w = i - stk.top() - 1;
                int a = h * w;

                ret = max(ret, a);
            }
            stk.push(i);
        }

        while (stk.top() != -1)
        {
            int tp = stk.top();
            stk.pop();

            int h = vec[tp];
            int w = n - stk.top() - 1;
            int a = h * w;

            ret = max(ret, a);
        }

        return ret;
    }
};