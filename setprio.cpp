#include <unistd.h>
#include <sched.h>
#include <iostream>
#include <typeinfo>

using namespace std;


int main(int argc, char *argv [])
{
    //argv[1] will be policy, argv[2] will be priority
    
    //error checking on the arguement numbers and exit if bad
    if(argc != 3)
    {
        cout << "must provide policy, priority, and sleeptime" << endl;
        return 0;
    }

    sched_param param;
    pid_t processID = getpid();
    param.sched_priority = atoi(argv[2]);
    string policy = argv[1];
    int policynum;

    if(policy == "SCHED_OTHER")
    {
        policynum = SCHED_OTHER;
    }
    else if(policy == "SCHED_FIFO")
    {
        policynum = SCHED_FIFO;
    }
    else if(policy == "SCHED_RR")
    {
        policynum = SCHED_RR;
    }
    else if(policy == "SCHED_BATCH")
    {
        policynum = SCHED_BATCH;
    }
    else if(policy == "SCHED_ISO")
    {
        policynum = SCHED_ISO;
    }
    else if(policy == "SCHED_IDLE")
    {
        policynum = SCHED_IDLE;
    }
    else if(policy == "SCHED_DEADLINE")
    {
        policynum = SCHED_DEADLINE;
    }
    else if(policy == "SCHED_RESET_ON_FORK")
    {
        policynum = SCHED_RESET_ON_FORK;
    }
    else
    {
        cout << "Invalid scheduling policy" << endl;
    }
    

    //need to put error checking that the sched type and value are acceptable matches

    int success = sched_setscheduler(processID, policynum, &param);

    if(success != 0 )
    {
        cout << "error with setting scheduler" << endl;
        cout << success << " : " << errno << endl;

    }


    int success2 = execl("/usr/local/bin/python", "python", "/rtyolo/predict_api.py", "predict_api.py", "--device", "cpu",(char*)0);
    if(success2 == -1)
    {
       cout << "error with the execl : " << errno << endl;
    }

    return 0;

}
