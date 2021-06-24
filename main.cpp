#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Client_Data
{
    int client_id = 0 ;
    string client_time;
    string client_name;


};

int clients_number = 0;  // global  variable

// Start Functions declaration
void system_process (int &clients_num, Client_Data* clients_data);

// End Function Declaration


// start sub func1:
//  role is to chack if the inserted id exist before or not
bool checking_the_existence_of_id(int check_id,int &clients_num, Client_Data* clients_data)
{
    for (int i = 0; i < 100; ++i)
    {
        if(check_id == clients_data[i].client_id && check_id <0)
        {
            return 1;
        }
    }
}
// End sub func1

//start sub func2:
// role is to count the number of clients in the system
void checking_no_of_clients(int &clients_num, Client_Data *clients_data)
{
    clients_num = 0;
    for (int i = 0; i < 100; i++)
    {
        if(clients_data[i].client_id > 0)
            clients_num++;
    }
}
//End sub func2:


// start  id sorting

// this function is to compare the id with each other
bool idCompare(Client_Data lhs, Client_Data rhs)
{
    return lhs.client_id > rhs.client_id;
}

// this function role is to sort the id
void sorting(Client_Data *clients_data)
{
    sort(clients_data, clients_data+100, idCompare);

}
// end id sorting

// start add_new_client function
// this functions role is to add clients to the system data
void add_new_client(int &clients_num, Client_Data* clients_data)
{
    sorting(clients_data);
    checking_no_of_clients(clients_num, clients_data);


    int added_id, repeat = 1; // added_id is used in the following if condition to test existince of the id

    cout << "\n\tPlease enter the id of the client who entered the cafe: ";
    cin>>  added_id;
    if(added_id <=0)
    {
        cout << "\n\tYou cant insert ID less than '1'\n";
       return add_new_client(clients_number, clients_data);

    }
    if(checking_the_existence_of_id(added_id,clients_num, clients_data)) // if the id is existing print error
    {
        cout << "\n\tError there is a client with this id \n";
    }

    else
    {
        clients_data[clients_num].client_id = added_id;
        cout << "\tPlease enter the time of the client who entered the cafe: ";
        cin >> clients_data[clients_num].client_time;
        cout << "\tPlease enter the name of the client who entered the cafe: ";
        cin >> clients_data[clients_num].client_name;
        cout << endl;
    }

    cout << "\n\tTo add other client, press 1 else to exit press 0.\n\tYour choose: ";
    cin >> repeat;

    if (repeat == 1)
    {
        return add_new_client(clients_number, clients_data); // using recursion function
    }
    else if (repeat == 0)
    {
        cout << endl;
        system_process(clients_number, clients_data);
    }

    // Dealing with the invalid input from the user if he did not enter 1 or 0
    while (repeat != 1 && repeat != 0)
    {
        cout << "\n\tInvalid input: Press '1' to add user or '0' to exit.\n\tYour choose: ";
        cin >> repeat;
        if (repeat == 1)
        {
            return add_new_client(clients_number, clients_data); // using recursion function
        }
        else if (repeat ==0)
        {
            system_process(clients_number, clients_data);
        }
    }



}
// End add_new_client function


// Start updateclient function
// This functions role is to update the client time and name
void update_client(int &clients_num, Client_Data* clients_data)
{

    int updated_id, repeat = 1;

    cout << "\n\tPlease enter the id of the client to update: ";
    cin >> updated_id;

    if(checking_the_existence_of_id(updated_id,clients_num, clients_data)) // if the id is existing print error
    {
        for (int i = 0; i < 100; i++)
        {
            if (updated_id == clients_data[i].client_id)
            {
                cout << "\tPlease enter the new time of the client: ";
                cin >> clients_data[i].client_time;
                cout << "\tPlease enter the new name of the client: ";
                cin >> clients_data[i].client_name;

            }
        }
    }

    else
    {
        cout << "\n\tError there is no client with this id \n";
    }

    // asking the user if he want to add another client
    cout << "\n\tTo update other client, press 1 else to exit press 0.\n\tYour choose: ";
    cin >> repeat;

    if (repeat == 1)
    {
        return update_client(clients_number, clients_data); // using recursion function
    }
    else if (repeat ==0)
    {
        cout << endl;
        system_process(clients_number, clients_data);
    }

    // Dealing with the invalid input from the user if he did not enter 1 or 0
    while (repeat != 1 && repeat != 0)
    {
        cout << "\n\tInvalid input: Press '1' to update a client or '0' to exit.\n\tYour choose: ";
        cin >> repeat;
        if (repeat == 1)
        {
            return update_client(clients_number, clients_data);
        }
        else if (repeat ==0)
        {
            system_process(clients_number, clients_data);
        }
    }
}
// End updateclient function


// Start deleteclien function
// This funcions role is to delete the client by changing it's ID to zero

void delete_client(int &clients_num, Client_Data* clients_data)
{

    int deleted_id;
    int repeat = 1;

    cout << "\n\tPlease enter the id of the client to delete: ";
    cin >> deleted_id;

    if(checking_the_existence_of_id(deleted_id,clients_num, clients_data))
    {
        for (int i = 0; i < 100; i++)
        {
            if (deleted_id == clients_data[i].client_id)
            {
                clients_data[i].client_id = 0;
                cout << "\tDeleted successfully";
                break;

            }
        }
    }
    else
    {
        cout << "\tError there is no client with this id";
    }

    // asking the user if he want to delete another client
    cout << "\n\tTo Delete other client, press 1 else to exit press 0.\n\tYour choose: ";
    cin >> repeat;

    if (repeat == 1)
    {
        return delete_client(clients_number, clients_data); // using recursion function
    }
    else if (repeat ==0)
    {
        cout << endl;
        system_process(clients_number, clients_data);
    }

// Dealing with the invalid input from the user if he did not enter 1 or 0
    while (repeat != 1 && repeat != 0)
    {
        cout << "\n\tInvalid input: Press '1' to add user or '0' to exit.\n\tYour choose: ";
        cin >> repeat;
        if (repeat == 1)
        {
            return delete_client(clients_number, clients_data);  // using recursion function
        }
        else if (repeat ==0)
        {
            system_process(clients_number, clients_data);
        }
    }

}
// End deleteclien function


// Start Show_all_client function
// This funcions role is to delete the client by changing it's ID to zero

void show_all_client(int &clients_num, Client_Data* clients_data)
{

    sorting(clients_data);
    checking_no_of_clients(clients_num, clients_data);

    int repeat;


    cout << "\n\t\tThe summary of clients visited the cafe today:\n" <<endl;
    for(int i =0; i < clients_num;)
    {
        if(clients_data[i].client_id!=0)
        {
            cout <<"\t"<< i+1 << ") At " << clients_data[i].client_time << " " << clients_data[i].client_name << " visited the cafe." << endl;
            i++;
        }
    }

    cout << "\n\tTo go back to home screen press '0': ";
    cin >> repeat;
    if (repeat == 0)
    {
        cout << endl;
        system_process(clients_number, clients_data);
    }
// Dealing with the invalid input from the user if he did not enter 1 or 0
    while (repeat != 1 && repeat != 0)
    {
        cout << "\n\tInvalid input: Press '0' to exit: ";
        cin >> repeat;

        if (repeat ==0)
        {
            system_process(clients_number, clients_data);
        }
    }
}
// End Show_all_client function





// Beginning of the Function
// This function deal with the selection of the user
int system_process_selection (int selection,int &clients_num, Client_Data* clients_data)
{
    while (selection != 1 && selection !=2 && selection != 3 && selection !=4&& selection !=5)
    {
        cout << "\n\tInvalid input, Please chose one from above choices: ";
        cin >> selection;
    }

    if (selection == 1)
    {
        cout << "\n\t\t\tWelcome user in: 'Adding New Clients Section'\n";
        add_new_client(clients_number, clients_data);
    }
    else if (selection == 2)
    {
        cout << "\n\t\t\tWelcome user in: 'updating clients section'\n";
        update_client(clients_number, clients_data);
    }
    else if (selection == 3)
    {
        cout << "\n\t\t\tWelcome user in: 'Deleting clients section'\n";
        delete_client(clients_number, clients_data);
    }
    else if (selection == 4)
    {
        cout << "\n\t\t\tWelcome user in: 'Showing all clients section'\n";
        show_all_client(clients_number, clients_data);
    }
    else if (selection == 5)
        return 0;

}
// The End of system_process_selection  Function






// Beginning of the Function
//  This function print to the user the process that he can do
void system_process (int &clients_num, Client_Data* clients_data)
{
    int select;

    cout << "\t \t Welcome to the management system for a cafe\n" << endl;
    cout << "\t1) Add new client." << endl;
    cout << "\t2) Update client." << endl;
    cout << "\t3) Delete client." << endl;
    cout << "\t4) Show all clients attended the cafe." << endl;
    cout << "\t5) Exit"<< endl<< endl;
    cout << "\tPlease chose one from above choices: ";
    cin >> select;

    system_process_selection(select, clients_number, clients_data);
}
// The End of system_process Function

int main()
{

    Client_Data *clients_data;
    clients_data =new Client_Data[100];



    system_process(clients_number, clients_data);

}
