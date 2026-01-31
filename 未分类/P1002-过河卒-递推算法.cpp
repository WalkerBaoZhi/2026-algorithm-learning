#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int m,n;
	cin >> m >> n;
	vector<vector<int>> mat(m,vector<int>(n,0));//走到mat[i][j]的总方法数
	vector<vector<int>> mat0(m,vector<int>(n,1));//判断,mat[i][j]能不能走
	int x,y;
	cin >>x >>y;
	mat0[x][y] = 0;
	if (x-2>=0&&y+1<=m) mat0[x-2][y+1] = 0;
	if (x-1>=0&&y+2<=m) mat0[x-1][y+2] = 0;
	if (x+1<=n&&y+2<=m) mat0[x+1][y+2] = 0;
	if (x+2<=n&&y+1<=m) mat0[x+2][y+1] = 0;
	if (x+2<=n&&y-1>=0) mat0[x+2][y-1] = 0;
	if (x+1<=n&&y-2>=0) mat0[x+1][y-2] = 0;
	if (x-1>=0&&y-2>=0) mat0[x-1][y-2] = 0;
	if (x-2>=0&&y-1>=0) mat0[x-2][y-1] = 0;
	
	for (int i = 0;i<m;i++){
		for (int j = 0;j<n;j++){
			if ((i==0||j==0)&&mat0[i][j]!=0){
				mat[i][j] = 1;
				continue;
			}
			if (mat0[i][j] == 0){
				mat[i][j] = 0;
				continue;
			}
			mat[i][j] = mat[i-1][j]+mat[i][j-1];
		}
	}
	cout <<mat[m][n];
	return 0;
}
