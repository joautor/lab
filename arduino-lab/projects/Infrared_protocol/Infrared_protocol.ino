#include <IRremote.h>  // Infrared remote header file

int RECV_PIN = 8; // Output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;

// For light bulb
#define LED 13
bool bLightON;
bool bStartLoop = false;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Starting...");

  pinMode(LED, OUTPUT);
  bLightON = false;
  Serial.println("Setup done");
}

void loop() {
  if (!bStartLoop) {
    Serial.println("loop started");
    bStartLoop = true;
  }
  //if (irrecv.decode(&results)) {  // 0: no data ready, 1: data ready
  if (irrecv.decode()) {
    //int resultValue = results.value;
    int resultValue = results.decodedIRData;
    Serial.print("Code: ");
    Serial.println(resultValue);
    Serial.println(" ");
    bLightON = (!bLightON);
    irrecv.resume(); // Restart the ISR state machine and Receive the next value
  }

  digitalWrite(LED, bLightON ? HIGH : LOW);
}
