class Solution {
public:
    long long modpow(long long base, long long exp, long long mod) {

        if(exp == 0) return 1;

        long long half = modpow(base, exp / 2, mod) % mod;

        half = (half * half) % mod;

        if(!(exp & 1)) {
            return half;
        }

        return (half * base) % mod;
    }
    int countGoodNumbers(long long n) {
        long long mod = 1000000007;

        long long oddplaces = n / 2;
        long long evenplaces = (n + 1) / 2;

        long long cnt = modpow(4, oddplaces, mod) * modpow(5, evenplaces, mod) % mod;

        return cnt;
    }
};