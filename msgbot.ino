#include <LedControl.h>

int DIN = 2;
int CS =  3;
int CLK = 4;

byte fuck1[8]=     {0x00,0x00,0xff,0x11,0x11,0x11,0x00,0x00,};
byte fuck2[8]=     {0x00,0x00,0x7e,0x80,0x80,0x7e,0x00,0x00,};
byte fuck3[8]=     {0x00,0x00,0x7e,0x81,0x81,0x81,0x00,0x00,};
byte fuck4[8]=     {0x00,0x00,0xff,0x18,0x24,0x42,0x81,0x00,};

byte heart1[8]=   {0x0c,0x1e,0x3e,0x7c,0x7c,0x3e,0x1e,0x0c,};
byte heart2[8]=   {0x00,0x0c,0x1c,0x38,0x38,0x1c,0x0c,0x00,};

byte haha1[8]=   {0x30,0x56,0x96,0x90,0x90,0x96,0x56,0x30,};
byte haha2[8]=   {0x30,0x56,0x56,0x50,0x50,0x56,0x56,0x30,};

byte cry1[8] = {0x02,0x02,0x42,0x20,0x20,0x42,0x02,0x02,};
byte cry2[8] = {0x02,0x06,0x42,0x20,0x20,0x42,0x06,0x02,};
byte cry3[8] = {0x02,0x0e,0x42,0x20,0x20,0x42,0x0e,0x02,};
byte cry4[8] = {0x02,0x1e,0x42,0x20,0x20,0x42,0x1e,0x02,};

byte awkward1[8] = {0x06,0x22,0x22,0x20,0x20,0x26,0x22,0x02,};
byte awkward2[8] = {0x02,0x22,0x26,0x20,0x20,0x22,0x22,0x06,};

byte relax1[8] = {0x02,0x06,0x42,0x40,0x40,0x42,0x26,0x02,};
byte relax2[8] = {0x01,0x05,0x41,0x40,0x40,0x41,0x25,0x01,};

byte sleepy1[8] = {0x0a,0x0e,0x4a,0x20,0x20,0x4a,0x0e,0x0a,};
byte sleepy2[8] = {0x06,0x06,0x46,0x20,0x20,0x46,0x06,0x06,};

byte jiong1[8] = {0xff,0x89,0xe7,0xa1,0xa1,0xe7,0x89,0xff,};
byte jiong2[8] = {0xff,0x89,0xc7,0xc1,0xc1,0xc7,0x89,0xff,};

byte cao1[8] = {0x42,0x42,0x5b,0x5a,0xfa,0x5a,0x5b,0x42,};

byte laugh1[8] = {0x38,0x28,0x38,0x08,0x04,0xea,0xa9,0xea,};
byte laugh2[8] = {0x28,0x38,0x08,0x04,0xea,0xa9,0xea,0x04,};
byte laugh3[8] = {0x38,0x08,0x04,0xea,0xa9,0xea,0x04,0x08,};
byte laugh4[8] = {0x08,0x04,0xea,0xa9,0xea,0x04,0x08,0x38,};
byte laugh5[8] = {0x04,0xea,0xa9,0xea,0x04,0x08,0x38,0x28,};
byte laugh6[8] = {0xea,0xa9,0xea,0x04,0x08,0x38,0x28,0x38,};
byte laugh7[8] = {0xa9,0xea,0x04,0x08,0x38,0x28,0x38,0x08,};
byte laugh8[8] = {0xea,0x04,0x08,0x38,0x28,0x38,0x08,0x04,};
byte laugh9[8] = {0x04,0x08,0x38,0x28,0x38,0x08,0x04,0xea,};
byte laugh10[8] = {0x08,0x38,0x28,0x38,0x08,0x04,0xea,0xa9,};


#define FLASH_NUM 10
#define INT_TIME 400 // interval time --> flash speed
#define BUF_SIZE  32
char newMessage[BUF_SIZE] = "";
bool newMessageAvailable = false;


LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value (15)
 lc.clearDisplay(0);         // and clear the display
 Serial.begin(115200);
 Serial.print("\n[Receiving Messages]\nType a message: [heart/fuck/haha/bye/cry]\n");
}

void loop()
{ 
    char c;
    while(Serial.available()) 
    {
      c = processCharInput(newMessage, Serial.read());
      Serial.print(c);
      if (c == '\n') 
      {
        Serial.println();
        //Full command received. Do your stuff here!      
        if (strcmp("heart", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            heart();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("haha", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            haha();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("cry", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            cry();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("fuck", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            fuck();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("awkward", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            awkward();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("relax", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            relax();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("sleepy", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            sleepy();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("jiong", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            jiong();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("cao", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            cao();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }
        else if (strcmp("laugh", newMessage) == 0)
        {
          int n = 0;
          while (n < FLASH_NUM)
          {
            laugh();
            n = n + 1;
          }
          lc.clearDisplay(0);
        }

        
        newMessage[0] = 0;
      }
    }
}

void haha()
{
  printByte(haha1);
  delay(INT_TIME);
  printByte(haha2);
  delay(INT_TIME);
}

void heart()
{
  printByte(heart1);
  delay(INT_TIME);
  printByte(heart2);
  delay(INT_TIME);
}

void cry()
{
  printByte(cry1);
  delay(INT_TIME/2);
  printByte(cry2);
  delay(INT_TIME/2);
  printByte(cry3);
  delay(INT_TIME/2);
  printByte(cry4);
  delay(INT_TIME/2);
}

void fuck()
{
  printByte(fuck1);
  delay(INT_TIME);
  printByte(fuck2);
  delay(INT_TIME);
  printByte(fuck3);
  delay(INT_TIME);
  printByte(fuck4);
  delay(INT_TIME);
}

void awkward()
{
  printByte(awkward1);
  delay(INT_TIME);
  printByte(awkward2);
  delay(INT_TIME);
}

void relax()
{
  printByte(relax1);
  delay(INT_TIME);
  printByte(relax2);
  delay(INT_TIME);
}

void sleepy()
{
  printByte(sleepy1);
  delay(INT_TIME*2);
  printByte(sleepy2);
  delay(INT_TIME);
}

void jiong()
{
  printByte(jiong1);
  delay(INT_TIME*2);
  printByte(jiong2);
  delay(INT_TIME);
}

void cao()
{
  printByte(cao1);
  delay(INT_TIME);
}

void laugh()
{
  printByte(laugh1);
  delay(INT_TIME/8);
  printByte(laugh2);
  delay(INT_TIME/8);
  printByte(laugh3);
  delay(INT_TIME/8);
  printByte(laugh4);
  delay(INT_TIME/8);
  printByte(laugh5);
  delay(INT_TIME/8);
  printByte(laugh6);
  delay(INT_TIME/8);
  printByte(laugh7);
  delay(INT_TIME/8);
  printByte(laugh8);
  delay(INT_TIME/8);
  printByte(laugh9);
  delay(INT_TIME/8);
  printByte(laugh10);
  delay(INT_TIME/8);
}



void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}


char processCharInput(char* cmdBuffer, const char c)
{
  //Store the character in the input buffer
  if (c >= 32 && c <= 126) //Ignore control characters and special ascii characters
  {
    if (strlen(cmdBuffer) < BUF_SIZE) 
    { 
      strncat(cmdBuffer, &c, 1);   //Add it to the buffer
    }
    else  
    {   
      return '\n';
    }
  }
  else if ((c == 8 || c == 127) && cmdBuffer[0] != 0) //Backspace
  {

    cmdBuffer[strlen(cmdBuffer)-1] = 0;
  }

  return c;
}
