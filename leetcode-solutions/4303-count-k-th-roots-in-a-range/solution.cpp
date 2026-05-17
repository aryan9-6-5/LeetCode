class Solution {
public:
    long long power(long long a, long long k, long long l) {
        if(a==0)return 0;
        long long res = 1;
        for (int i = 0; i < k; i++) {
            if (res > l / a)
                return l + 1;
            res *= a;
        }
        
        return res;
    }

    int k(long long n, int p) {
        long long low = 0, high = 1000000000;
        int ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long v = power(mid, p, n);
            if (v <= n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int countKthRoots(int l, int r, int ki) {
        int right = k((long long)r, ki);
        int left = 0;
        if (l > 0) {
            left = k(l - 1, ki);
        }
        int ans = right - left;
        if (l == 0) {
            ans++;
        }
        return ans;
    }
};
