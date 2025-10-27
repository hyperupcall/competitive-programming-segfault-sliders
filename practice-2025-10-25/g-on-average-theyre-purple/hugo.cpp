// Link: https://open.kattis.com/problems/onaveragetheyrepurple
//
// Constraints:
//
//    N = number of nodes
//    M = number of edges
//    a = a node
//    b = another node
//
//    (2 <= N <= 100000)
//    (1 <= M <= 100000)
//    (1 <= a <= N)
//    (1 <= b <= N)
//    (a != b)
//
//    simple connected undirected unweighted graph
//

#include <iostream>
#include <climits>
#include <queue>

int main() {
    int N, M;
    
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> adjList(N + 1);
    
    int a, b;
    for (int i = 0; i < M; ++i) {
        std::cin >> a >> b;
        
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    std::vector<int> seen(N + 1, INT_MAX);
    std::queue<int> visiting;

    seen[0] = INT_MAX;
    visiting.push(1);
    seen[1] = 0;

    while (!visiting.empty()) {
        int currentNode = visiting.front();
        for (const int &adjNode : adjList[currentNode]) {
            if (seen[adjNode] == INT_MAX) {
                visiting.push(adjNode);
                seen[adjNode] = seen[currentNode] + 1;
            }
        }
        visiting.pop();
    }
    
    std::cout << seen[N] - 1;
    
    return 0;
}

/*    
    A color change happens when you go through an edge with a color
    then go through another edge with a different color

    The trick is that bob is minimizing the number of color changes
    he has to face. This means he will take the shortest path as this
    lowers the number of color changes he can possibly face.

    Alice wants to maximize the number of color changes Bob has to do
    This means she will want to make each edge in the shortest path
    alternate colors.

    1 -> 2 -> 4 -> 5 -> 7
    1 -> 3 -> 4 -> 6 -> 7

    Here we have two shortest paths but we don't care about how many edges
    we have to change, we want to know the max number of color changes Alice
    can for Bob into having to do. So we can treat them equivalently

    If we start with edge 1 -> 2 blue.          | No color change since only 1 color so far
    then back to red for 2 -> 4                 | that's 1 color change from blue to red
    then back to blue for 4 -> 5                | that's 2 color changes now red to blue
    then finally back to red for 5 -> 7         | that's 3 color changes from blue to red
    
    7 == N so we stop there and return 3 color changes.
    
    The consistent pattern is that Bob will always take the shortest path
    to minimize possible color changes and the max number of color changes
    will always end up being the length of the shortest path - 1. The -1 comes
    from the first edge that will never be a color change since we just started
*/