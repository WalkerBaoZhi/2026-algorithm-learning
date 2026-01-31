#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main ()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	vector<int> a,b,c,d;
	
	
	//高精度加法
	const int len1 = s1.length();
	const int len2 = s2.length();
	int i;
	for (i = 0;i<len1;i++)
		a.push_back(s1[len1-i-1]-'0');
	for (i = 0;i<len2;i++)
		b.push_back(s2[len2-i-1]-'0');
	int len3 = max(len1,len2);
	if (len1>len2)
		for(i = len3-len2;i>0;i--)
			b.push_back(0);
	else if (len1<len2)
		for(i = len3-len1;i>0;i--)
			a.push_back(0);
	for (i = 0;i<len3;i++)
		c.push_back(a[i]+b[i]);
	for (i = 0;i<len3;i++){
		if (c[i]>=10){
			c[i+1] += (c[i]/10);
			c[i] = c[i]%10;
		}
	}
	cout <<s1<<"+"<<s2<<"=";
	if (len3!=c.size())
		for (i = len3;i>=0;i--)
			cout <<c[i];
	else
		for (i = len3-1;i>=0;i--)
			cout <<c[i];
	cout <<endl;
	
	
	//高精度减法
	
	//判断需不需要调换数字顺序以保证大的减小的,单独写高精度减法要写这一部分！
		bool is_swich = 0;
		if (s1.length()<s2.length()||(s1.length()==s2.length()&&s1<s2)){
	//		swap(s1,s2);  单独写减法的时候要交换
			is_swich = 1;
		}
	
	if (!is_swich){
		for (i = 0;i<len3;i++)
			d.push_back(a[i]-b[i]);
	}
	else{
		for (i = 0;i<len3;i++)
			d.push_back(b[i]-a[i]);
	}
	for (i = 0;i<len3;i++){
		if (d[i]<0){
			d[i+1]--;
			d[i]+=10;
		}
	}
	cout <<s1 <<"-" <<s2 <<"=";
	if (a == b){
		cout <<"0";
		return 0;
	}
	if (d[len3-1]!=0){
		if (is_swich)
			cout <<"-";
		bool find_none_zero = 0;
		for (i = len3-1;i>=0;i--){
			
			if (d[i]==0&&find_none_zero == 0)
				continue;
			if (d[i]!=0)
				find_none_zero = 1;
			if (find_none_zero)
				cout <<d[i];
		}
	}
	else{
		if (is_swich)
			cout <<"-";
		bool find_none_zero = 0;
		for (i = len3-1;i>=0;i--){
			
			if (d[i]==0&&find_none_zero == 0)
				continue;
			if (d[i]!=0)
				find_none_zero = 1;
			if (find_none_zero)
				cout <<d[i];
		}
			
	}
	return 0;
}
