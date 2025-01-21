void insert_data(){
    system("cls");
    char type[25], dest_code[4];
    int priority_level, travel_time;
    printf("\n\n");

    while(true){
        printf("\tEnter the Aircraft type [Cargo | Passenger]: ");
        scanf(" %[^\n]", &type);
        if(is_valid_type(type)) break;
        printf("\t\033[1;31mInvalid Aircraft type. Please try again.\033[0m\n");
    }
    getchar();

    while(true){
        printf("\tEnter the destination code ['LAX', 'CDG', JFK]: ");
        scanf(" %[^\n]", &dest_code);
        if(is_valid_destination_code(dest_code)) break;
        printf("\t\033[1;31mInvalid Destination Code. Please try again.\033[0m\n");
    }
    getchar();

    while(true){
        printf("\tEnter the priority level [1-3]: ");
        scanf("%d", &priority_level);
        if(is_valid_priority_level(priority_level)) break;
        printf("\t\033[1;31mInvalid Priority Level. Please try again.\033[0m\n");
    }
    getchar();

    while (true) {
        printf("\tEnter the travel time [number]: ");
        if (scanf("%d", &travel_time) == 1) {
            break;
        } else {
            printf("\\033[1;31mtInvalid input. Please enter a valid number.\033[0m\n");
            while (getchar() != '\n'); 
        }
    }
    getchar();

    //Confirmation
    while(true){
        char confirm;
        printf("\tAre You Sure? [Y/N]: ");
        scanf(" %c", &confirm);
        if(confirm == 'Y' || confirm == 'y'){
            insert_aircraft(create_data(type, dest_code, priority_level, travel_time));
            printf("\t\033[1;32mAircraft has been inserted.\033[0m\n");
            break;
        } else if(confirm == 'N' || confirm == 'n'){
            printf("\tInsertion has been cancelled.\n");
            break;
        } else {
            printf("\t\033[1;31mInvalid input. Please try again.\033[0m\n");
        }
    }

    printf("\n\tPress enter to continue...");
    getch();
}

void view_data(){
    system("cls");
    printf("\n\n");
    view_aircraft();
    printf("\n\tPress enter to continue...");
    getch();
}

void delete_data() {
    char id[6];
    while (true) {
        system("cls");
        printf("\n\n");
        view_aircraft();
        printf("\n\tEnter the Aircraft ID [0 to cancel]: ");
        scanf("%5s", id);
        getchar();

        if (strcmp(id, "0") == 0) {
            printf("\tExiting deletion process.\n");
            break;
        }

        if (strlen(id) != 5) {
            printf("\t\033[1;31mInvalid Aircraft ID. Please ensure it is 5 characters long.\033[0m\n");
            printf("\n\tPress enter to continue...");
            getch();
            continue;
        }

        if (is_valid_id(id)) {
            delete_aircraft(id);
            printf("\t\033[1;32mAircraft has been deleted.\033[0m\n");
            printf("\n\tPress enter to continue...");
            getch();
            break;
        } else {
            printf("\t\033[1;31mInvalid Aircraft ID. Please try again.\033[0m\n");
            printf("\n\tPress enter to continue...");
            getch();
        }
    }
}


void handle_option(int choice){
    switch(choice){
        case 1:
            insert_data();
            break;
        case 2:
            view_data();
            break;
        case 3:
            delete_data();
            break;
        default:
            break;
    }
}

void app_start(){
    int choice = -1;
    while(choice != 4){
        system("cls");
        printf("\n\n");

        main_menu();
        scanf("%d", &choice);
        handle_option(choice);
    }
}



