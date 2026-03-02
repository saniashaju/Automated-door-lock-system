# Automated-door-lock-system   

An Arduino-based security system that uses a keypad for password entry and a servo motor to control the locking mechanism. Created and simulated in **Tinkercad**.

## 🚀 How it Works
1. The user is prompted to "Enter Password" on the **LCD**.
2. Using the **4x4 Keypad**, the user enters the code (Default: `200A`).
3. Pressing `#` submits the code:
   - **Correct**: The buzzer sounds, and the **Servo Motor** rotates 90° to unlock.
   - **Incorrect**: The buzzer sounds an alarm, and the system remains locked.
4. Pressing `*` clears the current input.

## 🛠️ Components Used
* **Microcontroller**: Arduino UNO
* **Input**: 4x4 Membrane Keypad
* **Output**: I2C LCD (16x2), Servo Motor, Piezo Buzzer

## ⚡ Circuit Diagram
![Circuit Diagram](./Automated_door_lock_img.png)
