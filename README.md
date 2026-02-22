
#  Task 2 – Temperature-Based Fan Control  


##  Components Required  

- Arduino Uno  
- DHT11 Temperature Sensor  
- DC Motor (Fan)  
- Motor Driver Module (L298N / L293D) 
- Jumper wires  
- External power supply (9V/12V for motor)

---

##  Working Principle  

1. The DHT11 sensor continuously measures ambient temperature.  
2. Arduino reads the temperature data from the sensor.  
3. The temperature value is displayed on the Serial Monitor.  
4. The system compares the measured temperature with a preset threshold value (e.g., 30°C).  
5. If the temperature exceeds the threshold:  
   - The motor driver activates the DC motor.  
   - The fan runs at a speed proportional to the temperature (using PWM).  
6. If the temperature is below the threshold:  
   - The motor remains OFF.  

This demonstrates integration of sensor data acquisition with actuator control.


## Circuit Connections  

###  DHT11 Connections  

- VCC → 5V (Arduino)  
- GND → GND  
- DATA → Digital Pin 2  

### Motor Driver (L298N )  

- IN1 → Pin 8  
- IN2 → Pin 9  
- ENA → Pin 10 (PWM pin for speed control)  
- Motor terminals → DC Motor  
- External power supply → Motor driver power input  

---

##  Block Diagram  

- Temperature Sensor → Arduino → Motor Driver → DC Motor  
- Sensor provides input data  
- Arduino processes data  
- Motor driver controls fan operation  

---

##  Control Logic  

- Set a temperature threshold (for example, 30°C).  
- Continuously monitor temperature.  
- If Temperature > Threshold → Fan ON  
- If Temperature ≤ Threshold → Fan OFF  

For speed control:  
- As temperature increases, PWM value increases.  
- Higher PWM → Higher motor speed.  


##  Expected Output  

- Serial Monitor displays temperature every few seconds.  
- When temperature crosses threshold:  
  - Fan turns ON  
  - Speed adjusts according to temperature (using motor driver).  
- When temperature drops below threshold:  
  - Fan turns OFF  

---

##  Applications  

- Smart home temperature regulation  
- Automatic cooling systems  
