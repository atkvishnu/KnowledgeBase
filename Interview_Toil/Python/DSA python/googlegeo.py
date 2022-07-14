import urllib.request, urllib.parse, urllib.error
import json

serviceurl = 'https://api.mapbox.com/datasets/v1/nerdyninjahugs4u/?access_token=pk.eyJ1IjoibmVyZHluaW5qYWh1Z3M0dSIsImEiOiJjazFscnFqdWgwODc5M2hwY3NnNHN3dmtvIn0.2rd128ZVlVXda2grJSBzwg'

while True:
    address = input('Enter Location: ')
    if len(address) < 1: break

    url = serviceurl + urllib.parse.urlencode(
        {'address': address})

    print('Retreiving', url)
    uh = urllib.request.urlopen(url)
    data = uh.read().decode()
    print('Retreived', len(data), 'characters')

    try:
        js = json.loads(data)
    except:
        js = None

    if not js or 'status' not in js or js['status'] != 'OK':
        print('====Failure to Retrieve====')
        print(data)
        continue

print(json.dumps(js,indent=4))

lat = js["results"][0]["geometry"]["location"]["lat"]
lng = js["results"][0]["geometry"]["location"]["lng"]
print('lat', lat, 'lng', lng)
location = js['results'][0]['formatted_address']
print(location)