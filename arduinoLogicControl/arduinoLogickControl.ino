const int YellowLED = 2; //2 пин на плате Arduino будет относится к желтому светодиоду
const int RedLED = 3;    //3 пин на плате Arduino будет относится к красному светодоиоду



void setup()
{
Serial.begin(9600);            //настраиваем скорость передачи данных
pinMode(YellowLED, OUTPUT);     //настраиваем пин на режим, который будет выдавать 5V после разрешения на выдачу напряжения
pinMode(RedLED, OUTPUT);       //настраиваем пин на режим, который будет выдавать 5V после разрешения на выдачу напряжения
}

void loop()
{
  /*
  Так как в АЦП Arduino используется 10 бит, то он может выдавать значение от 0 до 1023, это значение
  соотвествует рабочему диапазону напряжения 0 - 5V. Решается пропорцией.
  voltageYellowLED и voltageRedLED используются для отправки напряжения в COM Port,
  где в WindowsWorms будет отображаться дейсвительно ли горит светодиод и есть ли напряжение.
  */
  //float voltageYellowLED = analogRead(A0) * (5.0 / 1023.0);
  //float voltageRedLED = analogRead(A1) * (5.0 / 1023.0);
  if(Serial.available() > 0)   //Если в буффере приема COM Port`a хранится какая-то команда, то заходим в условие
  {
    String serialInput = Serial.readString();   //Создаем переменную, в которую сохраняем содержимое буффера (ограничение по размеру только в самой памяти платы Arduino UNO, ~2КБ), завершающий символ \n или \r

    if(serialInput == "YellowON")               //Если буффер хранит "YellowON", то входим в условие
    {
      digitalWrite(YellowLED, HIGH);            //HIGH - выдает через пин напряжение (5V). Через светодиод проходит ток, затем к резистору и в землю.
    }

    else if(serialInput == "YellowOFF")
    {
      digitalWrite(YellowLED, LOW);            //LOW - отключает питание у пина, тем самым светодиод гаснит
    }

    else if(serialInput == "RedON")
    {
      digitalWrite(RedLED, HIGH);
    }

    else if(serialInput == "RedOFF")
    {
      digitalWrite(RedLED, LOW);
    }
  }  
}
