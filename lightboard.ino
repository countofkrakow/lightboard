#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define NUM_STRIPS 15
#define NUM_LEDS 73
uint32_t life_matrix[2][NUM_LEDS*NUM_STRIPS];
uint8_t frame, color_nonce;
Adafruit_NeoPixel strips[NUM_STRIPS];
void setup() {
  frame = 0;
  color_nonce = 0;
  for (uint8_t i=0; i < NUM_STRIPS; ++i) {
    strips[i] = Adafruit_NeoPixel(NUM_LEDS, i, NEO_GRB + NEO_KHZ800);
    strips[i].begin();
    strips[i].show();
  }
}

void loop() {
  for (uint8_t i=0; i < NUM_STRIPS; ++i) {
    turnRed(strips[i]);
    delay(500);
  }
}

void turnRed(Adafruit_NeoPixel strip) {
  for (uint8_t i=0; i<NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(255, 0,0));
  }
  strip.show(); // This sends the updated pixel color to the hardware.
}
void shuffle(uint32_t board[NUM_LEDS*NUM_STRIPS]) {
  for (uint32_t i=0; i<NUM_LEDS*NUM_STRIPS; i++) {
    
  }
}

void color(uint16_t pos) {
  uint8_t x = pos % NUM_LEDS;
  uint8_t y = pos / NUM_STRIPS;
  return strips[0].Color(255, 0,0);
}

