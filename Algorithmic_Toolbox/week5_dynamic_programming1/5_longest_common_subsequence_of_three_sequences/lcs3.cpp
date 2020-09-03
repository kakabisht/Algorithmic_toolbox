#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a1, vector<int> &b1, vector<int> &c1) {
  int a= a1.size(); int b= b1.size(); int c= c1.size();
vector<vector<vector<int>>> Longest(a + 1,vector<vector<int>>(b + 1,vector<int>(c + 1)));

	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (i == 0 || j == 0 || k == 0) {
					Longest[i][j][k] = 0;
					continue;
				}
				else if (a1[i - 1] == b1[j - 1] && a1[i - 1] == c1[k - 1]) {
					Longest[i][j][k] = Longest[i - 1][j - 1][k - 1] + 1;
					continue;
				}
				else {
					Longest[i][j][k] =
						std::max( std::max(Longest[i - 1][j][k], Longest[i][j - 1][k]),
							Longest[i][j][k - 1]);
				}
			}

		}
	}
	return Longest[a][b][c];  
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
