import random
from time import sleep

while True:
    sleep(5)
    temperature = random.randrange(0, 200, 3)
    print("\nCurrent Temperature  =",temperature,end="°C\n")
    humidity = random.randrange(0, 100, 6)
    print("Current Humidity     =",humidity,end="%\n\n")
    if temperature >=38:
        print("Temperature >> High - Alarm ON")
    if humidity >= 75:
        print("Humidity    >> High - Alarm ON")
    if temperature <=38:
        print("Temperature >> Low  - Alarm OFF")
    if humidity <= 75:
        print("Humidity    >> Low  - Alarm OFF")
