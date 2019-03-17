#include <iostream>
#include <vector>
#include <string>
#include<sstream>
#include<cctype>
#include<algorithm>

using namespace std;

vector<int> out;
void split(string s, string c, vector<string> &res) {
	int pos1, pos2;
	pos1 = 0;
	pos2 = s.find(c, 0);
	while (pos2 != string::npos) {
		res.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.size())
	{
		res.push_back(s.substr(pos1));
	}
}
int toi(const string &str)
{
	int ans;
	stringstream ss(str);
	ss >> ans;
	return ans;
}
void prin()
{
	int i;
	for (i = 0; i < out.size(); i++)
	{
		printf("%d ", out[i]);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	char s[1000];

	string str;

	scanf("%s", s);
	str.assign(s);
	printf("%s ", str.c_str());
	cout << endl;
	vector<string> res1;
	split(s, ",", res1);
	for (int i = 0; i < res1.size(); i++)
	{
		printf("%s ", res1[i].c_str());
		cout << endl;
		int l, r;
		vector<string> res2;
		split(res1[i], "-", res2);
		if (res2.size() == 1)
		{
			l = toi(res2[0]);
			r = toi(res2[0]);
		}
		else
		{
			l = toi(res2[0]);
			r = toi(res2[1]);
		}
		printf("*%d %d* ", l,r);
		cout << endl;
		for (int j = l; j <= r; j++)
		{
			out.push_back(j);
		}
			
	}
	prin();

	return 1;

}