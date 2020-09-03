#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numrefills=0;
    int currentrefill=0;
        
    while (currentrefill<=stops.size())
    {
        int lastrefil=currentrefill;
        while ((stops[currentrefill+1] -stops[lastrefil] <= tank) && (currentrefill != stops.size()-1) ){
            currentrefill+=1;
            cout<<stops[currentrefill];
        }
        if (currentrefill==lastrefil) 
            return -1;
        if (currentrefill<=tank) 
        {
            numrefills++;
            return numrefills;
        }
            
    }
}


int main() 
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
