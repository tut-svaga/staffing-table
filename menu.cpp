#include "menu.h"
#include "sort_algos.h"
#include <iostream>
#include <fstream>

void enter_users(std::vector <worker>& us){
    std::string name;
    std::string surname;
    int hours_work;
    int hours_money;
    std::string job_title;
    std::cout << "Surname: ";
    std::cin >> surname;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Post: ";
    std::cin >> job_title;
    std::cout << "Hr. pay: ";
    std::cin >> hours_money;
    std::cout << "Hours: ";
    std::cin >> hours_work;
    worker work(name, surname, hours_work, hours_money, job_title);
    save_in_vector(us, work);
}

void save_in_vector(std::vector <worker>& us ,worker &work){
    us.emplace_back(std::move(work));
}

void choice(std::vector <worker>& us){
    int num_choice{};
    do{
    std::cout << "1. New worker\n2. Edit data\n3. Find worker\n4. Delete data\n5. Save to file\n6. Load from file\n7. Show all workers\n8. Sort data\n9. Quit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> num_choice;
    switch (num_choice)
    {
        case 1:
        enter_users(us);
            break;
        case 2:
        for(int i {0}; i < us.size(); i++)
        us[i].edit_data(us);
            break;
        case 3:
        find_worker(us);
            break;
        case 4:
        delete_us(us);
            break;
        case 5:
        us[0].enter_txt(us);
            break;
        case 6:
            print_file(us);
            break;
        case 7:
        us[0].show_classes(us);
            break;
        case 8:
            sort(us);
            break;
        default:
            break;
        }

    }while(num_choice != 9);
}

void print_file(std::vector <worker>& us){
    std::ifstream file("staffing table.txt");
    std::string surname, name, title;
    int salary, hours_work, money_hours;
    if(file.is_open()){
        while(file >> std::ws && std::getline(file, surname)){
            if(surname.empty()) continue;
            std::getline(file, name);
            std::getline(file, title);
            file >> hours_work;
            file.ignore(1000, '\n');
            file >> money_hours;
            file.ignore(1000, '\n');
            
            us.emplace_back(surname, name, hours_work , money_hours, title);
            std::cout << "Data Completed!" << std::endl;
        }
        file.close();
    }else{
        std::cerr << "YOA MANN ! ERROR!!" << std::endl;
    }
}

void delete_us(std::vector <worker>& us){
    std::string bla;
    int i;
    for(int j {0}; j < us.size(); j++)
    us[j].show_classes(us);
    std::cout << "Who will be removed? or (all): ";
    std::cin >> bla;
    if(bla == "all"){
        us.clear();
    }else if ((i = std::stoi(bla)) > us.size()){     
        std::cout << "WHAT ARE YOU DOING !!!" << std::endl;
    }else{
        int i = std::stoi(bla) - 1;
        us.erase(us.begin() + i);
    }
}

void find_worker(std::vector<worker>& us) {
    int choi;
    std::cout << "What attribute should I search by?\n1. name\n2. surname\n3. title job\n4. ID\n5. salary\nenter: ";
    std::cin >> choi;
    bool exam = false;
    switch (choi) {
        case 1: {
            std::string name;
            std::cout << "Enter name: ";
            std::cin >> name;
            for (int i = 0; i < us.size(); i++) {
                if (name == us[i].getName()) {
                    us[i].show_classes(us);
                    exam = true;
                }
            }
            break;
        }
        case 2: {
            std::string surname;
            std::cout << "Enter surname: ";
            std::cin >> surname;
            for (int i = 0; i < us.size(); i++) {
                if (surname == us[i].getSurname()) {
                    us[i].print_info();
                    exam = true;
                }
            }
            break;
        }
        case 3: {
            std::string title;
            std::cout << "Enter title: ";
            std::cin >> title;
            for (int i = 0; i < us.size(); i++) {
                if (title == us[i].getTitleJob()) {
                    us[i].print_info();
                    exam = true;
                }
            }
            break;
        }
        case 4: {
            int ID;
            std::cout << "Enter ID: ";
            std::cin >> ID;
            for (int i = 0; i < us.size(); i++) {
                if (ID == us[i].getID()){
                    us[i].print_info();
                    exam = true;
                }
            }
            break;
        }
        case 5: {
            int salary;
            std::cout << "Enter salary: ";
            std::cin >> salary;
            for (int i = 0; i < us.size(); i++) {
                if (salary == us[i].getsalary()) {
                    us[i].print_info();
                    exam = true;
                }
            }
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
            return;
    }
    if (!exam) {
        std::cout << "Not found" << std::endl;
    }
}
