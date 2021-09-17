#include <iostream>
#include <istream>
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
            Core::Log("Invalid file\n");
            return 1;
        }
    } catch(std::logic_error) {
        Core::Log("Invalid file\n");
        return 0;
    }
    try {
        if(!Core::Usable_File(argv[2])) {
            Core::Log("Invalid file\n");
            return 1;
        }
    } catch(std::logic_error) {
        Core::Log("Invalid file\n");
        return 0;
    }
    std::string Buffer = Core::Read_File(argv[1]);
    Core::Log("Watching file\n");
    while(true) {
        if(Buffer != Core::Read_File(argv[1])) {
            Buffer = Core::Read_File(argv[1]);
            Core::Log("File update detected.\n");
            system(argv[2]);
        }
        Sleep(250);
    }
    return 0;
}