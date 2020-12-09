#include "main.h"
#include "blink.h"
#include "WiFiScan.h"

ThreadController allTask;

void setup() {
	Serial.begin(115200);
	blinkSetup();
	wifiScanSetup();
}

void loop() {
	allTask.run();
}
