#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main ()
{
	int n;
	cin >>n;
	struct people{
		int tim;
		int index;
	};
	vector<people> pp;
	for (int i=0;i<n;i++){
		int x;
		cin >>x;
		pp.push_back({x,i+1});
	}
	sort(pp.begin(),pp.end(),[](struct people a,struct people b){
		if (a.tim!=b.tim)
			return a.tim<b.tim;
		return a.index<b.index;
	});
	
	double avertime = 0.00;
	for (int i = 1;i<n;i++){
		for (int j = 0;j<i;j++){
			avertime+=(double)pp[j].tim;
		}
	}
	avertime /= (double)n;
	for (int i = 0;i<n;i++){
		if (i!=n-1)
			cout <<pp[i].index <<" ";
		else cout <<pp[i].index <<endl;
	}
	cout <<fixed <<setprecision(2) <<avertime;
	return 0;
}
