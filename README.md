## ✅ **สรุปการแก้ไขปัญหา undefined reference สำหรับ GDI+ ใน MinGW**

### 🛠 **ปัญหา**
- Error: `undefined reference to GdiplusStartup` หรือ `undefined reference to __gxx_personality_seh0`
- เกิดจากการใช้ **GDI+** ในภาษา C++ แต่คอมไพล์ด้วย `gcc` โดยไม่ได้ลิงก์ไลบรารีที่จำเป็น

---

### 🚀 **วิธีแก้ไข**

1. **ใช้คำสั่งที่ถูกต้องสำหรับการคอมไพล์**
    ```bash
    gcc main.cpp -o fade-wallp.exe -lgdiplus -lgdi32 -lstdc++
    ```
    - `-lgdiplus` → ลิงก์ GDI+ Library
    - `-lgdi32` → ลิงก์ GDI32 Library
    - `-lstdc++` → ลิงก์ C++ Standard Library

---

2. **ตรวจสอบไฟล์ GDI+**
    - ตรวจสอบไฟล์ `gdiplus.dll`:
      ```bash
      dir C:\Windows\System32\gdiplus.dll
      ```
    - ตรวจสอบไลบรารี GDI+:
      ```bash
      dir C:\ProgramData\mingw64\mingw64\lib\libgdiplus.a
      ```

---

3. **ตรวจสอบและเพิ่ม Path ของ MinGW**
    - ตรวจสอบว่ามี Path ของ MinGW หรือไม่:
      ```bash
      echo %PATH%
      ```
    - ถ้ายังไม่มี ให้เพิ่ม:
      ```
      C:\ProgramData\mingw64\mingw64\bin
      ```

---

### 🎉 **สรุปสุดท้าย**
- คอมไพล์ด้วย `gcc main.cpp -o fade-wallp.exe -lgdiplus -lgdi32 -lstdc++`  
- ตรวจสอบไฟล์ `gdiplus.dll` ใน `C:\Windows\System32`  
- ตรวจสอบไลบรารี `libgdiplus.a` ใน `C:\ProgramData\mingw64\mingw64\lib`  
- เพิ่ม Path ของ MinGW หากยังไม่ได้เพิ่ม  

หากทำตามนี้แล้ว ทุกอย่างจะทำงานได้เรียบร้อย! ✅
