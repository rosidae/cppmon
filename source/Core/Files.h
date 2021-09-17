#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define FILE_SIZE_BYTES         0
#define FILE_SIZE_KILOBYTES     1
#define FILE_SIZE_MEGABYTES     2
#define FILE_SIZE_GIGABYTES     3
#define HEAD_PNG              0x89504E470D0A1A0A
#define HEAD_MP3              0xFFFB
#define HEAD_MP4              0x6674797069736F6D


namespace Core {
    bool Usable_File(std::string File_Name) {
        std::ifstream File(File_Name);
        if(!File.is_open()) {
            return false;
        }
        File.close();
        return true;
    }
    std::string Read_File(std::string File_Name) {
        if(!Usable_File(File_Name)) { return ""; }
        std::ifstream File(File_Name);
        std::string Line;
        std::string Text;
        while(!File.eof()) {
            std::getline(File, Line);
            Text += Line;
        }
        File.close();
        return Text;
    }
    std::vector<std::string> Read_File_Lines(std::string File_Name) {
        if(!Usable_File(File_Name)) { return std::vector<std::string>{""}; }
        std::ifstream File(File_Name);
        std::string Line;
        std::vector<std::string> Lines;
        while(!File.eof()) {
            std::getline(File, Line);
            Lines.push_back(Line);
        }
        File.close();
        return Lines;
    }
    int Write_File(std::string File_Name, std::string Output, bool Append = false) {
        if(!Usable_File(File_Name)) { return -1; }
        std::ofstream File;
        if(Append) {
            File.open(File_Name, std::ios::app);
        } else {
            File.open(File_Name);
        }
        File << Output;
        File.close();
        return 0;
    }
    double Size_Of_File_Double(std::string File_Name, int Size_Notation) {
        if(!Usable_File(File_Name)) { return -1; }
        std::ifstream File(File_Name, std::ios::binary | std::ios::ate);
        double Size = File.tellg();
        File.close();
        switch (Size_Notation) {
            case 0: return Size/8;
            case 1: return Size/1024;
            case 2: return Size/1024/1024;
            case 3: return Size/1024/1024/1024;
        }
    }
    int Size_Of_File_Int(std::string File_Name, int Size_Notation) {
        if(!Usable_File(File_Name)) { return -1; }
        std::ifstream File(File_Name, std::ios::binary | std::ios::ate);
        int Size = File.tellg();
        File.close();
        switch (Size_Notation) {
            case 0: return Size/8;
            case 1: return Size/1024;
            case 2: return Size/1024/1024;
            case 3: return Size/1024/1024/1024;
        }
    }
    std::string Head_File(std::string File_Name, int Count) {
        if(!Usable_File(File_Name)) { return ""; }
        std::ofstream File(File_Name);
        int Index = 0;
        while(Index != Count) {
            
        }
    }
}