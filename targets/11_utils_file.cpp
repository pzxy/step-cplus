#include <iostream>
#include <fstream>
using namespace std;

void open_file()
{
    // ios::app	追加模式。所有写入都追加到文件末尾。
    // ios::ate	文件打开后定位到文件末尾。
    // ios::in	打开文件用于读取。
    // ios::out	打开文件用于写入。
    // ios::trunc	如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0。
    cout << "> open_file" << endl;
    ifstream f; // ofstream 默认会创建，ifstream的open默认不会创建。
    f.open("infile");
    cout << f.is_open() << endl;
    f.close();
}

void write_file()
{
    cout << "> write_file" << endl;
    ofstream outfile; // ofstream只能写入，就算用了 ios::in也只能写入，不能读取。
    outfile.open("outfile", ios::app);
    outfile << "hello world " << 1 << endl;
    outfile << "hello world " << 1 << endl;
    outfile << "hello world " << 1 << endl;
}

void read_file()
{
    char data[100];
    cout << "> read_file" << endl;
    ifstream infile;
    infile.open("outfile"); // ios::out对这 ifstream无效。只能读取，不能写入。
    infile >> data;         // 这种方式每次读取到空格。或者换行。
    cout << data << endl;
    infile >> data; // 这种方式每次读取到空格。或者换行。
    cout << data << endl;
    infile >> data; // 这种方式每次读取到空格。或者换行。
    cout << data << endl;
    infile.close();

    // 按照行读取。
    // ifstream f{"outfile"};
    fstream f{"outfile"};
    string s;
    getline(f, s);
    cout << s << endl;
    f.close();
}

int main()
{
    open_file();
    write_file();
    read_file();
}