void LinePIDFilter() { //PID control in line tracking mode
  //straight: 6, 0, 15, speed: 75
  static double kP = 20, kI = 0.03, kD = 25;
  static double gain = 100;
  static double prev_error = 0, prev_I = 0;
  double p = 0, i = 0, d = 0, pid_value;

  p = GetError();
  i = p + prev_I;
  d = p - prev_error;

  pid_value = kP * p + kI * i + kD * d;
  prev_I = i;
  prev_error = p;
  pid_value *= gain/100;
  Motor[0] = INITIAL_SPEED + pid_value;
  Motor[1] = INITIAL_SPEED - pid_value;
}
