/*
 * @author wucheng
 * @date 2019-08-14
 */

#include <math.h>
#include <windows.h>

#define ID_TIMER 1
#define TWOPI 2 * 3.14159

typedef struct {
  double x;
  double y;
  double z;
} POINT3D;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Draw the square
void DrawPoint(HDC, POINT3D[4], int);

// Connect the points accrding to a certain order (Use brush)
void ConnectPoint(HDC, POINT3D[4], int);

// Connect the points accrding to a certain order (Use pen)
void hpenConnectPoint(HDC, POINT3D[4], HPEN);

void RotateX(POINT3D[4], double);
void RotateY(POINT3D[4], double);
void RotateZ(POINT3D[4], double);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstasnce,
                   PSTR szCmdLine, int iCmdShow) {
  static TCHAR szAppName[] = TEXT("RotateSquare");
  HWND hwnd;
  MSG msg;
  WNDCLASS wndclass;

  wndclass.style = CS_VREDRAW | CS_HREDRAW;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wndclass.hInstance = hInstance;
  wndclass.lpfnWndProc = WndProc;
  wndclass.lpszClassName = szAppName;
  wndclass.lpszMenuName = NULL;

  if (!RegisterClass(&wndclass)) {
    MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName,
               MB_ICONERROR);
    return 0;
  }

  hwnd = CreateWindow(szAppName, TEXT("Rotate Square"), WS_OVERLAPPEDWINDOW,
                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                      CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

  ShowWindow(hwnd, iCmdShow);
  UpdateWindow(hwnd);

  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  static int cxClient, cyClient;
  // static POINT ptPoint[4] = {{-50, -50}, {50, -50}, {50, 50}, {-50, 50}};
  static POINT3D pt3dPoint[4] = {{-5000, -5000, 000},
                                 {-5000, 5000, 000},
                                 {5000, 5000, 000},
                                 {5000, -5000, 000}};
  static int iDegree;
  static double dbDegree;
  static HPEN hpenWhite;
  static RECT rcWindow;
  HDC hdc;
  PAINTSTRUCT ps;

  switch (msg) {
    case WM_CREATE:
      dbDegree = 3;
      hpenWhite = CreatePen(PS_SOLID, 200, RGB(255, 255, 255));
      SetTimer(hwnd, ID_TIMER, 100, NULL);
      return 0;

    case WM_SIZE:
      cxClient = LOWORD(lParam);
      cyClient = HIWORD(lParam);
      rcWindow.left = -25000;
      rcWindow.top = -250000;
      rcWindow.right = 25000;
      rcWindow.bottom = 25000;
      return 0;

    case WM_TIMER:
      // RotateX(pt3dPoint, TWOPI * (double) iDegree / 360);
      // RotateY(pt3dPoint, TWOPI * (double) iDegree / 360);
      // RotateZ(pt3dPoint, TWOPI * (double) iDegree / 360);
     /* if (iDegree == 360)
        iDegree = 0;
      else
        iDegree += 60;*/

      RotateX(pt3dPoint, dbDegree);
       RotateY(pt3dPoint, dbDegree);
       RotateZ(pt3dPoint, dbDegree);
      // dbDegree += 0.0005;  // speed up


      InvalidateRect(hwnd, NULL, FALSE);
      return 0;

    case WM_PAINT:
      hdc = BeginPaint(hwnd, &ps);

      SetMapMode(hdc, MM_ISOTROPIC);

      SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, NULL);
      SetViewportExtEx(hdc, cxClient, cyClient, NULL);
      SetWindowExtEx(hdc, 25000, 25000, NULL);

      FillRect(hdc, &rcWindow, GetStockObject(BLACK_BRUSH));

      hpenConnectPoint(hdc, pt3dPoint, hpenWhite);
      DrawPoint(hdc, pt3dPoint, 500);

      EndPaint(hwnd, &ps);
      return 0;

    case WM_DESTROY:
      KillTimer(hwnd, ID_TIMER);
      DeleteObject(hpenWhite);
      PostQuitMessage(0);
      return 0;
    default:
      break;
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}

// Draw the points of square
void DrawPoint(HDC hdc, POINT3D pt3dPoint[4], int iRadius) {
  SelectObject(hdc, GetStockObject(WHITE_PEN));
  SelectObject(hdc, GetStockObject(WHITE_BRUSH));
  Ellipse(hdc, pt3dPoint[0].x - iRadius, pt3dPoint[0].y + iRadius,
          pt3dPoint[0].x + iRadius, pt3dPoint[0].y - iRadius);
  Ellipse(hdc, pt3dPoint[1].x - iRadius, pt3dPoint[1].y + iRadius,
          pt3dPoint[1].x + iRadius, pt3dPoint[1].y - iRadius);
  Ellipse(hdc, pt3dPoint[2].x - iRadius, pt3dPoint[2].y + iRadius,
          pt3dPoint[2].x + iRadius, pt3dPoint[2].y - iRadius);
  Ellipse(hdc, pt3dPoint[3].x - iRadius, pt3dPoint[3].y + iRadius,
          pt3dPoint[3].x + iRadius, pt3dPoint[3].y - iRadius);
}

// Connect the points of square
void ConnectPoint(HDC hdc, POINT3D pt3dPoint[4], int iWidth) {
  SelectObject(hdc, GetStockObject(WHITE_BRUSH));
  Rectangle(hdc, pt3dPoint[0].x - iWidth, pt3dPoint[0].y,
            pt3dPoint[1].x + iWidth, pt3dPoint[1].y);
  Rectangle(hdc, pt3dPoint[1].x, pt3dPoint[1].y - iWidth, pt3dPoint[2].x,
            pt3dPoint[2].y + iWidth);
  Rectangle(hdc, pt3dPoint[3].x - iWidth, pt3dPoint[3].y,
            pt3dPoint[2].x + iWidth, pt3dPoint[2].y);
  Rectangle(hdc, pt3dPoint[0].x, pt3dPoint[0].y - iWidth, pt3dPoint[3].x,
            pt3dPoint[3].y + iWidth);
}

// Connect the points of square
void hpenConnectPoint(HDC hdc, POINT3D pt3dPoint[4], HPEN hpenWhite) {
  SelectObject(hdc, hpenWhite);
  MoveToEx(hdc, pt3dPoint[0].x, pt3dPoint[0].y, NULL);
  LineTo(hdc, pt3dPoint[1].x, pt3dPoint[1].y);
  LineTo(hdc, pt3dPoint[2].x, pt3dPoint[2].y);
  LineTo(hdc, pt3dPoint[3].x, pt3dPoint[3].y);
  LineTo(hdc, pt3dPoint[0].x, pt3dPoint[0].y);
}

void RotateX(POINT3D pt3dPoint[4], double dbDegree) {
  POINT3D pt3dtpPoint[4];
  for (int iIndex = 0; iIndex < 4; iIndex++) {
    pt3dtpPoint[iIndex].x = pt3dPoint[iIndex].x;
    pt3dtpPoint[iIndex].y = pt3dPoint[iIndex].y;
    pt3dtpPoint[iIndex].z = pt3dPoint[iIndex].z;
  }
  pt3dPoint[0].x =
      (1 * pt3dtpPoint[0].x + 0 * pt3dtpPoint[0].y + 0 * pt3dtpPoint[0].z);
  pt3dPoint[0].y =
      (0 * pt3dtpPoint[0].x + cos(TWOPI * dbDegree / 360) * pt3dtpPoint[0].y +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[0].z);
  pt3dPoint[0].z =
      (0 * pt3dtpPoint[0].x + sin(TWOPI * dbDegree / 360) * pt3dtpPoint[0].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[0].z);

  pt3dPoint[1].x =
      (1 * pt3dtpPoint[1].x + 0 * pt3dtpPoint[1].y + 0 * pt3dtpPoint[1].z);
  pt3dPoint[1].y =
      (0 * pt3dtpPoint[1].x + cos(TWOPI * dbDegree / 360) * pt3dtpPoint[1].y +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[1].z);
  pt3dPoint[1].z =
      (0 * pt3dtpPoint[1].x + sin(TWOPI * dbDegree / 360) * pt3dtpPoint[1].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[1].z);

  pt3dPoint[2].x =
      (1 * pt3dtpPoint[2].x + 0 * pt3dtpPoint[2].y + 0 * pt3dtpPoint[2].z);
  pt3dPoint[2].y =
      (0 * pt3dtpPoint[2].x + cos(TWOPI * dbDegree / 360) * pt3dtpPoint[2].y +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[2].z);
  pt3dPoint[2].z =
      (0 * pt3dtpPoint[2].x + sin(TWOPI * dbDegree / 360) * pt3dtpPoint[2].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[2].z);

  pt3dPoint[3].x =
      (1 * pt3dtpPoint[3].x + 0 * pt3dtpPoint[3].y + 0 * pt3dtpPoint[3].z);
  pt3dPoint[3].y =
      (0 * pt3dtpPoint[3].x + cos(TWOPI * dbDegree / 360) * pt3dtpPoint[3].y +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[3].z);
  pt3dPoint[3].z =
      (0 * pt3dtpPoint[3].x + sin(TWOPI * dbDegree / 360) * pt3dtpPoint[3].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[3].z);
}

void RotateY(POINT3D pt3dPoint[4], double dbDegree) {
  POINT3D pt3dtpPoint[4];
  for (int iIndex = 0; iIndex < 4; iIndex++) {
    pt3dtpPoint[iIndex].x = pt3dPoint[iIndex].x;
    pt3dtpPoint[iIndex].y = pt3dPoint[iIndex].y;
    pt3dtpPoint[iIndex].z = pt3dPoint[iIndex].z;
  }
  pt3dPoint[0].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[0].x + 0 * pt3dtpPoint[0].y +
       sin(TWOPI * dbDegree / 360) * pt3dtpPoint[0].z);
  pt3dPoint[0].y =
      (0 * pt3dtpPoint[0].x + 1 * pt3dtpPoint[0].y + 0 * pt3dtpPoint[0].z);
  pt3dPoint[0].z =
      (-sin(TWOPI * dbDegree / 360) * pt3dtpPoint[0].x + 0 * pt3dtpPoint[0].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[0].z);

  pt3dPoint[1].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[1].x + 0 * pt3dtpPoint[1].y +
       sin(TWOPI * dbDegree / 360) * pt3dtpPoint[1].z);
  pt3dPoint[1].y =
      (0 * pt3dtpPoint[1].x + 1 * pt3dtpPoint[1].y + 0 * pt3dtpPoint[1].z);
  pt3dPoint[1].z =
      (-sin(TWOPI * dbDegree / 360) * pt3dtpPoint[1].x + 0 * pt3dtpPoint[1].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[1].z);

  pt3dPoint[2].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[2].x + 0 * pt3dtpPoint[2].y +
       sin(TWOPI * dbDegree / 360) * pt3dtpPoint[2].z);
  pt3dPoint[2].y =
      (0 * pt3dtpPoint[2].x + 1 * pt3dtpPoint[2].y + 0 * pt3dtpPoint[2].z);
  pt3dPoint[2].z =
      (-sin(TWOPI * dbDegree / 360) * pt3dtpPoint[2].x + 0 * pt3dtpPoint[2].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[2].z);

  pt3dPoint[3].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[3].x + 0 * pt3dtpPoint[3].y +
       sin(TWOPI * dbDegree / 360) * pt3dtpPoint[3].z);
  pt3dPoint[3].y =
      (0 * pt3dtpPoint[3].x + 1 * pt3dtpPoint[3].y + 0 * pt3dtpPoint[3].z);
  pt3dPoint[3].z =
      (-sin(TWOPI * dbDegree / 360) * pt3dtpPoint[3].x + 0 * pt3dtpPoint[3].y +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[3].z);
}

void RotateZ(POINT3D pt3dPoint[4], double dbDegree) {
  POINT3D pt3dtpPoint[4];
  for (int iIndex = 0; iIndex < 4; iIndex++) {
    pt3dtpPoint[iIndex].x = pt3dPoint[iIndex].x;
    pt3dtpPoint[iIndex].y = pt3dPoint[iIndex].y;
    pt3dtpPoint[iIndex].z = pt3dPoint[iIndex].z;
  }
  pt3dPoint[0].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[0].x +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[0].y + 0 * pt3dtpPoint[0].z);
  pt3dPoint[0].y =
      (sin(TWOPI * dbDegree / 360) * pt3dtpPoint[0].x +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[0].y + 0 * pt3dtpPoint[0].z);
  pt3dPoint[0].z =
      (0 * pt3dtpPoint[0].x + 0 * pt3dtpPoint[0].y + 1 * pt3dtpPoint[0].z);

  pt3dPoint[1].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[1].x +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[1].y + 0 * pt3dtpPoint[1].z);
  pt3dPoint[1].y =
      (sin(TWOPI * dbDegree / 360) * pt3dtpPoint[1].x +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[1].y + 0 * pt3dtpPoint[1].z);
  pt3dPoint[1].z =
      (0 * pt3dtpPoint[1].x + 0 * pt3dtpPoint[1].y + 1 * pt3dtpPoint[1].z);

  pt3dPoint[2].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[2].x +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[2].y + 0 * pt3dtpPoint[2].z);
  pt3dPoint[2].y =
      (sin(TWOPI * dbDegree / 360) * pt3dtpPoint[2].x +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[2].y + 0 * pt3dtpPoint[2].z);
  pt3dPoint[2].z =
      (0 * pt3dtpPoint[2].x + 0 * pt3dtpPoint[2].y + 1 * pt3dtpPoint[2].z);

  pt3dPoint[3].x =
      (cos(TWOPI * dbDegree / 360) * pt3dtpPoint[3].x +
       -sin(TWOPI * dbDegree / 360) * pt3dtpPoint[3].y + 0 * pt3dtpPoint[3].z);
  pt3dPoint[3].y =
      (sin(TWOPI * dbDegree / 360) * pt3dtpPoint[3].x +
       cos(TWOPI * dbDegree / 360) * pt3dtpPoint[3].y + 0 * pt3dtpPoint[3].z);
  pt3dPoint[3].z =
      (0 * pt3dtpPoint[3].x + 0 * pt3dtpPoint[3].y + 1 * pt3dtpPoint[3].z);
}
