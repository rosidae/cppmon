#include <iostream>
#include <istream>
#include <vector>
#include <ostream>
#include <fstream>
#include <thread>
#include <string>
#include <Files.h>
#include <Windows.h>
#include <CoreUtilties.h>

int main(int argc, char* argv[]) {
    try {
        if(!Core::Usable_File(argv[1])) {
            Core::Log("Invalid file");
            return 1;
        }
    } catch(std::logic_error) {
        Core::Log("Invalid file");
        return 0;
    }
    std::string Buffer = Core::Read_File(argv[1]);
    Core::Log("Watching file");
    while(true) {
        if(Buffer != Core::Read_File(argv[1])) {
            Buffer = Core::Read_File(argv[1]);
            system("cls");
            Core::Log("File update detected.");
            for(std::string ex: Core::Read_File_Lines("cfile")) {
                Core::Log(ex.c_str());
                system(ex.c_str());
            }
        }
        Sleep(1);
    }
    return 0;
}