//
// Created by danila on 13.04.2021.
//

#ifndef INC_1C_TASK_COURSETABLE_H
#define INC_1C_TASK_COURSETABLE_H

#include <iostream>

#include <vector>

#include <unordered_map>

class CourseTable {
public:
    int dp_start(size_t course);

    int lazy_dfs(size_t key, std::vector<int>& dp, size_t level);

private:
    const int max_courses = 100000000;

    using Dependence = std::vector<size_t>;
    using Level = std::unordered_map<size_t, Dependence>;
    using Table = std::vector<Level>;

    size_t max_priority_;
    Table table_;
    std::unordered_map<size_t, std::string> names;
    std::unordered_map<size_t, size_t> levels;

    friend std::ifstream& operator>>(std::ifstream& stream, CourseTable& table);
};




#endif //INC_1C_TASK_COURSETABLE_H
