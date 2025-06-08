class Solution {
public:
    const int M = 1e9 + 7;

    long long fpow(long long n, long long m) {
        if (m == 0) return 1;
        long long half = fpow(n, m / 2);
        long long res = (half * half) % M;
        if (m % 2 == 1) res = (res * n) % M;
        return res;
    }

    int countGoodNumbers(long long n) {
        return (fpow(5, (n + 1) / 2) * fpow(4, n / 2)) % M;
    }
};
