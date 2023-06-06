
//*************** INISIALISASI LIBRARY YANG DIGUNAKAN ***************// 
#include "DHT.h" // Library DHT
#define DHTPIN 7 // Hubungkan pin Data Sensor DHT ke Pin 7 Arduino
#define DHTTYPE DHT11 // Definisikan Tipe Sensor DHT yang digunakan; ex : DHT11

DHT dht(DHTPIN, DHTTYPE); // Membuat objek variabel

float h, t; // Membuat tipe data variabel; ex : float (bilangan desimal)

void setup() {
  
  Serial.begin(9600); // Atur baud rate Serial Monitor yang digunakan; ex : baud rate 9600
  
  dht.begin(); // Menjalankan library DHT
}

void loop() {

  h = dht.readHumidity(); // Sensor Membaca Kelembapan ( % )
  t = dht.readTemperature(); // Sensor Membaca Suhu ( °C )
  Serial.print(h); // Menampilkan nilai Kelembapan di Serial Monitor
  Serial.print(","); // Menampilkan simbol koma (,) sebagai pemisah antara data sensor
  Serial.println(t); // Menampilkan nilai Suhu di Serial Monitor
  delay(1000); // delay setiap 1000 milisekon (1 detik)
}
