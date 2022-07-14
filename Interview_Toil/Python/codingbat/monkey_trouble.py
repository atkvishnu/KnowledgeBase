# We have two monkeys, a and b, and the parameters a_smile and b_smile indicate if each
# is smiling. We are in trouble if they are both smiling or if neither of them is smiling.
# Return True if we are in trouble.

# monkey_trouble(True, True) → True
# monkey_trouble(False, False) → True
# monkey_trouble(True, False) → False


def monkey_trouble(a_smile, b_smile):
  if a_smile and b_smile:
    return True
  elif not a_smile and not b_smile:
    return True
  elif a_smile and not b_smile:
    return False
  else:
    return False

# monkey_trouble(True, False)       (This is not working because we are returning the values and not printing it out.)
print("LOL")

#_____________________________________________________________________OR
# def monkey_trouble(a_smile, b_smile):
#   if a_smile and b_smile:
#     return True
#   if not a_smile and not b_smile:
#     return True
#   return False
  ## The above can be shortened to:
  ##   return ((a_smile and b_smile) or (not a_smile and not b_smile))
  ## Or this very short version (think about how this is the same as the above)
  ##   return (a_smile == b_smile)