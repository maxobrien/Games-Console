/* ===================================================== */
/* BREAKOUT DEFINITIONS */

//Defining the block
const int xBlocks = 4;
const int yBlocks = 3;
const int blockGap = 2;
int blockWidth = 0;
int blockHeight = 0;


//Coords for block
int xCoords[xBlocks];
int yCoords[yBlocks];


//Paddle
const int break_paddleWidth = 16;
const int break_paddleHeight = 2;
const int break_paddleY = 64 - 8;
int break_paddleX = (64 - (break_paddleWidth / 2));


//Ball
int break_ballX = 0;
int break_ballY = 0;
int break_ballWidth = 2;
int break_ballXDirection = 2;
/* Possible Values
    0 = Left
    1 = Right
    2 = Stop ball moving
*/
int break_ballYDirection = 2;
/* Possible Values
    0 = Down
    1 = Up
    2 = Stop ball moving
*/
bool break_ballRelease = false;
unsigned long break_previousBallMillis = 0;
long break_ballDelay = (45 - (difficulty * 5));


//Time delay for moving various things on the screen
unsigned long break_previousLeftMillis = 0;
unsigned long break_previousRightMillis = 0;
const long break_paddleMoveDelay = 10;

bool block_hit = false;
int blocksHit[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int numBlocksHit = 0;
int currentBlock = 0;

int break_lives = (7 - difficulty);

unsigned long break_previousSelectFlashMillis = 0;
bool break_selectDrawn = false;

/* ===================================================== */

void loadBreakout() {

  //Paddle
  break_paddleX = (64 - (break_paddleWidth / 2));


  //Ball
  break_ballX = 0;
  break_ballY = 0;
  break_ballXDirection = 2;
  /* Possible Values
      0 = Left
      1 = Right
      2 = Stop ball moving
  */
  break_ballYDirection = 2;
  /* Possible Values
      0 = Down
      1 = Up
      2 = Stop ball moving
  */
  break_ballRelease = false;
  break_ballDelay = (45 - (difficulty * 5));

  block_hit = false;
  for (int i = 0; i <= 11; i++) {
    blocksHit[i] = 0;
  }
  numBlocksHit = 0;
  currentBlock = 0;

  break_lives = (7 - difficulty);

  breakoutLoaded = true;

  break_selectDrawn = false;

  playedLoseMelody = false;
  playedWinMelody = false;
}

void setupBreakout() {
  blockWidth = ((100 - (blockGap * (xBlocks - 1))) / xBlocks);
  blockHeight = ((32 - (blockGap * (yBlocks - 1))) / yBlocks);

  //Add all X coords to an array
  for (int x = 0; x <= (xBlocks - 1); x++) {
    xCoords[x] = (14 + ((blockWidth * x) + blockGap));
  }

  //Add all Y coords to an array
  for (int y = 0; y <= (yBlocks - 1); y++) {
    yCoords[y] = (8 + ((blockHeight * y) + blockGap));
  }

  breakoutSetup = true;
}

void drawBreakout() {
  //We should generate a random seed for the random number generator based on an unconnected analoge input which will give a 'random' result
  randomSeed(analogRead(randomPin));

  //Draw border around the edge
  u8g2.drawFrame(0, 0, 128, 64);

  //Check if we won the game
  if (numBlocksHit != (xBlocks * yBlocks)) {
    //Check if we have lost all our lives or not, or if we can still play
    if (break_lives != 0) {

      //Draw paddle
      u8g2.drawBox(
        break_paddleX, //X
        break_paddleY, //Y
        break_paddleWidth, //Width
        break_paddleHeight); //Height

      //Change ball position
      if (break_ballRelease == true) {
        if (currentMillis - break_previousBallMillis >= break_ballDelay) {
          break_previousBallMillis = currentMillis;

          //Change ball X Direction
          if (break_ballXDirection == 0) {
            //The ball is going left
            break_ballX -= 1;
          } else if (break_ballXDirection == 1) {
            //The ball is going right
            break_ballX += 1;
          }

          //Change ball Y Direction
          if (break_ballYDirection == 0) {
            //The ball is going down
            break_ballY -= 1;
          } else if (break_ballYDirection == 1) {
            //The ball is going up
            break_ballY += 1;
          }
        }
      }

      if (break_ballRelease == false) {
        //Set the ball position to be on the paddle
        break_ballX = ((break_paddleX + (break_paddleWidth / 2)) - 1);
        break_ballY = (break_paddleY - 5);
      }

      //Top and Bottom frame constraints
      if (break_ballY == 1) {
        //Ball is at the top so change direction
        break_ballYDirection = 1;
      } else if (break_ballY == 63) {
        //Ball is at the bottom so change direction
        break_ballYDirection = 0;
        break_lives -= 1;
        break_ballRelease = false;
      }

      //Left and Right frame constraints
      if (break_ballX == 1) {
        //Ball is on the far left so we should change direction
        break_ballXDirection = 1;
      } else if ((break_ballX + break_ballWidth) == 127) {
        //Ball is on the far right so we should change direction
        break_ballXDirection = 0;
      }

      u8g2.drawBox(break_ballX, break_ballY, break_ballWidth, break_ballWidth);

      //Loop through all X and Y coord arrays and draw a box at the position
      for (int x = 0; x <= (xBlocks - 1); x++) {
        for (int y = 0; y <= (yBlocks - 1); y++) {

          //Decide what to do if we have a hit
          if (blocksHit[currentBlock] == 1) {
            //Destroy Block

            //If we have hit the block then we should draw it off the screen
            u8g2.drawBox(
              -30, //X
              -30, //Y
              2, //Width
              3); //Height
          } else {
            //If we haven't hit the block before we should draw it as normal
            u8g2.drawBox(
              xCoords[x], //X
              yCoords[y], //Y
              blockWidth - blockGap, //Width
              blockHeight - blockGap); //Height

            //Check for a hit
            if (((break_ballX > xCoords[x]) && (break_ballX < (xCoords[x] + blockWidth))) || (((break_ballX + break_ballWidth) > xCoords[x]) && ((break_ballX + break_ballWidth) < (xCoords[x] + blockWidth)))) {
              //We have hit on the X coords somehwere so we should check if we are within the Y
              if (((break_ballY  > yCoords[y]) && (break_ballY < (yCoords[y] + blockHeight))) || (((break_ballY + break_ballWidth) > yCoords[y]) && ((break_ballY + break_ballWidth) < (yCoords[y] + blockHeight)))) {
                //We have also hit inside the Y coords

                if (((break_ballY == (yCoords[y] - 1)) || (break_ballY == ((yCoords[y] + blockHeight) - 1))) || (((break_ballY + break_ballWidth) == (yCoords[y] - 1)) || ((break_ballY + break_ballWidth) == ((yCoords[y] + blockHeight) - 1)))) {
                  if (break_ballYDirection == 0) {
                    break_ballYDirection = 1;
                  } else if (break_ballYDirection == 1) {
                    break_ballYDirection = 0;
                  }
                }

                if (((break_ballX == (xCoords[x] - 1)) || (break_ballX == ((xCoords[x] + blockWidth) - 1))) || (((break_ballX + break_ballWidth) == (xCoords[x] - 1)) || ((break_ballX + break_ballWidth) == ((xCoords[x] + blockWidth) - 1)))) {
                  if (break_ballXDirection == 0) {
                    break_ballXDirection = 1;
                  } else if (break_ballXDirection == 1) {
                    break_ballXDirection = 0;
                  }
                }

                //Register a hit at the current block being drawn and 'save' it in the blocksHit array
                blocksHit[currentBlock] += 1;
                numBlocksHit += 1;
                tone(buzzerPin, buzzerFreq, 100);
              }
            }

          }


          //Keep track of the current block we are drawing and add some limiting to it
          if (currentBlock != 12) {
            currentBlock += 1;
          }

          if (currentBlock == 12) {
            currentBlock = 0;
          }

        }
      }

      //Paddle hit detection
      if ((((break_ballX + break_ballWidth) >= break_paddleX) && (break_ballX <= (break_paddleX + break_paddleWidth))) && ((break_ballY + break_ballWidth) >= break_paddleY)) {
        //We have hit the paddle
        break_ballYDirection = 0;
        tone(buzzerPin, buzzerFreq, 100);
      }

      //Draw the remaining lives 'blocks left'
      for (int i = 0; i <= (break_lives - 2); i++) {
        u8g2.drawBox(120, ((i * 6) + 6), break_ballWidth, break_ballWidth);
      }

    } else {
      if (playedLoseMelody == false) {
        loseMelody();
      }

      //If we have lost all our lives
      u8g2.drawStr((64 - (u8g2.getStrWidth("YOU LOOSE") / 2)), 12, "YOU LOOSE");
      u8g2.drawHLine(0, 15, 128); //Draw line under title
      u8g2.drawStr((64 - (u8g2.getStrWidth("You only hit:") / 2)), 30, "You only hit");
      u8g2.setCursor((64 - ((u8g2.getStrWidth(numBlocksHit) + u8g2.getStrWidth(" blocks")) / 2)), 41);
      u8g2.print(String(String(numBlocksHit) + " blocks"));

      u8g2.drawHLine(0, 49, 128); //Draw line
      if (currentMillis - break_previousSelectFlashMillis >= 1000) {
        break_previousSelectFlashMillis = currentMillis;

        if (break_selectDrawn == false) {
          break_selectDrawn = true;
        } else {
          break_selectDrawn = false;
        }
      }

      if (break_selectDrawn == false) {
        u8g2.drawStr((64 - (u8g2.getStrWidth("Press Select") / 2)), 60, "Press Select");
      }

      if ((digitalRead(selectBtn) == HIGH) && (prevSelectBtnState != digitalRead(selectBtn))) {
        breakoutLoaded = false;
        breakoutSetup = false;
      }
    }
  } else {
    if (playedWinMelody == false) {
      winMelody();
    }

    //We have won the game
    u8g2.drawStr((64 - (u8g2.getStrWidth("YOU WIN") / 2)), 12, "YOU WIN");
    u8g2.drawHLine(0, 15, 128); //Draw line under title
    u8g2.drawStr((64 - (u8g2.getStrWidth("You had:") / 2)), 30, "You had");
    u8g2.setCursor((64 - ((u8g2.getStrWidth(break_lives - 1) + u8g2.getStrWidth(" lives left")) / 2)), 41);
    u8g2.print(String(String(break_lives - 1) + " lives left"));

    u8g2.drawHLine(0, 49, 128); //Draw line
    if (currentMillis - break_previousSelectFlashMillis >= 1000) {
      break_previousSelectFlashMillis = currentMillis;

      if (break_selectDrawn == false) {
        break_selectDrawn = true;
      } else {
        break_selectDrawn = false;
      }
    }

    if (break_selectDrawn == false) {
      u8g2.drawStr((64 - (u8g2.getStrWidth("Press Select") / 2)), 60, "Press Select");
    }

    if ((digitalRead(selectBtn) == HIGH) && (prevSelectBtnState != digitalRead(selectBtn))) {
      breakoutLoaded = false;
      breakoutSetup = false;
    }
  }
}

void breakoutButtons() {
  //Check to see if we are playing breakout and then check the buttons accordingly
  if (currentScreen == 3) {

    //Check button inputs for controlling paddle
    //Since the paddle can only move horizontally, we only need this axis of button inputs
    //We might also need the up button to release the ball on start

    //LEFT
    if (digitalRead(leftBtn) == HIGH) {
      if (currentMillis - break_previousLeftMillis >= break_paddleMoveDelay) {
        break_previousLeftMillis = currentMillis;
        break_paddleX -= 1;
      }
    }

    //RIGHT
    if (digitalRead(rightBtn) == HIGH) {
      if (currentMillis - break_previousRightMillis >= break_paddleMoveDelay) {
        break_previousRightMillis = currentMillis;
        break_paddleX += 1;
      }
    }

    //UP
    if (digitalRead(upBtn) == HIGH) {
      if (break_ballRelease == false) {
        break_ballXDirection = random(0, 2);
        break_ballYDirection = 0;
        break_ballRelease = true;
      }
    }

    //SELECT
    if ((numBlocksHit == (xBlocks * yBlocks)) || (break_lives != 0)) {
      if ((digitalRead(selectBtn) == HIGH) && (prevSelectBtnState != digitalRead(selectBtn))) {
        if (break_ballRelease == false) {
          break_ballXDirection = random(0, 2);
          break_ballYDirection = 0;
          break_ballRelease = true;
        }
      }
    }

    //X-Limiting for the paddle position
    if (break_paddleX < 1) {
      break_paddleX = 1;
    } else if (break_paddleX > ((128 - break_paddleWidth) - 1)) {
      break_paddleX = ((128 - break_paddleWidth) - 1);
    }

    //Store the previous state of the buttons
    prevLeftBtnState = digitalRead(leftBtn);
    prevUpBtnState = digitalRead(upBtn);
    prevRightBtnState = digitalRead(rightBtn);
    prevDownBtnState = digitalRead(downBtn);
    prevSelectBtnState = digitalRead(selectBtn);
  }
}
