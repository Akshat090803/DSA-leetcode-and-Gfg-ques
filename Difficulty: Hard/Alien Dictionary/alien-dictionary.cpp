//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        //this is topological sort problem will use Kanhes algo
        // suppose input is  ["cb", "cba", "a", "bc"]
        //we will find prerequisite and make adjacency list of it
        // for given input , prerequiste wiil be
        // c->a
        // a->b
        //we compare adjacent string to get this prerequisite i.e, cb is compare with cba and cba is compare with a , a with bc
        //and make adjacent list of it
        //now as they are char, but for ease we will make adjacency list to be of type int and to cinvert char to int which represent index we will do char-'a'
        //and whn storing ans , we convert back by adding +'a'
        //if length of ans string == No.of Unique alphabet return ans else ""
        
        //count no.of unique char
       unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> in_degree;
    unordered_set<char> chars;

    // 1. Collect unique characters and initialize in-degree
    for (const string& word : words) {
        for (char c : word) {
            chars.insert(c);
            in_degree[c] = 0; // Initialize in-degree for all chars
        }
    }

    // 2. Build the adjacency list and in-degree map
    for (int i = 0; i < words.size() - 1; ++i) {
        string str1 = words[i];
        string str2 = words[i + 1];
        int j = 0,k=0;
        while (j < str1.size() && k < str2.size() && str1[j] == str2[k]) {
            j++;
            k++;
        }

        if (j < str1.size() && k < str2.size()) { // Found a difference
            char u = str1[j];
            char v = str2[k];
            if (adj[u].find(v) == adj[u].end()) { // Avoid duplicate edges
                adj[u].insert(v); // Correct: Use insert()
                in_degree[v]++;
            }
        } else if (j < str1.size() && k == str2.size()) { // str1 is a prefix of str2 (invalid order) measn str1="abc" and str2 ="ab" this is wrong order as str2 needs to be come before str1 in dictionary
            return "";
        }
    }

    // 3. Topological sort (Kahn's algorithm)
    queue<char> q;
    //push with char 0 in degree
    for (char c : chars) {
        if (in_degree.find(c) != in_degree.end() && in_degree[c] == 0) {
            q.push(c);
        }
    }

    string ans = "";
    while (!q.empty()) {
        char node = q.front();
        q.pop();
        ans += node;

        
            for (char vertex : adj[node]) {
                in_degree[vertex]--;
                if (in_degree[vertex] == 0) {
                    q.push(vertex);
                }
            
        }
    }

    // 4. Check for cycles (if the topological sort visited all characters)
    return (ans.size() == chars.size()) ? ans : "";
    }
};

//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends