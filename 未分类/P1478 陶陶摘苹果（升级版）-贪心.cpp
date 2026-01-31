#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int n,s,a,b;
	cin >>n >>s >>a >>b;
	struct apple{
		int height;
		int strength;
	};
	vector<apple> app;
	for (int i = 0;i<n;i++){
		int x,y;
		cin >>x >>y;
		if (a+b>=x)
			app.push_back({x,y});
	}
	sort(app.begin(),app.end(),[](apple x,apple y){
		return x.strength<y.strength;
	});
	int sum = 0,i = 0;
	while (s>0&&i<=(int)app.size()-1){
		if (s-app[i].strength<0)
			break;
		s-=app[i].strength;
		i++;
		sum++;
	}
	cout <<sum;
	return 0;
}
