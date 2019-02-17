#include <cstdio>

long long StrToIntCore(const char* str, bool minus);//字符指针类型str　布尔类型minus(负数)

enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    long long num = 0;
    //char a=nullptr;

    if(str != nullptr && *str != '\0') 
    {
        bool minus = false;
        if(*str == '+')
            str ++;
        else if(*str == '-') 
        {
            str ++;
            minus = true;
        }

        if(*str != '\0') 
            num = StrToIntCore(str, minus);
    }

    return (int)num;//强制类型转换为整型
}

long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;

    while(*digit != '\0') 
    {
        if(*digit >= '0' && *digit <= '9') 
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');

            if((!minus && num > 0x7FFFFFFF) 
                || (minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }

            digit++;
        }
        else //
        {
            num = 0;
            break;
        }
    }

    if(*digit == '\0') 
        g_nStatus = kValid;

    return num;
}

// ====================测试代码====================
void Test(const char* string)
{
    int result = StrToInt(string);
    if(result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    Test("");
    Test(" ");

    Test("123");

    Test("+123");
    
    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");
    Test("0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");    

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");    

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}
/*49StrtoInt
判断str是否为nullstr和空字符串
　 判断str的符号
　 判断str是否为空字符串
　　　　 判断str的每位上大于０且小于９
　　　　　　　 　计算num
		 每计算一位判断是否超过阈值
　 判断str是否执行完毕 if（*str=='\0'）
   return num;*/
