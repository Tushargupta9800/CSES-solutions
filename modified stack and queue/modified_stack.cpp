#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<pair<int, int>> min_st;
    stack<pair<int, int>> max_st;

    //adding a element in min stack
    int new_elem; // this is the element to be added
    int min_elem = min_st.empty() ? new_elem : min(new_elem, min_st.top().second);
    min_st.push({new_elem, min_elem});

    //removing element from min_st

    int removed_elem = min_st.top().first;
    min_st.pop();

    // minimum element
    int minimum = min_st.top().second;

    //adding element in max stack
    int max_elem = max_st.empty() ? new_elem : max(new_elem, max_st.top().second);
    max_st.push({new_elem, max_elem});

    //removing element
    removed_elem = max_st.top().first;

    //maximum element
    int maximum = max_st.top().second;
}