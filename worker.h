#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class worker{
    static inline int count {1};
private:
    std::ofstream file;
    std::string name;
    std::string surname;
    int hours_work;
    int hours_money;
    std::string job_title;
    int salary;
    int ID = count;
public:
    worker(std::string& n, std::string& s, int& h_w,int& m, std::string &j_t);

    void enter_txt(std::vector <worker> & us);
    void show_classes(std::vector <worker>& us);
    void edit_data(std::vector <worker>& us);
    void print_info();

    std::string getName() const;
    std::string getSurname() const;
    std::string getTitleJob() const;
    int getID() const;
    int getsalary() const;
};

#endif
