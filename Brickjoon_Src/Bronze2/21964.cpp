#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	string s1;
	int n;
	cin >> n >> s1;
	for(int i = n-5; i < n; i++)
	{
		cout << s1[i];
	}
}

// solve

/* code golf
#include <iostream>
using namespace std;
int main(){string s;int n;cin>>n>>s;for(int i=n-5;i<n;i++)cout<<s[i];}
*/