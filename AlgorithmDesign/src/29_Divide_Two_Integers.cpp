class Solution {
public:
    int divide(int dividend, int divisor) {

        /**
            dividend: 35
            divisor : 3

            count = 1, 2, 4 , 8 , 16
            temp  = 3, 6, 12, 24, 48 (X)

            quot: 8

            -----------------------------

            dividend: 35 - 24 = 11
            divisor : 3

            count = 1, 2, 4
            temp  = 3, 6, 12 (X)

            quot: 8 + 2 = 10

            -----------------------------

            dividend: 11 - 6 = 5
            divisor : 3

            count = 1, 2
            temp  = 3, 6 (X)

            quot: 10 + 1 = 11

            ------------------------------

            dividend: 5 - 3 = 2
            divisor : 3

        */

        long divd = static_cast<long>(dividend);
        long divr = static_cast<long>(divisor);

        long quot = 0;

        divd = (divd < 0) ? -divd : divd;
        divr = (divr < 0) ? -divr : divr;

        while (divr <= divd) {
            long temp = divr;
            long count = 1;

            while (divd >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }

            divd -= temp;
            quot += count;
        }

        if ((divisor > 0) ^ (dividend > 0) > 0) {
            quot = -quot;
        }

        return (quot > INT_MAX) ? INT_MAX : quot;
    }
};