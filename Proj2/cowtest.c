#include "types.h"
#include "user.h"

int global_array[2048] = {0};
int global_var = 0;

void testcase4(){
    int pid;

    printf(1,"\n----- Test case 4 -----\n");
    printf(1,"[prnt] - before fork - ");
    print_free_frame_cnt();

    if((pid = fork()) == 0)
    {
        //child
        sleep(50);
        printf(1,"[chld] - ");
        print_free_frame_cnt();
        
        global_array[0] = 222;
        global_array[2047] = 333;           
        printf(1,"[chld] - modified two elements in the 1st and the 2nd page - global_array[0] = %d - free frames should furhter decrease by 1 - ", global_array[0]);
        print_free_frame_cnt();
        
        exit();
    }
    else 
    {
        //parent
        printf(1,"[prnt] - ");
        print_free_frame_cnt();
        
        global_array[0] = 111;     
        printf(1,"[prnt] - modified one element in the 1st page - global_array[0 = %d - free frames should decrease by 1 - ", global_array[0]);
        print_free_frame_cnt();
    }

    if (wait() != pid)
    {
        printf(1,"wait() error!");
        exit();
    }    

    printf(1, "[prnt] - after wait - free frames change to orignial number - ");
    print_free_frame_cnt();
}

void testcase3(){
    int pid;

    printf(1,"\n----- Test case 3 -----\n");
    printf(1,"[prnt] - before fork - ");
    print_free_frame_cnt();

    if((pid = fork()) == 0)
    {
        //child
        sleep(50);
        printf(1,"[chld] - ");
        print_free_frame_cnt();
        
        global_var = 100;
        printf(1,"[chld] - acess global_v1 and modify - global_var = %d - free frames should decrease by 1 ", global_var);
        print_free_frame_cnt();
        
        exit();
    }
    else 
    {
        //parent
        printf(1,"[prnt] - ");
        print_free_frame_cnt();
        
        printf(1,"[prnt] - acess global_v1 without modify - global_var = %d - free frames should remain unchanged - ", global_var);
        print_free_frame_cnt();
    }
    
    if (wait() != pid)
    {
        printf(1,"wait() error!");
        exit();
    }    

    printf(1, "[prnt] - after wait - free frames change to orignial number - ");
    print_free_frame_cnt();
}

void testcase2(){
    int pid;
    
    printf(1,"\n----- Test case 2 -----\n");
    printf(1,"[prnt] - before fork - ");
    print_free_frame_cnt();

    if((pid = fork()) == 0)
    {
        //child
        sleep(50);
        printf(1,"[chld] - ");
        print_free_frame_cnt();
        
        printf(1,"[chld] - acess global_v1 without modify - global_var = %d - free frames should remain unchanged - ", global_var);
        print_free_frame_cnt();
        
        exit();
    }
    else 
    {
        //parent
        printf(1,"[prnt] - ");
        print_free_frame_cnt();
    }
    
    if (wait() != pid)
    {
        printf(1,"wait() error!");
        exit();
    }    

    printf(1, "[prnt] - after wait - free frames change to orignial number - ");
    print_free_frame_cnt();
}

void testcase1(){
    int pid;

    printf(1,"\n----- Test case 1 -----\n");
    printf(1,"[prnt] - before fork - ");
    print_free_frame_cnt();
    
    if((pid = fork()) == 0)
    {
        //child
        sleep(50);        
        printf(1, "[chld] - frames consumed when COW enbled should be less than when COW is disabled - ");
        print_free_frame_cnt();
        exit();
    }
    else 
    {
        //parent
        printf(1, "[prnt] - frames consumed when COW enabled should be less than when COW is disabled - ");
        print_free_frame_cnt();
    }
    
    if (wait() != pid)
    {
        printf(1, "wait() error!");
        exit();
    }
    
    printf(1, "[prnt] - after wait - free frames change to orignial number - ");
    print_free_frame_cnt();
}

int main(){
    testcase1();
    testcase2();
    testcase3();
    testcase4();
    exit();
}
