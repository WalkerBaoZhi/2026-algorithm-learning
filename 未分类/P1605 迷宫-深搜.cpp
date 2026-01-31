#include <iostream>
#include <vector>
using namespace std;

int m,n,t,sum = 0;
int sx,sy,fx,fy;

void dfs(int x,int y,vector<vector<int>> &a,vector<vector<char>> &rec){
	rec[x][y]='1';
	if (x == fx&&y == fy){
		sum++;
		dfs(sx,sy,a,rec);
	}
	
	if (rec[x+1][y]=='0'&&x+1<=n) dfs(x+1,y,a,rec);
	if (rec[x][y+1]=='0'&&y+1<=m) dfs(x,y+1,a,rec);
	if (rec[x-1][y]=='0'&&x-1>=1) dfs(x-1,y,a,rec);
	if (rec[x][y-1]=='0'&&y-1>=1) dfs(x,y-1,a,rec);
	
}
int main ()
{
	cin >>m >>n >>t;
	vector<vector<int>> a(m+1,vector<int>(n+1,0));
	vector<vector<char>> rec(m+1,vector<char>(n+1,'0'));
	cin >>sx >>sy >>fx >>fy;
	while (t--){
		int x,y;
		cin >>x >>y;
		rec[x][y] = '1';
	}
	dfs(sx,sy,a,rec);
	cout <<sum;
	return 0;
}
