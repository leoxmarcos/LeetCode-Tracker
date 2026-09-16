class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1000000007;

        long long ans = 1;

        int N = n + k - 1;
        int R = 2 * k;

        for (int i = 1; i <= R; i++) {
            ans = ans * (N - i + 1) % MOD;

            // modular inverse of i using Fermat's theorem
            long long inv = 1;
            int power = MOD - 2;
            long long base = i;

            while (power) {
                if (power & 1)
                    inv = inv * base % MOD;

                base = base * base % MOD;
                power /= 2;
            }

            ans = ans * inv % MOD;
        }

        return ans;
    }
};