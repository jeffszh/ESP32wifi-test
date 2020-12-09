#include <WiFi.h>

#include "WiFiScan.h"
#include "main.h"

static void wifiScanLoop() {
	Serial.println("扫描WiFi……");
	int n = WiFi.scanNetworks();
	if (n <= 0) {
		Serial.println("搜索不到任何WiFi网络。");
		return;
	}
	for (int i = 0; i < n; i++) {
		String id = WiFi.SSID(i);
		int rssi = WiFi.RSSI(i);
		bool encrypted = WiFi.encryptionType(i) != WIFI_AUTH_OPEN;
		Serial.print(id);
		Serial.printf(" - %d - ", rssi);
		Serial.println(encrypted);
	}
	Serial.println("============================");
}

void wifiScanSetup() {
	WiFi.disconnect();
	WiFi.mode(WIFI_STA);
	Serial.println("WiFi初始化完成。");

	static Thread wifiScanThread;
	wifiScanThread.enabled = true;
	wifiScanThread.setInterval(5000);
	wifiScanThread.onRun(wifiScanLoop);
	allTask.add(&wifiScanThread);
}
