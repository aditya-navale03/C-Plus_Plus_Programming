#include <windows.h>

bool running = true;
void *buffer_memory = nullptr; // Initialize to nullptr
int buffer_width;
int buffer_height;
BITMAPINFO buffer_bitmap_info;

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;
    switch (uMsg)
    {
    case WM_CLOSE:
    case WM_DESTROY:
    {
        running = false;
    }
    break;

    case WM_SIZE:
    {
        RECT rect;
        GetClientRect(hwnd, &rect);
        buffer_width = rect.right - rect.left;
        buffer_height = rect.bottom - rect.top;

        int buffer_size = buffer_width * buffer_height * sizeof(unsigned int);

        if (buffer_memory)
            VirtualFree(buffer_memory, 0, MEM_RELEASE);
        buffer_memory = VirtualAlloc(0, buffer_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        buffer_bitmap_info.bmiHeader.biSize = sizeof(buffer_bitmap_info.bmiHeader);
        buffer_bitmap_info.bmiHeader.biWidth = buffer_width;
        buffer_bitmap_info.bmiHeader.biHeight = -buffer_height; // Negative to render top-down
        buffer_bitmap_info.bmiHeader.biPlanes = 1;
        buffer_bitmap_info.bmiHeader.biBitCount = 32;
        buffer_bitmap_info.bmiHeader.biCompression = BI_RGB;
    }
    break;

    default:
    {
        result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    }

    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    // Create window class
    WNDCLASS window_class = {};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpszClassName = "Game Window Class";
    window_class.lpfnWndProc = window_callback;
    window_class.hCursor = LoadCursor(nullptr, IDC_ARROW); // Add cursor
    window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Add background
    window_class.hInstance = hInstance;

    // Register class
    if (!RegisterClass(&window_class))
        return -1;

    // Create window
    HWND window = CreateWindow(window_class.lpszClassName, "My First Game",
                               WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                               CW_USEDEFAULT, CW_USEDEFAULT,
                               1280, 720,
                               nullptr, nullptr, hInstance, nullptr);
    if (!window)
        return -1;

    HDC hdc = GetDC(window);

    while (running)
    {
        // INPUT
        MSG message;
        while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        // Simulate

        // Render
        StretchDIBits(hdc,
                      0, 0, buffer_width, buffer_height, // Destination rectangle
                      0, 0, buffer_width, buffer_height, // Source rectangle
                      buffer_memory, &buffer_bitmap_info,
                      DIB_RGB_COLORS, SRCCOPY);
    }

    // Release the device context when done
    ReleaseDC(window, hdc);

    return 0; // Add return statement
}
