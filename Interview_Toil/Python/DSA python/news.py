#!/usr/bin/python3
import json as js
import urllib.request

choice = 1


def grabNews(source, sort, apikey):
    url = ' https://newsapi.org/v1/articles?' + 'source=' + source + '&sortBy=' + sort + '&apikey=' + apikey
    # print(url)
    data = urllib.request.urlopen(url).read().decode('utf-8')
    newsdata = js.loads(data)
    return newsdata


def grabSources(language):
    url = ' https://newsapi.org/v1/sources?language=' + language
    rawSource = urllib.request.urlopen(url).read().decode('utf-8')
    allsources = js.loads(rawSource)
    sourcesEnlist = [x['id'] for x in allsources['sources']]
    return sourcesEnlist


while choice != '0':
    sources = grabSources('en')
    print('select a news source you like[using number]')
    for sno, item in enumerate(sources):
        print(sno, '->', item)
    sltsource = int(input('enter your choice:'))
    newsdata = grabNews(sources[sltsource], 'top', 'PASTE YOUR API KEY HERE')
    print('--------------------------------------------------------------------------------------')
    for news in newsdata['articles']:
        print(str(news['title']).upper())
        print(news['description'])
        print('url-> ', news['url'])
        print('--------------------------------------------------------------------------------------')
        print(' ')
    choice = str(input('enter "0" to leave news'))