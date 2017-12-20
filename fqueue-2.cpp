/*
    constTest.cpp

    testing the const and non-const versions of Top
*/

#include "tqueue.h"


void menu(){
    std::cout << "____________Menu_____________\n";
    std::cout << "Select operation on queue: \n";
    std::cout << "1. Push\n2. Pop\n3. Front\n";
    std::cout << "4. Set OFC.\n";
    std::cout << "5. Display\n6. Clear Queue\n7. Quit\n";
}

int main() {
    fsu::Queue<char> q;

    q.Push('A');
//    std::cout << q.Size() << " " << q.Capacity() << '\n';

    q.Push('B');
    q.Push('C');
    q.Push('D');
//    std::cout << q.Size() << " " << q.Capacity() << '\n';
    std::cout << q;
    q.SetOFC(' ');
    q.Dump(std::cout);
    std::cout << q;
    q.Pop();
    q.Pop();
    std::cout << q;

    fsu::Queue<char> qq(q);
    fsu::Queue<char> qqq;
    qqq = q;
    std::cout << qq;
//    s.Pop();

    char option;
    char item;
    while(1){
        menu();
        while(!(std::cin >> option)){
            std::cout << "Bad input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (option) {
            case '1':
                std::cout << "Enter an item to push: ";
                while (!(std::cin >> item)) {
                    std::cout << "Bad input!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                q.Push(item);
                break;
            case '2':
                q.Pop();
                break;
            case '3':
                std::cout << "Top item: " << q.Front() << "\n";
                break;
            case '4':
//                std::cout << "\tPress \'o\'/\'O\' to set OFC.\n";
//                std::cout << "\tPress \'<\' to set direction bottom to top\n";
//                std::cout << "\tPress \'>\' to set direction top to bottom \n";
                char ofc;
                std::cout << "Choose any ofc argument: \n";
                std::cout << "\tkb input  -->  ofc argument      character name\n"
                        "\t--------       -----------       --------------\n"
                        "\t0                 '\\0'           null character\n"
                        "\tb                  ' '            blank\n"
                        "\tB                  ' '            blank\n"
                        "\tt                 '\\t'           tab\n"
                        "\tT                 '\\t'           tab\n"
                        "\tn                 '\\n'           newline\n"
                        "\tN                 '\\n'           newline\n";
                while (!(std::cin >> ofc)) {
                    std::cout << "Bad input!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                if (ofc == '0') ofc = '\0';
                else if (ofc == 'b' || ofc == 'B') ofc = ' ';
                else if (ofc == 't' || ofc == 'T') ofc = '\t';
                else if (ofc == 'n' || ofc == 'N') ofc = '\n';
                else {
                    std::cout << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
                    break;
                }
                q.SetOFC(ofc);
                break;
            case '5':
                std::cout << "\n" << q;
                break;

            case '6':
                q.Clear();
                break;
            case '7':
                std::cout << "Good bye!\n";
                return 0;
            default:
                std::cout << "Enter options from 1 to 5.\n";
        }
    }
    return 0;
}


