#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Buffer
{
  public:
    Buffer();
    friend Buffer &operator<<(Buffer &curr, const string &str);
    void goToLine(int);
    int getCurrLine();
    void disp();
    void clear();

  private:
    int line;
    vector<string> buf;
    int size;

}writeBuf;

Buffer::Buffer()
{
    buf.push_back("");
    line = 0;
    size = 1;
}

Buffer &operator<<(Buffer &curr, const string &str)
{
    if (str == "\n")
    {
        if (curr.line == curr.size - 1)
        {
            curr.buf.push_back("");
            ++curr.line;
            ++curr.size;
        }
        else
        {
            ++curr.line;
        }
    }
    else
        curr.buf[curr.line] += str;
    
    return curr;
}

void Buffer::goToLine(int n)
{
    if (n > size)
        return;
    else
        line = n;
}

int Buffer::getCurrLine()
{
    return line;
}

void Buffer::disp()
{
    goToLine(0);
    for (auto str : buf)
        cout << str << endl;
}

void Buffer::clear()
{
    vector<string> t(size, "");
    buf = t;
}