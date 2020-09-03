#include <iostream>
#include <vector>

using std::vector;


long long get_inversions(vector<int> &a, vector<int> &b, size_t left, int ave, size_t right) {
    size_t i = left, j = ave, k = left;
    long long inv_count = 0;
    while (i <= ave - 1 && j <= right) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            inv_count += ave - i;
            j++;
        }
        k++;
    }
    while (i <= ave - 1) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= right) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++) {
        a[i] = b[i];
    }
    return inv_count;
}



long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  number_of_inversions += get_inversions(a, b, left, ave + 1, right);

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
