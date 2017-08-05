/* ********************Sintetizador de voz***************************/
/*                     *****Launchpad*****/

//#define rxPin 0    // Serial input (connects to Emic 2 SOUT)
//#define txPin 1    // Serial output (connects to Emic 2 SIN)
#define ledPin 8  // Most Arduino boards have an on-board LED on this pin
void Emic();

void setup()  {
  
  pinMode(ledPin, OUTPUT);
  Serial1.begin(9600);
 digitalWrite(ledPin, LOW);  // turn LED off
    Serial1.print('\n');             // Send a CR in case the system is already up
  while (Serial1.read() != ':');   // When the Emic 2 has initialized and is ready, it will send a single ':' character, so wait here until we receive it
  delay(10);                          // Short delay
  Serial1.flush();   // Flush the receive buffer
}


void loop()  // Main code, to run repeatedly
{
  Emic();
}

void Emic() {
 
  // Speak some text
  Serial1.print('S');
  Serial1.print("Hello. My name is Doctor Robo Piller.");  // Send the desired string to convert to speech
  Serial1.print('\n');
  digitalWrite(ledPin, HIGH);         // Turn on LED while Emic is outputting audio
  while (Serial1.read() != ':');   // Wait here until the Emic 2 responds with a ":" indicating it's ready to accept the next command
  digitalWrite(ledPin, LOW);
    
  delay(500);    // 1/2 second delay
  
  
  Serial1.print('S');
  Serial1.print("How are you?");  // Send the desired string to convert to speech
  Serial1.print('\n');
  digitalWrite(ledPin, HIGH);         // Turn on LED while Emic is outputting audio
  while (Serial1.read() != ':');   // Wait here until the Emic 2 responds with a ":" indicating it's ready to accept the next command
  digitalWrite(ledPin, LOW);
    
  delay(500);    // 1/2 second delay

  while(1)      // Demonstration complete!
  {
    delay(500);
    digitalWrite(ledPin, HIGH);
    delay(500);              
    digitalWrite(ledPin, LOW);
    }
  }


