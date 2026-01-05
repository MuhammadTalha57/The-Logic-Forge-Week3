"""
Asymptotic Analysis

Time Complexity = O(N)
Space Complexity = O(1)

"""

def count_ways_to_summit(n: int) -> int:
    ans = 0

    # a + 2b = n
    # For given b, Number of ways will be ((a + b)!) / (a! * b!)

    a = n
    aFactorial = 1
    for i in range(2, (n + 1)):
        aFactorial *= i

    aPlusBFactorial = aFactorial
    bFactorial = 1

    temp = n
    for b in range((n // 2) + 1):
        ans += aPlusBFactorial // (aFactorial * bFactorial)

        bFactorial *= b + 1

        aFactorial //= max(1, (a * (a - 1)))

        aPlusBFactorial //= temp

        temp -= 1
        a -= 2
    
    return ans


def main():
    
    n = 45
    print(count_ways_to_summit(n))


main()

