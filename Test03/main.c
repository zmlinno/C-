//
//  main.c
//  Test03
//
//  Created by 张木林 on 3/2/24.
//

#include <stdio.h>

//int main()
//{
//    int a,b;
//    scanf("%d,%d",&a,&b);
//    if(a = b)
//    {
//        printf("%d=%d",a=b);
//    }
//    else if(a>b)
//    {
//        printf("%d>%d",a>b);
//    }
//    else
//    {
//        printf("%d<%d",a<b);
//    }
//    return 0;
//}

//比较两个数的大小

//int main()
//{
//    int a = 0;
//    int b = 0;
//    while(scanf("%d%d",&a,&b)!= EOF)
//    if(a>b)
//    {
//        printf("%d>%d\n",a,b);
//    }
//    else if (a<b)
//    {
//        printf("%d<%d\n",a,b);
//    }
//    else
//    {
//        printf("%d=%d\n",a,b);
//    }
//    return 0;
//}
   





//求两个数的较大值
//方法1
//int main()
//{
//    int a,b;
//    while(scanf("%d%d",&a,&b)!=EOF)
//    {
//        if(a>b)
//        {
//            printf("%d\n",a);
//        }
//        else if(a<b)
//        {
//            printf("%d\n",b);
//        }
//        else
//        {
//            break;
//        }
//            
//    }
//    return 0;
//}


//方法2
//int swap(int a,int b)
//{
//    if(a>b)
//    {
//        return a;
//    }
//    else
//    {
//        return b;
//    }
//}
////方法2
//int main()
//{
//    int a,b;
//    scanf("%d%d",&a,&b);
//    
//    int bignumber = swap(a,b);
//    printf("%d\n",bignumber);
//    return 0;
//}






//成绩输入输出问题
// 1. 如果写成int arr[] = {0};的话，那么因为数组是只有1个长度，下面代码循环会9次，需要存储9次
// 2. 但是数组的储存值只有一个，所以会显示越界，正确应该写成下面这样。不写的话默认给一个单位的储存值。
//int main()
//{
//    int arr[10] = {0};
//    for(int i = 0;i<10;i++)
//    {
//        scanf("%d",&arr[i]);
//        printf("%d ",arr[i]);
//    }
//    return 0;
//}









// 判断整数奇偶性的代码
// 下面是我自己写的代码，但是在牛客上没法通过
//int main()
//{
//
//    int a,b;
//    scanf("%d\n%d",&a,&b);
//    if(a%b == 0)
//    {
//        printf("Even\n");
//    }
//    else
//    {
//        printf("Odd\n");
//    }
//
//    return 0;
//}




//改正后 ,这个题目在于你输入的数字是否为奇数或偶数
//int main()
//{
//    int a;
//    while(scanf("%d",&a)!=EOF)
//    {
//        if(a%2 == 0)
//        {
//            printf("Even\n");
//        }
//        else
//        {
//            printf("Odd\n");
//        }
//    }
//    return 0;
//}









//打星星的代码
//输入多少个数字会打出多少个星星
//int main()
//{
//    int a,b;
//    while(scanf("%d%d",&a,&b) != EOF)
//    {
//        for(int i = 0;i<=a-1;i++)
//        {
//            printf("*");
//        }
//        printf("\n");
//
//    }
//    return 0;
//}








//计算平均成绩的
//输入五个整数，计算平均成绩
int main()
{
    int a;
    int sum = 0;
    for(int i = 0; i<4;i++)
    {
        scanf("%d",&a);
        sum += a;
    }
    printf("%.1f\n",sum/5.0);
    return 0;
}
