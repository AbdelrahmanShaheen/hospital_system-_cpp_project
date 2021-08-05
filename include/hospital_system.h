#include "patients.h"

struct hospital_system {
    hospital_queue specializations[MAX_SPECIALIZATION + 1];

    void add_patient();

    void print_patients();

    void get_next_patient();

    int menu();

    void run();
};
