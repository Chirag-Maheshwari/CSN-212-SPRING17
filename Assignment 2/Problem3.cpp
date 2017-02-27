#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int n;
int comp( int index, int arr[] )
{
    int ans=1;
    vector<int>v;
    vector<int>::iterator temp;
    v.push_back(arr[index]);
    for ( int i=index+1; i<index+n; i++ )
    {
        if ( arr[i]<v[0] )
            v[0]=arr[index];
        else if ( arr[i]>v[v.size()-1] )
        {
            ans++;
            v.push_back(arr[i]);
        }
        else
        {
            temp=upper_bound( v.begin(), v.end(), arr[i] );
            *temp=arr[i];
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while( t-- )
    {
        cin>>n;
        int arr[2*n];
        int lcs=0;
        vector<pair<int,int> >v(n);
        for ( int i=0; i<n; i++ )
        {
            cin>>arr[i];
            arr[i+n]=arr[i];
            v[i].first=arr[i];
            v[i].second=i;
        }
        sort( v.begin(), v.end() );
        for ( int i=0; i<min(37,n); i++ )
        {
            lcs=max( lcs, comp(v[i].second, arr) );
        }
        cout<<lcs<<endl;
    }
    return 0;
}