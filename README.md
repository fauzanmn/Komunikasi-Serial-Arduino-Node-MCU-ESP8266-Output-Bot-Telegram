# Komunikasi Serial Arduino Node MCU ESP8266 Output Bot Telegram
Menjelaskan tentang bagaimana cara Komunikasi Serial antara Arduino dengan Node MCU ESP8266 dengan output ditampilkan pada Bot Telegram (Output dapat ditampilkan pada platform IoT yang lain, seperti Thingspeak, Blynk, Thinker.io dsb). 

Assalamualaikum Warahmatullah Wabarakatu
Alhamdulillah masih diberikan umur dan kesempatan untuk berbagi ilmu.

Step by step :
1. Membuat rangkaian monitoring suhu dan kelembapan menggunakan sensor DHT 11 & mikrokontroler Arduino Mega
2. Membuat rangkaian untuk menghubungkan antara Arduino Mega dengan Node MCU ESP8266 menggunakan Sistem Komunikasi Serial
3. Menghubungkan Node MCU ESP8266 dengan Bot Telegram 

# Rangkaian Monitoring Suhu dan Kelembapan
![dht_mega](https://github.com/fauzanmn/Komunikasi-Serial-Arduino-Node-MCU-ESP8266-Output-Bot-Telegram/assets/100438762/120eff92-39d2-4cbd-8eeb-000fbdedcc28)

- Upload Program arduino : ArduinoToNodeMCU.ino

- Tampilan Serial Monitor
![SERMON DHT](https://github.com/fauzanmn/Komunikasi-Serial-Arduino-Node-MCU-ESP8266-Output-Bot-Telegram/assets/100438762/a68068da-3c2c-4339-88ff-47c759880147)
#72.00 = nilai kelembapan
#31.40 = nilai suhu
Data tersebut yang nantinya akan kita parsing dan ditampilkan melalui Serial Mpnitor Node MCU ESP8266

# Rangkaian Komunikasi Serial Arduino Mega ke Node MCU ESP8266

