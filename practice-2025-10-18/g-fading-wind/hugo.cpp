// Link: https://open.kattis.com/problems/fadingwind
//
// Constraints:
//
//    Doesn't matter but every input is (1 <= n <= 10^3)
//

#include <iostream>
#include <cmath>

int main() {
    int v = 0, h = 0, k = 0, s = 0, d = 0;
    
    std::cin >> h >> k >> v >> s;
    
    while (h > 0) {
        v += s;
        
        v -= std::max(1, int(std::floor(v / 10)));
        
        if (v >= k) {
            h += 1;
        }
        
        if (0 < v && v < k) {
            h -= 1;
            if (h == 0) {
                v = 0;
            }
        }
        
        if (v <= 0) {
            h = 0;
            v = 0;
        }
        
        d += v;
        if (s > 0) {
            s -= 1;
        }
    }
    
    std::cout << d;
    
    return 0;
}