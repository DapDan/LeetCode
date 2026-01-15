class Solution(object):
    def reverse(self, x):
        intMin = -2**31
        intMax = 2**31 - 1

        sinal = 1
        if x < 0:
            sinal = -1

        x = abs(x)
        invertido = 0
        while x > 0:
            invertido = invertido * 10 + x % 10
            x //= 10

        invertido *= sinal

        if invertido < intMin or invertido > intMax:
            return 0
        else:
            return invertido
        