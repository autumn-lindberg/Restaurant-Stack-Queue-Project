#pragma once
#include "stack.h"
#include "queue.h"
#include "helpers/getters.h"
using namespace std;

bool loadGuests(Queue * guestList);
bool loadRecents(Stack * recentGuests);
char menu();
void executeOption(char option, Queue *& guestList, Stack *& recentGuests);
