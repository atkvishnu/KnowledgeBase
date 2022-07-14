class Solution:
    def isPalindrome(self, x):
        self.x = x

        rev = ''.join(reversed(x))

        if (x == rev):
            return True
        return False

if __name__ == '__main__':
    s = Solution()
    print(s.isPalindrome('google'))