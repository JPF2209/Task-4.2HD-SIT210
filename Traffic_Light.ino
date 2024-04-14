
#include <Arduino_LSM6DS3.h>
#include <Firebase_Arduino_WiFiNINA.h>

#define FIREBASE_HOST "test2-f11da.firebaseio.com"
#define FIREBASE_AUTH "gC6z1RGoGyRDO5a5glIzaWoUXMpBtb4T5Z9pKJsb"
#define WIFI_SSID "TelstraE78C95"
#define WIFI_PASSWORD "mnnu9vh7x7"

// WiFiClient client;
FirebaseData firebaseData;

bool val = "";

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println();

  Serial.print("Initialize IMU sensor...");
  if (!IMU.begin()) {
    Serial.println(" failed!");
    while (1);
  }

  Serial.print("Connecting to WiFi...");
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) {
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(".");
    delay(300);
  }
  Serial.print(" IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  startFirebase();
}

void loop()
{
  if (Firebase.getString(firebaseData, "/light/blue")){
    Serial.println("Yes");
  }
  Serial.println(" Wow ");
  delay(2500);
}

void startFirebase(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);
}
