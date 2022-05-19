# goal <= small + (big*5)

def make_bricks(small, big, goal):
    x = (goal%5)<=small and (goal-(big*5))<=small
    print(x)
    return x

make_bricks(3, 1, 8)
# make_bricks(3, 1, 9)
# make_bricks(3, 2, 10)