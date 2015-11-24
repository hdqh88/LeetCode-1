// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        map<int, int> ind;
        for(int i = 0; i < n; i++)
            ind[i] = i;
        for(pair<int, int> edge : edges){
            int x = find(&ind, edge.first);
            int y = find(&ind, edge.second);
            if(x == y)
                return false;
            ind[x] = y;
        }
        return edges.size() == n - 1;
    }
    
    int find(map<int, int> *a, int i){
        if((*a)[i] == i)
            return i;
        return find(a, (*a)[i]);
    }
};


// Same complexity, but faster version.
class Solution {
public:
    struct node {
        int parent = -1;
        vector<int>neighbors;
    };

    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        } else if (n == 1) {
            return true;
        }

        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
            nodes[edge.first].neighbors.emplace_back(edge.second);
            nodes[edge.second].neighbors.emplace_back(edge.first);
        }

        if (nodes.size() != n) {
            return false;
        }

        unordered_set<int> visited;
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            visited.emplace(i);
            for (const auto& node : nodes[i].neighbors) {
                if (node != nodes[i].parent) {
                    if (visited.find(node) != visited.end()) {
                        return false;
                    } else {
                        visited.emplace(node);
                        nodes[node].parent = i;
                        q.emplace(node);
                    }
                }
            }
        }
        return visited.size() == n;
    }
};

// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)
class Solution2 {
public:
    struct node {
        int parent = -1;
        vector<int>neighbors;
    };

    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
            nodes[edge.first].neighbors.emplace_back(edge.second);
            nodes[edge.second].neighbors.emplace_back(edge.first);
        }

        unordered_set<int> visited;
        queue<int> q;
        q.emplace(0);
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            visited.emplace(i);
            for (const auto& node : nodes[i].neighbors) {
                if (node != nodes[i].parent) {
                    if (visited.find(node) != visited.end()) {
                        return false;
                    } else {
                        visited.emplace(node);
                        nodes[node].parent = i;
                        q.emplace(node);
                    }
                }
            }
        }
        return visited.size() == n;
    }
};
