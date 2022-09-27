import requests
from tqdm import tqdm


url = 'https://karunadu.karnataka.gov.in/hfw/kannada/becdocs/Specialist%202022%20Passed%20out%20Candidate%20Merit%20List.pdf'
print("attempting request....")
r = requests.get(url, stream=True)
print("request success")


with open('matrix.pdf', 'wb') as fd:
    for chunk in tqdm(r.iter_content(2000)):
        fd.write(chunk)