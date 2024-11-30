# ATM Interface Project

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Setup Instructions](#setup-instructions)
- [docs/ Directory](#2-docs-directory)
- [License](#license)

## Project Overview

This project simulates the basic operations of an ATM machine, allowing users to perform transactions such as withdrawals and deposits, as well as providing technical support functionalities.

## Features

- Card insertion and PIN validation
- Withdrawal and deposit transactions
- Technical support access
- Error handling and logging
- Screen and sound interactions

## Setup Instructions

1. Clone the repository.
2. Navigate to the project directory.
3. Run the setup script to create necessary directories and files:

   ```bash
    git clone github.com/elqabasy/ATM-Interface.git
    mkdir build 
    cd build 
    cmake .. 
    make
    ```

### 2. **docs/** Directory

A `docs` directory can contain detailed documentation and images to explain the project further.

**docs/**:

- `API.md`: Detailed API documentation for the classes and methods.
- `diagrams/`: Directory to hold UML diagrams and other visual representations.

### 4. **tests/** Directory

A `tests` directory can contain unit tests and integration tests for the project.

### 5. **LICENSE**

A license file specifying the licensing terms for your project. Popular choices include MIT License, Apache License 2.0, GNU GPLv3, etc.

### **LICENSE**

```markdown
MIT License

Copyright (c) 2024 alqabasy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
