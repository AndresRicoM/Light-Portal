/*
██╗     ██╗ ██████╗ ██╗  ██╗████████╗    ██████╗  ██████╗ ██████╗ ████████╗ █████╗ ██╗     
██║     ██║██╔════╝ ██║  ██║╚══██╔══╝    ██╔══██╗██╔═══██╗██╔══██╗╚══██╔══╝██╔══██╗██║     
██║     ██║██║  ███╗███████║   ██║       ██████╔╝██║   ██║██████╔╝   ██║   ███████║██║     
██║     ██║██║   ██║██╔══██║   ██║       ██╔═══╝ ██║   ██║██╔══██╗   ██║   ██╔══██║██║     
███████╗██║╚██████╔╝██║  ██║   ██║       ██║     ╚██████╔╝██║  ██║   ██║   ██║  ██║███████╗
╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚═╝      ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝

Light Portal is a research panel part of the escPod. 
The panel has the goal of exploring two main questions:
  - How can we create devices that allow us to harness the benefits of light within closed spaces?
  - How can we use bioinspiration to create better non verbal communication between humans and machines. 

The following code was created to test functionallity of panel. It only opens up and closes the mechanisms
in a randomized manner. 

I encourage people to add different fucntions and sensors to the main device to expand the exploration of these questions!

Find out more about how to build your own light portal here:
https://github.com/AndresRicoM/Light-Portal
  
MIT Media Lab
Andres Rico - 2018

*/

int right = 8; //Declare control pins for activating motors. 
int left = 9;
bool state = true; 
bool opened;


void setup() {
  Serial.begin(9600);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  openiris();
  digitalWrite(left, HIGH);
  delay(1200);
  stopmotor();
  opened = true;
}

void loop() {

  while (abierto == true) {
    delay(random(300000,1000000)); //Random delay for iris to activate
    if (random(0,100) > 50) { //Change iris state with a probability of 50%
      closeiris();
      delay(500);
      abierto = false;
      Serial.println("Iris has been closed");
    }
  }

  while (abierto == false) {
    delay(random(300000,1000000)); //Random delay for iris to activate 
    if (random(0,100) > 50) { //Change iris state with a probability of 50%
      openiris();
      delay(1200);
      opened = true;
      Serial.println("Iris has been opened");
    }  
  }
  
  
}

void stopmotor() { //Function for stoping motors. 
  digitalWrite(right, LOW);
  digitalWrite(left, LOW);
}

void openiris() { //Function for activating motors and opening mechanism. 
  digitalWrite(left, HIGH);
  delay(2000);
  digitalWrite(left, LOW);
}

void closeiris() { //Function for activating motors and closing iris. Iris deos not close completelly due to mechanical constrains. 
  digitalWrite(right, HIGH);
  delay(400);
  digitalWrite(right, LOW);
}

