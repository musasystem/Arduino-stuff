
#define TRANSMITTER

// Arduino digital pins
#define BUTTON_PIN  2
#define BUTTON_PIN2  4
#define LED_PIN     6

// Button hardware is setup so the button goes LOW when pressed
#define BUTTON_PRESSED LOW
#define BUTTON_NOT_PRESSED HIGH
// Maurice Ribble 
// 8-30-2009
// http://www.glacialwanderer.com/hobbyrobotics
// Used Arduino 0017
// This does does some error checking to try to make sure the receiver on this one way RF 
//  serial link doesn't repond to garbage

#define NETWORK_SIG_SIZE 3

#define VAL_SIZE         2
#define CHECKSUM_SIZE    1
#define PACKET_SIZE      (NETWORK_SIG_SIZE + VAL_SIZE + CHECKSUM_SIZE)

// The network address byte and can be change if you want to run different devices in proximity to each other without interfearance
#define NET_ADDR 5
int val = 0;
int val2 = 0;
int ledPin = 7;
const byte g_network_sig[NETWORK_SIG_SIZE] = {0x8F, 0xAA, NET_ADDR};  // Few bytes used to initiate a transfer

// Sends an unsigned int over the RF network
void writeUInt(unsigned int val)
{
  byte checksum = (val/256) ^ (val&0xFF);
  Serial.write(0xF0);  // This gets reciever in sync with transmitter
  Serial.write(g_network_sig, NETWORK_SIG_SIZE);
  Serial.write((byte*)&val, VAL_SIZE);
  Serial.write(checksum); //CHECKSUM_SIZE
}


void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUTTON_PIN2, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(ledPin, OUTPUT);
  Serial.begin(1200);  // Hardware supports up to 2400, but 1200 gives longer range
}


void loop()
{

  val = digitalRead(BUTTON_PIN);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    
    digitalWrite(ledPin, HIGH);
    writeUInt(240); // Put any number you want to send here (71 is just a test)
  } else {
digitalWrite(ledPin, LOW);
  }

  val2 = digitalRead(BUTTON_PIN2);  // read input value
  if (val2 == HIGH) {         // check if the input is HIGH (button released)
    
    digitalWrite(ledPin, HIGH);
    writeUInt(275); // Put any number you want to send here (71 is just a test)
  } else {
digitalWrite(ledPin, LOW);
  }

  
}





