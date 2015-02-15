String readString;

int red= 13;
int green= 12;
int blue= 11;

int servo1pos, servo2pos, servo3pos;

// the setup routine runs once when you press reset:
void setup() {                
	// initialize the digital pin as an output.
	pinMode(red, OUTPUT); 
	pinMode(green, OUTPUT); 
	pinMode(blue, OUTPUT); 
	Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {

	while (Serial.available()) {
		delay(3);  //delay to allow buffer to fill 
		if (Serial.available() >0) {
			char c = Serial.read();  //gets one byte from serial buffer
			readString += c; //makes the string readString
		} 
	}

	if (readString.length() >0)
	{
		Serial.println(readString); //see what was received
		
		int commaIndex = readString.indexOf(' ');
		int secondCommaIndex = readString.indexOf(' ', commaIndex+1);
		
		String firstValue = readString.substring(0, commaIndex);
		String secondValue = readString.substring(commaIndex+1, secondCommaIndex);
		String thirdValue = readString.substring(secondCommaIndex);
		servo1pos = firstValue.toInt();
		servo2pos = secondValue.toInt();
		servo3pos = thirdValue.toInt();
				
		if (servo1pos > 40) {
			digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
		} else { 
			digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
		}
		
		if (servo2pos > 40) {			
			digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)			
		} else { 
			digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
		}

		if (servo3pos > 40) {			
			digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
		} else {			
			digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW	
		}	
	}
	//очистим строку
	readString = "";
}
