#include <iostream>
#include <chrono>

#include "PCN.cpp"

using namespace std;

void displayHelp()
{
    cout << "*****************************************\n";
    cout << "* COMMAND HELP: \n";
    cout << "* r: resetting counters\n";
    cout << "* p: get passenger count\n";
    cout << "* c: toggle display color\n";
    cout << "* C: toggle display calibration\n";
    cout << "* b: toggle display background subtraction view\n";
    cout << "* d: toggle display denoised view\n";
    cout << "* q: exit program\n";
    cout << "* h: display this help message\n";
    cout << "*****************************************\n";

    return;
}

int main(int argc, char * argv[])
{
    bool stop = false;
    bool displayHelpFlag = false;
    char choice;

    vector<PCN *> counters;
    int deviceNumber = 1;

    for(int i = 0; i < deviceNumber; i++) {
        counters.push_back(new PCN(i));
        cout << endl; 
        cout << "Device number: " << i << endl;
    }

    if(argc >= 2)
    {
        if(!strcmp(argv[1], "-s")) {
            for(int i = 0; i < deviceNumber; i++) {
                counters[i]->setSaveVideo(true);
            }
        }
    }

    for(int i = 0; i < deviceNumber; i++) {
        counters[i]->start();
    }

    displayHelp();

    do
    {
        cout << "Please enter a valid command:\n>";
        choice = getchar();
        cout << "You entered: " << choice << endl;

        for(int i = 0; i < deviceNumber; i++) {
            
            cout << "Device : " << i << endl;
            switch(choice)
            {
                case('p'):
                    cout << "Current count:\n";
                    cout << "Count in  = " << counters[i]->getCountIn() << endl;
                    cout << "Count out = " << counters[i]->getCountOut() << endl;
                    cout << "Current balance =" << counters[i]->getCountIn() - counters[i]->getCountOut() << endl;
                    break;

                case('r'):
                    cout << "Resetting counters\n";
                    counters[i]->resetCounters();
                    break;

                case('c'):
                    cout << "Toggle color\n";
                    counters[i]->toggleDisplayColor();
                    break;
                
                case('C'):
                    cout << "Toggle calibration\n";
                    counters[i]->toggleCalibration();
                    break;

                case('b'):
                    cout << "Toggle background subtraction view\n";
                    counters[i]->toggleDisplayBacksub();
                    break;

                case('d'):
                    cout << "Toggle denoise view\n";
                    counters[i]->toggleDisplayDenoise();
                    break;
                
                case('q'):
                    cout << "Exiting program!\n";
                    counters[i]->stop();
                    cout << "Capture closed.\n";
                    stop = true;
                    break;

                default:
                    displayHelpFlag = true;
                    break;
            }
        }

        if(displayHelpFlag) {
            displayHelp();
            displayHelpFlag = false;
        }

        // Consume input
        while ((choice = getchar()) != '\n' && choice != EOF);

    } while(!stop);

    return 0;
}
