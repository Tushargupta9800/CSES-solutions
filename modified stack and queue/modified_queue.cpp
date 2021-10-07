#include <bits/stdc++.h>
using namespace std;
int main()
{
    //this modified DS technique will not store all your elements it will only store
    //the minimum elements so that you can access the minimum elements as fast as possible in that sub array
    deque<int> q;

    //adding element in the deque
    int new_elem;
    while (!q.empty() && q.back() > new_elem)
    {
        q.pop_back();
    }

    q.push_back(new_elem);

    //finding minimum
    int minimum = q.front();

    //removing the element
    int removed_element;
    if (!q.empty() && q.front() == removed_element)
    {
        q.pop_front();
    }
}