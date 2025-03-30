# 🖼️ Fade Wallpaper with GDI+ using C++

โปรเจคนี้เป็นตัวอย่างการเปลี่ยน **Wallpaper** พร้อมเอฟเฟกต์ **Fade In/Out** บน **Windows 11** โดยใช้ **C++** และ **GDI+**

## 🚀 Features
- เปลี่ยนวอลเปเปอร์ด้วย GDI+
- เอฟเฟกต์ Fade In และ Fade Out
- รองรับการทำงานบน Windows 10/11

---

## 🛠️ Prerequisites

- Windows 10 หรือ 11
- MinGW หรือ GCC ที่รองรับ C++
- GDI+ (ติดตั้งมากับ Windows โดย default)

---

## 📦 Installation

1. **ติดตั้ง MinGW**:
    - ดาวน์โหลดจาก [Mingw-w64](https://www.mingw-w64.org/)
    - เพิ่ม Path ของ MinGW ใน Environment Variables เช่น:
    ```bash
    C:\ProgramData\mingw64\mingw64\bin
    ```

2. **ตรวจสอบ GDI+**:
    - ตรวจสอบว่ามี `gdiplus.dll` ใน System32 หรือไม่:
    ```bash
    dir C:\Windows\System32\gdiplus.dll
    ```

---

## 🧑‍💻 Build และ Run

ใช้คำสั่งนี้เพื่อคอมไพล์:
```bash
gcc main.cpp -o fade-wallp.exe -lgdiplus -lgdi32 -lstdc++
fade-wallp.exe
```

## 🙌 Acknowledgments

- ขอบคุณ MinGW-w64 สำหรับ Compiler ที่ยอดเยี่ยม
- ขอบคุณ Microsoft สำหรับ GDI+ API