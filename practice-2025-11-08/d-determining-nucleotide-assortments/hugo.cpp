// Link: https://open.kattis.com/problems/nucleotides
//
// Constraints:
//
//    n = size of string
//    m = number of queries
//    start = start index of substring we're querying
//    end = end index of substring we're querying
//    
//    
//    (1 <= n <= 50000)
//    (1 <= m <= 25000)
//    (1 <= start <= n)
//    (1 <= end <= n)
//    
//    **Note**: worst case is 1.25 * 10^9 because
//              you're doing 2.5 * 10^4 queries
//              and have a max length of 5 * 10^4.
//

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <string>
#include <algorithm>

int main() {
    std::string dnaStr;
    std::getline(std::cin, dnaStr);

    int m;
    std::cin >> m;

    std::vector<char> dnaChars = { 'A', 'T', 'G', 'C' };
    std::unordered_map<char, int> order = {
        {'A', 0},
        {'T', 1},
        {'G', 2},
        {'C', 3}
    };

    std::vector<std::vector<int>> runningSum;
    runningSum.push_back(std::vector<int>(4, 0)); // start with {0 0 0 0} freq for running sum logic

    // Creates a running sum of frequencies
    for (const char c : dnaStr) {
        std::vector<int> newSum = runningSum.back();
        newSum[order[c]] += 1;
        runningSum.push_back(newSum);
    }

    // Handles each query one at a time
    for (int _ = 0; _ < m; _++) {
        int start, end;
        std::cin >> start >> end;

        // Subtracts the frequencies from the one prior to the start from the end
        // to return frequencies from start to end indexes
        //
        // Uses pair to keep character associated to it easily accessible later
        std::vector<std::pair<char, int>> rangeFreqs(4);
        for (int i = 0; i < 4; i++) {
            rangeFreqs[i] = {dnaChars[i], runningSum[end][i] - runningSum[start - 1][i]};
        }

        // Uses lambda that sorts in reverse for freq. If freq1 == freq2 then tiebreaker is
        // the order (highest priority) ATGC (lowest priority)
        std::sort(rangeFreqs.begin(), rangeFreqs.end(), [&order](const auto &p1, const auto &p2){
            char c1 = p1.first;
            char c2 = p2.first;

            int freq1 = p1.second;
            int freq2 = p2.second;

            if (freq1 != freq2) {
                return freq1 > freq2;
            }

            return order[c1] < order[c2];
        });

        // print out each character in rangeFreqs after it's sorted
        for (const auto &[c, freq] : rangeFreqs) {
            std::cout << c;
        }
	    std::cout << '\n';
    }

    return 0;
}

