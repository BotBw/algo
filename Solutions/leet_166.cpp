class Solution {
public:
    using ll = long long;
    string fractionToDecimal(ll p, ll q) {
        map<int, int> vis;
        bool neg = p * q < 0;
        if (p < 0) p = -p;
        if (q < 0) q = -q;
        string res(to_string(p / q));
        p %= q;
        if (p == 0) return neg ? "-" + res : res;
        res.push_back('.');
        while (p) {
            vis[p * 10] = res.size();
            p *= 10;
            int di = p / q;
            p -= di * q;
            res.push_back('0' + di);
            if (vis.contains(p * 10)) {
                res.insert(vis[p * 10], "(");
                res.push_back(')');
                break;
            }
        }
        if (neg) {
            res = "-" + res;
        }
        return res;
    }
};

/*

1 / 3

-> 1.0 / 0.3
->   9 ...
     1 0 
*/
