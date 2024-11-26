#include<iostream>
#include<string>
#include<vector>
using namespace std;
class stack
{
private:
	vector<int> n;
public:
	stack() {};
	void push(int p) {
		n.push_back(p);

	}
	void pop() {
		n.pop_back();
	}
	void out(){
		cout << *(n.end() - 1) << " ";
	}
};
int main() {
	vector<int> a;
	int b;
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> b;
		a.push_back(b);
		for (it = a.begin();it != a.end()-1;it++)
		{
			if (*it <= a.end() - 1)
			{
				a.remove(*it);
			}
		}
		cout << a.size() << endl;
	}
	
}