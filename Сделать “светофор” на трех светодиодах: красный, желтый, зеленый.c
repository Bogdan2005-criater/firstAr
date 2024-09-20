//-Светофор работает в строгой последовательности цветов сигналов
//1. Зеленый сигнал — разрешает движение в данном направлении.
//2. Зеленый мигающий сигнал 3 раза — разрешает движение и предупреждает, что будет смена сигнала.
//3. Желтый сигнал — запрещает движение и предупреждает, что будет красный сигнал.
//4. Красный сигнал — запрещает движение в данном направлении
//-Добавить кнопку перехода пешехода в светофор


const int greenLed = 9;
const int yellowLed = 10;
const int redLed = 11;
const int buttonPin = 2;

bool pedestrianPressed = false;
unsigned long previousMillis = 0;
const long interval = 1000; 

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  

  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    pedestrianPressed = true;
  }

  if (pedestrianPressed) {
    changeToGreen();           
    blinkGreen(3);            
    changeToYellow();  
    delay(5000); 
    changeToRed();           
    delay(5000);               
    pedestrianPressed = false; 
  } else {
    changeToGreen();
    delay(5000);              
    blinkGreen(3);             
    changeToYellow();
    delay(5000);
    changeToRed();
    delay(8000);              
  }
}

void changeToGreen() {
  digitalWrite(greenLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
}

void blinkGreen(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(greenLed, LOW);
    delay(500);              
    digitalWrite(greenLed, HIGH);
    delay(500);
  }
}

void changeToYellow() {
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(redLed, LOW);
}

void changeToRed() {
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, HIGH);
}
