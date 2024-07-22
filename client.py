from time import sleep
import requests
import sys

if __name__ == "__main__":

    sleeptime = float(sys.argv[1])
    port = str(sys.argv[2])
    url = 'http://117.16.143.43:' + port + '/predict?source=https://raw.githubusercontent.com/ultralytics/ultralytics/main/ultralytics/assets/zidane.jpg'
  
    for i in range(1000):
        sleep(sleeptime)
        resp = requests.get(url, verify=False)
