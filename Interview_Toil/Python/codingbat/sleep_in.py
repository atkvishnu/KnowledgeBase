def sleep_in(weekday, vacation):
    if (weekday == True) and (vacation == True):
        return True
    elif (weekday == True) and (vacation == False):
        return False
    elif (weekday == False) and (vacation == True):
        return True
    else:
        return True
#_______________________________________________________OR

# def sleep_in(weekday, vacation):
#   if not weekday or vacation:
#     return True
#   else:
#     return False


