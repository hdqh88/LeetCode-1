// Time:  O(1)
// Space: O(1)


class Vector2D {
    vector<vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size())
            i++, j = 0;
        return i != iEnd;
    }
};



class Vector2D_2 {
public:
    Vector2D(vector<vector<int>>& vec2d) : vec(vec2d) {
        x = vec.begin();
        if (x != vec.end()) {
            y = x->begin();
            adjustNextIter();
        }
    }

    int next() {
        const auto ret = *y;
        ++y;
        adjustNextIter();
        return ret;
    }

    bool hasNext() {
        return x != vec.end() && y != x->end();
    }
    
    void adjustNextIter() {
        while (x != vec.end() && y == x->end()) { 
            ++x;
            if (x != vec.end()) {
                y = x->begin();
            }
        }
    }

private:
    vector<vector<int>>& vec;
    vector<vector<int>>::iterator x;
    vector<int>::iterator y;
};
