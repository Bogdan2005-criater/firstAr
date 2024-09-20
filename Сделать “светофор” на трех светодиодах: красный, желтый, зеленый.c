//-Светофор работает в строгой последовательности цветов сигналов
//1. Зеленый сигнал — разрешает движение в данном направлении.
//2. Зеленый мигающий сигнал 3 раза — разрешает движение и предупреждает, что будет смена сигнала.
//3. Желтый сигнал — запрещает движение и предупреждает, что будет красный сигнал.
//4. Красный сигнал — запрещает движение в данном направлении
//-Добавить кнопку перехода пешехода в светофор


int greenLED = 9;
int yellowLED = 10;
int redLED = 11;
int buttonPin = 2;

bool pedestrianRequest = false; 
unsigned long lastButtonPress = 0;
const unsigned long delayTime = 5000; 

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW && millis() - lastButtonPress > delayTime) {
    pedestrianRequest = true;
    lastButtonPress = millis(); 
  }
  
  if (pedestrianRequest) {
    pedestrianLightCycle(); 
    pedestrianRequest = false; 
  } else {
    normalLightCycle(); 
  }
}

void normalLightCycle() {
  digitalWrite(greenLED, HIGH);
  delay(5000);
  
  for (int i = 0; i < 3; i++) {
    digitalWrite(greenLED, LOW);
    delay(500);
    digitalWrite(greenLED, HIGH);
    delay(500);
  }
  digitalWrite(greenLED, LOW);
  
  digitalWrite(yellowLED, HIGH);
  delay(2000);
  digitalWrite(yellowLED, LOW);
  
  digitalWrite(redLED, HIGH);
  delay(5000);
  digitalWrite(redLED, LOW);
}

void pedestrianLightCycle() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(yellowLED, HIGH);
    delay(500);
    digitalWrite(yellowLED, LOW);
    delay(500);
  }
  
  digitalWrite(redLED, HIGH);
  delay(5000);
  digitalWrite(redLED, LOW);
  
}

void controlLEDFromSerial() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == '1') {
      digitalWrite(greenLED, HIGH);  
    } else if (command == '0') {
      digitalWrite(greenLED, LOW);  
    }
  }
}

