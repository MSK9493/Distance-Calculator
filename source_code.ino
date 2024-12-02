1.  //Distance Meter OLED Display

2.  #include <SPI.h>
3.  #include <Wire.h>
4.  #include <Adafruit_GFX.h>
5.  #include <Adafruit_SSD1306.h>

6.  #define trigPin 9
7.  #define echoPin 8

8.  #define OLED_RESET 4
9.  Adafruit_SSD1306 display(OLED_RESET);

10. void setup() {
11. Serial.begin (9600);
12. pinMode(trigPin, OUTPUT);
13. pinMode(echoPin, INPUT);
14. display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
15. display.clearDisplay();

16. }

17. void loop() {
18. float duration;
19. float distance_cm;
20. float distance_in;
21. digitalWrite(trigPin, LOW); //PULSE __|---|__
22. delayMicroseconds(2);
23. digitalWrite(trigPin, HIGH);
24. delayMicroseconds(10);
25. digitalWrite(trigPin, LOW);

26. duration = pulseIn(echoPin, HIGH);

27. distance_cm = (duration/2) / 29.1;
28. distance_in = (duration/2) / 73.914;

29. display.setCursor(25,0); //oled display
30. display.setTextSize(1);
31. display.setTextColor(WHITE);
32. display.println("Distance Meter");

33. display.setCursor(10,20); //oled display
34. display.setTextSize(2);
35. display.setTextColor(WHITE);
36. display.println(distance_cm);
37. display.setCursor(90,20);
38. display.setTextSize(2);
39. display.println("cm");
40. display.setCursor(10,45); //oled display
41. display.setTextSize(2);
42. display.setTextColor(WHITE);
43. display.println(distance_in);
44. display.setCursor(90,45);
45. display.setTextSize(2);
46. display.println("in");
47. display.display();

48. delay(500);
49. display.clearDisplay();

50. Serial.println(distance_cm);
51. Serial.println(distance_in);
52. }
