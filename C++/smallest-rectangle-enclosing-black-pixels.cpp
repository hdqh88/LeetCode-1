// Binary Search
// Time:  O(m log n + n log m)
// Space: O(1)
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        int top = searchRows(0, x, 0, n, true, &image);
        int bottom = searchRows(x+1, m, 0, n, false, &image);
        int left = searchColumns(0, y, 0, m, true, &image);
        int right = searchColumns(y+1, n, 0, m, false, &image);
        return (bottom - top) * (right - left);
    }
    
    int searchRows(int i, int j, int start, int end, bool opt, vector<vector<char> > *p){
        while(i < j){
            int mid = (i + j)/2;
            int k = start;
            while(k < end && (*p)[mid][k] == '0')
                k++;
            if(k < end == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return j;
    }
    
    int searchColumns(int i, int j, int start, int end, bool opt, vector<vector<char> > *p){
        while(i < j){
            int mid = (i + j)/2;
            int k = start;
            while(k < end && (*p)[k][mid] == '0')
                k++;
            if(k < end == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return j;
    }
};





// Time:  O(nlogn)
// Space: O(1)

// Using template.
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        using namespace std::placeholders;  // for _1, _2, _3...

        const auto searchColumns =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image.cbegin(), image.cend(),
                                         [=](const vector<char>& row) { return row[mid] == '1'; });
            };
        const auto searchRows =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image[mid].cbegin(), image[mid].cend(),
                                         [](const char& col) { return col == '1'; });
            };

        const int left = binarySearch(0, y - 1, bind(searchColumns, image, true, _1));
        const int right = binarySearch(y + 1, image[0].size() - 1, bind(searchColumns, image, false, _1));
        const int top = binarySearch(0, x - 1, bind(searchRows, image, true, _1));
        const int bottom = binarySearch(x + 1, image.size() - 1, bind(searchRows, image, false, _1));

        return (right - left) * (bottom - top);
    }
    
private:
    template<typename T>
    int binarySearch(int left, int right, const T& find) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (find(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// Using std::bind().
class Solution2 {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        using namespace std::placeholders;  // for _1, _2, _3...

        const auto searchColumns =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image.cbegin(), image.cend(),
                                         [=](const vector<char>& row) { return row[mid] == '1'; });
            };
        const auto searchRows =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image[mid].cbegin(), image[mid].cend(),
                                         [](const char& col) { return col == '1'; });
            };

        function<bool(const int)> findLeft = bind(searchColumns, image, true, _1);
        const int left = binarySearch(0, y - 1, findLeft);
    
        function<bool(const int)> findRight = bind(searchColumns, image, false, _1);
        const int right = binarySearch(y + 1, image[0].size() - 1, findRight);

        function<bool(const int)> findTop = bind(searchRows, image, true, _1);
        const int top = binarySearch(0, x - 1, findTop);

        function<bool(const int)> findBottom = bind(searchRows, image, false, _1);
        const int bottom = binarySearch(x + 1, image.size() - 1, findBottom);

        return (right - left) * (bottom - top);
    }
    
private:
    int binarySearch(int left, int right, function<bool(const int)>& find) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (find(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// Using lambda.
class Solution3 {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        const auto searchColumns =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image.cbegin(), image.cend(),
                                         [=](const vector<char>& row) { return row[mid] == '1'; });
            };
        const auto searchRows =
            [](const vector<vector<char>>& image, bool has_one, const int mid) {
                return has_one == any_of(image[mid].cbegin(), image[mid].cend(),
                                         [](const char& col) { return col == '1'; });
            };

        const int left = binarySearch(0, y - 1, searchColumns, image, true);
        const int right = binarySearch(y + 1, image[0].size() - 1, searchColumns, image, false);
        const int top = binarySearch(0, x - 1, searchRows, image, true);
        const int bottom = binarySearch(x + 1, image.size() - 1, searchRows, image, false);

        return (right - left) * (bottom - top);
    }
    
private:
    int binarySearch(int left, int right,
                     const function<bool(const vector<vector<char>>&, bool, const int)>& find,
                     const vector<vector<char>>& image,
                     bool has_one) {
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (find(image, has_one, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
