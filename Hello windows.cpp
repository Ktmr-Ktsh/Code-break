#include <iostream>
#include <windows.h>
#include <ctime>
HWND hWnd;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg){
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
	return 0;
}
void MoveWindowRandomly(){
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int xPos = rand() % (screenWidth - 400);
    int yPos = rand() % (screenHeight - 200);
	SetWindowPos(hWnd, HWND_TOPMOST, xPos, yPos, 400, 200, SWP_SHOWWINDOW);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	srand(time(NULL));
	WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    RegisterClassEx(&wc);
	hWnd = CreateWindowEx(0, "MyWindowClass", "My Window", WS_OVERLAPPEDWINDOW, 0, 0, 400, 200, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nShowCmd);
	MoveWindowRandomly(); // ≥ı º¥∞ø⁄Œª÷√

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        //if (msg.message == WM_KEYDOWN && msg.wParam == VK_SPACE)
        //{
        //    MoveWindowRandomly();
		//}
		while(true)
			//generateAlert();
			MoveWindowRandomly();
		//generateAlert();
		MoveWindowRandomly();
    }
	return msg.wParam;
}
 

 
