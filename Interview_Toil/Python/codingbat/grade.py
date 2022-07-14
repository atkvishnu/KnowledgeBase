# sco = float(input("Enter score: "))
# if sco > 1.0:
#     print("Bad score!")
# elif 0.9 >= sco > 1.0:
#     print("A")
# elif 0.8 >= sco > 0.9:
#     print("B")
# elif 0.7 >= sco > 0.6:
#     print("C")
# elif 0.6 >= sco > 0.7:
#     print("D")
# elif sco < 0.6:
#     print("F")
# ______________________________________
# new approach

# initialize the variables

input1 = input("Enter score: ")

try:
    score = float(input1)
except ValueError:
    print("Bad score!")
    quit()

if 0.0 <= score <= 1.0:
    if score >= 0.9:
        grade = 'A'
    elif score >= 0.8:
        grade = 'B'
    elif score >= 0.7:
        grade = 'C'
    elif score >= 0.6:
        grade = 'D'
    else:
        grade = 'F'
else:
    grade = 'Bad score!'

print(grade)