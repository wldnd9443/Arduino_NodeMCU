# Visualize_Weatherinfo_Arduino
> 아두이노의 NodeMCU를 활용하여 실시간으로 환경에 대한 데이터(온도, 조도, 압력)를 얻고 시각화 합니다.


## 목표
NodeMCU에 센서를 연결하여 단자 주위의 실시간 환경 데이터를 수집하고 그 정보를 가져와 차트, 막대 그래프, 게이지로 다양하게 시각화 하여 웹 화면에 출력합니다.


![intro2](https://user-images.githubusercontent.com/44831709/131536151-d6d4d963-7be3-4e82-82e7-a2725a4f3de9.png)
![intro3](https://user-images.githubusercontent.com/44831709/131536155-8e6a4d49-c1b0-4e30-8093-4fddb033ab62.png)

## 필요한 기구

NodeMCU(ESP8266), 점퍼선, BH1750(조도센서), BMP180(온도, 압력센서), Bread Board, USB Cable

## 회로도

* BMP180: SDA-D1, SCL-D2, GND-(-), VIN(+)
* BH1750: SDA-D1, SCL-D2, GND-(-), VIN(+)
![electro_circuit](https://user-images.githubusercontent.com/44831709/131541620-fd64bae1-3730-4afa-861d-d32ecd3ea286.png)


## 사용 방법

첨부된 PPT 참고 바랍니다.



## 참고

* Random Nerd Tutorials: ESP8266 Web Server using SPIFFS (SPI Flash File System) – NodeMCU (SPIFFS & BME280 온도 습도 압력 UI)
  https://randomnerdtutorials.com/esp8266-web-server-spiffs-nodemcu/
* Random Nerd Tutorials: Install ESP32 Filesystem Uploader in Arduino IDE (SPIFFS 사용 시 필요한 라이브러리 및 시리얼 모니터로 텍스트 문서 띄우기)
  https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/
* Random nerd Tutorials esp8266 webserverhttps://randomnerdtutorials.com/esp8266-web-server/
* BMP library http://www.esp8266learning.com/wemos-mini-bmp180-sensor-example.php 
* BH1750 library https://github.com/claws/BH1750
* Google chart (구글 차트 모음) https://developers.google.com/chart
* Google Gauge (게이지)
https://developers.google.com/chart/interactive/docs/gallery/gauge
* Google Pie Chart https://developers.google.com/chart/interactive/docs/gallery/piechart
* Google Bar Chart https://developers.google.com/chart/interactive/docs/gallery/barchart
* Real Time Chart https://randomnerdtutorials.com/esp32-esp8266-plot-chart-web-server/


