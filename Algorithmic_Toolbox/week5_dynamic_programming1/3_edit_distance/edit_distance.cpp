#include <iostream>
#include <string>
#include <vector>


using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int m=str1.size();
  int n=str2.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j;

			else if (j == 0)
				dp[i][j] = i;

			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
		}
	}

	return dp[m][n];  return 0;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}



