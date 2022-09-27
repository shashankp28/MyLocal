import multiprocessing
import time
import requests

def requester(url, response):
    response = requests.get(url=url)
    response = response.text

if __name__ == '__main__':
    url = "https://unifiedportal-mem.epfindia.gov.in/memberinterface/"
    while True:
        response = None
        p = multiprocessing.Process(target=requester, name="Foo", args=(url, response))
        p.start()
        time.sleep(0.1)
        p.terminate()
        p.join()
        print(response)