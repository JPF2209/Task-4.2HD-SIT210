#include <Firebase_Arduino_WiFiNINA.h>

#define FIREBASE_HOST "FireHost"
#define FIREBASE_AUTH "FireAuth"
#define WIFI_SSID "WiFi SSID"
#define WIFI_PASSWORD "WiFi PASS"

FirebaseData firebaseData;

int blueLED = 2;
int greenLED = 4;
int redLED = 6;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

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
    String blue = firebaseData.stringData();
    if (blue == "on")
    {
      digitalWrite(blueLED, HIGH);
    }
    else
    {
      digitalWrite(blueLED, LOW);
    }
  }
  if (Firebase.getString(firebaseData, "/light/green")){
    String green = firebaseData.stringData();
    if (green == "on")
    {
      digitalWrite(greenLED, HIGH);
    }
    else
    {
      digitalWrite(greenLED, LOW);
    }
  }
  if (Firebase.getString(firebaseData, "/light/red")){
    String red = firebaseData.stringData();
    if (red == "on")
    {
      digitalWrite(redLED, HIGH);
    }
    else
    {
      digitalWrite(redLED, LOW);
    }
  }
}

void startFirebase(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);
}
