#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bitset<64> ans;

        bitset<32> tem_a(dividend), tem_b(divisor);
        if (!(tem_a[31] ^ tem_b[31])) { 
            bitset<64> a(0), b(0);
            for (int i = 0; i < 32; i ++) {
                a[i] = tem_a[i];
                b[32 + i] = tem_b[i];
            }

            for (int i = 0; i <= 32; i ++) {
                a = sub(a, b);
                // cout << "========== " << i << " ==========" << endl;
                // cout << "ans: " << ans << endl;
                // cout << "a:   " << a << endl;
                // cout << "b:   " << b << endl << endl;

                if (a[63]) {
                    a = add(a, b);
                    ans <<= 1;
                }
                else {
                    ans <<= 1;
                    ans[0] = 1;
                }

                b >>= 1;
            }

            a = add(a, a);
            b = sub(a, b);
            if (!b[63])
                ans = add(ans, bitset<64>(1));
            

        }   // All positive or all negative
        else {
            
        }   // One positive and one negative

        return int(ans.to_ulong());
    }

    bitset<64> sub(bitset<64> a, bitset<64> b) {
        b.flip();
        b = add(b, bitset<64>(1));

        return add(a, b);
    }

    bitset<64> add(bitset<64> a, bitset<64> b) {
        bitset<64> ans;
        bool carry = false;
        for (int i = 0; i < 64; i ++) {
            ans[i] = a[i] ^ b[i] ^ carry;
            carry = (a[i] & b[i]) | ((a[i] ^ b[i]) & carry);
        }

        return ans;
    }
};

int main() {
    Solution s;
    int dividend, divisor;

    dividend = -10, divisor = -3;
    cout << s.divide(dividend, divisor) << endl;

    // dividend = 7, divisor = -3;
    // cout << s.divide(dividend, divisor) << endl;

    // dividend = -11, divisor = 4;
    // cout << s.divide(dividend, divisor) << endl;

    // dividend = -2147483648, divisor = -1;
    // cout << s.divide(dividend, divisor) << endl;
}