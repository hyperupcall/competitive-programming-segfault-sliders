// Link: https://open.kattis.com/problems/roadtosavings
//
// Constraints:
//
//    n = num nodes
//	  m = num edges
//
//    (1 <= n <= 100)
//
//	  Weighted bidirectional graph. Goal is to find
//	  the difference between the total length/cost of all roads
//    and the cost of all roads in the shortest path.
//
//	  This is because we are looking for all roads we don't want to
//	  pave.

#include <functional>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <tuple>

struct Edge {
	int currentNode;
	int adjNode;
	int weight;
};

struct Node {
	int id;
	int cost;

	bool operator >(const Node &other) const {
		return cost > other.cost;
	}
};

std::vector<int> shortestPaths(const int &start, const int &target, const int &n, const std::vector<std::vector<Edge>> &graph);

int main() {
	int n, m, house, office;
	std::cin >> n >> m >> house >> office;

	int totalCost = 0;
	std::vector<std::vector<Edge>> graph(n + 1);
	std::vector<std::tuple<int, int, int>> edges;
	for (int _ = 0; _ < m; _++) {
		int n1, n2, w;
		std::cin >> n1 >> n2 >> w;

		graph[n1].push_back({ n1, n2, w });
		graph[n2].push_back({ n2, n1, w });
		edges.push_back({n1, n2, w});

		totalCost += w;
	}

	std::vector<int> distFromHouse = shortestPaths(house, office, n, graph);
	std::vector<int> distFromOffice = shortestPaths(office, house, n, graph);

	int shortestPath = distFromHouse[office];
	int shortestPathCosts = 0;

	for (const auto &[n1, n2, w] : edges) {
		bool inShortestPath = false;

		if (distFromHouse[n1] == INT_MAX || distFromHouse[n2] == INT_MAX || distFromOffice[n1] == INT_MAX || distFromOffice[n2] == INT_MAX) {
			continue;
		}

		// if house -> n1 + n2 <- office + the edge connecting n1 and n2 == the shortest path
		// Then this edge is on a shortest path
		if (distFromHouse[n1] + w + distFromOffice[n2] == shortestPath
		|| distFromHouse[n2] + w + distFromOffice[n1] == shortestPath) {
			inShortestPath = true;
		}

		if (inShortestPath) {
			shortestPathCosts += w;
		}
	}

	std::cout << totalCost - shortestPathCosts << std::endl;

	return 0;
}

std::vector<int> shortestPaths(const int &start, const int &target, const int &n, const std::vector<std::vector<Edge>> &graph) {
	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> visiting;
	std::vector<int> weights(n + 1, INT_MAX);

	visiting.push({start, 0});
	weights[start] = 0;

	while (!visiting.empty()) {
		Node current = visiting.top();
		visiting.pop();
	
		for (const auto &edge : graph[current.id]) {
			int cost = current.cost + edge.weight;
			if (cost < weights[edge.adjNode]) {
				visiting.push({edge.adjNode, cost});
				weights[edge.adjNode] = cost;	
			}
		}
	}

	return weights;
}