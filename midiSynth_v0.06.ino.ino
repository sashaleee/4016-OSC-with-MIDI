#include <MIDI.h>

boolean sustain;
boolean mute;

MIDI_CREATE_DEFAULT_INSTANCE();

// -----------------------------------------------------------------------------

void handleControlChange(byte channel, byte number, byte value) {

  if (number == 64 && value == 127) {
    sustain = HIGH;
  }
  if (number == 64 && value == 0) {
    sustain = LOW;
  }
}

// -----------------------------------------------------------------------------

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  if (channel == 1) {
    if (pitch == 62) { //D
      digitalWrite(12, HIGH);
    }
    if (pitch == 65) { //F
      digitalWrite(13, HIGH);
    }
    if (pitch == 67) { //G
      digitalWrite(8, HIGH);
    }
    if (pitch == 69) { //A
      digitalWrite(11, HIGH);
    }
    if (pitch == 72) { //C
      digitalWrite(10, HIGH);
    }
    if (pitch == 74) { //D
      digitalWrite(9, HIGH);
    }
  }

  else if (channel == 2) {
    if (pitch == 62) { //D
      digitalWrite(12, HIGH);
    }
    if (pitch == 63) { //F
      digitalWrite(13, HIGH);
    }
    if (pitch == 67) { //G
      digitalWrite(8, HIGH);
    }
    if (pitch == 69) { //A
      digitalWrite(11, HIGH);
    }
    if (pitch == 70) { //C
      digitalWrite(10, HIGH);
    }
    if (pitch == 74) { //D
      digitalWrite(9, HIGH);
    }
  }
}

// -----------------------------------------------------------------------------

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  if (channel == 1) {
    if (pitch == 62) { //D
      digitalWrite(12, LOW);
    }
    if (pitch == 65) { //F
      digitalWrite(13, LOW);
    }
    if (pitch == 67) { //G
      digitalWrite(8, LOW);
    }
    if (pitch == 69) { //A
      digitalWrite(11, LOW);
    }
    if (pitch == 72) { //C
      digitalWrite(10, LOW);
    }
    if (pitch == 74) { //D
      digitalWrite(9, LOW);
    }
  }

  else if (channel == 2) {
    if (pitch == 62) { //D
      digitalWrite(12, LOW);
    }
    if (pitch == 63) { //F
      digitalWrite(13, LOW);
    }
    if (pitch == 67) { //G
      digitalWrite(8, LOW);
    }
    if (pitch == 69) { //A
      digitalWrite(11, LOW);
    }
    if (pitch == 70) { //C
      digitalWrite(10, LOW);
    }
    if (pitch == 74) { //D
      digitalWrite(9, LOW);
    }
  }
}

// -----------------------------------------------------------------------------

void setup()
{
  sustain = false;
  mute = false;

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleControlChange);

  MIDI.begin(MIDI_CHANNEL_OMNI); // Listen to all MIDI channel;
}

// -----------------------------------------------------------------------------

void loop()
{
  MIDI.read();
}
