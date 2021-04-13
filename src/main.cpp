#include <iostream>

#include <fstream>

#include "CourseTable.cpp"


int main (const int argc, const char** argv) {
    if (argc != 6) {
        std::cout << "На вход должно даваться 4 аргумента\n";
    }

    std::ifstream file_read;
    file_read.open(/*argv[1]*/"/home/danila/CLionProjects/1C/course.csv");

    CourseTable table;

    file_read >> table;

    std::cout << table.dp_start(std::stoi(argv[2])) + table.dp_start(std::stoi(argv[3])) + table.dp_start(std::stoi(argv[4])) + table.dp_start(std::stoi(argv[5])) << "\n";
}
