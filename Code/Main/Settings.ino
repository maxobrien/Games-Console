/* ===================================================== */
/* SETTINGS DEFINITIONS */

const int settings_menuItems = 2; //Number of menu items - includes 0

/* Select Box */
const int settings_selectBoxPosY = 18; //Y pos for highlight box
const int settings_selectBoxHeight = 12; //Height of the highlight box

int settings_currentMenuItem = 0; //Keep track of currently selected item - start at first

/* ===================================================== */

void loadSettings() {
  settings_currentMenuItem = 0;
  settingsLoaded = true;
}

void drawSettings() {
  u8g2.drawStr((64 - (u8g2.getStrWidth("Settings") / 2)), 12, "Settings");
  u8g2.drawHLine(0, 15, 128); //Draw line under title

  u8g2.setFontMode(1); //Transparent font mode
  u8g2.setDrawColor(1); //Box fill colour

  //Draw out the hightlight box
  u8g2.drawBox(0, (settings_selectBoxPosY + (settings_currentMenuItem * settings_selectBoxHeight)), 128, settings_selectBoxHeight);

  //Give the text XOR colour mode - the box being over the text will change it's colour
  u8g2.setDrawColor(2);

  //Itterate over all the settings and wirte them out
  for (int i = 0; i <= settings_menuItems; i++) {
    switch (i) {
      case 0: //Difficulty
        u8g2.drawStr(2, (15 + ((i + 1) * 12)), "Difficulty");

        switch (difficulty) {
          case 2:
            u8g2.drawStr((126 - (u8g2.getStrWidth("Easy"))), (15 + ((i + 1) * 12)), "Easy");
            break;

          case 3:
            u8g2.drawStr((126 - (u8g2.getStrWidth("Medium"))), (15 + ((i + 1) * 12)), "Medium");
            break;

          case 5:
            u8g2.drawStr((126 - (u8g2.getStrWidth("Hard"))), (15 + ((i + 1) * 12)), "Hard");
            break;

          default:
            break;
        }

        break;

      case 1: //Frequency
        u8g2.drawStr(2, (15 + ((i + 1) * 12)), "Frequency");

        switch (buzzerFreq) {
          case 250:
            u8g2.drawStr((126 - (u8g2.getStrWidth("250 Hz"))), (15 + ((i + 1) * 12)), "250 Hz");
            break;

          case 450:
            u8g2.drawStr((126 - (u8g2.getStrWidth("450 Hz"))), (15 + ((i + 1) * 12)), "450 Hz");
            break;

          case 550:
            u8g2.drawStr((126 - (u8g2.getStrWidth("550 Hz"))), (15 + ((i + 1) * 12)), "550 Hz");
            break;

          case 750:
            u8g2.drawStr((126 - (u8g2.getStrWidth("750 Hz"))), (15 + ((i + 1) * 12)), "750 Hz");
            break;

          case 1150:
            u8g2.drawStr((126 - (u8g2.getStrWidth("1150 Hz"))), (15 + ((i + 1) * 12)), "1150 Hz");
            break;

          default:
            break;
        }

        break;

      case 2: //Back button
        u8g2.drawStr(2, (15 + ((i + 1) * 12)), "<- Back");

      default:
        break;
    }
  }
}

void settingsButtons() {
  //Check to see if we are on the menu screen. If we are then we want to check the value of the buttons
  if (currentScreen == 4) {

    //UP
    if ((digitalRead(upBtn) == HIGH) && (prevUpBtnState != digitalRead(upBtn))) {
      settings_currentMenuItem -= 1;
      tone(buzzerPin, buzzerFreq, 100);
    }

    //LEFT
    if ((digitalRead(leftBtn) == HIGH) && (prevLeftBtnState != digitalRead(leftBtn))) {
      leftSettingsOptions();
      tone(buzzerPin, buzzerFreq, 100);
    }

    //RIGHT
    if ((digitalRead(rightBtn) == HIGH) && (prevRightBtnState != digitalRead(rightBtn))) {
      rightSettingsOptions();
      tone(buzzerPin, buzzerFreq, 100);
    }
    
    //DOWN
    if ((digitalRead(downBtn) == HIGH) && (prevDownBtnState != digitalRead(downBtn))) {
      settings_currentMenuItem += 1;
      tone(buzzerPin, buzzerFreq, 100);
    }

    //SELECT
    if ((digitalRead(selectBtn) == HIGH) && (prevSelectBtnState != digitalRead(selectBtn))) {
      rightSettingsOptions();
      tone(buzzerPin, buzzerFreq, 100);
    }

    if (settings_currentMenuItem < 0) {
      settings_currentMenuItem = settings_menuItems;
    } else if (settings_currentMenuItem > settings_menuItems) {
      settings_currentMenuItem = 0;
    }

    prevLeftBtnState = digitalRead(leftBtn);
    prevUpBtnState = digitalRead(upBtn);
    prevRightBtnState = digitalRead(rightBtn);
    prevDownBtnState = digitalRead(downBtn);
    prevSelectBtnState = digitalRead(selectBtn);
  }
}


void rightSettingsOptions() {
  switch (settings_currentMenuItem) {

    case 0: //Difficulty
      switch (difficulty) {
        case 2:
          difficulty = 3;
          break;

        case 3:
          difficulty = 5;
          break;

        case 5:
          difficulty = 2;
          break;

        default:
          break;
      }

      break;

    case 1: //Frequency
      switch (buzzerFreq) {
        case 250:
          buzzerFreq = 450;
          break;

        case 450:
          buzzerFreq = 550;
          break;

        case 550:
          buzzerFreq = 750;
          break;

        case 750:
          buzzerFreq = 1150;
          break;

        case 1150:
          buzzerFreq = 250;
          break;
      }
      break;

    case 2: //Back Button
      currentScreen = 1;
      break;

    default:
      break;
  }
}

void leftSettingsOptions() {
  switch (settings_currentMenuItem) {

    case 0: //Difficulty
      switch (difficulty) {
        case 2:
          difficulty = 5;
          break;

        case 3:
          difficulty = 2;
          break;

        case 5:
          difficulty = 3;
          break;

        default:
          break;
      }

      break;

    case 1: //Frequency
      switch (buzzerFreq) {
        case 250:
          buzzerFreq = 1150;
          break;

        case 450:
          buzzerFreq = 250;
          break;

        case 550:
          buzzerFreq = 450;
          break;

        case 750:
          buzzerFreq = 550;
          break;

        case 1150:
          buzzerFreq = 750;
          break;
      }
      break;

    case 2: //Back Button
      currentScreen = 1;
      break;

    default:
      break;
  }
}

