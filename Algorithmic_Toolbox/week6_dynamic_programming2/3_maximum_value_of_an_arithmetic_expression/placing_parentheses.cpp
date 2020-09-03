#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring> 
#include<climits>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  	int Len = exp.size();
	int NumOfOperands = (Len + 1) / 2;

	long long Mini[NumOfOperands][NumOfOperands];
	long long Maxi[NumOfOperands][NumOfOperands];

	memset(Mini, 0, sizeof(Mini)); // initialize to 0
	memset(Maxi, 0, sizeof(Maxi)); // initialize to 0
	for (int i = 0; i < NumOfOperands; i++) {

		Mini[i][i] = std::stoll (exp.substr(2 * i, 1));
		Maxi[i][i] = std::stoll(exp.substr(2 * i, 1));
	}

	for (int s = 0; s < NumOfOperands - 1; s++) {
		for (int i = 0; i < NumOfOperands - s - 1; i++) {
			int j = i + s + 1;
			long long MinValue = LLONG_MAX;
			long long MaxValue = LLONG_MIN;

			for (int k = i; k < j; k++) {
				long long a = eval(Mini[i][k], Mini[k + 1][j], exp[2 * k + 1]);
				long long b = eval(Mini[i][k], Maxi[k + 1][j], exp[2 * k + 1]);
				long long c = eval(Maxi[i][k], Mini[k + 1][j], exp[2 * k + 1]);
				long long d = eval(Maxi[i][k], Maxi[k + 1][j], exp[2 * k + 1]);

				MinValue = min(MinValue, min(a, min(b, min(c, d))));
				MaxValue = max(MaxValue, max(a, max(b, max(c, d))));

			}
			Mini[i][j] = MinValue;
			Maxi[i][j] = MaxValue;
		}
	}

	return Maxi[0][NumOfOperands - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
