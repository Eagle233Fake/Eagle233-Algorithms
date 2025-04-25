#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define MAX_N 100006
int n;
map<int, int> distanceMap;
map<int, int>::iterator lowerIt, prevIt;

int main() {
    while (scanf("%d", &n) == 1 && n) {
        distanceMap.clear();
        distanceMap[1000000000] = 1;
        
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            lowerIt = distanceMap.lower_bound(y);
            
            if (lowerIt == distanceMap.begin()) {
                printf("%d %d\n", x, lowerIt->second);
            } else {
                prevIt = lowerIt;
                prevIt--;
                
                if (abs(y - prevIt->first) <= abs(y - lowerIt->first)) {
                    printf("%d %d\n", x, prevIt->second);
                } else {
                    printf("%d %d\n", x, lowerIt->second);
                }
            }
            
            distanceMap[y] = x;
        }
    }
    return 0;
}
