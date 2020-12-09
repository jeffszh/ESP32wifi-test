#include "blink.h"
#include "main.h"

// constexpr int LED_BUILTIN = 2;

static void blinkLoop() {
	static int x = 0;
	switch (x) {
	case 0:
	case 2:
	case 4:
		digitalWrite(LED_BUILTIN, HIGH);
		break;
	case 1:
	case 3:
	case 5:
		digitalWrite(LED_BUILTIN, LOW);
		break;
	// case 6:
	// 	Serial.printf("很好123！！\n");
	// 	break;
	default:
		break;
	}
	x++;
	if (x >= 10) {
		x = 0;
	}
}

void blinkSetup() {
	pinMode(LED_BUILTIN, OUTPUT);
	static Thread blinkThread;
	blinkThread.enabled = true;
	blinkThread.setInterval(200);
	blinkThread.onRun(blinkLoop);
	allTask.add(&blinkThread);
}
