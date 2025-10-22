// Link: https://open.kattis.com/problems/threedice
//
// Constraints:
//
//    n = num words
//
//    (1 <= n <= 1000)
//    lowercase alphabetical letters only
//    duplicate words allowed
//    character repeats in word allowed
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<string> words;
unordered_set<char> wordLetters;
unordered_map<char, int> assignment; // maps each letter to die (0, 1, or 2)

bool isValidPartial() {
    // Check if current assignments violate any word constraints
    for (const string& word : words) {
        bool allAssigned = true;
        unordered_set<int> diceUsed;
        
        // Check if all letters of this word are assigned
        for (char c : word) {
            if (assignment.find(c) == assignment.end()) {
                allAssigned = false;
                break;
            }
            diceUsed.insert(assignment[c]);
        }
        
        // If all assigned, they must be on 3 different dice
        if (allAssigned && diceUsed.size() != 3) {
            return false;
        }
    }
    return true;
}

bool backtrack(vector<char>& letters, int index, int dieCount[3]) {
    // Base case: all word letters successfully assigned
    if (index == letters.size()) {
        return true;
    }
    
    char letter = letters[index];
    
    // Try assigning this letter to each die
    for (int die = 0; die < 3; die++) {
        if (dieCount[die] >= 6) continue; // Die already full
        
        assignment[letter] = die;
        dieCount[die]++;
        
        // Check if this assignment is valid and recurse
        if (isValidPartial() && backtrack(letters, index + 1, dieCount)) {
            return true;
        }
        
        // Backtrack: undo assignment
        assignment.erase(letter);
        dieCount[die]--;
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;
    
    words.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        
        // Check for duplicate letters within a word
        if (words[i][0] == words[i][1] || 
            words[i][0] == words[i][2] || 
            words[i][1] == words[i][2]) {
            cout << 0 << endl;
            return 0;
        }
        
        for (char c : words[i]) {
            wordLetters.insert(c);
        }
    }
    
    // Convert set to vector for backtracking
    vector<char> letters(wordLetters.begin(), wordLetters.end());
    int dieCount[3] = {0, 0, 0};
    
    if (!backtrack(letters, 0, dieCount)) {
        cout << 0 << endl;
        return 0;
    }
    
    // Build dice strings from assignments
    vector<string> dice(3);
    for (const auto& [letter, die] : assignment) {
        dice[die] += letter;
    }
    
    // Fill remaining faces with unused letters
    unordered_set<char> used = wordLetters;
    for (int d = 0; d < 3; d++) {
        for (char c = 'a'; c <= 'z' && dice[d].size() < 6; c++) {
            if (used.find(c) == used.end()) {
                dice[d] += c;
                used.insert(c);
            }
        }
    }
    
    cout << dice[0] << " " << dice[1] << " " << dice[2] << endl;
    
    return 0;
}