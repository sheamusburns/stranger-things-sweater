#include <Adafruit_NeoPixel.h>

class NeoPixel_Letter {
    
  public:
    int location;
    NeoPixel_Letter(int);
    void set_location(int);
};

NeoPixel_Letter::NeoPixel_Letter(int num) {
	location = num;
}

void NeoPixel_Letter::set_location(int num) {
  location = num;
}

NeoPixel_Letter a(18), b(19), c(20), d(21), e(22), f(23), g(24), h(25),
i(17), j(16), k(15), l(14), m(13), n(12), o(11), p(10), q(9),
r(0), s(1), t(2), u(3), v(4), w(5), x(6), y(7), z(8);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(26, PIN, NEO_GRB + NEO_KHZ800);



#define PIN 12
#define Pixels 26

float redStates[Pixels];
float blueStates[Pixels];
float greenStates[Pixels];
float fadeRate = 0.96;
uint32_t maxBrightness = 40;



void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  colorWipe(Wheel(30), 100);
  colorWipe(Wheel(random(255)), 100);
//  //colorWipe((0,0,0), 100);
//  upsideDown();
  
}

void endMessage() {
  colorWipe(Wheel(random(255)), 70);
  clearStrip();
}

void waffles(){
  printLetter(w);
  printLetter(a);
  printLetter(f);
  printLetter(f);
  printLetter(l);
  printLetter(e);
  printLetter(s);
}


void kevin(){
  printLetter(k);
  printLetter(e);
  printLetter(v);
  printLetter(i);
  printLetter(i);
  printLetter(i);
  printLetter(n);
}

void tooMuchSauce(){
  printLetter(t);
  printLetter(o);
  printLetter(o);
  pause();
  printLetter(m);
  printLetter(u);
  printLetter(c);
  printLetter(h);
  pause();
  printLetter(s);
  printLetter(a);
  printLetter(u);
  printLetter(c);
  printLetter(e);
}


void aLittleTipsy(){
  printLetter(i);
  pause();
  printLetter(i);
  printLetter(s);
  pause();
  printLetter(a);
  pause();
  printLetter(l);
  printLetter(i);
  printLetter(t);
  printLetter(t);
  printLetter(l);
  printLetter(e);
  pause();
  printLetter(t);
  printLetter(i);
  printLetter(p);
  printLetter(s);
  printLetter(y);
  pause();
}

void eleven() {
  printLetter(e);
  printLetter(l);
  printLetter(e);
  printLetter(v);
  printLetter(e);
  printLetter(n);
}

void helpMe(){
  printLetter(h);
  printLetter(e);
  printLetter(l);
  printLetter(p);
  pause();
  printLetter(m);
  printLetter(e);
  pause();
}


void sorryImLate(){
    printLetter(s);
    printLetter(o);
    printLetter(r);
    printLetter(r);
    printLetter(y);
    pause();
    printLetter(i);
    printLetter(m);
    pause();
    printLetter(l);
    printLetter(a);
    printLetter(t);
    printLetter(e);
    pause();
    printLetter(i);
    pause();
    printLetter(d);
    printLetter(i);
    printLetter(d);
    printLetter(n);
    printLetter(t);
    pause();
    printLetter(w);
    printLetter(a);
    printLetter(n);
    printLetter(t);
    pause();
    printLetter(t);
    printLetter(o);
    pause();
    printLetter(c);
    printLetter(o);
    printLetter(m);
    printLetter(e);
    pause();
}

void happyNewYear() {
    printLetter(h);
    printLetter(a);
    printLetter(p);
    printLetter(p);
    printLetter(y);
    pause();
    printLetter(n);
    printLetter(e);
    printLetter(w);
    pause();
    printLetter(y);
    printLetter(e);
    printLetter(a);
    printLetter(r);
    pause();
}

void upsideDown() {
    printLetter(u);
    printLetter(p);
    printLetter(s);
    printLetter(i);
    printLetter(d);
    printLetter(e);
    pause();
    printLetter(d);
    printLetter(o);
    printLetter(w);
    printLetter(n);
    pause();
}

void pause() {
  delay(1000);
}

void fadeOn(int pixel, uint32_t color, int wait) {
  uint32_t del;
  for (int i=0; i<maxBrightness; i++) {
    del = 40 * cos(i/(10*3.14156));
    Serial.println(del);
    strip.setPixelColor(pixel, color);
    strip.setBrightness(i);
    strip.show();
    delay(del);
  }
}

void fadeOff(int pixel, uint32_t color, int wait) {
  uint32_t del;
  for (int i=maxBrightness; i>=0; i--) {
    del = 40 * cos(i/(10*3.14156));
    Serial.println(del);
    strip.setPixelColor(pixel, color);
    strip.setBrightness(i);
    strip.show();
    delay(del);
  }
}

void breathe(int pixel, int wait) {
  uint32_t c = Wheel(random(255));
  fadeOn(pixel,c, wait);
  fadeOff(pixel, c, wait);
}


void colorWipe(uint32_t c, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.setBrightness(40);
    strip.show();
    delay(wait);
  }
}

void printLetter(NeoPixel_Letter letter) {
  breathe(letter.location, 30);
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}