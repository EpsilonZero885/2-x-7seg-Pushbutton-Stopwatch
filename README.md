Stopwatch using Arduino UNO R3

Function:
  "0 0" is displayed
  While Pushbutton is depressed, value increments by 1 every second, restarting at "0 0" after reaching "9 9"
  When Pushbutton is released, last value reached continues to be displayed
  When RESET button is pressed value restarts at "0 0"

Materials:
  2 x 7-segment displays (CMN Cathode) 
  1 x Pushbutton  
  2 x 220 Ohm Resistors

Project Modelled using TinkerCAD
Created for ESC-111 Introduction to Engineering Class. No pre-existing libraries were permitted in this assignment.
  Digital model was successful, physical model was not.
 
 Experimentation Notes:
 - Changed "INPUT" pin, Cannot use Digital Pins 0, 1, or 13 for INPUT as they default to HIGH unless written otherwise.
  -Counter slowly increments when the button is not pressed. (faster when vibrated/bumped)
  
