#
# try:
#     hrs = int(input("Enter hours: "))
#     rate = float(input("Enter rate: "))
#     if ( hrs < 40 ):
#         pay1 = hrs * rate
#         print("Pay: ", pay1)
#     else:
#         count = hrs - 40
#         extra = 1.5 * count * rate
#         pay = 400 + extra
#         print("Pay: ", pay)
# except:
#     print("Error, please enter numeric input")
#___________________________________________________________

hours = 0.0
rate = 0.0
pay = 0.0

input_hours = input("Enter Hours: ")
try:
    hours = float(input_hours)
except ValueError:
    print("Error, please enter numeric values")
    quit()

input_rate = input("Enter Rate: ")
try:
    rate = float(input_rate)
except ValueError:
    print("Error, please enter numeric values")
    quit()

if hours < 40:
    pay = rate * hours
else:
    overtime = hours - 40
    pay = (rate * 40.0) + ( 1.5 * overtime * rate)

print("Pay: ", pay)