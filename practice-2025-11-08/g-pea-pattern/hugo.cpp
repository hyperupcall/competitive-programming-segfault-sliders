// Link: https://open.kattis.com/problems/peapattern
//
// Constraints:
//
//    n = starting number
//	  m = goal
//
//	  (0 < n < 10^100 - 1)
//	  (0 < m < 10^100 - 1)
//
//	  Trick is that you can brute force as the problem says
//	  you only need to try 100 times before quitting
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

int main() {
	std::string startNum;
	std::string targetNum;

	std::cin >> startNum >> targetNum;

	std::unordered_set<std::string> seen;

	std::string current = startNum;
	int i = 1;
	while (i <= 100) {
		if (current == targetNum) {
			std::cout << i << '\n';
			return 0;
		}

		seen.insert(current);

		std::vector<std::pair<char, int>> freqs = {
			{ '0', 0 }, 
			{ '1', 0 }, 	
			{ '2', 0 }, 
			{ '3', 0 }, 
			{ '4', 0 }, 
			{ '5', 0 }, 
			{ '6', 0 }, 
			{ '7', 0 }, 
			{ '8', 0 }, 
			{ '9', 0 }
		};

		for (const char &c : current) {
			freqs[c - '0'].second += 1;
		}

		std::sort(freqs.begin(), freqs.end(), [](const auto &p1, const auto &p2){
			return p1.first < p2.first;
		});

		current = "";
		for (const auto &[chrNum, freq] : freqs) {
			if (freq > 0) {
				current += (std::to_string(freq) + chrNum);
			}
		}

		// If pattern begins repeating, then we will continue repeating
		if (seen.find(current) != seen.end()) {
			std::cout << "Does not appear\n";
			return 0;
		}

		i += 1;
	}

	std::cout << "I'm bored\n";

	return 0;
}
