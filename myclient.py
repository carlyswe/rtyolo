from time import sleep
import requests
import sys

if __name__ == "__main__":

    sleeptime = int(sys.argv[1])

    sleep(15)
    
    for i in range(10000):
        #call our command
        sleep(sleeptime)
        #resp = requests.get('http://0.0.0.0:5000/predict?source=https://www.youtube.com/watch?v=MNn9qKG2UFI', verify=False)
        resp = requests.get('http://0.0.0.0:5000/predict?source=https://raw.githubusercontent.com/ultralytics/ultralytics/main/ultralytics/assets/zidane.jpg', verify=False)
#we could provide it how long to sleep and how many iterations as command line args somewhere 
