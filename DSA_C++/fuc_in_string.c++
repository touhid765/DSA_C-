#include <iostream>
#include <string>
#include <queue>
#include <vector>

// Function to find the index of the first unique character using a queue
int firstUniqCharUsingQueue(std::string s) {
    // Array to store frequencies of all 256 ASCII characters
    std::vector<int> count(256, 0);
    
    // Queue to store pairs of {character, index} in order of appearance
    std::queue<std::pair<char, int>> q;

    // Process each character in the string
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        // 1. Update frequency
        count[static_cast<unsigned char>(c)]++;
        
        // 2. Push current character and its index into the queue
        q.push({c, i});
        
        // 3. Clean up the queue front: Remove characters that are no longer unique
        while (!q.empty() && count[static_cast<unsigned char>(q.front().first)] > 1) {
            q.pop();
        }
    }

    // If queue is not empty, the front element is the first unique character
    if (!q.empty()) {
        return q.front().second; // Return its 0-based index
    }

    return -1; // Return -1 if no unique character exists
