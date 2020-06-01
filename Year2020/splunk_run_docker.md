Run Docker command:
docker run -p 8000:8000 -e 'SPLUNK_START_ARGS=--accept-license' -e 'SPLUNK_PASSWORD=password' store/splunk/splunk:7.3 start --name local_splunk

Goto localhost:8000
click on the license Change it to free license

docker start <image_name>
