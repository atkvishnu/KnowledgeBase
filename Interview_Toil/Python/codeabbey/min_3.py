counts = int(input())

for n in range(counts):
    num = input().split()
    mins = 0

    for i in num:
        if mins == 0:
            mins = int(i)

        if int(i) < mins:
            mins = int(i)

    print(mins)


# -2310391 -5785295 -3910227 -4823497 -5932307 4704720 -4498008 -2945922 -4044791 -426308 -6272501 -5463977 -8885375 -7019473 -9712871 -8090632 -7085007 -8378136 3219894 -6097569 1865362