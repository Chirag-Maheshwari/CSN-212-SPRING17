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

bool checkOpp( int a, int b )
{
	return ( a>0 && b<0 ) || ( a<0 && b>0 );
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for ( int i=0; i<n; i++ )
	{
		cin>>arr[i];
	}
	int dp[n][2];
	for ( int i=0; i<n; i++ )
	{
		dp[i][0]=1;
	}
	for ( int i=1; i<n; i++ )
	{
		for ( int j=0; j<i; j++ )
		{
			int diff=arr[i]-arr[j];
			if ( dp[j][1]==0 )
			{	
				dp[i][0]+=1;
				dp[i][1]=diff;
			}
			else
			{
				if ( checkOpp( dp[j][1], diff ) && dp[j][0]+1>dp[i][0] )	
				{
					dp[i][0]=dp[j][0]+1;
					dp[i][1]=diff;
				}
			}
		}
	}
	cout<<dp[n-1][0]<<endl;
	return 0;
}