# ThingSpeak Dashboard Setup

## Overview

This project uses ThingSpeak as a cloud-based IoT platform to monitor and visualize real-time environmental air quality data generated through ESP32 simulation in Wokwi.

The ESP32 sends sensor values to the ThingSpeak cloud dashboard, where users can monitor pollution levels and environmental conditions through live graphs.

---

## Channel Information

**Platform:** ThingSpeak

**Channel ID:** 3405125

**Project Name:** IoT-Based Air Quality & Pollution Monitoring Dashboard

**Purpose:** Real-time air quality monitoring and environmental pollution analysis.

---

## Configured Fields

The following four fields are configured in the ThingSpeak dashboard:

| Field Number | Field Name  | Description                                                                         |
| ------------ | ----------- | ----------------------------------------------------------------------------------- |
| Field 1      | Temperature | Displays temperature values collected from the DHT22 sensor (°C)                    |
| Field 2      | Humidity    | Displays humidity readings from the DHT22 sensor (%)                                |
| Field 3      | AQI         | Displays calculated Air Quality Index values                                        |
| Field 4      | Gas Value   | Displays gas concentration values simulated using potentiometer (MQ135 replacement) |

---

## Dashboard Working Flow

Sensors (DHT22 + Simulated MQ135)
↓
ESP32 (Wokwi Simulation)
↓
Data Processing & AQI Calculation
↓
ThingSpeak Cloud Dashboard
↓
Real-Time Monitoring & Visualization

---

## AQI Classification

| AQI Range | Category  | Status                         |
| --------- | --------- | ------------------------------ |
| 0–50      | Good      | Clean Air                      |
| 51–100    | Moderate  | Acceptable Air Quality         |
| 101–150   | Poor      | Unhealthy for Sensitive People |
| Above 150 | Hazardous | Dangerous Pollution Level      |

---

## Dashboard Features

The ThingSpeak dashboard provides:

* Real-time temperature monitoring
* Humidity tracking
* Air Quality Index (AQI) monitoring
* Gas concentration analysis
* Live environmental data visualization
* Cloud-based monitoring system

---

## Data Update Interval

The ESP32 sends sensor data to ThingSpeak every **15 seconds** for real-time monitoring and visualization.

---

## Alert System

The project includes a basic alert system:

* **LED turns ON** during poor or hazardous air quality
* **Buzzer activates** when pollution level becomes dangerous

This helps users identify unsafe environmental conditions immediately.

---

## ThingSpeak Screenshots Included

The following screenshots are added in the `images/` folder for project proof and documentation.

### 1. Full ThingSpeak Dashboard Screenshot

Description:
Complete dashboard showing all four sensor fields and graphs.

File Name:
thingspeak_dashboard.png

---

### 2. ThingSpeak Graph Screenshot

Description:
Graph visualization showing sensor data trends and air quality monitoring.

File Name:
thingspeak_graph.png

---

## Conclusion

ThingSpeak acts as the cloud visualization platform in this project by collecting and displaying environmental sensor data in graphical format. It enables users to monitor air pollution conditions remotely and understand environmental changes in real time.
