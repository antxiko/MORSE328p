

const byte numChars = 255;      // Max chars in the array
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;        // When receibed data, true
const int buzzer = 9;           //buzzer to arduino pin 9


void setup(){
    
    // Set the baud rate speed
    Serial.begin(9600);
    Serial.println("Serial working");
    pinMode(buzzer, OUTPUT);    // Set buzzer - pin 9 as an output

}

void loop(){

  recvWithEndMarker();
  showNewData();
  
}


void recvWithEndMarker() {      //function for filling the array of chars
    static byte ndx = 0;        //array counter
    char endMarker = '\n';      //marker of carrier return
    char rc;                    //receibed char of the array
                                //until carriage return or char array max, fill the array 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();           //reads the char
        int r = tolower(rc);          //if Uppercase, it converts to lowercase

        if (rc != endMarker) {        
            receivedChars[ndx] = r;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {                      //reads the char from the array, prints it on serial and plays the morse code of it
    if (newData == true) {                //if the array has receibed new data, go
          char t = sizeof(receivedChars); //t is the size of the array
          playsChar(t);           //plays that char to morse
          Serial.println();               //carriage return and reset of the array
          memset(receivedChars, 0, sizeof(receivedChars));
          newData = false;
      }
}

void dash(){          // plays DASH
  tone(buzzer, 650);  // Sends 650Hz sound signal...
  delay(300);         // for 3 units of morse code
  noTone(buzzer);     // Stop sound...
  delay(100);         // 1 unit of silence
}

void point(){         //plays POINT
  tone(buzzer, 650);  //Sends 650Hz sound signal...
  delay(100);         // for 1 unit of morse code
  noTone(buzzer);     // Stop sound...
  delay(100);         // 1 unit of silence
}

void margin(){        //margin whithing code units of a letter
  delay(200);
}

void playsChar(char i){     //print the char and plays it in MORSE
  for (i = 0; i < sizeof(receivedChars) - 1; i++)
  {
   Serial.print(receivedChars[i]);
   morse(receivedChars[i]);
   newData = false;
  }
}

void morse(char m){       //plays the char m in MORSE
  switch (m){
    case 'a':
    point();
    dash();
    margin();
    break;
    case 'b':
    dash();
    point();
    point();
    point();
    margin();
    break;
    case 'c':
    dash();
    point();
    dash();
    point();
    margin();
    break;
    case 'd':
    dash();
    point();
    point();
    margin();
    break;
    case 'e':
    point();
    margin();
    break;
    case 'f':
    point();
    point();
    dash();
    point();
    margin();
    break;
    case 'g':
    dash();
    dash();
    point();
    margin();
    break;
    case 'h':
    point();
    point();
    point();
    point();
    margin();
    break;
    case 'i':
    point();
    point();
    margin();
    break;
    case 'j':
    point();
    dash();
    dash();
    dash();
    margin();
    break;
    case 'k':
    dash();
    point();
    dash();
    margin();
    break;
    case 'l':
    point();
    dash();
    point();
    point();
    margin();
    break;
    case 'm':
    dash();
    dash();
    margin();
    break;
    case 'n':
    dash();
    point();
    margin();
    break;
    case 'o':
    dash();
    dash();
    dash();
    margin();
    break;
    case 'p':
    point();
    dash();
    dash();
    point();
    margin();
    break;
    case 'q':
    dash();
    dash();
    point();
    dash();
    margin();
    break;
    case 'r':
    point();
    dash();
    point();
    margin();
    break;
    case 's':
    point();
    point();
    point();
    margin();
    break;
    case 't':
    dash();
    margin();
    break;
    case 'u':
    point();
    point();
    dash();
    margin();
    break;
    case 'v':
    point();
    point();
    point();
    dash();
    margin();
    break;
    case 'w':
    point();
    dash();
    dash();
    margin();
    break;
    case 'x':
    dash();
    point();
    point();
    dash();
    margin();
    break;
    case 'y':
    dash();
    point();
    dash();
    dash();
    margin();
    break;
    case 'z':
    dash();
    dash();
    point();
    point();
    margin();
    break;
    case '1':
    point();
    dash();
    dash();
    dash();
    dash();
    margin();
    break;
    case '2':
    point();
    point();
    dash();
    dash();
    dash();
    margin();
    break;
    case '3':
    point();
    point();
    point();
    dash();
    dash();
    margin();
    break;
    case '4':
    point();
    point();
    point();
    point();
    dash();
    margin();
    break;
    case '5':
    point();
    point();
    point();
    point();
    point();
    margin();
    break;
    case '6':
    dash();
    point();
    point();
    point();
    point();
    margin();
    break;
    case '7':
    dash();
    dash();
    point();
    point();
    point();
    margin();
    break;
    case '8':
    dash();
    dash();
    dash();
    point();
    point();
    margin();
    break;
    case '9':
    dash();
    dash();
    dash();
    dash();
    point();
    margin();
    break;
    case '0':
    dash();
    dash();
    dash();
    dash();
    dash();
    margin();
    break;
    case ' ':
    delay(700);
    break;
  default:
  break;
  }
}
