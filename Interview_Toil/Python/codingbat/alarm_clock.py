def alarm_clock(day, vacation):

    # day = [0, 1, 2, 3, 4, 5, 6]
    # vacation = bool
    weekdays = [1, 2, 3, 4, 5]
    weekends = [0, 6]

    if (day == weekdays) and (vacation == False):
        print("7:00")
    elif (day == weekends) and (vacation == False):
        print("10:00")
    elif (day == weekdays) and (vacation == True):
        print("10:00")
    elif (day == weekends) and (vacation == True):
        print("off")
    else:
        print("Fucked")

    print(weekdays)
    print(weekends)

# alarm_clock(1, False)
alarm_clock(5, False)
# alarm_clock(0, False)