String score;
String noteLength;
float tempo;

void setup() {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  loadScore();
  loadNoteLength();
  loadTempo();
  for(int i = 0; i < score.length(); i += 4) {
        float frequency = getFrequency(score.substring(i, i + 3));
        float noteDuration = getTempo(noteLength.substring(i, i + 3), tempo);
        printFreqAndTempo(frequency, noteDuration, i);
        tone(10, frequency, noteDuration);
        delay(noteDuration);
  }
  return;
}

void loop() {}

void printFreqAndTempo(float frequency, float noteDuration, int i) { //string concatenation avoided as it increases memory consumption
        Serial.print("Note: ");                                      //Arduino uno has only 2 kB of RAM.
        Serial.print(score.substring(i, i + 3));
        Serial.print("\t|\tFrequency: ");
        Serial.print(frequency);
        Serial.print("Hz\t|\tTempo: ");
        Serial.print(noteDuration);
        Serial.println("ms");
}

void waitForInput() {
  while(!Serial.available());
}

void loadScore() {
  Serial.print("Input score: ");
  waitForInput();
  if(Serial.available()){
        score = Serial.readStringUntil('\n');
        Serial.println(score);
        
  }
}

void loadNoteLength() {
  Serial.print("Input note length: ");
  waitForInput();
  if(Serial.available()){
        noteLength = Serial.readStringUntil('\n');
        Serial.println(noteLength);
        
  }
}

void loadTempo() {
  Serial.print("Input tempo: ");
  waitForInput();
  if(Serial.available()){
        tempo = Serial.parseFloat();
        Serial.print(tempo);
        Serial.println("bpm");
  }
}

int getNoteModifier(String note) {
    switch (note.charAt(0)) {
        case 'A' :
            return 1;
        case 'B' :
            return 3;
        case 'C' :
            return -8;
        case 'D' :
            return -6;
        case 'E' :
            return -4;
        case 'F' :
            return -3;
        case 'G' :
            return -1;
        default:
            return 0;
    }
}

int getDegreeModifier(String note) {
    switch (note.charAt(1)) {
        case 'b' :
            return -1;
        case '/' :
            return 0;
        case '#' :
            return 1;
        default :
            return 0;
    }
}

float getFrequency(String note) {
    int octave = note.charAt(2) - '0';
    int keyNumber = 12 * octave + getNoteModifier(note) + getDegreeModifier(note) ;
    return (float) (pow(2, (keyNumber - 49)/12.0)) * 440;
}

float getTempoNotation (String tempo) {
    switch (tempo.charAt(0) + tempo.charAt(1) - 96) {
        case 1 :
            return 4.0;
        case 2 :
            return 2.0;
        case 4 :
            return 1.0;
        case 8 :
            return 0.5;
        case 16 :
            return 0.25;
        case 32 :
            return 0.125;
        default :
            return 0;
    }
}

float getTempoModifier (String tempo) {
  float notation = getTempoNotation(tempo);
  switch(tempo.charAt(2)) {
      case 't' :
          return (2/3) * notation;
      case '/' :
          return notation;
      case '.' :
          return notation * 1.5;
      case 'D' :
          return notation * 2.0;
      case 'T' :
          return notation * 3.0;
      default :
          return 0;
  }
}

float getTempo(String tempoInput, float tempo) {
  float tempoToSecondsRatio = 100.0/6.0 * tempo;
  return round(getTempoModifier(tempoInput) * (1000000 / tempoToSecondsRatio));
}
