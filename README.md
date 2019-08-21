# Games Console Project - Max O'Brien
<img src="https://github.com/maxobrien/Games-Console/blob/master/Images/01.jpg" />

Above are all the files for my games console project.

## PCB Design Files
The PCB was originally designed in <a href="http://kicad-pcb.org/">KiCad 4.0.7</a> however other versions may still be able to open it. The board is a 2-layered design that can easily be manufactured at most places if that is what you wish to do.

**UPDATE** As of KiCad version 5.0 the board can still be opened however, you will need to run the automatic schematic symbol converter.

## STL Files
These files are for the enclosure of the games console. They fit the PCB supplied and so would need to be changed if you changed the dimensions of the board. If you are making your own then they can just be printed on a normal 3D printer, however, I would suggest you choose settings, and material, that will yield the highest quality detail as some of the model contains fine details. I chose black and white (as seen in the above render) and also printed it in SLS nylon.

## The Code
The code is written in the Arduino IDE. This means to open it, you will need the <a href="https://www.arduino.cc/en/Main/Software">Arduino IDE</a>. Before loading the code onto the micro, you will first have to burn a bootloader. Some guides to do this are listed below, however, doing your own research may yield better results.

- https://www.arduino.cc/en/Hacking/Bootloader
- https://learn.adafruit.com/ftdi-friend/programming-the-arduino-bootloader
- http://www.gammon.com.au/breadboard

Once the bootloader has be burned, you can upload the code. To do this, ensure your programmer is connected with a USB cable and open up the code in the Arduino IDE. Also ensure that the programmer is correctly connected to the programming header (Bottom Left) on the PCB. Check that all 5 tabs can be seen along the top labelled; "Main", "Breakout", "Menu", "pong" and "Settings". Next go to 'Tools > Board' and ensure 'Arduino/Genuino Uno' is selected. Then go to 'Tools > Port' and select the right port for your programmer. Finally, select 'Sketch > Upload Using Programmer'. Once this operation is complete, you should have a working games console!

## Console Renders
<details>
  <summary>Click to show renders</summary>
  <img src="https://github.com/maxobrien/Games-Console/blob/master/Images/01.jpg" />
  <img src="https://github.com/maxobrien/Games-Console/blob/master/Images/02.jpg" />
  <img src="https://github.com/maxobrien/Games-Console/blob/master/Images/03.jpg" />
  <img src="https://github.com/maxobrien/Games-Console/blob/master/Images/04.jpg" />
  <img src="https://github.com/maxobrien/Games-Console/blob/master/Images/05.jpg" />
  <img src="https://github.com/maxobrien/Games-Console/blob/master/Images/06.jpg" />
</details>

## Required Libraries for Code
- U8g2
