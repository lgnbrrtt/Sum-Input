const long interval = 1;
long t = 0;

int tempo = 20;

const long dur1A = 45 * interval;
const long dur1B = 48 * interval;
const long dur1C = 100 * interval;

float vals1A[] = {0, 1, 29, 4, 8, 33, 0, 1, 11, 4, 26, 15, 18, 19, 11, 22, 8, 15};
float vals1B[] = {6, 7, 35, 10, 14, 1, 6, 7, 17, 10, 32, 3, 24, 25, 17, 28, 14, 3};
float vals1C[] = {12, 13, 23, 16, 2, 27, 12, 13, 5, 16, 20, 9, 30, 31, 5, 34, 2, 9};


bool play1A = false;
bool play1B = false;
bool play1C = false;

int seq1A = 0;
int seq1B = 0;
int seq1C = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if ((t % dur1A) == 0) {
    play1A = true;
    play1B = false;
    play1C = false;
  }

  else if ((t % dur1B) == 0) {
    play1A = false;
    play1B = true;
    play1C = false;
  }

  else if ((t % dur1C) == 0) {
    play1A = false;
    play1B = false;
    play1C = true;
  }

  else {};

  //////////////////////////////////////

  if (play1A == true) {
    if (random(100) > 80) {
      tone(3, 60);
      noTone(6);
      noTone(9);
    }
    else {
      tone(3, 35 * pow(2, (vals1A[seq1A % 18]) / 18));
      noTone(6);
      noTone(9);
      seq1A = seq1A + 1;
    }
  }

  else if (play1B == true) {
    if (random(100) > 80) {
      noTone(3);
      tone(6, 60);
      noTone(9);
    }
    else {
      noTone(3);
      tone(6, 35 * pow(2, (vals1B[seq1B % 18]) / 18));
      noTone(9);
      seq1B = seq1B + 1;
    }
  }

  else if (play1C == true) {
      noTone(3);
      noTone(6);
      tone(9, 60);
  }

  else {};

  t = t + interval;

  if (random(100) > 90) {
    tempo = random(40) + 1;
  }

  delay(tempo);
}
