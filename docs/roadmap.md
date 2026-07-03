# QtMarstek Roadmap

Version: 0.x

Status: In development

---

# Milestone 1 - Foundation

## Core library

- [ ] CMake project
- [ ] Shared library
- [ ] Static library
- [ ] Export macros
- [ ] Doxygen configuration

---

## Network discovery

- [x] UDP broadcast reception
- [x] Device identification
- [ ] Automatic disappearance detection
- [ ] Discovery timeout
- [ ] Device cache

---

## Device object

- [x] Basic information
- [ ] Complete status
- [ ] Live update
- [ ] Device capabilities

---

# Milestone 2 - Protocol

## Packet layer

- [x] Packet class
- [ ] CRC verification
- [ ] Packet builder
- [ ] Packet parser

---

## Commands

- [x] Discovery
- [ ] Read configuration
- [ ] Read battery state
- [ ] Read inverter state
- [ ] Read statistics
- [ ] Read schedules

---

## Write commands

- [ ] Set output power
- [ ] Set working mode
- [ ] Configure Wi-Fi
- [ ] Configure schedules

---

# Milestone 3 - Scheduler

## Time slots

- [ ] Read
- [ ] Modify
- [ ] Validation
- [ ] Upload

---

# Milestone 4 - Monitoring

- [ ] SOC
- [ ] Battery voltage
- [ ] Battery current
- [ ] Temperature
- [ ] Grid power
- [ ] PV production

---

# Milestone 5 - Advanced features

- [ ] Automatic refresh
- [ ] Command queue
- [ ] Retry mechanism
- [ ] Time synchronization

---

# Milestone 6 - Examples

## Console

- [x] Discovery
- [ ] Monitoring
- [ ] Scheduler

## Widgets

- [ ] Device browser
- [ ] Live monitor
- [ ] Scheduler editor

---

# Milestone 7 - Tests

- [ ] Packet parser
- [ ] CRC
- [ ] Protocol
- [ ] Scheduler

---

# Milestone 8 - Documentation

- [ ] API reference
- [ ] User guide
- [ ] Developer guide
- [ ] Protocol documentation

---

# Future

## Multi-device support

- [ ] Venus A
- [ ] Future Marstek models

## Network

- [ ] IPv6
- [ ] Multiple interfaces

## Qt

- [ ] QML bindings
- [ ] Qt Designer plugin

Suivi :

| ID      | Titre                   | État |
| ------- | ----------------------- | ---- |
| QTM-001 | Automatic UDP discovery | 🚧   |
| QTM-002 | Packet parser           | ⏳   |
| QTM-003 | Command queue           | ⏳   |
| QTM-004 | Read device information | ⏳   |
| QTM-005 | Read realtime status    | ⏳   |
| QTM-006 | Scheduler               | ⏳   |
| QTM-007 | Write configuration     | ⏳   |
| QTM-008 | Automatic refresh       | ⏳   |
| QTM-009 | Widgets example         | ⏳   |
| QTM-010 | Documentation 1.0       | ⏳   |
