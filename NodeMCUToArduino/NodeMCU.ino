#include <CTBot.h>
CTBot myBot;

String ssid  = "Kos Stay Halal";
String pass  = "ahbokislu";
String token = "5971954379:AAE5s0e0dO1SHAdfSBoGmY85KjchrJ9VS7Y";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);

  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");
}

void loop() {
  TBMessage msg;
  //   put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    Serial.println(data);
    int comma = data.indexOf(',');
    if (comma != -1) {
      float suhu = data.substring(0, comma).toFloat();
      float kelembapan = data.substring(comma + 1).toFloat();
      String cekKondisi = "Suhu : " + String(suhu) + " C.\nKelembapan : " + String(kelembapan) + " %.";

      Serial.println(cekKondisi);
      Serial.println();

      //Kondisi ketika Tegangan dibawah 1 Volt
    
    if (CTBotMessageText == myBot.getNewMessage(msg)) {
      if (msg.text.equalsIgnoreCase("/start")) {                   //Perintah dari telegram ke perangkat
        String reply;
        reply = (String)"Selamat Datang " + msg.sender.username + (String)".\n\n==================================================\n\nBot monitoring tegangan dan arus aki adalah sebuah program yang dirancang untuk mengumpulkan, menganalisis, dan melaporkan data tegangan dan arus aki secara real-time.\n\nBot Telegram ini merupakan Bot Monitoring Tegangan dan Arus (Montegar) pada Aki Baterai Portable AWOS Kategori II.\n\nGunakan perintah /Cek untuk monitoring tegangan dan arus pada Aki Baterai Portable AWOS Kategori II .\n\nGood Luck Brodiii.\n\n Tugas Akhir Andhika INS C.\n\n ==================================================";
        myBot.sendMessage(msg.sender.id, reply);
      }
      else if (msg.text.equalsIgnoreCase("/Cek")) {
        //Perintah dari telegram ke perangkat
        myBot.sendMessage(msg.sender.id, cekKondisi);
        // }
      } 
      else {                                                    // otherwise...
        String balas;
        balas = "Perintah yang dimasukkan salah. \nGunakan perintah 'Cek Kondisi'.";
        myBot.sendMessage(msg.sender.id, balas);
      }
    }
    if (suhu > 31) {
        String darurat;
        darurat = (String)"PERINGATAN!!!\nStatus : Suhu terlalu panas. \nSuhu : " + suhu + (String)" C.";
        myBot.sendMessage(5379077205, darurat);
        Serial.println("pesan darurat terkirim");
        delay(5000);
      }
  }
}
delay(1000);
}
