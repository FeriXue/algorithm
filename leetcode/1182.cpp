class Solution {
public:
int find(vector<int> &a, int l, int r, int x) {
    int bigger = 0, smaller = 0;
    int left = l, right = r;
    while (l < r) {
        int mid = (l + r) >> 1;  
        if (a[mid] >= x) {
            r = mid;
        } else if (a[mid] < x){
            l = mid + 1;
        }
    }
    bigger = l;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (a[mid] <= x) {
            left = mid;
        } else if (a[mid] > x) {
            right = mid - 1;
        }
    }
    smaller = left;
    if ((a[bigger] - x) >= (x - a[smaller])) {
        return smaller;
    } else {
        return bigger;
    }
}
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> out_re;
        const int N = 1e5 + 10;
        vector<int> a, b, c;
        for (int i = 0; i < colors.size(); ++ i) {
            if (colors[i] == 1) {
                a.push_back(i);
            } else if(colors[i] == 2) {
                b.push_back(i);
            } else {
                c.push_back(i);
            }
        }
        for (auto &iter : queries) {
            int l = 0, k = 0;
            if (iter[1] == 1) {
                if (!a.size()) {
                    out_re.push_back(-1);
                } else {
                    l = find(a, 0, a.size() - 1, iter[0]);
                    k = iter[0] - a[l];
                    k = ((k > 0) ? k : -k);
                    out_re.push_back(k);
                }
            } else if (iter[1] == 2) {
                if (b.size() == 0) {
                    out_re.push_back(-1);
                } else {
                    l = find(b, 0, b.size() - 1, iter[0]);
                    k = iter[0] - b[l];
                    k = ((k > 0) ? k : -k);
                    out_re.push_back(k);
                }
            } else {
                if (c.size() == 0) {
                    out_re.push_back(-1);
                } else {
                    l = find(c, 0, c.size() - 1, iter[0]);
                    k = iter[0] - c[l];
                    k = ((k > 0) ? k : -k);
                    out_re.push_back(k);
                }
            }
        }
        return out_re;
    }
};


