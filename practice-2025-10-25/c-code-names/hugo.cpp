#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

bool canSwapToMatch(const std::string &s1, const std::string &s2);
int countInversions(const std::string &word, const std::string &reference);
int maxBipartiteMatching(int leftSize, int rightSize, const std::vector<std::vector<int>> &adj);
bool dfs(const std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::vector<int> &match, int u);

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (std::string &word : words) {
        std::cin >> word;
    }

    // reference order == alphabetical order
    std::string reference = words[0];
    std::sort(reference.begin(), reference.end());

    // Partition by parity
    std::vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int inversions = countInversions(words[i], reference);
        if (inversions % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    // Build bipartite adjacency list (even -> odd)
    std::vector<std::vector<int>> adj(even.size());
    for (int i = 0; i < even.size(); i++) {
        for (int j = 0; j < odd.size(); j++) {
            if (canSwapToMatch(words[even[i]], words[odd[j]])) {
                adj[i].push_back(j);
            }
        }
    }

    int matching = maxBipartiteMatching(even.size(), odd.size(), adj);
    std::cout << n - matching;

    return 0;
}

int countInversions(const std::string &word, const std::string &reference) {
    // Map each character to its position in according to reference order
    std::vector<int> pos(26, -1); // -1 not important but i want it there
    for (int i = 0; i < reference.length(); i++) {
        pos[reference[i] - 'a'] = i;
    }

    // Count inversions in the mapped sequence
    int inversions = 0;
    std::vector<int> mapped;
    for (char c : word) {
        mapped.push_back(pos[c - 'a']);
    }

    for (int i = 0; i < mapped.size(); i++) {
        for (int j = i + 1; j < mapped.size(); j++) {
            if (mapped[i] > mapped[j]) {
                inversions++;
            }
        }
    }

    return inversions;
}

int maxBipartiteMatching(int leftSize, int rightSize, const std::vector<std::vector<int>> &adj) {
    std::vector<int> match(rightSize, -1); // match[right] = left node
    int result = 0;

    for (int u = 0; u < leftSize; u++) {
        std::vector<bool> visited(rightSize, false);

        if (dfs(adj, visited, match, u)) {
            result++;
        }
    }

    return result;
}

bool canSwapToMatch(const std::string &s1, const std::string &s2) {
    std::vector<int> diffPositions;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            diffPositions.push_back(i);
        }
    }
    
    if (diffPositions.size() == 2) {
        int pos1 = diffPositions[0];
        int pos2 = diffPositions[1];
        return (s1[pos1] == s2[pos2] && s1[pos2] == s2[pos1]);
    }
    
    return false;
}

bool dfs(const std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::vector<int> &match, int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;

        if (match[v] == -1 || dfs(adj, visited, match, match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}