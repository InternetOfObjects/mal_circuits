

/*
 * 0, 1 ,2
 * 8, 0, 10
 * 
 * 0, 1, 2
 */

int interval = 0;
double distance = 0;

int OVER_DISTANCE = -1;

void setup() {

    pinMode( 3, OUTPUT );
    pinMode( 11, INPUT );

    pinMode( 1, OUTPUT );
    pinMode( 9, INPUT );

    pinMode( 2, OUTPUT );
    pinMode( 10, INPUT );
    
    Serial.begin( 9600 );
}

int getSuperSonicSensor(int output_pin, int input_pin) {
    int interval = 0;
    double distance = 0;

    // pulse !
    digitalWrite( output_pin, HIGH );
    delayMicroseconds( 100 );
    digitalWrite( output_pin, LOW );

    // mesure the interval 
    interval = pulseIn( input_pin, HIGH );

    distance = interval * 0.017; // cm 

    if(distance < 100 && distance > 0) {
      return int(distance);
    }

    return OVER_DISTANCE;
}

int getIRDASensor(int pin) {
  int irda =analogRead(pin);
  int val = (6762/(irda-9))-4;

  if (val < 100 && val > 0) {
      return val;
  }

  return OVER_DISTANCE;
}

void loop() {
  
  Serial.print(getSuperSonicSensor(3, 11));
  Serial.print("\t");
  Serial.print(getSuperSonicSensor(1, 9));
  Serial.print("\t");
  Serial.print(getSuperSonicSensor(2, 10));
  Serial.print("\t");
  Serial.print(getIRDASensor(0));
  Serial.print("\t");
  Serial.print(getIRDASensor(1));
  Serial.print("\t");
  Serial.print(getIRDASensor(2));
  Serial.print("\n");
  
}
