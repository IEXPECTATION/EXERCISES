# 将正方形变为正方体

第一步：将四个点改为八个点  

在函数WndProc中修改pt3dPoint的声明为如下说示：  
`static POINT3D pt3dPoint[8] = {
    {-5000, -5000, 5000},
    {-5000, 5000, 5000},
    {5000, 5000, 5000},
    {5000, -5000, 5000},
    {-5000, -5000, -5000},
    {-5000, 5000, -5000},
    {5000, 5000, -5000},
    {5000, -5000, -5000},
}`

第二步：修改函数声明和定义的参数  

将参数POINT3D [4]/pt3dPoint[4]修改为POINT3D [8]/pt3dPoint[8]

第三步：修改函数的定义

以RotateX为例，其余旋转函数类似。

``` C
RotateX(POINT3D pt3dPoint[8])
{
    POINT3D pt3dtpPoint[8];
    for (int iIndex = 0; iIndex < 8; iIndex++)
    {
        pt3dtpPoint[iIndex].x = pt3dPoint[iIndex].x;
        pt3dtpPoint[iIndex].y = pt3dPoint[iIndex].y;
        pt3dtpPoint[iIndex].z = pt3dPoint[iIndex].z;
    }
    pt3dPoint[0].x =  (1 * pt3dtpPoint[0].x + 0 * pt3dtpPoint[0].y + 0 * pt3dtpPoint[0].z);
    pt3dPoint[0].y =  (0 *pt3dtpPoint[0].x + cos(dbDegree) * pt3dtpPoint[0].y + -sin(dbDegree) * pt3dtpPoint[0].z);
    pt3dPoint[0].z =  (0 *pt3dtpPoint[0].x + sin(dbDegree) * pt3dtpPoint[0].y + cos(dbDegree) * pt3dtpPoint[0].z);
    pt3dPoint[1].x =  (1 * pt3dtpPoint[1].x + 0 * pt3dtpPoint[1].y + 0 * pt3dtpPoint[1].z);
    pt3dPoint[1].y =  (0 *pt3dtpPoint[1].x + cos(dbDegree) * pt3dtpPoint[1].y + -sin(dbDegree) * pt3dtpPoint[1].z);
    pt3dPoint[1].z =  (0 *pt3dtpPoint[1].x + sin(dbDegree) * pt3dtpPoint[1].y + cos(dbDegree) * pt3dtpPoint[1].z);
    pt3dPoint[2].x =  (1 * pt3dtpPoint[2].x + 0 * pt3dtpPoint[2].y + 0 * pt3dtpPoint[2].z);
    pt3dPoint[2].y =  (0 * pt3dtpPoint[2].x + cos(dbDegree) * pt3dtpPoint[2].y + -sin(dbDegree) * pt3dtpPoint[2].z);
    pt3dPoint[2].z =  (0 * pt3dtpPoint[2].x + sin(dbDegree) * pt3dtpPoint[2].y + cos(dbDegree) * pt3dtpPoint[2].z);
    pt3dPoint[3].x =  (1 * pt3dtpPoint[3].x + 0 * pt3dtpPoint[3].y + 0 * pt3dtpPoint[3].z);
    pt3dPoint[3].y =  (0 * pt3dtpPoint[3].x + cos(dbDegree) * pt3dtpPoint[3].y + -sin(dbDegree) * pt3dtpPoint[3].z);
    pt3dPoint[3].z =  (0 * pt3dtpPoint[3].x + sin(dbDegree) * pt3dtpPoint[3].y + cos(dbDegree) * pt3dtpPoint[3].z);
    pt3dPoint[4].x =  (1 * pt3dtpPoint[4].x + 0 * pt3dtpPoint[4].y + 0 * pt3dtpPoint[4].z);
    pt3dPoint[4].y =  (0 *pt3dtpPoint[4].x + cos(dbDegree) * pt3dtpPoint[4].y + -sin(dbDegree) * pt3dtpPoint[4].z);
    pt3dPoint[4].z =  (0 *pt3dtpPoint[4].x + sin(dbDegree) * pt3dtpPoint[4].y + cos(dbDegree) * pt3dtpPoint[4].z);
    pt3dPoint[5].x =  (1 * pt3dtpPoint[5].x + 0 * pt3dtpPoint[5].y + 0 * pt3dtpPoint[5].z);
    pt3dPoint[5].y =  (0 *pt3dtpPoint[5].x + cos(dbDegree) * pt3dtpPoint[5].y + -sin(dbDegree) * pt3dtpPoint[5].z);
    pt3dPoint[5].z =  (0 *pt3dtpPoint[5].x + sin(dbDegree) * pt3dtpPoint[5].y + cos(dbDegree) * pt3dtpPoint[5].z);
    pt3dPoint[6].x =  (1 * pt3dtpPoint[6].x + 0 * pt3dtpPoint[6].y + 0 * pt3dtpPoint[6].z);
    pt3dPoint[6].y =  (0 * pt3dtpPoint[6].x + cos(dbDegree) * pt3dtpPoint[6].y + -sin(dbDegree) * pt3dtpPoint[6].z);
    pt3dPoint[6].z =  (0 * pt3dtpPoint[6].x + sin(dbDegree) * pt3dtpPoint[6].y + cos(dbDegree) * pt3dtpPoint[6].z);
    pt3dPoint[7].x =  (1 * pt3dtpPoint[7].x + 0 * pt3dtpPoint[7].y + 0 * pt3dtpPoint[7].z);
    pt3dPoint[7].y =  (0 * pt3dtpPoint[7].x + cos(dbDegree) * pt3dtpPoint[7].y + -sin(dbDegree) * pt3dtpPoint[7].z);
    pt3dPoint[7].z =  (0 * pt3dtpPoint[7].x + sin(dbDegree) * pt3dtpPoint[7].y + cos(dbDegree) * pt3dtpPoint[7].z);
}
```

关于连线的函数只展示是用画笔的，使用矩阵的连线方法只能使用在一个方向的旋转。

``` C
// 前面的正方形
MoveToEx(hdc, pt3dPoint[0].x, pt3dPoint[0].y, NULL); // 移动到第一个圆的圆心
LineTo(hdc, pt3dPoint[1].x, pt3dPoint[1].y);
LineTo(hdc, pt3dPoint[2].x, pt3dPoint[2].y);
LineTo(hdc, pt3dPoint[3].x, pt3dPoint[3].y);

// 后面的正方形
MoveToEx(hdc, pt3dPoint[4].x, pt3dPoint[4].y, NULL); // 移动到第一个圆的圆心
LineTo(hdc, pt3dPoint[5].x, pt3dPoint[5].y);
LineTo(hdc, pt3dPoint[6].x, pt3dPoint[6].y);
LineTo(hdc, pt3dPoint[7].x, pt3dPoint[7].y);

// 连接两个正方形
MoveToEx(hdc, pt3dPoint[0].x, pt3dPoint[0].y, NULL);
LineTo(hdc, pt3dPoint[4].x, pt3dPoint[4].y);
MoveToEx(hdc, pt3dPoint[1].x, pt3dPoint[1].y, NULL);
LineTo(hdc, pt3dPoint[5].x, pt3dPoint[5].y);
MoveToEx(hdc, pt3dPoint[2].x, pt3dPoint[2].y, NULL);
LineTo(hdc, pt3dPoint[6].x, pt3dPoint[6].y);
MoveToEx(hdc, pt3dPoint[3].x, pt3dPoint[3].y, NULL);
LineTo(hdc, pt3dPoint[7].x, pt3dPoint[7].y);
```

上面代码本没有进行测试，可能会有错误。
=======
# 将正方形变为长方形

第一步：将四个点改为八个点  

在函数WndProc中修改pt3dPoint的声明为如下说示：  
`static POINT3D pt3dPoint[8] = {
    {-5000, -5000, 5000},
    {-5000, 5000, 5000},
    {5000, 5000, 5000},
    {5000, -5000, 5000},
    {-5000, -5000, -5000},
    {-5000, 5000, -5000},
    {5000, 5000, -5000},
    {5000, -5000, -5000},
}`

第二步：修改函数声明和定义的参数  

将参数POINT3D [4]/pt3dPoint[4]修改为POINT3D [8]/pt3dPoint[8]

第三步：修改函数的定义

以RotateX为例，其余旋转函数类似。

``` C
RotateX(POINT3D pt3dPoint[8])
{
    POINT3D pt3dtpPoint[8];
    for (int iIndex = 0; iIndex < 8; iIndex++)
    {
        pt3dtpPoint[iIndex].x = pt3dPoint[iIndex].x;
        pt3dtpPoint[iIndex].y = pt3dPoint[iIndex].y;
        pt3dtpPoint[iIndex].z = pt3dPoint[iIndex].z;
    }
    pt3dPoint[0].x =  (1 * pt3dtpPoint[0].x + 0 * pt3dtpPoint[0].y + 0 * pt3dtpPoint[0].z);
    pt3dPoint[0].y =  (0 *pt3dtpPoint[0].x + cos(dbDegree) * pt3dtpPoint[0].y + -sin(dbDegree) * pt3dtpPoint[0].z);
    pt3dPoint[0].z =  (0 *pt3dtpPoint[0].x + sin(dbDegree) * pt3dtpPoint[0].y + cos(dbDegree) * pt3dtpPoint[0].z);
    pt3dPoint[1].x =  (1 * pt3dtpPoint[1].x + 0 * pt3dtpPoint[1].y + 0 * pt3dtpPoint[1].z);
    pt3dPoint[1].y =  (0 *pt3dtpPoint[1].x + cos(dbDegree) * pt3dtpPoint[1].y + -sin(dbDegree) * pt3dtpPoint[1].z);
    pt3dPoint[1].z =  (0 *pt3dtpPoint[1].x + sin(dbDegree) * pt3dtpPoint[1].y + cos(dbDegree) * pt3dtpPoint[1].z);
    pt3dPoint[2].x =  (1 * pt3dtpPoint[2].x + 0 * pt3dtpPoint[2].y + 0 * pt3dtpPoint[2].z);
    pt3dPoint[2].y =  (0 * pt3dtpPoint[2].x + cos(dbDegree) * pt3dtpPoint[2].y + -sin(dbDegree) * pt3dtpPoint[2].z);
    pt3dPoint[2].z =  (0 * pt3dtpPoint[2].x + sin(dbDegree) * pt3dtpPoint[2].y + cos(dbDegree) * pt3dtpPoint[2].z);
    pt3dPoint[3].x =  (1 * pt3dtpPoint[3].x + 0 * pt3dtpPoint[3].y + 0 * pt3dtpPoint[3].z);
    pt3dPoint[3].y =  (0 * pt3dtpPoint[3].x + cos(dbDegree) * pt3dtpPoint[3].y + -sin(dbDegree) * pt3dtpPoint[3].z);
    pt3dPoint[3].z =  (0 * pt3dtpPoint[3].x + sin(dbDegree) * pt3dtpPoint[3].y + cos(dbDegree) * pt3dtpPoint[3].z);
    pt3dPoint[4].x =  (1 * pt3dtpPoint[4].x + 0 * pt3dtpPoint[4].y + 0 * pt3dtpPoint[4].z);
    pt3dPoint[4].y =  (0 *pt3dtpPoint[4].x + cos(dbDegree) * pt3dtpPoint[4].y + -sin(dbDegree) * pt3dtpPoint[4].z);
    pt3dPoint[4].z =  (0 *pt3dtpPoint[4].x + sin(dbDegree) * pt3dtpPoint[4].y + cos(dbDegree) * pt3dtpPoint[4].z);
    pt3dPoint[5].x =  (1 * pt3dtpPoint[5].x + 0 * pt3dtpPoint[5].y + 0 * pt3dtpPoint[5].z);
    pt3dPoint[5].y =  (0 *pt3dtpPoint[5].x + cos(dbDegree) * pt3dtpPoint[5].y + -sin(dbDegree) * pt3dtpPoint[5].z);
    pt3dPoint[5].z =  (0 *pt3dtpPoint[5].x + sin(dbDegree) * pt3dtpPoint[5].y + cos(dbDegree) * pt3dtpPoint[5].z);
    pt3dPoint[6].x =  (1 * pt3dtpPoint[6].x + 0 * pt3dtpPoint[6].y + 0 * pt3dtpPoint[6].z);
    pt3dPoint[6].y =  (0 * pt3dtpPoint[6].x + cos(dbDegree) * pt3dtpPoint[6].y + -sin(dbDegree) * pt3dtpPoint[6].z);
    pt3dPoint[6].z =  (0 * pt3dtpPoint[6].x + sin(dbDegree) * pt3dtpPoint[6].y + cos(dbDegree) * pt3dtpPoint[6].z);
    pt3dPoint[7].x =  (1 * pt3dtpPoint[7].x + 0 * pt3dtpPoint[7].y + 0 * pt3dtpPoint[7].z);
    pt3dPoint[7].y =  (0 * pt3dtpPoint[7].x + cos(dbDegree) * pt3dtpPoint[7].y + -sin(dbDegree) * pt3dtpPoint[7].z);
    pt3dPoint[7].z =  (0 * pt3dtpPoint[7].x + sin(dbDegree) * pt3dtpPoint[7].y + cos(dbDegree) * pt3dtpPoint[7].z);
}
```

关于连线的函数只展示是用画笔的，使用矩阵的连线方法只能使用在一个方向的旋转。

``` C
// 前面的正方形
MoveToEx(hdc, pt3dPoint[0].x, pt3dPoint[0].y, NULL); // 移动到第一个圆的圆心
LineTo(hdc, pt3dPoint[1].x, pt3dPoint[1].y);
LineTo(hdc, pt3dPoint[2].x, pt3dPoint[2].y);
LineTo(hdc, pt3dPoint[3].x, pt3dPoint[3].y);

// 后面的正方形
MoveToEx(hdc, pt3dPoint[4].x, pt3dPoint[4].y, NULL); // 移动到第一个圆的圆心
LineTo(hdc, pt3dPoint[5].x, pt3dPoint[5].y);
LineTo(hdc, pt3dPoint[6].x, pt3dPoint[6].y);
LineTo(hdc, pt3dPoint[7].x, pt3dPoint[7].y);

// 连接两个正方形
MoveToEx(hdc, pt3dPoint[0].x, pt3dPoint[0].y, NULL);
LineTo(hdc, pt3dPoint[4].x, pt3dPoint[4].y);
MoveToEx(hdc, pt3dPoint[1].x, pt3dPoint[1].y, NULL);
LineTo(hdc, pt3dPoint[5].x, pt3dPoint[5].y);
MoveToEx(hdc, pt3dPoint[2].x, pt3dPoint[2].y, NULL);
LineTo(hdc, pt3dPoint[6].x, pt3dPoint[6].y);
MoveToEx(hdc, pt3dPoint[3].x, pt3dPoint[3].y, NULL);
LineTo(hdc, pt3dPoint[7].x, pt3dPoint[7].y);
```

上面代码没有进行测试，可能会有错误。
