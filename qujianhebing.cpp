#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

//const int N 

int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9) {
                res.push_back({st, ed});
            } 
            st = seg.first;
            ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }

    if (st != -2e9) {
        res.push_back({st, ed});
    }

    //segs = res;
    segs.assign(res.begin(), res.end());
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        int l = 0, r = 0;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() << endl;
    return 0;
}

