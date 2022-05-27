//Example Code EP 5: Input Switch&Output LED 
// Summation Technology 

int led1 = 2; // กำหนดขาใช้งานของหลอด LED

int buttonPin = 3;  // กำหนดขาใช้งานของ Switch
int buttonState = 0;
void setup()
{
pinMode(led1, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 2 เป็น OUTPUT
pinMode(buttonPin, INPUT);// กำหนดขาทำหน้าที่ให้ขา 3 เป็น INPUT รับค่าจากสวิตช์
digitalWrite(led1, LOW);
}
void loop()
{
buttonState = digitalRead(buttonPin); // อ่านค่าสถานะขา3
if (buttonState == HIGH) { //กำหนดเงื่อนไขถ้าตัวแปล buttonState เก็บ ค่า 1(HIGH) ให้ทำในปีกกา
digitalWrite(led1, HIGH); // ไฟ LED 1ติด
}
else { //ถ้าตัวแปล buttonState ไม่ได้เก็บ ค่า 1(HIGH) คือ ตัวแปล buttonState เก็บค่า 0(LOW) อยู่ ให้ทำปีกกาข้างล่าง
digitalWrite(led1, LOW); // ไฟ LED 1ดับ
}
}
