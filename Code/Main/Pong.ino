
/* ===================================================== */
/* PADDLE DEFINITIONS */

int pongRandom = 5;
int missFactor = 0;

//Paddle
const int paddleHeight = 16;
const int paddleWidth = 2;
const int paddleX = 5;
int paddleUserY = (32 - (paddleHeight / 2));
int paddleCompY = (32 - (paddleHeight / 2));
unsigned long previousPaddleHit = 0;
const int paddleHitDelay = 10;

//Time delay for buttons
unsigned long previousUpMillis = 0;
unsigned long previousDownMillis = 0;
unsigned long previousCompMillis = 0;
const long paddleMoveDelay = 10;

//Ball
int ballX = 80;
int ballY = 20;
int ballWidth = 2;
int ballXDirection = 1;
/* Possible Values
    0 = Left
    1 = Right
*/
int ballYDirection = 0;
/* Possible Values
    0 = Down
    1 = Up
*/
unsigned long previousBallMillis = 0;
long ballDelay = 30;

int userScore = 0;
int compScore = 0;

unsigned long previousSelectFlashMillis = 0;
bool selectDrawn = false;

/* ===================================================== */

void loadPong() {
  pongRandom = 5;
  missFactor = 0;

  //Paddle
  paddleUserY = (32 - (paddleHeight / 2));
  paddleCompY = (32 - (paddleHeight / 2));

  //Ball
  ballX = 80;
  ballY = 20;
  ballXDirection = 1;
  /* Possible Values
      0 = Left
      1 = Right
  */
  ballYDirection = 0;
  /* Possible Values
      0 = Down
      1 = Up
  */

  userScore = 0;
  compScore = 0;

  pongLoaded = true;

  selectDrawn = false;

  playedLoseMelody = false;
  playedWinMelody = false;
}

void drawPong() {

  //We should generate a random seed for the random number generator based on an unconnected analoge input which will give a 'random' result
  randomSeed(analogRead(randomPin));

  //Draw border around the edge
  u8g2.drawFrame(0, 0, 128, 64);


  if (userScore != 10) {
    if (compScore != 10) {

      //Draw out dashed line in middle of screen
      for (int i = 0; i <= 15; i++) {
        if (i % 2 == 1) {
          //We have an odd number so we want to draw a line
          u8g2.setDrawColor(1);
          u8g2.drawVLine(64, (i * 4), 4);
        }
      }


      //Draw out all 3 components having calculated their respective values
      drawPaddles();
      drawBall();
      drawScore();

      //Keep position of ball moving
      if (currentMillis - previousBallMillis >= ballDelay) {
        previousBallMillis = currentMillis;

        //Change ball X Direction
        if (ballXDirection == 0) {
          //The ball is going left
          ballX -= 1;
        } else if (ballXDirection == 1) {
          //The ball is going right
          ballX += 1;
        }

        //Change ball Y Direction
        if (ballYDirection == 0) {
          //The ball is going down
          ballY -= 1;
        } else if (ballYDirection == 1) {
          //The ball is going up
          ballY += 1;
        }
      }

      //Top and Bottom frame constraints
      if (ballY == 1) {
        //Ball is at the top so change direction
        ballYDirection = 1;
      } else if (ballY == 63) {
        //Ball is at the bottom so change direction
        ballYDirection = 0;
      }

      //Winning
      if (ballX < 1) {
        //Computer wins
        compScore += 1;
        ballX = 80;
        ballY = random(20, 44);
        ballXDirection = 1;
        pongRandom = 5;
        ballDelay = 30;
      } else if (ballX > 127) {
        //User wins
        userScore += 1;
        ballX = 80;
        ballY = random(20, 44);
        ballXDirection = 1;
        pongRandom = 5;
        ballDelay = 30;
      }



      /*Ball hitting paddles */
      //User paddle
      if ((ballX == (paddleX + paddleWidth)) && ((ballY >= paddleUserY) && (ballY <= paddleUserY + paddleHeight))) {
        if (currentMillis - previousPaddleHit >= 10) {

          previousPaddleHit = currentMillis;

          ballXDirection = 1;
          tone(buzzerPin, buzzerFreq, 100);

          //If we have hit the paddle then we should generate a new random number based on the difficuilty
          pongRandom = random((difficulty));
          missFactor = random(-10, 10);

          //Keep generating until we get a number that isn't 0, but we only need to run the check once
          if (missFactor == 0) {
            missFactor = random(-10, 10);
          }

          //Increase the speed of the ball by a different amount depending on difficulty
          ballDelay = ballDelay * (0.9 + (difficulty / 100));
          if (ballDelay < (16 - difficulty)) {
            ballDelay = (16 - difficulty);
          }
        }
      }

      //Computer paddle
      if ((ballX == (128 - paddleX - paddleWidth)) && ((ballY >= paddleCompY) && (ballY <= paddleCompY + paddleHeight))) {
        ballXDirection = 0;
        tone(buzzerPin, buzzerFreq, 100);
      }


      //AI
      if (ballX > random(50, 70)) {
        if (pongRandom != 1) {
          //Normally the computer should always win and can't loose
          //paddleCompY = ballY - (paddleHeight / 2); //Minus that value to center the ball int the paddle

          if (currentMillis - previousCompMillis >= ballDelay) {
            //The paddle should only move after a delay of the same as the ball so it looks like it is following the ball
            previousCompMillis = currentMillis;

            //We should move the paddle in a direction if the ball does not line up with the middle of the paddle
            if ((paddleCompY + (paddleHeight / 2)) != ballY) {

              //Find out if the ball is above or below the paddle and move accordingly
              if (ballY < (paddleCompY + (paddleHeight / 2))) {
                paddleCompY -= 1;
              } else if (ballY > (paddleCompY + (paddleHeight / 2))) {
                paddleCompY += 1;
              }

            }
          }

        } else if (pongRandom == 1) {
          //The computer should now loose by missing by a certain value
          //paddleCompY = ((ballY - (paddleHeight / 2)) - missFactor);

          //Move the padddle after a time delay of the same as the ball so it looks like it is following it
          if (currentMillis - previousCompMillis >= ballDelay) {
            previousCompMillis = currentMillis;

            //Work out which way we should miss the ball by and by how much
            if (missFactor > 0) {
              if (((paddleHeight / 2) - missFactor) != ballY) {

                //Move the paddle so it is aligned with the balll but with the miss factor as an offset
                if (ballY < ((paddleHeight / 2) - missFactor)) {
                  paddleCompY -= 1;
                } else if (ballY > ((paddleHeight / 2) - missFactor)) {
                  paddleCompY += 1;
                }

              }
            } else if (missFactor <= 0) {
              //Move the paddleso it is aligned with the ball but leave an offset of the miss factor
              if (((paddleHeight / 2) - missFactor) != ballY) {
                if (ballY > ((paddleHeight / 2) - missFactor)) {
                  paddleCompY -= 1;
                } else if (ballY < ((paddleHeight / 2) - missFactor)) {
                  paddleCompY += 1;
                }

              }
            }
          }
        }
      }


      //Y-Constrain computer paddle
      if (paddleCompY < 1) {
        paddleCompY = 0;
      } else if (paddleCompY > ((64 - paddleHeight) - 1)) {
        paddleCompY = ((64 - paddleHeight) - 1);
      }
    } else {
      if (playedLoseMelody == false) {
        loseMelody();
      }

      //Computer won the game
      u8g2.drawStr((64 - (u8g2.getStrWidth("YOU LOOSE") / 2)), 12, "YOU LOOSE");
      u8g2.drawHLine(0, 15, 128); //Draw line under title
      u8g2.drawStr((64 - (u8g2.getStrWidth("Unlucky") / 2)), 30, "Unlucky");
      u8g2.drawStr((64 - (u8g2.getStrWidth("The Computer Won") / 2)), 41, "The Computer Won");

      u8g2.drawHLine(0, 49, 128); //Draw line
      if (currentMillis - previousSelectFlashMillis >= 1000) {
        previousSelectFlashMillis = currentMillis;

        if (selectDrawn == false) {
          selectDrawn = true;
        } else {
          selectDrawn = false;
        }
      }

      if (selectDrawn == false) {
        u8g2.drawStr((64 - (u8g2.getStrWidth("Press Select") / 2)), 60, "Press Select");
      }

      if ((digitalRead(selectBtn) == HIGH) && (prevSelectBtnState != digitalRead(selectBtn))) {
        pongLoaded = false;
      }
    }
  } else {
    if (playedWinMelody == false) {
      winMelody();
    }

    //The user won the game
    u8g2.drawStr((64 - (u8g2.getStrWidth("YOU WIN") / 2)), 12, "YOU WIN");
    u8g2.drawHLine(0, 15, 128); //Draw line under title
    u8g2.drawStr((64 - (u8g2.getStrWidth("Congratulations,") / 2)), 24, "Congratulations,");
    u8g2.drawStr((64 - (u8g2.getStrWidth("You beat the") / 2)), 35, "You beat the");
    u8g2.drawStr((64 - (u8g2.getStrWidth("computer") / 2)), 46, "computer");

    u8g2.drawHLine(0, 49, 128); //Draw line
    if (currentMillis - previousSelectFlashMillis >= 1000) {
      previousSelectFlashMillis = currentMillis;

      if (selectDrawn == false) {
        selectDrawn = true;
      } else {
        selectDrawn = false;
      }
    }

    if (selectDrawn == false) {
      u8g2.drawStr((64 - (u8g2.getStrWidth("Press Select") / 2)), 60, "Press Select");
    }

    if ((digitalRead(selectBtn) == HIGH) && (prevSelectBtnState != digitalRead(selectBtn))) {
      pongLoaded = false;
    }
  }
}

//Function to draw paddles on screen
void drawPaddles() {
  //Draw left paddle
  u8g2.drawBox(
    paddleX, //X
    paddleUserY, //Y
    paddleWidth, //Width
    paddleHeight); //Height

  //Draw right paddle
  u8g2.drawBox(
    (128 - paddleX - paddleWidth), //X
    paddleCompY, //Y
    paddleWidth, //Width
    paddleHeight); //Height
}

//Will draw the ball at the coordinates calculated
void drawBall() {
  u8g2.drawBox(ballX, ballY, ballWidth, ballWidth);
}

//Draws out the score on the screen
void drawScore() {
  u8g2.setCursor(50, 15);
  u8g2.print(String(userScore));
  u8g2.setCursor(74, 15);
  u8g2.print(String(compScore));
}

void pongButtons() {
  //Check to see if we are playing pong. If we are then we want to check the value of the buttons
  if (currentScreen == 2) {

    //Check button inputs for controlling paddle
    //We don't need horizontal directions as we only want to control up and down

    //UP
    if (digitalRead(upBtn) == HIGH) {
      if (currentMillis - previousUpMillis >= paddleMoveDelay) {
        previousUpMillis = currentMillis;
        paddleUserY -= 1;
      }
    }

    //DOWN
    if (digitalRead(downBtn) == HIGH) {
      if (currentMillis - previousDownMillis >= paddleMoveDelay) {
        previousDownMillis = currentMillis;
        paddleUserY += 1;
      }
    }

    //Y-Limiting for the user paddle
    if (paddleUserY < 1) {
      paddleUserY = 0;
    } else if (paddleUserY > ((64 - paddleHeight) - 1)) {
      paddleUserY = ((64 - paddleHeight) - 1);
    }


    prevLeftBtnState = digitalRead(leftBtn);
    prevUpBtnState = digitalRead(upBtn);
    prevRightBtnState = digitalRead(rightBtn);
    prevDownBtnState = digitalRead(downBtn);
    prevSelectBtnState = digitalRead(selectBtn);
  }
}
