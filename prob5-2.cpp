#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> a;
	int b;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> b;
		a.push_back(b);
		while (a.size() > 1 && a[a.size() - 2] <= b)
		{
			a.pop_back();
		}
			
		cout << a.size()<<endl;
		
	}

}