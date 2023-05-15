#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WinSunProc(
  HWND hwnd,      //handle to window
  UINT uMsg,      //message identifier
  WPARAM wParam,  //first message parameter
  LPARAM lParam)  //second message parameter
{
  switch(uMsg)
  {
    case WM_LBUTTONDOWN:
      MessageBox(hwnd,L"Mouse Clicked!",L"Message 1",MB_OK);
      HDC hdc;
      hdc=GetDC(hwnd);
      TextOut(hdc,0,0,L"Mouse Clicked!",strlen("Mouse Clicked!"));
      ReleaseDC(hwnd,hdc);
      break;
    case WM_CLOSE:
      if(IDYES==MessageBox(hwnd,L"Close Windows?",L"Message 2",MB_YESNO))
		DestroyWindow(hwnd);
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd,uMsg,wParam,lParam);
  }
  return 0;
}

int WINAPI WinMain(
  HINSTANCE hInstance,      //handle to current instance
  HINSTANCE hPrevInstance,  //handle to previous instance
  LPSTR lpCmdLine,          //command line
  int nCmdShow)             //show state
{
  WNDCLASS wndcls;
  wndcls.cbClsExtra=0;
  wndcls.cbWndExtra=0;
  wndcls.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
  wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
  wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);
  wndcls.hInstance=hInstance;
  wndcls.lpfnWndProc=WinSunProc;
  wndcls.lpszClassName=L"Test";
  wndcls.lpszMenuName=NULL;
  wndcls.style=CS_HREDRAW|CS_VREDRAW;
  RegisterClass(&wndcls);
  HWND hwnd;
  hwnd=CreateWindow(L"Test",L"Win32 Application",WS_OVERLAPPEDWINDOW,400,300,500,400,NULL,NULL,hInstance,NULL);
  ShowWindow(hwnd,SW_SHOWNORMAL);
  UpdateWindow(hwnd);
  MSG msg;
  while(GetMessage(&msg,NULL,0,0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}