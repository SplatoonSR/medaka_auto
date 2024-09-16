//www.elegoo.com
//リレースイッチというもので、
既存の餌やり機の電源を遠隔操作できるプログラム

#define DIRA 3 //リレースイッチ1
#define DIRB 4 //リレースイッチ2
#define INP A0 //マイコンから操作する

int i;

void setup() {
  //初期設定
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  pinMode(INP, INPUT);
  Serial.begin(9600);//パソコンへの通信用
}

void loop() {

    //マイコンからの入力
    Serial.println(analogRead(inp));

    if(analogRead(INP) > 200){      
      Serial.println("spin");
      digitalWrite(DIRA, HIGH); //motor spins
      digitalWrite(DIRB, LOW);
    }
    else
    {
      Serial.println("stop");
      digitalWrite(DIRA, LOW); //motor stops
      digitalWrite(DIRB, HIGH);
    }
  
  
  // enable on
  for (i = 0; i < 5; i++)
  {
    Serial.println("spin");
    digitalWrite(DIRA, HIGH); //motor spins
    digitalWrite(DIRB, LOW);
    delay(2000);
    Serial.println("stop");
    digitalWrite(DIRA, LOW); //motor stops
    digitalWrite(DIRB, HIGH);
    delay(2000);
  }
}
