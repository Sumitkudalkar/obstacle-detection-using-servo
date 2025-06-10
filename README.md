# 🧠 Obstacle Detection System using Servo & Ultrasonic Sensor

Hey there!  
This is a fun little project I built that uses a **servo motor** and an **ultrasonic sensor** to scan the surroundings and figure out the safest direction to move.  
It also uses a **buzzer** to alert the user and tell them where to go — just by sound.

---

## 🔹 Phase 1: Live Scanning & Distance Detection

In the first phase, I connected an **HC-SR04 ultrasonic sensor** to measure distance and used a **servo motor** to rotate it at different angles (like 0°, 45°, 90°, etc.).

If something is detected closer than **70 cm**, a **buzzer beeps**, and the system starts scanning left to right to find which direction is the clearest. Once it knows that, it tells the user via buzzer patterns.

▶️ [Try it out here (Phase 1 - Real Sensor Logic)](https://lnkd.in/eP4FDx_V)

---

## 🔹 Phase 2: Simulated Scanning (TinkerCAD Limitation)

In simulators like TinkerCAD, you can’t really “attach” the sensor to a servo physically.  
So for Phase 2, I faked the distance readings to simulate how the logic would work if the sensor actually rotated.

▶️ [Phase 2 Simulation Link](https://lnkd.in/eZEhSsrP)

---

## 🔊 How the Buzzer Signals Work

To help someone know which way to go, the buzzer gives sound cues:

| Direction        | Angle  | Buzzes |
|------------------|--------|--------|
| Stop             | 0°     | 0      |
| Forward-Right    | 45°    | 1      |
| Right            | 90°    | 2      |
| Forward-Left     | 135°   | 3      |
| Left             | 180°   | 4      |

So even if someone can't see the path, they'll know which way is safest just by counting the beeps 🔉

---


