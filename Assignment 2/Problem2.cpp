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

using namespace std;

int Compute(int w, int h, string bad)
{
	vector<vector<int>> dp(h+1, vector<int>(w+1, 0));
	vector<vector<int>> road(h+1, vector<int>(w+1, 0));
	vector<int> cross(4,0);
	int i=1, j=0, num;
	while ( i!=bad.size())
	{
		if ( bad[i]==',')
		{
			cross[j] = num;
			num = 0;
			j = 0;
			
			if(cross[1] == cross[3])
			{	
				if(road[cross[1]][max(cross[0], cross[2])] == 0) 
					road[cross[1]][max(cross[0], cross[2])] = 1;
				else
					road[cross[1]][max(cross[0], cross[2])] = 3;	
			}
			else
			{
				if(road[max(cross[1], cross[3])][cross[0]] == 0) 
					road[max(cross[1], cross[3])][cross[0]] = 2;
				else
					road[max(cross[1], cross[3])][cross[0]] = 3;
			}
		}
		else if ( bad[i] == ' ') 
			cross[j++]=num,num = 0;
		else if (bad[i] == '\"');
		else
		{
			num *= 10;
			num += (bad[i]-'0');
		}
		i++;
	}
	
	dp[0][0]=1;
	for ( int i=0; i<=h; i++ )
	{
		for( int j=0; j<=w; j++ )
		{	
			if ( i==0 || j==0 )
			{
				
				if(i == 0 && j == 0) 
					continue;
				if(road[i][j] != 0) 
					dp[i][j] = 0;
				else 
					dp[i][j] = (i == 0)?dp[0][j-1]:dp[i-1][0];	
			}
			else
			{
				
				if(road[i][j] == 0) 
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				else if(road[i][j] == 1) 
					dp[i][j] = dp[i-1][j];
				else if(road[i][j] == 2) 
					dp[i][j] = dp[i][j-1];
			}
		}
	}
	return dp[h][w];
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0)
	int w,h;
	string bad;
	cin>>w>>h;
	cin.ignore();
	getline(cin, bad);
	bad[bad.size()-1] = ',';
	int ans = Compute( w, h, bad );
	cout<<ans<<endl;
	return 0;
}
