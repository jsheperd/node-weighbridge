const int MAXTIME = 400;
const int bSize = 20;
char buffer[bSize];
int ByteCount;


void setup () {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(MAXTIME);
  memset(buffer, 0, bSize);
}

void loop () {
  if (Serial.available()) {
    ByteCount = -1;
    ByteCount = Serial.readBytesUntil( '\n', buffer, bSize); // We are expecting \r\n closing
    if(ByteCount > 0) {
      //Serial.println(ByteCount, DEC);
      if(strcmp( buffer, "AX:T?\r") == 0 ) Serial.println("XA:B0002");  
      else if(strcmp( buffer, "AX:N?\r") == 0 ) Serial.println("XA:T0010"); 
      else if(strcmp( buffer, "AX:B?\r") == 0 ) Serial.println("XA:T0012");
      else if(strcmp( buffer, "AX:NU\r") == 0 ) Serial.println("XA:OK");
      else if(strcmp( buffer, "AX:TA\r") == 0 ) Serial.println("XA:OK");
      else if(strcmp( buffer, "AX:BR\r") == 0 ) Serial.println("XA:OK");
      else if(strcmp( buffer, "AX:NT\r") == 0 ) Serial.println("XA:OK");
      else if(strcmp( buffer, "AX:TR\r") == 0 ) Serial.println("XA:OK");
      else Serial.println("XA:NACK");
      Serial.flush();
      memset(buffer, 0, bSize);
    }
  }
  delay(10);
}

