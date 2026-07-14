#include <windows.h>
#include <string>
#include <iostream>

int main() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    
    std::wstring en = L"qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    std::wstring ru = L"йцукенгшщзхъфывапролджэячсмитьбю.";

    wchar_t buffer[1024];
    DWORD read;
    ReadConsoleW(hStdin, buffer, 1024, &read, NULL);
    std::wstring s(buffer, read);

    std::wstring result = L"";

    for (wchar_t c : s) {
        size_t p_en = en.find(c);
        size_t p_ru = ru.find(c);

        if (p_en != std::wstring::npos) {
         
            result += ru[p_en];
        }
        else if (p_ru != std::wstring::npos) {
          
            result += en[p_ru];
        }
        else {
          
            result += c;
        }
    }

    WriteConsoleW(hStdout, result.c_str(), (DWORD)result.length(), NULL, NULL);

    return 0;
}
