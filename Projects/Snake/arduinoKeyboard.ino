// 1) Configura el número de puerto según 
//    tu microcontrolador. UP, DOWN, LEFT y RIGHT son pulsadores
//    ALIVELED es un LED

#define ALIVELED 8
#define UP 4
#define DOWN 5
#define LEFT 6
#define RIGHT 7

void setup() {

    // 2) Configura los puertos de entradad/salida
    
     pinMode(UP, INPUT_PULLUP);
    digitalWrite(UP, false);
    pinMode(DOWN, INPUT_PULLUP);
    digitalWrite(DOWN, false);
    pinMode(LEFT, INPUT_PULLUP);
    digitalWrite(LEFT, false);
    pinMode(RIGHT, INPUT_PULLUP);
    digitalWrite(RIGHT, false);
    
    
    pinMode(ALIVELED, OUTPUT);
    analogReadResolution(20);
    
    // 3) configura el puerto serial
   
    Serial.begin(115200);
   
        
}                  
    

}

void Task1() {
    // 4) Realiza una tarea NO BLOQUEANTE que 
    //    encienda y apague el LED ALIVELED a una frecuencia 
    //    de 2 Hz
    
    static uint32_t previousMillis = 0;
    const uint32_t interval = 500;
    static bool ledState = false;
    uint32_t currentMillis = millis();
    
    if ( (currentMillis - previousMillis) >= interval) {
    previousMillis = currentMillis;

    if (ledState == false) {
      ledState = true;
    } else {
      ledState = false;
    }
    digitalWrite(ALIVELED, ledState);
    
}


void Task2() {
    
    // 5) Realiza la tarea que se comunicará con la aplicación 
    //    interactiva para enviar el estado de los pulsadores.  
    
   if (digitalRead(4) == HIGH && digitalRead(5) == LOW && digitalRead(6) == LOW && digitalRead(7) == LOW)
  {
      estado1 = 1;
      estado2 = 0;
      estado3 = 0;
      estado4 = 0;
  }
  if (digitalRead(4) == LOW && digitalRead(5) == HIGH && digitalRead(6) == LOW && digitalRead(7) == LOW)
  {
      estado1 = 0;
      estado2 = 1;
      estado3 = 0;
      estado4 = 0;
  }
  if (digitalRead(4) == LOW && digitalRead(5) == LOW && digitalRead(6) == HIGH && digitalRead(7) == LOW)
  {
      estado1 = 0;
      estado2 = 0;
      estado3 = 1;
      estado4 = 0;
  }
  if (digitalRead(4) == LOW && digitalRead(5) == LOW && digitalRead(6) == LOW && digitalRead(7) == HIGH)
  {
      estado1 = 0;
      estado2 = 0;
      estado3 = 0;
      estado4 = 1;
  }
  if (Serial.available() > 0)
  {
    String dato = Serial.readStringUntil('\n');
    if (dato == "read")
    {
      if (estado1 == 1)
      {
        Serial.print("arriba");
      }
      if (estado2 == 1)
      {
        Serial.print("abajo");
      }
      if (estado3 == 1)
      {
        Serial.print("izquierda");
      }
      if (estado4 == 1)
      {
        Serial.print("derecha");
      }
     
    }
  }
}

void loop() {
  Task1();  // Alive LED
  Task2();  // Comunicación serial
}
