def date_fashion(you, date):
    you = [1,2,3,4,5,6,7,8,9,10]
    date = [1,2,3,4,5,6,7,8,9,10]

    for i, j in zip(you, date):
        if you[i] >= 8 or date[j] >= 8:
            x = 2
        elif you[i] <= 2 or date[j] >= 2:
            x = 0
        else:
            x = 1
    print(x)



# date_fashion(5, 10)
# date_fashion(5, 2)
date_fashion(5, 5)