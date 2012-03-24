#include <iostream>
#include <cstring>

#define N 4800

using namespace std;

const int BIGINT_SIZE = 1008;

class BigInt {
    private:
        char ele[BIGINT_SIZE];
    public:
        BigInt()
        {
            /* initialized with zero */
            ele[0] = '0', ele[1] = '\0';
        }
        BigInt(int t)
        {
            int len = 0;
            while(t > 0)
            {
                ele[len] = t % 10 + '0';
                t /= 10;
                len++;
            }
            ele[len] = '\0';
        }
        friend BigInt operator + (const BigInt& tl, const BigInt& tr)
        {
            /* Assume that tl.len <= tr.len */
            BigInt r;
            int i, carry;
            for(carry = i = 0; tl.ele[i] != '\0'; i++)
            {
                carry += (tl.ele[i] - '0') + (tr.ele[i] - '0');
                r.ele[i] = carry % 10 + '0';
                carry /= 10;
            }
            while(tr.ele[i] != '\0')
            {
                carry += (tr.ele[i] - '0');
                r.ele[i] = carry % 10 + '0';
                carry /= 10;
                i++;
            }
            while(carry != 0)
            {
                r.ele[i] = carry % 10 + '0';
                carry /= 10;
                i++;
            }
            r.ele[i] = '\0';
            return r;
        }
        friend ostream& operator << (ostream& os, const BigInt& t)
        {
            for(int i = strlen(t.ele)-1; i >= 0; i--)
                os << t.ele[i];
            return os;
        }
};


int main()
{

    
    return 0;
}
