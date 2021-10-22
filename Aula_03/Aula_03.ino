#define RAIO 1
#define STEP 0.001

#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15


int timer0 = 0;

#define DEBUG
//#define LED 2

void setup() {
  // put your setup code here, to run once:
  #ifdef DEBUG
    Serial.begin(57600);
  #endif
  #ifdef LED
    pinMode(LED, OUTPUT);
  #endif
}

void loop() {
  #ifdef LED
    digitalWrite(LED, HIGH);
  #endif
  timer0 = millis();
  float h = STEP;
  float totalq = h *RAIO;
    while (h <=RAIO){
        float alt =RAIO * float(sin(acos(h/RAIO)));
        float area = STEP * alt;
        totalq += area;
        h = h+STEP;
    }
  totalq = totalq * 4;
  #ifdef DEBUG
  Serial.print("O tempo para calcular o valor de PI foi de (ms): ");
  Serial.println(millis() - timer0);
  Serial.print("O valor de pi calculado é: ");
  Serial.println(totalq);
  #endif
  #ifdef LED
    digitalWrite(LED, LOW);
  #endif
  delay(1000);
}
