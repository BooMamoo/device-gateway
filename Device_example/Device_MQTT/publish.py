import sys
import paho.mqtt.client as mqtt
import time
import datetime

BROKER_PORT = 1884
BROKER_HOST = "127.0.0.1"
KEEPALIVE = 60
TOPIC = 'IoTPlatform/MQTT/Temperature'
num = 0

def on_connect(client, userdata, results):
    print "Connected!!"
    client.subscribe(TOPIC, 0)
    
def on_publish(client, userdata, mid):
    current = datetime.datetime.now()
    print "Message has been already published with number " + str(value) + " @ time : " + str(current)
         
client = mqtt.Client()
client.on_connect =  on_connect
client.on_publish = on_publish

client.connect(BROKER_HOST, BROKER_PORT, KEEPALIVE)
client.loop_start()

while True:
    try :
		value = num
		client.publish(TOPIC, value)
		sys.stdout.flush()
		time.sleep(300)
		num+=1
    except KeyboardInterrupt :
		client.disconnect()
		break
