from textblob import TextBlob

text = '''
Articles are words that define a noun as specific or unspecific.
Consider the following examples: After the long day, the cup of tea 
tasted particularly good. By using the article the, we've shown that 
it was one specific day that was long and one specific cup of tea that tasted good
'''

blob = TextBlob(text)
blob.tags

blob.noun_phrases

for sentence in blob.sentences:
    print(sentence.sentiment.polarity)
# 0.060
# -0.341

blob.translate(to="hi")