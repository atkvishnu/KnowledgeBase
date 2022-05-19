# Given a non-empty string like "Code" return a string like "CCoCodCode".
#
#
# string_splosion('Code') → 'CCoCodCode'
# string_splosion('abc') → 'aababc'
# string_splosion('ab') → 'aab'

def string_splosion(str):
    result = ''

    for i in range(1, len(str) + 1):
        result += str[0:i]

    return result

#_______________________________________OR

# def string_splosion(str):
# #   result = ""
# #   # On each iteration, add the substring of the chars 0..i
# #   for i in range(len(str)):
# #     result = result + str[:i+1]
# #   return result