/* ===================================================== */
/* MENU DEFINITIONS */

const char menuTitle[] = "Main Menu"; //Menu title text

const int menuItems = 2; //Number of menu items - includes 0

/* Select Box */
const int selectBoxPosY = 18; //Y pos for highlight box
const int selectBoxHeight = 12; //Height of the highlight box

int currentMenuItem = 0; //Keep track of currently selected item - start at first

/* ===================================================== */

void loadMenu() {
  currentMenuItem = 0;
  menuLoaded = true;

  playedLoseMelody = false;
  playedWinMelody = false;
}

void drawMenu() {
  u8g2.drawStr((64 - (u8g2.getStrWidth(menuTitle) / 2)), 12, menuTitle); //Write out title text
  u8g2.drawHLine(0, 15, 128); //Draw line under title

  u8g2.setFontMode(1); //Transparent font mode
  u8g2.setDrawColor(1); //Box fill colour

  //Draw out the hightlight box
  u8g2.drawBox(0, (selectBoxPosY + (currentMenuItem * selectBoxHeight)), 128, selectBoxHeight);

  //Give the text XOR colour mode - the box being over the text will change it's colour
  u8g2.setDrawColor(2);

  //Itterate through number of items we have and then print out text for every value
  for (int i = 0; i <= menuItems; i++) {
    switch (i) {
      case 0: //Pong
        u8g2.drawStr(2, (15 + ((i + 1) * 12)), "Pong");
        break;

      case 1: //Breakout
        u8g2.drawStr(2, (15 + ((i + 1) * 12)), "Breakout");
        break;

      case 2: //Settings
        u8g2.drawStr(2, (15 + ((i + 1) * 12)), "Settings");
        break;

      default:
        break;
    }
  }
}

void menuButtons() {
  //Check to see if we are on the menu screen. If we are then we want to check the value of the buttons
  if (currentScreen == 1) {

    //Checks to see if the differnt inputs have been pressed whilst on the menu screen
    //We don't need left as it shouldn't do anythignw whilst on the main menu

    //UP
    if ((digitalRead(upBtn) == HIGH) && (prevUpBtnState != digitalRead(upBtn))) {
      currentMenuItem -= 1;
      tone(buzzerPin, buzzerFreq, 100);
    }

    //RIGHT
    if ((digitalRead(rightBtn) == HIGH) && (prevRightBtnState != digitalRead(rightBtn))) {
      screenDraw();
      tone(buzzerPin, buzzerFreq, 100);
    }

    //DOWN
    if ((digitalRead(downBtn) == HIGH) && (prevDownBtnState != digitalRead(downBtn))) {
      currentMenuItem += 1;
      tone(buzzerPin, buzzerFreq, 100);
    }

    //SELECT
    if ((digitalRead(selectBtn) == HIGH) && (prevSelectBtnState != digitalRead(selectBtn))) {
      screenDraw();
      tone(buzzerPin, buzzerFreq, 100);
    }

    if (currentMenuItem < 0) {
      currentMenuItem = menuItems;
    } else if (currentMenuItem > menuItems) {
      currentMenuItem = 0;
    }

    prevLeftBtnState = digitalRead(leftBtn);
    prevUpBtnState = digitalRead(upBtn);
    prevRightBtnState = digitalRead(rightBtn);
    prevDownBtnState = digitalRead(downBtn);
    prevSelectBtnState = digitalRead(selectBtn);
  }
}

//Once we have selected something, we should then redraw the screen to the selected option
void screenDraw() {
  switch (currentMenuItem) {
    case 0: //Pong
      currentScreen = 2;
      break;

    case 1: //Breakout
      currentScreen = 3;
      break;

    case 2: //Settings
      currentScreen = 4;
      break;

    default:
      break;
  }
}
