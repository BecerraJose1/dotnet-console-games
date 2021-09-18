// 1) Configura el número de puerto según 
//    tu microcontrolador. UP, DOWN, LEFT y RIGHT son pulsadores
//    ALIVELED es un LED

#define ALIVELED 5
#define UP 23
#define DOWN 18
#define LEFT 21
#define RIGHT 19

void setup() {

    // 2) Configura los puertos de entradad/salida

    // 3) configura el puerto serial

}

void Task1() {
    // 4) Realiza una tarea NO BLOQUEANTE que 
    //    encienda y apague el LED ALIVELED a una frecuencia 
    //    de 2 Hz
}


void Task2() {
    
    // 5) Realiza la tarea que se comunicará con la aplicación 
    //    interactiva para enviar el estado de los pulsadores. 
}

void loop() {
  Task1();  // Alive LED
  Task2();  // Comunicación serial
}
