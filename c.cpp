#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

class worker;

void choice(std::vector <worker>& us);
void save_in_vector(std::vector<worker>& us, worker &work);
void enter_users(std::vector <worker> &);
void delete_us(std::vector <worker>& us);
void print_file(std::vector <worker>& us);
void find_worker(std::vector <worker>& us);
void sort(std::vector <worker>& us);
void quick_sort(std::vector<worker>& us, int low, int high, std::function<bool(worker&, worker&)> comp);
int partitipion(std::vector<worker>& us, int low, int high, std::function<bool(worker&, worker&)>);
void shella_sort(std::vector <worker>& us, std::function<bool(worker& , worker&)>);
void bubble_sort(std::vector <worker>& us, std::function<bool(worker& , worker&)>);

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
    worker(std::string& n, std::string& s, int& h_w,int& m, std::string &j_t) : name(n) , surname(s) , hours_work(h_w), job_title(j_t), hours_money(m){
        salary = hours_work * hours_money;
        count++;
        std::cout << "Worker add" << std::endl;
    }
    void enter_txt(std::vector <worker> & us);
    void show_classes(std::vector <worker>& us);
    void edit_data(std::vector <worker>& us);
    void print_info(){
        std::cout << ID << '\t' << surname << '\t' << name << '\t' << job_title << '\t' << hours_money << '\t'  << hours_work << '\t' << salary << std::endl;
    }

    std::string getName() const {return name;}
    std::string getSurname() const {return surname;}
    std::string getTitleJob() const {return job_title;}
    int getID() const {return ID;}
    int getsalary() const {return salary;}
};
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

int main(){
    system("cls");
    std::vector <worker> us;
    choice(us);
    return 0;
}
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