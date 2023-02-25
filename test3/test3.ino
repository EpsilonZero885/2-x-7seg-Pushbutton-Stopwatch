//Arduino Uno R3
//2 x 7-segment displays (Common Cathode) + Pushbutton + 2 x 220 Ohm Resistors

//"0 0" is displayed
//While Pushbutton is depressed, value increments by 1 every second, restarting at "0 0" after reaching "9 9"
//When Pushbutton is released, last value reached continues to be displayed
//When RESET button is pressed value restarts at "0 0"

//Modelled using TinkerCad
//Tested using Elegoo Arduino Uno R3 and 4 digit 7-segment display

//Troubleshoot notes:
  //CANNOT use pins 1, 13 as INPUT
  //Sometimes increments VERY slowly when pushbutton is not connected – Why??? ☹
    //Also increments on its own when vibrated lol/cry

//Define pins as segment sections, Misc variables
int CMNB=2; //Right Display Cathode
int CMNA=3; //Left Display Cathode
int C=6; //Common Anodes from Display
int D=7;
int E=8;
int G=9;
int F=10;
int A=11;
int B=13;
int Short_Delay=10; //Flash Characters @10mS
int max_count=50; //50 Cycles = 1 Second Display


void setup () {
  Serial.begin(9600); //Start Serial Connection
  pinMode(12, INPUT); //Pin 13 as Input for Button
  pinMode(1, OUTPUT); //Pushbutton Anode for Button
  pinMode(CMNA, OUTPUT);
  pinMode(CMNB, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  } 

void R_library (int R) { //Maps Characters to Right Display
    if(R==0) {
   //Display 0 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  }

      if(R==1) {
   //Display 1 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW); 
   }
      
      if(R==2) {
   //Display 2 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  }
      
    if(R==3) {
   //Display 3 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH); 
  }
     
   if(R==4) {
   //Display 4 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 
   }
     
    if(R==5) {
   //Display 5 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  }
     
   if(R==6) {
   //Display 6 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 
   }
       
    if(R==7) {
   //Display 7 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW); 
  }
    
   if(R==8) {
   //Display 8 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 
   }
        
   if(R==9) {
   //Display 9 on DB
  digitalWrite(CMNA, HIGH);
  digitalWrite(CMNB, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 
   }    
}
void L_library (int L) { //Maps Characters to Left Display
    if(L==0) {
   //Display 0 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  }

      if(L==1) {
   //Display 1 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW); 
   }
      
      if(L==2) {
   //Display 2 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  }
      
    if(L==3) {
   //Display 3 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH); 
  }
     
   if(L==4) {
   //Display 4 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 
   }
     
    if(L==5) {
   //Display 5 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  }
     
   if(L==6) {
   //Display 6 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 
   }
       
    if(L==7) {
   //Display 7 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW); 
  }
    
   if(L==8) {
   //Display 8 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 
   }
        
   if(L==9) {
   //Display 9 on DA
  digitalWrite(CMNA, LOW);
  digitalWrite(CMNB, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH); 

   }
 } 
  

  
void loop (){

  int pbState = digitalRead(12); //Pushbutton value to variable
 
  digitalWrite(1, HIGH); //Turn Pin 1 ON
          
 if (pbState==HIGH){ //If Button is ON
  
  for (int L=0; L<=9; L++) { //10's place Loop 
    for (int R=0; R<=9; R++) { //1's place loop
      for (int ctr=0; ctr<max_count; ctr++) { //Display loop
          
      int pbState = digitalRead(12); //Pushbutton value to variable
 
        digitalWrite(1, HIGH); //Turn Pin 1 ON
          
           if (pbState==HIGH){ //If Button is ON
             
             L_library(L);    //Display Left
           delay (Short_Delay);
           R_library(R);    //Display Right
          delay (Short_Delay);
        
          } //Ends "if"
       
                 
          if (pbState==LOW) { //If Button is OFF
            
          for (int ctr=0; ctr<max_count; ctr++) { //Display loop             
             L_library(L);    //Display Left
           delay (Short_Delay);
           R_library(R);    //Display Right
          delay (Short_Delay);
            pbState=digitalRead(12);
            
              } //Ends "for"            
             } //Ends "if"           
          
      
          } //Ends "for"            
          } //Ends "for"
        } //Ends "for"          

           
 } //Ends "if"
} //Ends "void loop"
