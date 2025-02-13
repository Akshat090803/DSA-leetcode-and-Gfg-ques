class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto next : adj[curr]) {
                mp[next].insert(curr);
                for(auto pre : mp[curr]) {
                    mp[next].insert(pre);
                }
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        vector<bool> res;
        for(auto q : queries) {
            res.push_back(mp[q[1]].count(q[0]));
        }
        return res;
        
    }
//     think of courses like a family tree! \U0001f468‍\U0001f469‍\U0001f467‍\U0001f466

// Each course can have "parent" courses (prerequisites)
// If course A is parent of B, and B is parent of C, then A is like a "grandparent" to C!
// We need to track all these relationships efficiently
// \U0001f6e0️ Approach Step by Step
// 1️⃣ Building the Graph \U0001f3d7️
// vector<vector<int>> adj(numCourses);
// vector<int> indegree(numCourses, 0);
// for(auto p : prerequisites) {
//     adj[p[0]].push_back(p[1]);
//     indegree[p[1]]++;
// }
// Create an adjacency list (like a contact list where each person has their friends' numbers) \U0001f4f1
// Count how many prerequisites each course has (indegree) \U0001f522
// 2️⃣ Finding Starting Points \U0001f3af
// queue<int> q;
// for(int i = 0; i < numCourses; i++) {
//     if(indegree[i] == 0) {
//         q.push(i);
//     }
// }
// Find courses with no prerequisites (they're like the oldest ancestors!) \U0001f474
// Put them in a queue (like a line at a coffee shop ☕)
// 3️⃣ Processing Courses \U0001f504
// unordered_map<int, unordered_set<int>> mp;
// while(!q.empty()) {
//     int curr = q.front();
//     q.pop();
//     for(auto next : adj[curr]) {
//         mp[next].insert(curr);            // Direct prerequisite
//         for(auto pre : mp[curr]) {
//             mp[next].insert(pre);         // Indirect prerequisites
//         }
//         indegree[next]--;
//         if(indegree[next] == 0) {
//             q.push(next);
//         }
//     }
// }
// Use a map to store all prerequisites for each course \U0001f5fa️
// For each course we process:
// Add it as a prerequisite to its dependent courses \U0001f4dd
// Pass down all its prerequisites (like inherited traits!) \U0001f9ec
// Update the prerequisite count \U0001f504
// When a course has all prerequisites processed, add it to queue ➕
// 4️⃣ Answering Queries \U0001f4a1
// vector<bool> res;
// for(auto q : queries) {
//     res.push_back(mp[q[1]].count(q[0]));
// }
// For each query, we just check our map! \U0001f50d
// Like checking if someone is in your family tree
};