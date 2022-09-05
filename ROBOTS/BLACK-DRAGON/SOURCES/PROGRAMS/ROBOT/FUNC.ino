void left_wheel(int Speed)
{
  int dir = (Speed + 255) / 255;
  digitalWrite(A0, !dir);
  digitalWrite(A1, dir);
  analogWrite(9, abs(Speed));
}

void right_wheel(int Speed)
{
  int dir = (Speed + 255) / 255;
  digitalWrite(A2, dir);
  digitalWrite(A3, !dir);
  analogWrite(10, abs(Speed));
}

void motion(int x, int y)
{
  int Speed = map(x, 0, 1024, 255, -255); 
  int dif = map(y, 0, 1024, -255, 255);
  int speed_l = Speed + dif;
  int speed_r = Speed - dif;
  speed_l = constrain(speed_l, -255, 255);
  speed_r = constrain(speed_r, -255, 255);
  left_wheel(speed_l);
  right_wheel(speed_r);
}
