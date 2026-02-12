#ifndef SORT_H
#define SORT_H

#include <vector>
#include <functional>
#include "worker.h"

void sort(std::vector <worker>& us);
void quick_sort(std::vector<worker>& us, int low, int high, std::function<bool(worker&, worker&)> comp);
int partitipion(std::vector<worker>& us, int low, int high, std::function<bool(worker&, worker&)>);
void shella_sort(std::vector <worker>& us, std::function<bool(worker& , worker&)>);
void bubble_sort(std::vector <worker>& us, std::function<bool(worker& , worker&)>);

#endif

