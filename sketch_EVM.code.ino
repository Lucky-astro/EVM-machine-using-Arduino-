#include<LiquidCrystal.h>
LiquidCrystal lcd(11,10,9,8,7,6);

#define sw1 A0//Button 1
#define sw2 A1//Button 2
#define sw3 A2//Button 3
#define sw4 A3//Button 4
#define sw5 A4//Button 5

int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;

void setup()
{
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT);
  pinMode(sw5,INPUT);
  
  pinMode(13,OUTPUT);//Red led
  pinMode(12,OUTPUT);//green led
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("VOTING MACHINE ");
  lcd.setCursor(0,1);
  lcd.print("Please press");
  delay(3000);
  
  digitalWrite(sw1,HIGH);
  digitalWrite(sw2,HIGH);
  digitalWrite(sw3,HIGH);
  digitalWrite(sw4,HIGH);
  digitalWrite(sw5,HIGH);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("JSP");
  lcd.setCursor(4,0);
  lcd.print("TDP");
  lcd.setCursor(8,0);
  lcd.print("YCP");
  lcd.setCursor(12,0);
  lcd.print("BJP");
}
void loop(){
  lcd.setCursor(0,0);
  lcd.print("JSP");
  lcd.setCursor(1,1);
  lcd.print(vote1);
  lcd.setCursor(4,0);
  lcd.print("TDP");
  lcd.setCursor(5,1);
  lcd.print(vote2);
  lcd.setCursor(8,0);
  lcd.print("YCP");
  lcd.setCursor(9,1);
  lcd.print(vote3);
  lcd.setCursor(12,0);
  lcd.print("BJP");
  lcd.setCursor(13,1);
  lcd.print(vote4);
  
  if(digitalRead(sw1)==0)
  {
    vote1++;
    digitalWrite(12,HIGH);
    delay(500);
    while(digitalRead(sw1)==0);
    digitalWrite(12,LOW);
    delay(1000);
  }
  
  if(digitalRead(sw2)==0)
  {
    vote2++;
    digitalWrite(12,HIGH);
    delay(500);
    while(digitalRead(sw2)==0);
    digitalWrite(12,LOW);
    delay(1000);
  }

  if(digitalRead(sw3)==0)
  {
    vote3++;
    digitalWrite(12,HIGH);
    delay(500);
    while(digitalRead(sw3)==0);
    digitalWrite(12,LOW);
    delay(1000);
  }

  if(digitalRead(sw4)==0)
  {
    vote4++;
    digitalWrite(12,HIGH);
    delay(500);
    while(digitalRead(sw4)==0);
    digitalWrite(12,LOW);
    delay(1000);
  }
if (digitalRead(sw5) == 0)
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FINAL RESULT");

    delay(1500);
    lcd.clear();

    // Find the highest vote
    int maxVote = vote1;
    String winner = "JSP";

    if (vote2 > maxVote) { maxVote = vote2; winner = "TDP"; }
    if (vote3 > maxVote) { maxVote = vote3; winner = "YCP"; }
    if (vote4 > maxVote) { maxVote = vote4; winner = "BJP"; }

    lcd.setCursor(0,0);
    lcd.print("Winner: ");
    lcd.print(winner);

    lcd.setCursor(0,1);
    lcd.print("Votes: ");
    lcd.print(maxVote);

    // Green LED to indicate result shown
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(12, LOW);

    while(digitalRead(sw5) == 0); // wait until button released
    delay(1000);
}
}
  