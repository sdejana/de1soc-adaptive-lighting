
# AI Tools Usage

This document details how and where specific AI tools were used throughout the project.

## AI Tools Used

| Tool | Model / Version | Primary Purpose |
|---|---|---|
| **Google Gemini** | Gemini 1.5 Pro | Translation, Markdown formatting, proofreading, and error correction |
| **Claude** | Claude Sonnet 5 | C code generation, debugging, and logic optimization |

## Specific contributions

### README.md

Both mentioned AI tools were used for:

* **Translation:** Translated technical notes and repository instructions from Serbian to English.
* **Grammar & Proofreading:** Corrected grammatical, spelling, and punctuation errors throughout the file.
* **Sentence Restructuring:** Refined sentence structure and phrasing to enhance readability and ensure a professional, technical tone.

### User Application

* **Initial Logic & Draft:** Generated the baseline implementation for `main.c` to establish the control loop for reading illuminance levels and driving FPGA user LEDs via the Linux `/sys` interface (*Claude Sonnet 5*).
* **Code Optimization & Enhancements:** Suggested architectural refinements and code improvements after modular source files (`sensor.c`, `sensor.h`, `led.c`, `led.h`) were manually authored and integrated (*Claude Sonnet 5*).

### Debugging 

#### Device Tree and U-Boot configuration

* **Device Tree Compiler (DTC) Syntax Error:** Fixed a DTC compilation failure by renaming the FPGA bridge label from `&fpga-bridge0` (hyphenated) to `&fpga_bridge0` (underscored), as hyphens are prohibited in label names (*Google Gemini 1.5 Pro*).
* **Stale DTB Artifacts:** Resolved issues where `.dts` changes were not reflected in the generated binary files by running `make host-uboot-tools-dirclean` (*Claude Sonnet 5*)

#### Buildroot

* **Partition & Image Layout Configuration**: Identified that the failure to fit the FPGA bitstream (`socfpga.rbf`) onto the SD card boot partition was due to default size constraints. Based on AI architectural guidance, the VFAT partition size in `genimage.cfg` was expanded, resolving the storage bottleneck for `socfpga.rbf`, `zImage`, and the DTB file. (*Claude Sonnet 5*).

#### Driver Setup

* **Dynamic I2C Bus Indexing Identification:** Diagnosed a common Linux Kernel behavior where the physical hardware `i2c2` controller was enumerated dynamically as `/dev/i2c-0` in the `/dev` filesystem instead of `/dev/i2c-2`. Identifying this dynamic mapping allowed the C application to open the correct I2C bus device file. (*Claude Sonnet 5*)

## This manual

This manual and project documentation were enhanced, translated and formatted with the assistance of AI tools (Google Gemini 1.5 Pro and Claude 3.5 Sonnet) to ensure technical clarity, correct terminology, and consistent structure. 

