#include <Arduino.h>
#include <BluetoothSerial.h>
#include <WheelieTooth.h>

BluetoothSerial SerialBT;

WheelieTooth::WheelieTooth() {
}

String WheelieTooth::read() {
  if(control.messageReady) {
    String data = control.msgBuffer;
    control.messageReady = false;
    return data;
  }

  return String();
}

void WheelieTooth::write(String cmd) {
    SerialBT.print(cmd); 
}


void WheelieTooth::onBluetoothData(const uint8_t *buffer, size_t size) {

  for (size_t i = 0; i < size; i++) {
    char c = (char)buffer[i];

    // If a message is already waiting for the main loop, ignore new bytes to prevent overwrite
    if (control.messageReady) continue; 

    if (c == START_MARKER) {
      control.msgIdx = 0;          // Sync point: Always reset index to start of buffer
      control.isReceiving = true;  // Lock into receiving state
    } 
    else if (control.isReceiving) {
      if (c == END_MARKER) {
        control.msgBuffer[control.msgIdx] = '\0'; // Null-terminate the string
        control.messageReady = true;      // Flag the main loop that a clean packet is ready
        control.isReceiving = false;      // Reset state machine
      } 
      else {
        if (control.msgIdx < MAX_MSG_LEN - 1) {
          control.msgBuffer[control.msgIdx++] = c; // Store data byte
        } else {
          control.isReceiving = false;     // Buffer overflow protection: discard packet
        }
      }
    }
  }
}

void WheelieTooth::begin() {
  SerialBT.begin("ESP32_Synced_Receiver");
  SerialBT.onData([](const uint8_t *buffer, size_t size) { WheelieTooth::onBluetoothData(buffer, size); }); 
}


