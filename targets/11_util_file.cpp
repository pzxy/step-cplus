#include <iostream>
#include <fstream>
using namespace std;

/**

int main ()
{

   char data[100];

   // 以写模式打开文件
   ofstream outfile;
   outfile.open("afile.dat");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: ";
   cin.getline(data, 100);

   // 向文件写入用户输入的数据
   outfile << data << endl;

   cout << "Enter your age: ";
   cin >> data;
   cin.ignore();

   // 再次向文件写入用户输入的数据
   outfile << data << endl;

   // 关闭打开的文件
   outfile.close();

   // 以读模式打开文件
   ifstream infile;
   infile.open("afile.dat");

   cout << "Reading from the file" << endl;
   infile >> data;

   // 在屏幕上写入数据
   cout << data << endl;

   // 再次从文件读取数据，并显示它
   infile >> data;
   cout << data << endl;

   // 关闭打开的文件
   infile.close();

   return 0;
}
*/
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
    ofstream outfile;
    outfile.open("outfile", ios::app);
    outfile << "hello world " << 1 << endl;
}

void read_file()
{
    char data[100];
    cout << "> read_file" << endl;
    ifstream infile;
    infile.open("outfile");
    infile >> data; // 这种方式每次读取到空格。或者换行。
    cout << data << endl;
    infile >> data; // 这种方式每次读取到空格。或者换行。
    cout << data << endl;
}

int main()
{
    open_file();
    write_file();
    read_file();
}