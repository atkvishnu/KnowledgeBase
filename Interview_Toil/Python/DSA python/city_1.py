def missing(x):
    n = len(x)
    N = (x + 2) * (x + 1) / 2
    S = sum(A)
    return N - S


S = [1, 2, 4, 5]
miss = missing(S)
print(int(miss))