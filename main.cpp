#include <iostream>
#include <unistd.h>
#include <getopt.h>

using namespace std;

void helpPlease();
void programVersion();
void listOfNumbers(char *arg);
void deleteSomething(char *arg);
void countSomething();
void addSomething();

int main(int argc, char *argv[]) {
    int rez = -1;
    int option_index;
    const char* short_options = "hvcal:d::";
    const struct option long_options[] = {
            {"help",    no_argument, nullptr, 'h'},
            {"version", no_argument, nullptr, 'v'},
            {"list",  required_argument, nullptr, 'l'},
            {"delete",     optional_argument, nullptr, 'd'},
            {"count",   no_argument, nullptr, 'c'},
            {"add", no_argument, nullptr, 'a'},
            {nullptr, 0, nullptr, 0}
    };
    int h_counter = 1;
    int v_counter = 1;
    int l_counter = 1;
    int d_counter = 1;
    int c_counter = 1;
    int a_counter = 1;



    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index))  != -1) {

        switch(rez){
            case 'h': {
                if (h_counter < 1){
                    goto exitH;
                }
                h_counter--;
                helpPlease();
                exitH: break;
            }

            case 'v':
                if (v_counter < 1){
                    goto exitV;
                }
                v_counter--;
                programVersion();
                exitV: break;

            case 'l':
                if (l_counter < 1){
                    goto exitL;
                }
                l_counter--;
                listOfNumbers(optarg);
                exitL: break;

            case 'd':                
                if (d_counter < 1){
                    goto exitD;
                }
                d_counter--;
                deleteSomething(optarg);
                exitD: break;

            case 'c':
                if (c_counter < 1){
                    goto exitC;
                }
                c_counter--;
                countSomething();
                exitC: break;

            case 'a':
                if (a_counter < 1){
                    goto exitA;
                }
                a_counter--;
                addSomething();
                exitA: break;           

            case '?': default: {
                printf("Unknown option\n");
                break;
            }
        }
    }
}

void helpPlease()
{
    std::cout << " --help (-h) successfully was used." << std::endl;
}

void programVersion()
{
    std::cout << " --version (-v) successfully was used." << std::endl;
}

void listOfNumbers(char *arg)
{
    std::cout << " --list (-l) with value " << arg << " successfully was used." << std::endl;
}

void deleteSomething(char *arg)
{
    if(arg == nullptr)
    {
        std::cout << " --delete (-d) with no optional value was used." << std::endl;
    }
    else
    {
        std::cout << " --delete (-d) with optional value " << arg << " successfully was used." << std::endl;
    }
}

void countSomething()
{
    std::cout << " --count successfully (-c) was used." << std::endl;
}

void addSomething()
{
    std::cout << " --add successfully (-a) was used." << std::endl;
}