#include "worker.h"

worker::worker(std::string& n, std::string& s, int& h_w,int& m, std::string &j_t)
    : name(n), surname(s), hours_work(h_w), job_title(j_t), hours_money(m){
    salary = hours_work * hours_money;
    count++;
    std::cout << "Worker add" << std::endl;
}

void worker::enter_txt(std::vector <worker>& us){
    show_classes(us);
    std::string choice_file;
    std::cout << "Enter ID which need save in file or write (all): ";
    std::cin >> choice_file;
    std::ofstream file("staffing table.txt");
    if(choice_file == "all"){
            if(file.is_open()){
                for(int i {0} ; i < us.size(); i++){
                    file << us[i].surname << '\n' << us[i].name << '\n' << us[i].job_title << '\n' << us[i].hours_work << '\n' << us[i].hours_money << '\n' << us[i].salary << std::endl;
                }
                file.close();
            }else{
            std::cerr << "ERROR ZAPISI!" << std::endl;
            }
    }else{
        int i = std::stoi(choice_file) - 1;
        if(file.is_open()){
            file << us[i].surname << '\n' << us[i].name << '\n' << us[i].job_title << '\n' << us[i].hours_work << '\n' << us[i].hours_money << '\n' << us[i].salary << std::endl;
            file.close();
        }else{
            std::cerr << "ERROR ZAPISI!" << std::endl;
        }
    }
}

void worker::show_classes(std::vector <worker>& us){
    for(int i {0}; i < us.size(); i++){
        std::cout << us[i].ID << '\t' << us[i].surname << '\t' << us[i].name << '\t' << us[i].job_title 
        << '\t' << us[i].hours_money << '\t' << us[i].hours_work << '\t' << us[i].salary << std::endl;
    }
    std::cout << std::endl;
}

void worker::edit_data(std::vector <worker>& us){
    show_classes(us);
    int edit;
    char eduard;
    std::cout << "Which ID str edit:";
    std::cin >> edit;
    edit--;

    std::cout << us[edit].name << "\tEdit? (y/n): ";
    std::cin >> eduard;
    if(eduard == 'y'){std::cout << "enter: ";
    std::cin >> us[edit].name;
    }
    std::cout << us[edit].surname << "\tEdit? (y/n): ";
    std::cin >> eduard;
    if(eduard == 'y'){std::cout << "enter: ";
    std::cin >> us[edit].surname;
    }
    std::cout << us[edit].job_title << "\tEdit? (y/n): ";
    std::cin >> eduard;
    if(eduard == 'y'){std::cout << "enter: ";
    std::cin >> us[edit].job_title;
    }
    std::cout << us[edit].hours_money << "\tEdit? (y/n): ";
    std::cin >> eduard;
    if(eduard == 'y'){std::cout << "enter: ";
    std::cin >> us[edit].hours_money;
    us[edit].salary = us[edit].hours_money * us[edit].hours_work;
    }
    std::cout << us[edit].hours_work << "\tEdit? (y/n): ";
    std::cin >> eduard;
    if(eduard == 'y'){std::cout << "enter: ";
    std::cin >> us[edit].hours_work;
    us[edit].salary = us[edit].hours_money * us[edit].hours_work;
    }
}

void worker::print_info(){
    std::cout << ID << '\t' << surname << '\t' << name << '\t' << job_title << '\t' << hours_money << '\t'  << hours_work << '\t' << salary << std::endl;
}

std::string worker::getName() const {return name;}
std::string worker::getSurname() const {return surname;}
std::string worker::getTitleJob() const {return job_title;}
int worker::getID() const {return ID;}
int worker::getsalary() const {return salary;}
