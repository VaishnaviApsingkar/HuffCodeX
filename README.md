# **🔢HuffCodeX 

HuffCodeX is an implementation of **Huffman Encoding and Decoding** in C++. It efficiently compresses text files by assigning variable-length binary codes to characters based on their frequency.

This project is divided into multiple parts:
1. **📊 Character Frequency Calculation (Part One)**
2. **🛠️ Huffman Encoding (Part Two)**
3. **🔠 Encoding Using Huffman Codes (Part Three A)**
4. **🔄 Decoding the Encoded File (Part Three B)**
5. **💾 Bit-Level Encoding (Part Four A)**
6. **📥 Bit-Level Decoding (Part Four B)**

The project includes tests to analyze the compression efficiency and correctness of the decoded output.

---

## **🚀 How to Use the Program**
### **1️⃣ Input File (clear.txt)**
- The program reads `clear.txt`, calculates character frequencies, and generates the Huffman code table.

### **2️⃣ Encoding & Compression**
- The program encodes the text into two formats:
  - `coded.txt`: Stores Huffman codes as **strings of '0' and '1'**.
  - `codedalt.txt`: Uses **bit-level encoding** for efficient storage.

### **3️⃣ Decoding**
- The program decodes `coded.txt` and `codedalt.txt` back to their original form (`decoded.txt`, `decodedalt.txt`).

### **4️⃣ File Size Comparisons**
| 📂 File Name      | 📏 Size (bytes) |
|---------------|-------------|
| `clear.txt`   | 484         |
| `freq.txt`    | 197         |
| `coded.txt`   | 2084        |
| `codetable.txt` | 362       |
| `decoded.txt` | 484         |
| `codedalt.txt` | 261       |
| `decodedalt.txt` | 484     |

- **Key Insight:** `codedalt.txt` (bit-level encoding) is **much smaller** than `coded.txt`, showing better compression.

---

## **📖 Technical Implementation**
### **🔹 Project Design Pattern Used**
This project follows the **Modular Design Pattern** to enhance maintainability and reusability:
1. **🧩 Separation of Concerns** – Each part of the project (character frequency calculation, encoding, decoding) is implemented in separate files.
2. **🔒 Encapsulation** – Each module (PartOne, PartTwo, etc.) has its own `.cpp` and `.h` files to keep implementation details hidden from other modules.
3. **🔄 Reusability** – Header files (`.h`) define functions that are reusable across multiple parts of the program.
4. **📈 Scalability** – New encoding methods can be easily added without affecting existing functionality.

---

## **📊 Analysis & Results**
### **🔹 Observations**
1. **String-based encoding (`coded.txt`)** is **inefficient** since each '0' and '1' is stored as a full character (1 byte each).
2. **Bit-level encoding (`codedalt.txt`)** stores true binary values, making it **much smaller**.
3. **Final decoded files (`decoded.txt`, `decodedalt.txt`) match the original `clear.txt`, proving correctness**.

### **🔹 Compression Efficiency**
- `codedalt.txt` (261 bytes) is significantly smaller than `coded.txt` (2084 bytes), proving that **bitwise encoding saves storage**.

### **🔹 Encoding and Decoding Symbol Size in Bytes**
| 🏷 Symbol | 📝 Encoded Size (coded.txt) | 🔢 Encoded Size (codedalt.txt) | 📄 Decoded Size (decoded.txt) |
|--------|--------------------------|----------------------------|--------------------------|
| 'A'    | 3 bits                   | 3 bits                     | 1 byte                   |
| 'B'    | 4 bits                   | 4 bits                     | 1 byte                   |
| 'C'    | 5 bits                   | 5 bits                     | 1 byte                   |
| 'LF'   | 6 bits                   | 6 bits                     | 1 byte                   |
| 'SP'   | 2 bits                   | 2 bits                     | 1 byte                   |

- In `coded.txt`, each bit is stored as a **character**, leading to higher storage requirements.
- `codedalt.txt` uses **actual bits**, reducing storage size significantly.
- `decoded.txt` restores the original byte size of each character.

---

## **📷 Output Screenshot**
![Program Output](https://github.com/VaishnaviApsingkar/HuffCodeX/blob/main/OutputImg.png)

---

**Made with ❤️ by Vaishnavi Pravin Apsingkar**
