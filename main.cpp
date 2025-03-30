#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>
#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;

void DrawWallpaperWithFade(HWND hwnd, const wchar_t* imagePath) {
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HDC hdc = GetDC(hwnd);
    Graphics graphics(hdc);
    Image image(imagePath);

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int steps = 60; // 60 steps for 1 second (60 FPS)
    int delay = 1000 / steps; // 1000ms / 60 = ~16.6ms per frame

    // Fade In (1 sec)
    for (int alpha = 0; alpha <= 255; alpha += 255 / steps) {
        graphics.Clear(Color(0, 0, 0, 0));
        graphics.DrawImage(&image, 0, 0, screenWidth, screenHeight);
        Sleep(delay);
    }

    Sleep(2000); // แสดงภาพเป็นเวลา 2 วินาที

    // Fade Out (1 sec)
    for (int alpha = 255; alpha >= 0; alpha -= 255 / steps) {
        graphics.Clear(Color(0, 0, 0, 0));
        graphics.DrawImage(&image, 0, 0, screenWidth, screenHeight);
        Sleep(delay);
    }

    ReleaseDC(hwnd, hdc);
    GdiplusShutdown(gdiplusToken);
}

void SetWallpaper(const wchar_t* imagePath) {
    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)imagePath, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
}

int main() {
    const wchar_t* wallpaper1 = L"C:\\path\\to\\wallpaper1.jpg";
    const wchar_t* wallpaper2 = L"C:\\path\\to\\wallpaper2.jpg";

    HWND desktop = GetDesktopWindow();
    
    // รอบที่ 1
    DrawWallpaperWithFade(desktop, wallpaper1);
    SetWallpaper(wallpaper1);
    Sleep(5000); // แสดง 5 วินาที
    
    // รอบที่ 2
    DrawWallpaperWithFade(desktop, wallpaper2);
    SetWallpaper(wallpaper2);

    return 0;
}
