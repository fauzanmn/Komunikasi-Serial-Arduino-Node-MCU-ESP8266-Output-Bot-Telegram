
//https://github.com/fauzanmn/Komunikasi-Serial-Arduino-Node-MCU-ESP8266-Output-Bot-Telegram

//*************** INISIALISASI LIBRARY YANG DIGUNAKAN ***************//
#include <ESP8266WiFi.h> // Library ESP8266WiFi untuk Koneksi ke Bot Telegram
#include <CTBot.h> // Library CTBot untuk Koneksi ke Bot Telegram
CTBot myBot; // Membuat objek variabel

String ssid  = "namaWifi"; // Nama Wifi
String pass  = "passWifi"; // Password Wifi
String token = "tokenBotTelegram"; // Bot Telegram


void setup() {

  Serial.begin(9600); // Atur baud rate Serial Monitor yang digunakan; ex : baud rate 9600

  myBot.wifiConnect(ssid, pass); // Menghubungkan Node MCU ESP8266 dengan Wifi

  while (WiFi.status() != WL_CONNECTED) { // Memeriksa status koneksi antara Node MCU ESP8266 dengan WiFi
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Koneksi WiFi berhasil");
  Serial.print("Alamat IP: ");
  Serial.println(WiFi.localIP()); // Menampilkan alamat IP Lokal

  myBot.setTelegramToken(token); // Menghubungkan Node MCU ESP8266 dengan Bot Telegram melalui token bot

  if (myBot.testConnection()) // Memeriksa status koneksi antara Node MCU ESP8266 dengan Bot Telegram
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");
}

void loop() {

  TBMessage msg; // Membuat Objek Variabel Kirim Pesan ke Bot Telegram


  //***************************** Menunggu Data dari Sensor yang masuk ke Serial Monitor *****************************//
  if (Serial.available() > 0) {
    Serial.println("Data dari Arduino Mega :");
    String data = Serial.readStringUntil('\n'); // Tampung nilai yang masuk ke Serial Monitor ke dalam variabel 'data'
    Serial.println(data); // Menampilkan data dari sensor yang dikirim melalui Arduino ke Serial Monitor Node MCU ESP8266
    int comma = data.indexOf(','); // Delimiter, pemisah antara data sensor

    //*************************** Parsing Data Start ***************************//
    if (comma != -1) {
      float suhu = data.substring(0, comma).toFloat(); // Masukkan data pertama ke dalam variabel suhu
      float kelembapan = data.substring(comma + 1).toFloat(); // Masukkan data kedua ke dalam variabel kelembapan
      String cekKondisi = "Suhu : " + String(suhu) + " C.\nKelembapan : " + String(kelembapan) + " %."; // Masukkan semua data ke dalam variabel cekKondisi

      Serial.println(cekKondisi); // Tampilkan isi di dalam variabel cekKondisi ke Serial Monitor
      Serial.println();

      //*************************** Parsing Data End ***************************//


      //*************************** Proses Terima, Balas, dan Kirim Pesan Start ***************************//

      if (CTBotMessageText == myBot.getNewMessage(msg)) {
        if (msg.text.equalsIgnoreCase("/start")) {  //Terima pesan dengan perintah /start dari user
          String reply;
          // **** Membuat format balas pesan /start ****//
          reply = (String)"Selamat Datang " + msg.sender.username + (String)".\n\n==================================================\n\nBot monitoring Suhu dan Kelembapan adalah sebuah program yang dirancang untuk monitoring suhu dan kelembapan secara real-time.\n\n\nGunakan perintah /Cek untuk monitoring suhu dan kelembapan.\\n\n  ==================================================";
          myBot.sendMessage(msg.sender.id, reply); //Kirim pesan ke Bot Telegram
        }
        else if (msg.text.equalsIgnoreCase("/Cek")) { //Terima pesan dengan perintah /start dari user
          //Perintah dari telegram ke perangkat
          myBot.sendMessage(msg.sender.id, cekKondisi); //Kirim pesan ke Bot Telegram
        }
      }
      else {
        // **** Membuat format balas pesan diluar perintah yang telah disediakan ****//
        String balas;
        balas = "Perintah yang dimasukkan salah. \nGunakan perintah '/Cek'.";
        myBot.sendMessage(msg.sender.id, balas); //Kirim pesan ke Bot Telegram
      }
    }
    // **** Membuat format kirim notifikasi ****//
    if (suhu > 31) {
      String darurat;
      darurat = (String)"PERINGATAN!!!\nStatus : Suhu terlalu panas. \nSuhu : " + suhu + (String)" C.";
      myBot.sendMessage(5379077205, darurat); // 5379077205 adalah ID dari masing-masing user telegram, ubah sesuai ID anda
      Serial.println("pesan darurat terkirim"); // Tampilkan keterangan pesan darurat telah dikirim ke Serial Monitor
      delay(5000);
    }
  }
}
delay(1000);
}
