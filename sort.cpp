#include "sort.h"
#include <iostream>

void sort(std::vector <worker>& us){
    int choice_algo;
    std::cout << "Enter algorithm:\n1. Sort Quick\n2. Shella\n3. Bubble sort\nenter: ";
    std::cin >> choice_algo;
    int attr;
    std::cout << "What to sort?\n1. ID\n2. Name\n3. Surname\n4. Title job\n5. Salary\nEnter: ";
    std::cin >> attr;
    int order;
    std::cout << "Order:\n1. Ascending (A-Z, 0-9)\n2. Descending (Z-A, 9-0)\nenter: ";
    std::cin >> order;

    std::function<bool(worker&, worker&)> comp;

    switch (attr)
    {
    case 1:
        comp = (order == 1) ? [](worker& a, worker& b) {return a.getID() < b.getID();}
        : [](worker& a, worker& b) {return a.getID() > b.getID();};
        break;
    case 2:
        comp = (order == 1) ? [](worker& a, worker& b) {return a.getName() < b.getName();}
        : [](worker& a, worker& b) {return a.getName() > b.getName();}; 
        break;
    case 3:
        comp = (order == 1) ? [](worker& a, worker& b) {return a.getSurname() < b.getSurname();}
        : [](worker& a, worker& b) {return a.getSurname() > b.getSurname();};
        break;
    case 4:
        comp = (order == 1) ? [](worker& a, worker& b) {return a.getTitleJob() < b.getTitleJob();}
        : [](worker& a, worker& b) {return a.getTitleJob() > b.getTitleJob();};
        break;
    case 5:
        comp = (order == 1) ? [](worker& a, worker& b) {return a.getsalary() < b.getsalary();}
        : [](worker& a, worker& b) {return a.getsalary() > b.getsalary();};
        break;
    default:
        break;
    }

    if(choice_algo == 1){
        quick_sort(us, 0, us.size() - 1, comp);
    }else if(choice_algo == 2){
        shella_sort(us, comp);
    }else if(choice_algo == 3){
        bubble_sort(us, comp);
    }else{
        std::cout << "Error!" << std::endl;
    }
}

void quick_sort(std::vector<worker>& us, int low, int high, std::function<bool(worker&, worker&)> comp){
    if(low < high){
        int pi = partitipion(us, low, high, comp);
        quick_sort(us, low, pi - 1, comp);
        quick_sort(us, pi + 1, high, comp);
    }
}

int partitipion(std::vector<worker>& us, int low, int high, std::function<bool(worker&, worker&)> comp){
    int pivot_index = high;
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(comp(us[j], us[high])){
            i++;
            std::swap(us[i], us[j]);
        }
    }
    std::swap(us[i + 1], us[high]);
    return i + 1;
}

void shella_sort(std::vector <worker>& us, std::function<bool(worker& , worker&)> comp){
    int n = us.size();

    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            worker temp = std::move(us[i]);
            int j;
            for(j = i; j >= gap && comp(temp, us[j - gap]); j -= gap){
                us[j] = std::move(us[j - gap]);
            }
            us[j] = std::move(temp);
        }
    }
}

void bubble_sort(std::vector <worker>& us, std::function<bool(worker& , worker&)> comp){
    int n = us.size();

    for(int i {0}; i < n - 1; i++){
        for(int j {0}; j < n - i - 1; j++){
            if(comp(us[j + 1], us[j])){
                std::swap(us[j], us[j + 1]);
            }
        }
    }
}
