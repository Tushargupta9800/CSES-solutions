// store all the element
// remove an element from front without knowing the value
// minimum in O(1)
// using stack
// we can perform all the operations in O(1)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<pair<int, int>> s1, s2;

    int new_elem;
    //adding the element in queue
    int minimum = s1.empty() ? new_elem : min(new_elem, s1.top().second);
    s1.push({new_elem, minimum});

    //removing an element
    if (s2.empty())
    {
        while (!s1.empty())
        {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, minimum});
        }
    }
    int removed_elem = s2.top().first;
    s2.pop();

    //finding the minimum
    if (s1.empty() || s2.empty())
    {
        minimum = s1.empty() ? s2.top().second : s1.top().second;
    }
    else
    {
        minimum = min(s1.top().second, s2.top().second);
    }
}
