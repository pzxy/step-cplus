#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

void timestamp()
{
    cout << "> timestamp" << endl;
    std::time_t now = std::time(0); // 时间戳
    cout << now << endl;
}

void timestamp2locatime()
{
    cout << "> timestamp2locatime" << endl;
    time_t now = std::time(0);
    // 将时间戳转换为本地时间
    std::tm *local_time = std::localtime(&now);

    // 输出本地时间
    std::cout << "Year: " << local_time->tm_year + 1900 << std::endl;
    std::cout << "Month: " << local_time->tm_mon + 1 << std::endl;
    std::cout << "Day: " << local_time->tm_mday << std::endl;
    std::cout << "Hour: " << local_time->tm_hour << std::endl;
    std::cout << "Minute: " << local_time->tm_min << std::endl;
    std::cout << "Second: " << local_time->tm_sec << std::endl;
}

void timestamp2string()
{
    cout << "> timestamp2string" << endl;
    time_t now = time(0);
    char *dt = ctime(&now); // 时间戳转字符。
    cout << "ctime: " << dt << endl;
    // 格式化
    char buf[100];
    std::tm *local_time = std::localtime(&now);
    std::strftime(buf, 100, "%Y-%m-%d %H:%M:%S", local_time);
    cout << "strftime: " << buf << endl;
}

void timestamp2UTC()
{
    cout << "> timestamp2UTC" << endl;
    time_t now = time(0);
    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now); // 将时间转成UTC时间
    char *dt = asctime(gmtm);
    cout << "UTC time: " << dt << endl;
}

void string2timestamp()
{
    cout << "> string2timestamp" << endl;
    // 定义字符串和格式化字符串
    const char *str_time = "2023-06-23 12:34:56";
    const char *format = "%Y-%m-%d %H:%M:%S";

    // 定义tm结构体,表示时间信息。
    std::tm tm{};

    // 转换字符串为时间
    strptime(str_time, format, &tm); // c语言中的库，没有自己的命名空间，这里不是 std::strptime
    std::time_t time = std::mktime(&tm);
    cout << time << endl;
}

int main()
{
    timestamp();
    timestamp2locatime();
    timestamp2string();
    timestamp2UTC();
    string2timestamp();
    // 总结：
    // 主要是从time_t(long时间戳),tm结构体 ,char* 三种结构之间的转换。
    // asctime 和 ctime 都是将时间转换成字符串。不过 asctime 的参数是tm，ctime的参数是time_t
    // 此外还有更强大的 chrono 库可以对时间进行处理。
}