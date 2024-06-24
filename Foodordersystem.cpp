#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Details {
    char uname[100];
    int age;
    char password[100];
    char email[100];
    char mobile[10];
};

struct Hotels {
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[25];
    int first, second, third, fourth;
};

Hotels m[5];
Details s[100];

void signup();
void account_check();
int validate();
void login();
void cart();
void search_by_hotels();
void search_by_food();
void food_order(int food);
void hotel_initialize();
void hotels(int hotel_choice);

int flag = 1, i, j = 0, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x, choice;
char temp_name[100], temp_password1[100];
char temp_password2[100], temp_email[100];
char temp_mobile[100];
int temp_age, total = 0, food_choice, n;
int hotel_choice, search_choice, confirm;
int ch, food, hotel_id;

int main() {
    while (1) {
        cout << "\n\n********************Welcome to Food Ordering System****************\n";
        cout << "\n1) SIGNUP\n";
        cout << "2) LOGIN\n3) EXIT\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "\n**********************Thank you visit again*******************\n";
                exit(0);
                return 0;
            default:
                cout << "\nPlease enter a valid choice.\n";
                break;
        }
    }
}

void signup() {
    cout << "\n\n************Welcome to signup page*************\n";
    cout << "\tEnter Your name: ";
    cin >> temp_name;

    cout << "\tEnter Your Age: ";
    cin >> temp_age;

    cout << "\tEnter Your Email: ";
    cin >> temp_email;

    cout << "\tEnter Password: ";
    cin >> temp_password1;

    cout << "\tConfirm Password: ";
    cin >> temp_password2;

    cout << "Enter Your Mobile Number: ";
    cin >> temp_mobile;

    x = validate();
    if (x == 1) {
        account_check();
        login();
    }
}


int validate() {
    // Validate the name
    for (i = 0; temp_name[i] != '\0'; i++) {
        if (!isalpha(temp_name[i])) {
            cout << "\nPlease Enter a valid Name\n";
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        count = 0;
        // Validate the Email ID
        for (i = 0; temp_email[i] != '\0'; i++) {
            if (temp_email[i] == '@' || temp_email[i] == '.')
                count++;
        }

        if (count >= 2 && strlen(temp_email) >= 5) {
            // Validating the Password and
            // Check whether it matches with Confirm Password
            if (strcmp(temp_password1, temp_password2) == 0) {
                if (strlen(temp_password1) >= 8 && strlen(temp_password1) <= 12) {
                    caps = 0;
                    small = 0;
                    numbers = 0;
                    special = 0;
                    for (i = 0; temp_password1[i] != '\0'; i++) {
                        if (isupper(temp_password1[i]))
                            caps++;
                        else if (islower(temp_password1[i]))
                            small++;
                        else if (isdigit(temp_password1[i]))
                            numbers++;
                        else if (temp_password1[i] == '@' || temp_password1[i] == '&' || temp_password1[i] == '#' || temp_password1[i] == '*')
                            special++;
                    }

                    if (caps >= 1 && small >= 1 && numbers >= 1 && special >= 1) {
                        // Validating the Input age
                        if (temp_age > 0) {
                            // Validating the Input mobile number
                            if (strlen(temp_mobile) == 10) {
                                for (i = 0; i < 10; i++) {
                                    if (!isdigit(temp_mobile[i])) {
                                        cout << "\nPlease Enter a valid mobile number\n";
                                        return 0;
                                    }
                                }
                                success = 1;
                            } else {
                                cout << "\nPlease Enter a 10-digit mobile number\n";
                                return 0;
                            }
                        } else {
                            cout << "\nPlease Enter a valid age\n";
                            return 0;
                        }
                    } else {
                        cout << "\nPlease Enter a strong password. Your password must contain at least one uppercase, lowercase, number, and special character\n";
                        return 0;
                    }
                } else {
                    cout << "\nYour Password is very short. Length must be between 8 to 12 characters\n";
                    return 0;
                }
            } else {
                cout << "\nPassword Mismatch\n";
                return 0;
            }
        } else {
            cout << "\nPlease Enter a valid E-Mail\n";
            return 0;
        }
    }
    return 1;
}

void account_check() {
    for (i = 0; i < 100; i++) {
        if (!(strcmp(temp_email, s[i].email) && strcmp(temp_password1, s[i].password))) {
            cout << "\n\nAccount Already Existed. Please Login !!\n\n";
            main();
            break;
        }
    }
    if (i == 100) {
        strcpy(s[j].uname, temp_name);
        s[j].age = temp_age;
        strcpy(s[j].password, temp_password1);
        strcpy(s[j].email, temp_email);
        strcpy(s[j].mobile, temp_mobile);
        j++;
        cout << "\n\n\nAccount Successfully Created!!\n\n";
    }
}

void login() {
    cout << "\n\n**************Welcome to Login page ****************\n\n";
    cout << "\tEnter Your Email: ";
    cin >> temp_email;
    cout << "\tEnter Your Password: ";
    cin >> temp_password1;
    for (i = 0; i < 100; i++) {
        if (!strcmp(s[i].email, temp_email)) {
            if (!strcmp(s[i].password, temp_password1)) {
                cout << "\n\nWelcome " << s[i].uname << ", ";
                cout << "You are successfully logged in\n\n ";
                cout << "We Provide two ways of search\n ";
                cout << "1) Search By Hotels\n ";
                cout << "2) Search by Food\n ";
                cout << "3)Exit\n\n";
                cout << "Please Enter your choice: ";
                cin >> search_choice;
                switch (search_choice) {
                    case 1:
                        search_by_hotels();
                        break;
                    case 2:
                        search_by_food();
                        break;
                    case 3:
                        main();
                        return;
                    default:
                        cout << "Please Enter the valid choice\n\n ";
                        break;
                }
                break;
            } else {
                cout << "\n\nInvalid Password! Please Enter the correct password\n\n";
                main();
                break;
            }
        } else {
            cout << "\n\nAccount doesn't exist, Please signup!!\n\n ";
            main();
            break;
        }
    }
}

void hotel_initialize() {
    strcpy(m[1].hotel, "KHANA'S ");
    strcpy(m[1].first_food, "Sandwich");
    strcpy(m[1].second_food, "Pizza");
    strcpy(m[1].third_food, "Fried_Rice");
    strcpy(m[1].fourth_food, "Ice_Cream");
    m[1].first = 70;
    m[1].second = 100;
    m[1].third = 95;
    m[1].fourth = 50;

    strcpy(m[2].hotel, "HAZI NANNA ");
    strcpy(m[2].first_food, "Parotta");
    strcpy(m[2].second_food, "Noodles");
    strcpy(m[2].third_food, "Chicken_Rice");
    strcpy(m[2].fourth_food, "Dosa");
    m[2].first = 15;
    m[2].second = 75;
    m[2].third = 80;
    m[2].fourth = 50;

    strcpy(m[3].hotel, "ALTUR TONG");
    strcpy(m[3].first_food, "Chicken_Biriyani");
    strcpy(m[3].second_food, "Prawn");
    strcpy(m[3].third_food, "Falooda");
    strcpy(m[3].fourth_food, "burger");
    m[3].first = 90;
    m[3].second = 120;
    m[3].third = 35;
    m[3].fourth = 50;
}

void search_by_hotels() {
    hotel_initialize();
    cout << "\n\nPlease Choose the hotels\n\n1) " << m[1].hotel
         << "\n2) " << m[2].hotel << "\n3) " << m[3].hotel
         << "\n4) Exit\n\nPlease select the hotel\t";
    cin >> hotel_choice;
    if (hotel_choice > 4) {
        cout << "Please Enter the valid choice\n\n";
        search_by_hotels();
    } else if (hotel_choice == 4) {
        return;
    } else {
        hotels(hotel_choice);
    }
}

void hotels(int hotel_choice) {
    total = 0;
    while (true) {
        cout << "\n\nList of foods available in " << m[hotel_choice].hotel
             << "\n\n1) " << m[hotel_choice].first_food << "\tRs: " << m[hotel_choice].first
             << "\n2) " << m[hotel_choice].second_food << "\tRs: " << m[hotel_choice].second
             << "\n3) " << m[hotel_choice].third_food << "\tRs: " << m[hotel_choice].third
             << "\n4) Cart\n5) Exit\n\nPlease Enter Your Choice\t";
        cin >> food_choice;
        if (food_choice == 1) {
            cout << "Please Enter the Count of " << m[hotel_choice].first_food << "\t";
            cin >> n;
            total += (n * m[hotel_choice].first);
        } else if (food_choice == 2) {
            cout << "Please Enter the Count of " << m[hotel_choice].second_food << "\t";
            cin >> n;
            total += (n * m[hotel_choice].second);
        } else if (food_choice == 3) {
            cout << "Please Enter the Count of " << m[hotel_choice].third_food << "\t";
            cin >> n;
            total += (n * m[hotel_choice].third);
        } else if (food_choice == 4) {
            cart();
        } else if (food_choice == 5) {
            search_by_hotels();
        } else {
            cout << "Please Enter the valid Choice\n\n";
        }
    }
}

void search_by_food() {
    total = 0;
    hotel_initialize();
    while (true) {
        cout << "\n\nPlease choose the food\n\n1) " << m[1].first_food << "\t" << m[1].first
             << "\n2) " << m[1].second_food << "\t" << m[1].second
             << "\n3) " << m[1].third_food << "\t" << m[1].third
             << "\n4) " << m[2].first_food << "\t" << m[2].first
             << "\n5) " << m[2].second_food << "\t" << m[2].second
             << "\n6) " << m[2].third_food << "\t" << m[2].third
             << "\n7) " << m[3].first_food << "\t" << m[3].first
             << "\n8) " << m[3].second_food << "\t" << m[3].second
             << "\n9) " << m[3].third_food << "\t" << m[3].third
             << "\n10) Cart\n11) Exit"
             << "\nPlease Enter Your Choice\t";
        cin >> food;
        if (food > 10) {
            cout << "Please Enter the valid choice\n\n";
            search_by_food();
        } else if (food == 10) {
            cart();
        } else if (food == 11) {
            return;
        } else {
            food_order(food);
        }
    }
}


void food_order(int food) {
    if (food >= 1 && food <= 3)
        hotel_id = 1;
    else if (food >= 4 && food <= 6)
        hotel_id = 2;
    else
        hotel_id = 3;

    if ((food % 3) == 1) {
        cout << "Please Enter the Count of " << m[hotel_id].first_food << "\t";
        cin >> n;
        total += (n * m[hotel_id].first);
    } else if ((food % 3) == 2) {
        cout << "Please Enter the Count of " << m[hotel_id].second_food << "\t";
        cin >> n;
        total += (n * m[hotel_id].second);
    } else if ((food % 3) == 0) {
        cout << "Please Enter the Count of " << m[hotel_id].third_food << "\t";
        cin >> n;
        total += (n * m[hotel_id].third);
    }
}

void cart() {
    cout << "\n\n\n\n*************Cart***************"
         << "\nYour Total Order Amount is: " << total
         << "\n\nDo You wish to order (y=1/n=0): ";
    cin >> ch;
    if (ch == 1) {
        cout << "\n\nThank You for your order!! Your Food is on the way. Welcome again!!\n\n";
        return;
    } else if (ch == 0) {
        cout << "Do You want to exit =-1 or Go back =0";
        cin >> confirm;
        if (confirm == 1) {
            cout << "\n\nOops! Your order is cancelled!! Exiting.. Thank You visit again!\n";
            return;
        } else {
            cout << "\n\nThank You\n\n";
            login();
        }
    } else {
        cout << "\n\nPlease Enter the correct choice\n\n";
        cart();
    }
}
