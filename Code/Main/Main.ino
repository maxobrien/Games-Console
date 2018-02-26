/* Include definitions */
#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

//Screen constructor
U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(/*Rotation=*/ U8G2_R0, /*cs=*/ 10, /*dc=*/ 9, /*Reset=*/ 8);



/* ===================================================== */
/* GLOBAL VARIABLE DEFINITIONS */

//Value for which 'screen' we should draw - we should starton the menu by default
int currentScreen = 1;
/* Possilbe Values
    1 = Menu
    2 = Pong
    3 = Breakout
    4 = Settings
*/

//Assigning currentMillis to start at 0
unsigned long currentMillis = 0;

//Button inputs
const int leftBtn = A1;
const int upBtn = A2;
const int rightBtn = A3;
const int downBtn = A0;
const int menuBtn = A4;
const int selectBtn = A5;

//Previous button inputs
int prevLeftBtnState = 0;
int prevUpBtnState = 0;
int prevRightBtnState = 0;
int prevDownBtnState = 0;
int prevMenuBtnState = 0;
int prevSelectBtnState = 0;

//Loading 'apps'
bool menuLoaded = false;
bool pongLoaded = false;
bool breakoutLoaded = false;
bool settingsLoaded = false;

//Game difficulty
int difficulty = 3;
/* Possible Values
    2 = Easy
    3 = Medium
    5 = Hard
*/

int buzzerFreq = 450;

const int randomPin = 7;

const int buzzerPin = 3;

unsigned long previousSelectMillis = 0;

bool playedPowerMelody = false;
bool playedLoseMelody = false;
bool playedWinMelody = false;

/* ===================================================== */

bool breakoutSetup = false;

void setup() {
  //The main line to initialise the display
  u8g2.begin();

  //Set the font for the display, this will be the only font used
  u8g2.setFont(u8g2_font_6x12_tr);

  pinMode(leftBtn, INPUT);
  pinMode(upBtn, INPUT);
  pinMode(rightBtn, INPUT);
  pinMode(downBtn, INPUT);
  pinMode(menuBtn, INPUT);
  pinMode(selectBtn, INPUT);

  pinMode(buzzerPin, OUTPUT);


  
}

void loop() {

  if (playedPowerMelody == false) {
    powerMelody();
  }

  if ((digitalRead(menuBtn) == HIGH) && (prevMenuBtnState != digitalRead(menuBtn))) {
    currentScreen = 1;
  }
  prevMenuBtnState = digitalRead(menuBtn);

  //Storing the current millis so that the various apps can use it
  currentMillis = millis();

  u8g2.firstPage(); //Required line

  switch (currentScreen) {
    case 1: //Main Menu
      do {
        if (menuLoaded == false) {
          loadMenu();
        }
        drawMenu(); //Draw the main menu
        menuButtons(); //Check for button presses in the menu 'screen'
        breakoutSetup = false;

        pongLoaded = false;
        breakoutLoaded = false;
        settingsLoaded = false;
      } while ( u8g2.nextPage() );
      break;

    case 2: //Pong
      do {
        if (pongLoaded == false) {
          loadPong();
        }
        drawPong(); //Draw the pong game
        pongButtons(); //Check the buttons inputs when playing pong

        menuLoaded = false;
        breakoutLoaded = false;
        settingsLoaded = false;
      } while ( u8g2.nextPage() );
      break;

    case 3: //Breakout
      do {
        if (breakoutLoaded == false) {
          loadBreakout();
        }
        //If we want to play breakout and we haven't set up the function yet, then we should. This will only run once per time we want to play.
        if (breakoutSetup == false) {
          setupBreakout(); //Run the setup of breakout once everytime we want to play;
        }
        drawBreakout(); //Draw the main menu
        breakoutButtons(); //Check the buttons inputs when playing breakout

        menuLoaded = false;
        pongLoaded = false;
        settingsLoaded = false;
      } while ( u8g2.nextPage() );
      break;

    case 4: //Settings
      do {
        if (settingsLoaded == false) {
          loadSettings();
        }
        drawSettings();
        settingsButtons();

        menuLoaded = false;
        pongLoaded = false;
        breakoutLoaded = false;
      } while ( u8g2.nextPage() );
      break;

    default:
      //If all else fails, just draw the menu
      do {
        drawMenu(); //Draw the main menu
        menuButtons(); //Check for button presses in the menu 'screen'
        breakoutSetup = false;

        pongLoaded = false;
        breakoutLoaded = false;
        settingsLoaded = false;
      } while ( u8g2.nextPage() );
      break;
  }
}

void powerMelody() {
  tone(buzzerPin, 261.63, 272.727);
  delay(272.727);
  tone(buzzerPin, 440.00, 68.182);
  delay(68.182 + 68.182);
  tone(buzzerPin, 329.63, 136.364);
  delay(68.182 + 136.364);
  tone(buzzerPin, 246.94, 272.727);
  delay(272.727);
  tone(buzzerPin, 261.63, 272.727);
  delay(272.727);
  playedPowerMelody = true;
}

void loseMelody() {
  tone(buzzerPin, 233.08, (136.364 * 3));
  delay((136.364 * 3) + 136.364);
  tone(buzzerPin, 220.00, (136.364 * 3));
  delay((136.364 * 3) + 136.364);
  tone(buzzerPin, 207.65, (136.364 * 3));
  delay((136.364 * 3) + 136.364);
  tone(buzzerPin, 196.00, (545.455 + 272.727));
  delay(545.455 + 272.727);
  playedLoseMelody = true;
}

void winMelody() {
  tone(buzzerPin, 261.63, 272.727);
  delay(272.727);
  tone(buzzerPin, 329.63, 272.727);
  delay(272.727);
  tone(buzzerPin, 392.00, 272.727);
  delay(272.727);
  tone(buzzerPin, 523.25, (136.364 * 3));
  delay(136.364 * 3);
  playedWinMelody = true;
}

