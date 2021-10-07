#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<pair<int, int>> q;
    int cnt_added = 0;
    int cnt_removed = 0;

    int new_elem;

    //finding the minimum
    int minimum = q.front().first;

    // adding an element
    while (!q.empty() && q.back().first > new_elem)
    {
        q.pop_back();
    }

    q.push_back({new_elem, cnt_added});
    cnt_added++;

    //removed an element
    if (!q.empty() && q.front().second == cnt_removed)
    {
        q.pop_front();
    }
    cnt_removed++;
}