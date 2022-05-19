def squirrel_play(temp, is_summer):
    if (is_summer == False):
        if (60 <= temp <= 90):
            return True
        else:
            return False

    if (is_summer == True):
        if (60 <= temp <= 100):
            return True
        else:
            return False