#include <iostream>
#include "renderEngine/DisplayManager.h"

int main(){
    std::cout<<"Hello world\n";

    DisplayManager dm;
    dm.create_display();

    while(!glfwWindowShouldClose(dm.window)){
        dm.update_display();        
    }

    dm.clost_display();
    return 0;
}