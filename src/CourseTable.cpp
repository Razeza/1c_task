//
// Created by danila on 13.04.2021.
//

#include "CourseTable.h"

#include <iostream>

#include <vector>

#include <unordered_map>


#include <string>

#include <stdio.h>

#include <string.h>

#include <sstream>


int CourseTable::dp_start(size_t course) {
    std::vector<int> dp(max_courses);

    for (auto &i: dp) {
        i = -1;
    }

    for (size_t i = 0; i < max_priority_ - 1; ++i) {
        for (auto&[key, value] : table_[i]) {
            if (table_[i].empty()) {
                dp[key] = 0;
            }
        }
    }

    return lazy_dfs(fifth_course, dp, max_priority_ - 1);
}

int CourseTable::lazy_dfs(size_t key, std::vector<int>& dp, size_t level) {
    if (dp[key] != -1){
        return dp[key] + 1;
    }

    int sum = 0;
    auto children = table_[level][key];
    for (auto& child : children)
    {
        sum += lazy_dfs(child, dp, levels[child]);
    }

    return sum + 1;
}

std::ifstream& operator>>(std::ifstream& stream, CourseTable& table)
{
    std::string cur_line;
    std::getline(stream, cur_line);
    sscanf(cur_line.c_str(), "%zd", &table.max_priority_);

    table.table_.resize(table.max_priority_);
    if (0 == table.max_priority_) {
        return stream;
    }


    size_t number_of_course = 0;

    auto str = new char[50];
    auto dependence = new char[50];
    for (size_t current_level = 0; current_level < table.max_priority_; current_level++) {
        std::getline(stream, cur_line);

        int read_bytes = 0;
        int bytes = 0;
        while (sscanf(cur_line.c_str() + read_bytes, " (%zd) %[^[] [%[^]]],%n", &number_of_course, str, dependence, &bytes) == 3) {
            table.names[number_of_course] = std::string(str);
            table.levels[number_of_course] = current_level;
            read_bytes += bytes;


            size_t read_dependence = 0;
            size_t bytes_to_add = 0;
            while (sscanf(dependence + bytes_to_add, "%zd,%n", &read_dependence, &bytes) == 1) {
                bytes_to_add += bytes;
                table.table_[current_level][number_of_course].push_back(read_dependence);
            }
        }
    }

    delete[] str;
    delete[] dependence;
    return stream;
}



