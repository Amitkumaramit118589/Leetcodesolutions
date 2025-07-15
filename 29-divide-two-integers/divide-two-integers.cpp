class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case: INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Use long long to safely handle abs(INT_MIN)
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            ans += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return ans;
    }
};
