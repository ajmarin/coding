# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        v = 50
        while v > 40:
            v = 7 * (rand7() - 1) + rand7()
        return v % 10

