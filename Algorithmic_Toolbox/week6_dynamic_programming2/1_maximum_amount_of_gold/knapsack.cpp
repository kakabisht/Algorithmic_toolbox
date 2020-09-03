#include <iostream>
#include <vector>
#include <algorithm>

using std::max;


using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  
  int n= w.size();
  vector<vector<int>>  K(n + 1,vector<int>(W + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0)
				K[i][j] = 0;
			else if (w[i - 1] <= j)
				K[i][j] = max(w[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
			else
				K[i][j] = K[i - 1][j];
		}
	}

	return K[n][W];

  
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  sort(w.begin(), w.end(), std::greater<int>()); 
  std::cout << optimal_weight(W, w) << '\n';
}
