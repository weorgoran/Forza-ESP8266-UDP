#include "ssid_creds.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include "ForzaData.h"
#include <FastLED.h>

#define DATA_PIN 25
#define NUM_LEDS 5

CRGB ledColourMap[NUM_LEDS] = {CRGB::Green, CRGB::Green, CRGB::Yellow, CRGB::Orange, CRGB::Red};
CRGB leds[NUM_LEDS];

const uint32_t UDP_RX_PACKET_SIZE = sizeof(ForzaData_t);
unsigned int localPort = 2808;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_RX_PACKET_SIZE + 1]; //buffer to hold incoming packet,
ForzaData_t *forzaData = (ForzaData_t *)packetBuffer;
WiFiUDP Udp;

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Udp.begin(localPort);

  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    // read the packet into packetBufffer
	Udp.read(packetBuffer, UDP_RX_PACKET_SIZE);
	
    // float mph = forzaData->Speed * 2.237;
    
    uint8_t numLEDs = (uint8_t)map(forzaData->CurrentEngineRpm, 0, forzaData->EngineMaxRpm, 0 ,5);

    if(numLEDs <= NUM_LEDS){     
      for(uint8_t led = 0; led < NUM_LEDS; led++) {
        if(forzaData->IsRaceOn && ((led) <= numLEDs) ) {
        leds[led] = ledColourMap[led];
        } else {
        leds[led] = CRGB::Black;        
        }
      }
      FastLED.show();
    }
  }

}
