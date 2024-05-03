/*
You are given n activities with their start and finish times, input through
keyboard. Write a program to select all possible maximum number of activities that
can be performed by a single person including one activity of his/her choice,
assuming that a person can only work on a single activity at a time.
Exact Input/Output Sample-1
Enter maximum number of activities: 11
Enter the name of activities with their start and finish time:
(p, 3, 5) (q, 0, 6) (r, 3, 9) (s, 5, 9) (t, 6, 10) (u, 8, 11)
(v, 2, 14) (w, 12, 16) (x, 5, 7) (y, 8, 12) (z, 1, 4)

Enter the name of activity of person’s choice: y
Maximum number of activity selected = 4
Selected Activity Set (s): {p, x, y w} or {z, x, y w}
Explanation
The activities sorted in ascending order with their finish time.
Activities
(z, 1,4)
(p, 3, 5)
(q, 0, 6)
(x, 5, 7)
(r, 3, 9)
(s, 5, 9)
(t, 6, 10)
(u, 8, 11)
(y, 8, 12)
(v, 2, 14)
(w, 12, 16)

If user choice is t, the output will be
Maximum number of activity selected = 3
Selected Activity Set(s): {q, t, w} or {p, t, w} or {z, t, w}

If user choice is v, the output will be

Maximum number of activity selected = 1
Selected Activity Set(s): {v}
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n;
    cout<<"Enter maximum number of activities: ";
    cin>>n;
    cout<<"Enter the name of activities with their start and finish time: "<<endl;
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++)
    {
        char ch;
        int s,f;
        cin>>ch>>s>>f;
        v.push_back({f,{s,ch}});
    }
    sort(v.begin(),v.end());
    cout<<"   "<<endl;
    cout<<"Enter the name of activity of person's choice: ";
    char ch;
    cin>>ch;
    int i=0;
    while(v[i].second.second!=ch)
    {
        i++;
    }
    int j=i+1;
    int count=1;
    cout<<"Maximum number of activity selected = "<<count<<endl;
    cout<<"Selected Activity Set(s): {";
    cout<<v[i].second.second;
    while(j<n)
    {
        if(v[j].second.first>=v[i].first)
        {
            cout<<", "<<v[j].second.second;
            i=j;
            count++;
        }
        j++;
    }
    cout<<"}"<<endl;
    cout<<"Explanation"<<endl;
    cout<<"The activities sorted in ascending order with their finish time."<<endl;
    cout<<"Activities"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"("<<v[i].second.second<<", "<<v[i].second.first<<", "<<v[i].first<<")"<<endl;
    }

    
    return 0;
}