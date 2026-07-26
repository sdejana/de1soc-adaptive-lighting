# VEML6035 ambient light sensor integration and lighting control on DE1-SoC

This project was developed as part of the **Embedded Computer Systems** (*Ugrađeni računarski sistemi*) course at the **Faculty of Electrical Engineering, University of Banja Luka (ETFBL)**.

## Project Assignment & Requirements

Integrate the ambient light measurement sensor, available on the Ambient 11 Click board (integrated circuit VEML6035), onto the DE1-SoC platform. Implement an application that enables adaptive room lighting control based on the information received from the given sensor.

## Hardware Setup

Required hardware:
- DE1-SoC development board with power supply and UART cable.
- Ambient 11 Click (VEML6035) board.
- SD card.
- Ethernet cable (for SSH connection).
  
### Connecting Ambient 11 Click to target board

The pin layout and hardware schematics can be found in the [DE1-SoC Schematic Diagram](https://people.ece.cornell.edu/land/courses/ece5760/DE1_SOC/DE1-SoC%20schematic.pdf) and the course User Manual provided by the professor (`hps-soc-system.pdf` in docs). 
The sensor pins are connected to the GPIO 0 expansion header as shown in the table below:
| Sensor Pin (Ambient 11 Click) | GPIO 0 Header Pin | Description |
| :--- | :--- | :--- |
| **VCC** | **Pin 29** | Power Supply (3.3V) |
| **GND** | **Pin 30** | Ground |
| **SDA** | **Pin 1** | $I^2C2$ Serial Data |
| **SCL** | **Pin 2** | $I^2C2$ Serial Clock |

Here is the physical connection between the **DE1-SoC** board and the **Ambient 11 Click** sensor via the **GPIO 0** header:

<p align="center">
  <img src="docs/img/img_de1soc_hardwarejpg" width="450" alt="Hardware Setup">
  <br>
  <sub><b>Image 1:</b> Physical connection between DE1-SoC and Ambient 11 Click sensor</sub>
</p>


## Embedded Linux Setup

## User Application Development

## Testing & Demo
