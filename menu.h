#ifndef MENU_H
#define MENU_H

#include <vector>
#include "worker.h"

void choice(std::vector <worker>& us);
void save_in_vector(std::vector<worker>& us, worker &work);
void enter_users(std::vector <worker> &);
void delete_us(std::vector <worker>& us);
void print_file(std::vector <worker>& us);
void find_worker(std::vector <worker>& us);

#endif
