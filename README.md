# Census Data Management System

A comprehensive C-based application for managing and analyzing census data with user authentication, data visualization, and file persistence capabilities.

![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=python)
![Output](https://img.shields.io/badge/Output-File-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)


## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Program Versions](#program-versions)
- [Data Structure](#data-structure)
- [Security Features](#security-features)
- [File Operations](#file-operations)
- [Contributing](#contributing)
- [Disclaimer](#disclaimer)
- [License](#license)

## 🌟 Overview

This project consists of two enhanced C programs for census data management:

1. **Console Display Version** (`CaseStudy_KathitJoshi.c`) - Interactive console-based data display
2. **File Storage Version** (`CaseStudy2_KathitJoshi.c`) - File-based data persistence and reporting

Both programs handle demographic data across multiple years, categorized by age groups and geographical locations (continents).

## ✨ Features

### Common Features
- 🔐 **Secure Authentication System** with username/password protection
- 📊 **Multi-year Data Management** (5-year data sets)
- 🌍 **Geographic Analysis** across 7 continents
- 👥 **Age Group Demographics** (10 age categories)
- ✅ **Input Validation** with error handling
- 📈 **Statistical Analysis** and summary reports

### Console Version Specific
- 📺 **Real-time Data Display** in formatted tables
- 🧮 **Interactive Statistical Analysis**
- 📋 **Menu-driven Interface**
- 💻 **Immediate Visual Feedback**

### File Storage Version Specific  
- 💾 **Persistent Data Storage** in text files
- 🔄 **Automatic Backup System**
- 📑 **Detailed Report Generation**
- 📊 **Growth Analysis Reports**
- 🕒 **Timestamped Data Management**


### Basic Workflow

1. **Authentication Setup**
   - Create username and password
   - Login with credentials (3 attempts max)

2. **Data Entry**
   - Enter population data for each year (2016-2020 or 2019-2023)
   - Input age group demographics
   - Input geographical distribution

3. **Data Analysis**
   - View formatted data tables
   - Generate statistical summaries
   - Create analysis reports (File version)

## 📊 Program Versions

### Version 1: Console Display 

**Purpose:** Real-time data visualization and analysis

**Key Features:**
- Interactive menu system
- Formatted table displays
- Live statistical calculations
- Memory-based data processing

**Best For:**
- Quick data analysis
- Interactive exploration
- Temporary data processing
- Educational demonstrations

### Version 2: File Storage 

**Purpose:** Data persistence and comprehensive reporting

**Key Features:**
- File-based data storage
- Automatic backup creation
- Detailed report generation
- Growth trend analysis

**Best For:**
- Long-term data storage
- Report generation
- Data archiving
- Professional analysis

## 📈 Data Structure

### Age Groups (10 categories)
- 0-10 years
- 11-20 years  
- 21-30 years
- 31-40 years
- 41-50 years
- 51-60 years
- 61-70 years
- 71-80 years
- 81-90 years
- 91-130 years

### Geographic Locations (7 continents)
- Asia
- Africa
- Europe
- North America
- South America
- Australia
- Antarctica

### Time Periods
- **Console Version:** 2019-2023 (5 years)
- **File Version:** 2016-2020 (5 years)

## 🔒 Security Features

- **User Authentication:** Username/password system
- **Access Control:** Limited login attempts (3 max)
- **Data Validation:** Input sanitization and bounds checking
- **Error Handling:** Comprehensive error management
- **Backup Protection:** Automatic data backup before modifications

## 📁 File Operations

### Generated Files

| File Type | Description | Example |
|-----------|-------------|---------|
| `CensusData.txt` | Primary data storage | Main census data |
| `CensusData_backup.txt` | Automatic backup | Backup before changes |
| `CensusReport_*.txt` | Analysis reports | Timestamped reports |

### File Format
```
=== CENSUS DATA MANAGEMENT SYSTEM ===
Generated on: 2024-01-15 10:30:45
Data for years: 2016 - 2020

=====================================
YEAR: 2016
=====================================

AGE GROUP DISTRIBUTION:
------------------------
0-10      :       150000
11-20     :       120000
...
```

## 🤝 Contributing

We welcome contributions! Please follow these guidelines:

1. **Fork the repository**
2. **Create a feature branch** (`git checkout -b feature/amazing-feature`)
3. **Commit your changes** (`git commit -m 'Add amazing feature'`)
4. **Push to the branch** (`git push origin feature/amazing-feature`)
5. **Open a Pull Request**

### Development Guidelines
- Follow C99 standard
- Add comprehensive comments
- Include error handling
- Test on multiple platforms
- Update documentation

## ⚠️ Disclaimer

**Important Notice:**

This software is designed for **educational and demonstration purposes only**. The census data entered and processed by this system should be considered as **dummy/sample data** unless you specifically input real census information.

**For Official Census Data:**
- Visit: [https://www.census.gov/data.html](https://www.census.gov/data.html)
- Use official government statistical resources
- Consult professional demographic databases

**Not Recommended For:**
- Official census reporting
- Government statistical analysis
- Academic research without proper data sources
- Commercial demographic analysis

## 📋 System Requirements

- **Operating System:** Windows, Linux, macOS
- **Compiler:** GCC 4.8+ or equivalent C99 compiler
- **Memory:** Minimum 512MB RAM
- **Storage:** 50MB free space for data files
- **Terminal:** Command-line interface access

## 🐛 Known Issues

- Large dataset input may be time-consuming
- File corruption possible if program terminated unexpectedly
- Limited to 5-year data sets in current version

## 📞 Support

For issues and questions:
- **GitHub Issues:** [Create an issue](https://github.com/Kathitjoshi/Census_Management/issues)
- **Email:** kathitjoshi@gmail.com

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Original concept by Kathit Joshi
- Enhanced and modularized for educational use
- Inspired by real-world census management systems
- Thanks to the open-source community for testing and feedback

---

**Last Updated:** June 2025 
**Version:** 2.0  
**Author:** Kathit Joshi  
**Status:** Dormant Development
