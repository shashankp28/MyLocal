import urllib.request
import urllib.parse

n = int(input())
print(n)
print(end='')
url = 'https://httpbin.org/'
f = urllib.request.urlopen(url)