int speakerPin = 11; //buzzer is connected to Pin 11 of the Board.

int length = 27; // the number of notes 
char notes[] = "cdeeeeeeeeeeedef eeedddbdc "; // a space represents a rest 
int beats[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 4 };//Duration of each note
int tempo = 300; //Change song speed here

void playTone(int tone, int duration) {  //creating a square wave for the given duration 
  for (long i = 0; i < duration * 1000L; i += tone * 2) { 
    digitalWrite(speakerPin, HIGH); 
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW); 
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) { //Assigning high time for the notes
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 956, 851, 758, 716, 638, 568, 1014, 478 }; 

  // play the tone corresponding to the note name 
  for (int i = 0; i < 8; i++) { 
    if (names[i] == note) { 
      playTone(tones[i], duration); 
    }
  }
}

void setup() { 
  pinMode(speakerPin, OUTPUT); // Setting pin 9 as an OutPut Pin
}

void loop() {  //Main function
  for (int i = 0; i < length; i++) {  //For the length of the tune array
    if (notes[i] == ' ') {  //take space as rest
      delay(beats[i] * tempo); // rest 
    } else { 
      playNote(notes[i], beats[i] * tempo); //play the corresponding note for the corresponding beat
    } 

    // pause between notes 
    delay(tempo / 2); 
  } 
}
