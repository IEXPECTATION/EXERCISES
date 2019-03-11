#include<stdio.h>

int array_3[3][3] = {0};
int array_4[4][4] = {0};
int array_5[5][5] = {0};

int result_3(int (*)[]);
int result_4(int (*)[]);
int result_5(int (*)[]);

int main()
{
    int flag;
    printf("1)三阶\n2)四阶\n3)五阶\n");
    scanf("%d", &flag);
    switch(flag)
    {
        case 1: //三阶
            printf("输入三阶行列式\n");
            scanf("%d %d %d %d %d %d %d %d %d", \
            &array_3[0][0], &array_3[0][1], &array_3[0][2], \
            &array_3[1][0], &array_3[1][1], &array_3[1][2], \
            &array_3[2][0], &array_3[2][1], &array_3[2][2]);
            printf("三阶行列式:%d\n", result_3(array_3));
            break;
        case 2: //四阶 
            printf("输入四阶行列式\n");
            scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", \
            &array_4[0][0], &array_4[0][1], \
            &array_4[0][2], &array_4[0][3], \
            &array_4[1][0], &array_4[1][1], \
            &array_4[1][2], &array_4[1][3], \
            &array_4[2][0], &array_4[2][1], \
            &array_4[2][2], &array_4[2][3], \
            &array_4[3][0], &array_4[3][1], \
            &array_4[3][2], &array_4[3][3]);
            printf("四阶行列式:%d\n", result_4(array_4));
            break;
        case 3: //五阶
            printf("输入五阶行列式\n");
            scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", \
             &array_5[0][0], &array_5[0][1], \
             &array_5[0][2], &array_5[0][3], \
             &array_5[0][4], \
             &array_5[1][0], &array_5[1][1], \
             &array_5[1][2], &array_5[1][3], \
             &array_5[1][4], \
             &array_5[2][0], &array_5[2][1], \
             &array_5[2][2], &array_5[2][3], \
             &array_5[2][4], \
             &array_5[3][0], &array_5[3][1], \
             &array_5[3][2], &array_5[3][3], \
             &array_5[3][4], \
             &array_5[4][0], &array_5[4][1], \
             &array_5[4][2], &array_5[4][3], \
             &array_5[4][4]);
            printf("五阶行列式：%d\n", result_5(array_5));
            break;
    }
        /*
        printf("请输入三阶行列式\n");
        scanf("%d %d %d %d %d %d %d %d %d"\
        ,&a[0][0], &a[0][1], &a[0][2], \
         &a[1][0], &a[1][1], &a[1][2], &a[2][0], \
        &a[2][1], &a[2][2]);
        printf("行列式:%d\n", result(a));
        */
    return 0;
}

int result_3(int array_3[3][3])
{
    return (\
    (array_3[0][0]) * (array_3[1][1]) * (array_3[2][2]) \
    + \
    (array_3[0][1]) * (array_3[1][2]) * (array_3[2][0]) \
    + \
    (array_3[1][0]) * (array_3[2][1]) * (array_3[0][2]) \
    - \
    (array_3[0][2]) * (array_3[1][1]) * (array_3[2][0]) \
    - \
    (array_3[1][0]) * (array_3[0][1]) * (array_3[2][2]) \
    - \
    (array_3[2][1]) * (array_3[1][2]) * (array_3[0][0]));
}


int result_4(int array_4[4][4])
{
    int array_0[3][3], array_1[3][3], array_2[3][3], \
    array_3[3][3];
    
    array_0[0][0] = array_4[1][1];
    array_0[0][1] = array_4[1][2];
    array_0[0][2] = array_4[1][3];
    array_0[1][0] = array_4[2][1];
    array_0[1][1] = array_4[2][2];
    array_0[1][2] = array_4[2][3];
    array_0[2][0] = array_4[3][1];
    array_0[2][1] = array_4[3][2];
    array_0[2][2] = array_4[3][3];

    array_1[0][0] = array_4[1][0];
    array_1[0][1] = array_4[1][2];
    array_1[0][2] = array_4[1][3];
    array_1[1][0] = array_4[2][0];
    array_1[1][1] = array_4[2][2];
    array_1[1][2] = array_4[2][3];
    array_1[2][0] = array_4[3][0];
    array_1[2][1] = array_4[3][2];
    array_1[2][2] = array_4[3][3];

    array_2[0][0] = array_4[1][0];
    array_2[0][1] = array_4[1][1];
    array_2[0][2] = array_4[1][3];
    array_2[1][0] = array_4[2][0];
    array_2[1][1] = array_4[2][1];
    array_2[1][2] = array_4[2][3];
    array_2[2][0] = array_4[3][0];
    array_2[2][1] = array_4[3][1];
    array_2[2][2] = array_4[3][3];
    
    array_3[0][0] = array_4[1][0];
    array_3[0][1] = array_4[1][1];
    array_3[0][2] = array_4[1][2];
    array_3[1][0] = array_4[2][0];
    array_3[1][1] = array_4[2][1];
    array_3[1][2] = array_4[2][2];
    array_3[2][0] = array_4[3][0];
    array_3[2][1] = array_4[3][1];
    array_3[2][2] = array_4[3][2];

    return array_4[0][0] * result_3(array_0) \
            + \
            array_4[0][1] * (-1) * result_3(array_1) \
            + \
            array_4[0][2] * result_3(array_2) \
            + \
            array_4[0][3] * (-1) * result_3(array_3);
}

int result_5(int array_5[5][5])
{
    int i,j;

    int array_0[4][4], array_1[4][4], array_2[4][4], \
    array_3[4][4], array_4[4][4];
    
    array_0[0][0] = array_5[1][1];
    array_0[0][1] = array_5[1][2];
    array_0[0][2] = array_5[1][3];
    array_0[0][3] = array_5[1][4];
    array_0[1][0] = array_5[2][1];
    array_0[1][1] = array_5[2][2];
    array_0[1][2] = array_5[2][3];
    array_0[1][3] = array_5[2][4];
    array_0[2][0] = array_5[3][1];
    array_0[2][1] = array_5[3][2];
    array_0[2][2] = array_5[3][3];
    array_0[2][3] = array_5[3][4];
    array_0[3][0] = array_5[4][1];
    array_0[3][1] = array_5[4][2];
    array_0[3][2] = array_5[4][3];
    array_0[3][3] = array_5[4][4];
    
    array_1[0][0] = array_5[1][0];
    array_1[0][1] = array_5[1][2];
    array_1[0][2] = array_5[1][3];
    array_1[0][3] = array_5[1][4];
    array_1[1][0] = array_5[2][0];
    array_1[1][1] = array_5[2][2];
    array_1[1][2] = array_5[2][3];
    array_1[1][3] = array_5[2][4];
    array_1[2][0] = array_5[3][0];
    array_1[2][1] = array_5[3][2];
    array_1[2][2] = array_5[3][3];
    array_1[2][3] = array_5[3][4];
    array_1[3][0] = array_5[4][0];
    array_1[3][1] = array_5[4][2];
    array_1[3][2] = array_5[4][3];
    array_1[3][3] = array_5[4][4];

    array_2[0][0] = array_5[1][0];
    array_2[0][1] = array_5[1][1];
    array_2[0][2] = array_5[1][3];
    array_2[0][3] = array_5[1][4];
    array_2[1][0] = array_5[2][0];
    array_2[1][1] = array_5[2][1];
    array_2[1][2] = array_5[2][3];
    array_2[1][3] = array_5[2][4];
    array_2[2][0] = array_5[3][0];
    array_2[2][1] = array_5[3][1];
    array_2[2][2] = array_5[3][3];
    array_2[2][3] = array_5[3][4];
    array_2[3][0] = array_5[4][0];
    array_2[3][1] = array_5[4][1];
    array_2[3][2] = array_5[4][3];
    array_2[3][3] = array_5[4][4];

    array_3[0][0] = array_5[1][0];
    array_3[0][1] = array_5[1][1];
    array_3[0][2] = array_5[1][2];
    array_3[0][3] = array_5[1][4];
    array_3[1][0] = array_5[2][0];
    array_3[1][1] = array_5[2][1];
    array_3[1][2] = array_5[2][2];
    array_3[1][3] = array_5[2][4];
    array_3[2][0] = array_5[3][0];
    array_3[2][1] = array_5[3][1];
    array_3[2][2] = array_5[3][2];
    array_3[2][3] = array_5[3][4];
    array_3[3][0] = array_5[4][0];
    array_3[3][1] = array_5[4][0];
    array_3[3][2] = array_5[4][1];
    array_3[3][3] = array_5[4][2];

    array_4[0][0] = array_5[1][0];
    array_4[0][1] = array_5[1][1];
    array_4[0][2] = array_5[1][2];
    array_4[0][3] = array_5[1][3];
    array_4[1][0] = array_5[2][0];
    array_4[1][1] = array_5[2][1];
    array_4[1][2] = array_5[2][2];
    array_4[1][3] = array_5[2][3];
    array_4[2][0] = array_5[3][0];
    array_4[2][1] = array_5[3][1];
    array_4[2][2] = array_5[3][2];
    array_4[2][3] = array_5[3][3];
    array_4[3][0] = array_5[4][0];
    array_4[3][1] = array_5[4][1];
    array_4[3][2] = array_5[4][2];
    array_4[3][3] = array_5[4][3];

    
    return array_5[0][0] * result_4(array_0) \
            + \
            array_5[0][1] * (-1) * result_4(array_1) \
            + \
            array_5[0][2] * result_4(array_2) \
            + \
            array_5[0][3] * (-1) * result_4(array_3) \
            + \
            array_5[0][4] * result_4(array_4);
}
