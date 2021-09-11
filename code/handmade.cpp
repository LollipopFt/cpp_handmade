// Copyright [2014] <Molly Rocket, Inc.>

#include <windows.h>

LRESULT CALLBACK WindowProc(
    HWND   hwnd,
    UINT   uMsg,
    WPARAM wParam,
    LPARAM lParam
) {
    LRESULT Result = 0;
    switch (uMsg) {
        case WM_SIZE:
        {
            OutputDebugStringA("WM_SIZE\n");
        }
        break;
        case WM_DESTROY:
        {
            OutputDebugStringA("WM_DESTROY\n");
        }
        break;
        case WM_CLOSE:
        {
            OutputDebugStringA("WM_CLOSE\n");
        }
        break;
        case WM_ACTIVATEAPP:
        {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT Paint;
            HDC hdc = BeginPaint(
                hwnd,
                &Paint);
            LONG height = Paint.rcPaint.bottom - Paint.rcPaint.top;
            LONG width = Paint.rcPaint.right - Paint.rcPaint.left;
            int x = Paint.rcPaint.left;
            int y = Paint.rcPaint.top;
            static DWORD operation = WHITENESS;
            PatBlt(hdc, x, y, width, height, operation);
            if (operation = WHITENESS) {  // making an epilepsy window
                operation = BLACKNESS;
            } else {
                operation = WHITENESS;
            }
            EndPaint(hwnd, &Paint);
        }
        default:
        {
            Result = DefWindowProc(
                hwnd,
                uMsg,
                wParam,
                lParam);
        }
        break;
    }
    return(Result);
}

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd) {
    WNDCLASS WindowClass = {};
    WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
    WindowClass.lpfnWndProc = WindowProc;
    // WindowClass.cbClsExtra = ;
    // WindowClass.cbWndExtra = ;
    WindowClass.hInstance = hInstance;
    // WindowClass.hIcon = ;
    // WindowClass.hCursor = ;
    // WindowClass.hbrBackground = ;
    // WindowClass.lpszMenuName = ;
    WindowClass.lpszClassName = "HandmadeHeroWindowClass";

    if (RegisterClass(&WindowClass)) {
        HWND WindowHandle = CreateWindowEx(
            0,
            WindowClass.lpszClassName,
            "Handmade Hero",
            WS_OVERLAPPEDWINDOW|WS_VISIBLE,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            0,
            0,
            hInstance,
            0);
        if (WindowHandle) {
            for (;;) {
                MSG uMsg;
                BOOL MessageResult = GetMessage(&uMsg, 0, 0, 0);
                if (MessageResult > 0) {
                    TranslateMessage(&uMsg);
                    DispatchMessage(&uMsg);
                } else {
                    break;
                }
            }
        }
    } else {
    }

    return 0;
}