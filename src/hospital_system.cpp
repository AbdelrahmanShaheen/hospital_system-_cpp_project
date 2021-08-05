#include "..\include\hospital_system.h"

int hospital_system::menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "Enter your choice :\n";
        cout << "1) Add new patients\n";
        cout << "2) Print all patients\n";
        cout << "3) Get new patient\n";
        cout << "4) Exit\n";
        cin >> choice;
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Try again):\n\n";
            choice = -1;
        }
    }
    return choice;
}

void hospital_system::run() {
    while (true) {
        int choice = menu();
        if (choice == 1) {
            add_patient();
        } else if (choice == 2) {
            print_patients();
        } else if (choice == 3) {
            get_next_patient();
        }
        if (choice == 4)
            break;
    }
}

void hospital_system::add_patient() {
    int spec, status;
    string name;
    cout << "Enter specialization ,name ,status :";
    cin >> spec >> name >> status;
    while (spec < 1 || spec > MAX_SPECIALIZATION) {
        cout << "Specializations from [1 --> 20] please choose one from them \n";
        cout << "Enter specialization again : ";
        cin >> spec;
    }

    if (specializations[spec].queue.size() >= MAX_QUEUE) {
        cout << "sorry we cant add more patients for this specialization" << endl;
    } else {
        if (status == 0) {
            specializations[spec].queue.push_back({name, status});
        } else {
            specializations[spec].queue.push_front({name, status});
        }
    }
}

void hospital_system::print_patients() {
    for (int spec = 1; spec <= MAX_SPECIALIZATION; spec++) {
        if (specializations[spec].queue.size()) {
            cout << "there are " << specializations[spec].queue.size() << " patients in specialization " << spec
                 << endl;
            for (int patient = 0; patient < specializations[spec].queue.size(); patient++) {
                cout << specializations[spec].queue[patient].first << " ";
                if (specializations[spec].queue[patient].second == 0) {
                    cout << "regular\n";
                } else {
                    cout << "urgent\n";
                }
            }
        }
    }
}

void hospital_system::get_next_patient() {
    int spec;
    cout << "Enter specialization :";
    cin >> spec;
    if (specializations[spec].queue.size()) {
        cout << specializations[spec].queue.front().first << " please go with the Dr\n";
        specializations[spec].queue.pop_front();
    } else {
        cout << "No patients at the moment. Have rest, Dr\n";
    }
}