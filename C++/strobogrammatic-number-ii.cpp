// Time:  O(n^2 * 5^(n/2))
// Space: O(n)


class Solution {
    unordered_map<string, string> dic{{"0", "0"}, {"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}};
public:
    vector<string> findStrobogrammatic(int n) {
        return recursion(n, n);
    }
    
    vector<string> recursion(int n, int k){
        if(k == 0)
            return {""};
        if(k == 1)
            return {"0", "1", "8"};
        vector<string> rec = recursion(n, k - 2);
        vector<string> result;
        for(string& str : rec)
            for(map<string, string>::value_type& ele : dic)
                if(n != k || ele.first != "0")
                    result.push_back(ele.first + str + ele.second);
        return result;
    }
};


class Solution2 {
public:
    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammaticRecu(n, n);
    }
    
    vector<string> findStrobogrammaticRecu(const int n, int k) {
        if (k == 0) {
            return {""};
        } else if (k == 1) {
            return {"0", "1", "8"};
        }
    
        vector<string> result;
        for (const auto& num : findStrobogrammaticRecu(n, k - 2)) {
            for (const auto& kvp : lookup) {
                if (n != k || kvp.first != "0") {
                    result.emplace_back(kvp.first + num + kvp.second);
                }
            }
        }
        return result;
    }

private:
    const unordered_map<string, string> lookup{{"0", "0"}, {"1", "1"},
                                               {"6", "9"}, {"8", "8"}, 
                                               {"9", "6"}};
};
