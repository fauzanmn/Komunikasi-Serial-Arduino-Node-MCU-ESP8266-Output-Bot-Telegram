# Komunikasi Serial Arduino Node MCU ESP8266 Output Platform IoT
Menjelaskan tentang bagaimana cara Komunikasi Serial antara Arduino dengan Node MCU ESP8266 dengan output ditampilkan pada Platform IoT (Output dapat ditampilkan pada platform IoT seperti Bot Telegram, Thingspeak, Blynk, Thinker.io dsb). 

Assalamualaikum Warahmatullah Wabarakatu.
Alhamdulillah masih diberikan umur dan kesempatan untuk berbagi ilmu.

Step by step :
1. Membuat rangkaian monitoring suhu dan kelembapan menggunakan sensor DHT 11 & mikrokontroler Arduino Mega
2. Membuat rangkaian untuk menghubungkan antara Arduino Mega dengan Node MCU ESP8266 menggunakan Sistem Komunikasi Serial
3. Menghubungkan Node MCU ESP8266 dengan Bot Telegram 

Komponen yang digunakan untuk contoh pengujian Komunikasi Serial ini antara lain :
  1. Mikrokontroler Arduino Mega 
  2. NODE MCU ESP8266
  3. Sensor DHT 11
  4. Bot Telegram

# Rangkaian Monitoring Suhu dan Kelembapan
![dht_mega](https://github.com/fauzanmn/Komunikasi-Serial-Arduino-Node-MCU-ESP8266-Output-Bot-Telegram/assets/100438762/120eff92-39d2-4cbd-8eeb-000fbdedcc28)

- Upload Program arduino : ArduinoToNodeMCU.ino

- Tampilan Serial Monitor Arduino Mega

![SERMON DHT](https://github.com/fauzanmn/Komunikasi-Serial-Arduino-Node-MCU-ESP8266-Output-Bot-Telegram/assets/100438762/a68068da-3c2c-4339-88ff-47c759880147)

72.00 = nilai kelembapan.
31.40 = nilai suhu.

Data tersebut yang nantinya akan kita parsing dan ditampilkan melalui Serial Mpnitor Node MCU ESP8266

# Rangkaian Komunikasi Serial Arduino Mega ke Node MCU ESP8266
![komser](https://github.com/fauzanmn/Komunikasi-Serial-Arduino-Node-MCU-ESP8266-Output-Platform-IoT/assets/100438762/31639290-0137-4f3f-8abb-4b43686a3a77)

Catatan :
  1. Buka Arduino IDE Baru (bukan New File).
  2. Ubah Board & Port sesuai dengan Node MCU ESP8266.
  3. Ketika upload program ke Node MCU ESP8266, lepas pin RX Node MCU ESP8266 yang terhubung ke pin TX Arduino Mega.
  4. Ketika proses upload program selesai, hubungkan kembali pin RX Node MCU ESP8266 yang terhubung ke pin TX Arduino Mega.
  5. Gunakan library CTBot versi 2.1.10
  6. Gunakan library ArduinoJson versi 6.15.0

- Upload Program Node MCU ESP8266 : NodeMCUToArduino.ino

- Tampilan Serial Monitor Node MCU ESP8266

![sermon komser](https://github.com/fauzanmn/Komunikasi-Serial-Arduino-Node-MCU-ESP8266-Output-Platform-IoT/assets/100438762/579a7542-ab52-4ac4-9479-b79c0424bf0c)



