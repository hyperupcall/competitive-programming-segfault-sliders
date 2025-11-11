// NOT EFFICIENT, DOESNT WORK IN PYTHON. THIS IS MY FIRST SOLUTION
// LOOK AT PYTHON SOLUTION FOR MUCH FASTER CLEANER SOLUTION 

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

static std::unordered_map<int, std::unordered_set<int>> t1Hierarchy;
static std::unordered_map<int, std::unordered_set<int>> t2Hierarchy;


void readLine(std::string &s) noexcept;

void treeToList(const std::string &s, std::vector<int> &v) noexcept;

int constructTree(std::string &tree, int start, int end, const int &treeNum) noexcept;

int main() {
    std::string tree1, tree2;

    readLine(tree1);
    readLine(tree2);
    
    std::vector<int> t1Nodes;
    std::vector<int> t2Nodes;
    
    treeToList(tree1, t1Nodes);
    treeToList(tree2, t2Nodes);

    if (t1Nodes.size() != t2Nodes.size()) {
        std::cout << "No\n";
        return 0;
    }

    constructTree(tree1, 0, tree1.size(), 1);
    constructTree(tree2, 0, tree2.size(), 2);

    std::sort(t1Nodes.begin(), t1Nodes.end());
    std::sort(t2Nodes.begin(), t2Nodes.end());

    for (int i = 0; i < t1Nodes.size(); i++) {
        if (t1Nodes[i] != t2Nodes[i]) {
            std::cout << "No\n";
            return 0;
        }

        if (t1Hierarchy[t1Nodes[i]] != t2Hierarchy[t2Nodes[i]]) {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";

    return 0;
}

void readLine(std::string &s) noexcept {
    char c;

    while (std::cin.get(c) && c != '\n') {
        if (c != ' ') s += c;
    }
}

void treeToList(const std::string &s, std::vector<int> &v) noexcept {
    std::string currentNum;
    for (const auto &c : s) {
        if (isdigit(c)) {
            currentNum += c;
        } else if (!currentNum.empty()) {
            v.push_back(std::stoi(currentNum));
            currentNum = "";
        }
    }

    if (!currentNum.empty()) {
        v.push_back(std::stoi(currentNum));
    }
}

int constructTree(std::string &tree, int start, int end, const int &treeNum) noexcept {
    if (start >= end) {
        return 0;
    }

    int i = start;
    while (i < end && tree[i] != '(' && tree[i] != ')') {
        i += 1;
    }

    if (i == start) {
        return 0;
    }

    int val = 0;
    try {
        val = std::stoi(tree.substr(start, i - start));
    } catch (...) {
        return 0;
    }

    // no more children :(
    if (i >= end || tree[i] != '(') {
        return val;
    }

    int current = val;
    while (i < end) {
        if (tree[i] == '(') {
            int childStart = i + 1;
            int depth = 1;
            i = childStart;

            while (i < end && depth > 0) {
                if (tree[i] == '(') {
                    depth += 1;
                } else if (tree[i] == ')') {
                    depth -= 1;
                }
                i += 1;
            }

            int child = constructTree(tree, childStart, i - 1, treeNum);

            if (child != 0) {
                if (treeNum == 1) {
                    t1Hierarchy[current].insert(child);
                } else {
                    t2Hierarchy[current].insert(child);
                }
            }
        } else {
            i += 1;
        }
    }

    return current;
}