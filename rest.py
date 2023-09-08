import requests,json
movie = input()
dates = input() #use a datepicker

dictionary = {"movie": movie,
              "date": dates}

urls = "some website"
headers = {"Content-Type": "application/json"}
response = requests.post(urls, data=json.dumps(dictionary), headers=headers)

response.json() # expected in json with 
# {"movie availability: none"}
if response.status_code != 200:
    print("Some problem")
elif response.json() == "none":
    print("No ticket")
else:
    print("Lottery")
    

