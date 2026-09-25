<div align="center">

# 🏎️ TALOS

### Vehicle Telemetry & Anomaly Detection for UCF Baja SAE

**Real-time telemetry pipeline for the 2027 Baja SAE car**

`C++` • `STM32` • `Embedded Systems` • `RF` • `Telemetry` • `Machine Learning`

</div>

---

## 📖 Overview

TALOS is a telemetry system for the **University of Central Florida Baja SAE** team.

The goal is to reliably transmit **10 Hz** vehicle telemetry from the car to the pits over an RF link while building the foundation for future machine learning–based fault/anomaly detection.

### Current Scope

- Embedded firmware
- Binary packet protocol
- Bit packing & fixed-point encoding
- CRC-16 error detection
- UART communication
- Digi XLR PRO radios
- Grafana Live dashboards
- Future ML anomaly detection

---

## 🏗️ Architecture

```text
Sensors
   │
STM32
   │
Packet Builder
   │
Encoding + CRC
   │
UART
   │
XLR PRO Radio
   │
 RF Link
   │
Base Station
   │
Grafana
   │
Machine Learning
```

---

## ⚙️ Features

- Modular packet builder
- Bit-packed binary telemetry
- Fixed-point encoding
- CRC-16 validation
- UART communication
- Expandable telemetry protocol
- Debug serial interface

---

## 🛠️ Tech Stack

**Embedded:** STM32 • STM32 HAL • UART

**Communications:** Digi XLR PRO • CRC-16 • Binary Protocol

**Planned:** Grafana • FastAPI • PostgreSQL • Python • scikit-learn

---

## ✅ TODO

### Core Telemetry

- [X] Finalize telemetry packet format
- [ ] Add sequence numbers & timestamps
- [ ] Complete packet decoder
- [ ] Integrate vehicle sensors
- [ ] Transmit first live telemetry packet

### Radio

- [X] Configure XLR PRO radios
- [ ] Measure range & packet loss
- [ ] Optimize radio parameters

### Ground Station

- [X] Telemetry receiver
- [ ] Grafana Live dashboard
- [ ] Historical data logging

### Machine Learning

- [ ] Build telemetry dataset
- [ ] Train anomaly detection model
- [ ] Detect belt slip & component faults

---

</div>
