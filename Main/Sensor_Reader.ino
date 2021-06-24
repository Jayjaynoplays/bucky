//void GetSensorStatus() { //Get all the sensor status
//  for (int i = 0; i < 7; i++) {
//    Line[i] = ReadLine(i);
//  }
//}
 void GetSensorStatus() { //Get all the sensor status
   for (int i = 0; i < 7; i++) {
     Line[i] = ReadLine(i);
     if(i == 6) {
       Serial.print(Line[i]);
       Serial.println("     ");
     } else {
       Serial.print(Line[i]);
       Serial.print("     ");
     }  
   }
 }
bool ReadLine(int index) { //Get the sensor status for each sensor
  int temp = analogRead(Sensors[index]);
  if (temp <= Sensor_HIGH) {
    return true;
  }
  else {
    return false;
  }
}
