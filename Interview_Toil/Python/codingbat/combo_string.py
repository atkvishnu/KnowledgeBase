
def combo_string(a, b):

    short = ''
    long = ''

    if len(a) > len(b):
        long = a
    else:
        long = b

    if a == long:
        short = b
    else:
        short = a

    print(short+long+short)

# combo_string('Hello', 'hi')
combo_string('hi', 'Hello')
# combo_string('aaa', 'b')