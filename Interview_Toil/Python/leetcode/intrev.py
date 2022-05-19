# Number = int(input("Please Enter any Number: "))
# Reverse = 0
# while Number != 0:
#     Reminder = Number % 10
#     Reverse = (Reverse * 10) + Reminder
#     Number = Number // 10
#
# print("\n Reverse of entered number is = %d" % Reverse)
from typing import List


class Solution:
    def reverse(self, x):
        self.x = x

        if x > 0:
            x = str(x)
            x = int(x[::-1])
            if x < 100:
                x = str(x)
                revlis = list(x.split("-"))
                revli_sorted = [i for i in revlis if i != 0]
                revli_sorted: str = "".join(revli_sorted)
                return revli_sorted
            return x
        else:
            x = str(x)
            y = ('-'+''.join(reversed(x[1:])))
            if y[1] == 0:
                y1 = str(y)
                y1 = list(y1.split(""))
                y1_sorted = [i for i in y1 if i != 0]
                y1_sorted = "".join(y1_sorted)
                return y1_sorted+"x"
            return y

if __name__ == '__main__':
    s = Solution()
    print(s.reverse(-10))