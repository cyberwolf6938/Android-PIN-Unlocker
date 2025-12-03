# Android-PIN-Unlocker

Arduino-based Android lock-screen PIN testing tool designed **for educational and research purposes only**.  
This project uses **HID-compatible Arduino boards** (like Arduino Pro Micro) to simulate fast PIN entry attempts on Android devices.

⚠️ **This project is ONLY for security research, device-recovery testing, and educational demonstrations. Never use it on devices you do not own or have permission to test.**

---

## 📌 Features

- 4-digit PIN brute-force sketch
- 6-digit PIN brute-force sketch
- HID keyboard emulation for automated PIN entry  
- Works with boards that support **USB HID** (Arduino Pro Micro, Leonardo, Beetle, etc.)
- Simple setup & easy to customize PIN entry speed

---

## 🔧 Hardware Requirements

### ✔️ Supported HID Boards
These boards support native USB HID, so they work perfectly:

| Board Name | Supported | Notes |
|-----------|-----------|-------|
| **Arduino Pro Micro** | ✅ | Recommended |
| **Arduino Leonardo** | ✅ | HID supported |
| **Beetle ATmega32u4** | ✅ | Mini Pro Micro clone |
| **ATmega32U4 Dev Boards** | ✅ | Any 32u4 HID board works |

### ❌ Unsupported Boards
These boards **cannot emulate a keyboard**, so they *do not* work:

| Board Name | Supported | Reason |
|-----------|-----------|---------|
| Arduino Uno | ❌ | No native HID |
| Arduino Nano | ❌ | No HID support |
| Arduino Mega | ❌ | No HID |
| ESP8266 / ESP32 (classic) | ❌ | Keyboard emulator unstable/not native |
| STM32 Blue Pill | ❌ | HID requires custom patches |

---

## 🛠️ Install Arduino IDE

1. Download Arduino IDE from the official website:  
   [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

2. Install normally (Windows / macOS / Linux supported).

3. Open the IDE and go to:  
   **Tools → Board → Arduino AVR Boards → Arduino Leonardo / Pro Micro**

4. Install required board files if prompted.

---

## 🧩 Setting Up Arduino Pro Micro in Arduino IDE

1. Connect your **Arduino Pro Micro** using a USB data cable.  
2. In Arduino IDE:


3. Open one of the code files:
- [`4-Digit-PIN.ino`](4-Digit-PIN.ino) 
- [`6-digit-pin.ino`](6-Digit-PIN.ino)

4. Click **Upload**.

If Pro Micro disconnects during programming, double-tap the reset button to enter **bootloader mode**.

---

## ▶️ How to Use

### 1. Prepare the Android Device
- Enable lock screen with PIN  
- Ensure screen is ON  
- Pattern or fingerprint must be disabled  
- Increase screen timeout if needed

### 2. Connect the Arduino
- Plug Arduino into OTG cable  
- Connect OTG cable to Android phone

### 3. Start Testing
Once you upload the code, the Arduino will automatically:

- Send PIN digits like a keyboard  
- Hit ENTER after each attempt  
- Move to the next PIN

### ⚠️ Important
Newer Android security patches block brute-force attempts by adding time delays or lockouts.  
This tool is mainly for **old devices**, **educational demos**, and **lab testing**.

---

## 🎥 Demo Video
Watch these videos:

*([4-Digit-PIN](https://drive.google.com/file/d/1YSimRdjg3kdy9Wn76U0cXvBQEsnFTT8x/view?usp=sharing))*

*([6-Digit-PIN](https://drive.google.com/file/d/1Do9xCyGujeaJZcqiVsGPnGvGqISrSeuF/view?usp=sharing))*

---

## 📝 Disclaimer

This project is intended **ONLY for:**

- Personal device recovery  
- Security research  
- Educational/University demonstrations  
- Testing lock-screen security mechanisms  

**Do NOT use this tool on any device you do not own or have explicit permission to test.  
The author is not responsible for misuse.**

## created by Cyber Wolf ##
