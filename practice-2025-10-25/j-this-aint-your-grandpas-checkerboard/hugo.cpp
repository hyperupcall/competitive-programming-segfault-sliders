#include <iostream>
#include <vector>

int main() {
    int n;
    
    std::cin >> n;
    
    std::vector<std::vector<char>> grid;
    
    for (int i = 0; i < n; ++i) {
        std::vector<char> row(n);
        for (char &c : row) {
            std::cin >> c;
        }
        grid.push_back(row);
    }
    
    for (const auto r : grid) {
        int rowCount = 0;
        int consecutiveBlack = 0;
        int consecutiveWhite = 0;
        
        for (const char c : r) {
            if (c == 'B') {
                rowCount += 1;
                consecutiveWhite = 0;
                consecutiveBlack += 1;
                if (consecutiveBlack == 3) {
                    std::cout << 0;
                    return 0;
                }
            } else {
                rowCount -= 1;
                consecutiveWhite += 1;
                consecutiveBlack = 0;
                if (consecutiveWhite == 3) {
                    std::cout << 0;
                    return 0;
                }
            }
        }
        
        if (rowCount != 0) {
            std::cout << 0;
            return 0;
        }
    }
    
    for (int c = 0; c < n; ++c) {
        int colCount = 0;
        int consecutiveBlack = 0;
        int consecutiveWhite = 0;
        for (int r = 0; r < n; ++r) {
            if (grid[r][c] == 'B') {
                colCount += 1;
                consecutiveWhite = 0;
                consecutiveBlack += 1;
                if (consecutiveBlack == 3) {
                    std::cout << 0;
                    return 0;
                }
            } else {
                colCount -= 1;
                consecutiveWhite += 1;
                consecutiveBlack = 0;
                if (consecutiveWhite == 3) {
                    std::cout << 0;
                    return 0;
                }
            }
        }
        if (colCount != 0) {
            std::cout << 0;
            return 0;
        }
    }

    std::cout << 1;

    return 0;
}
