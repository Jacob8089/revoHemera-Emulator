#include<iostream>
#include<thread>
#include<stdlib.h>
#include<windows.h>

using namespace std;

double w,d,t,h,feed_rate, ext_rate = 0.0000;//width depth time filament-size build speed
double b = 391;
double s = 1.75;
bool flag = true;
int digital_bit = 0;

double processTime() {
    t = (w / b) * (d / s) * (h / s); //build time calculator
    return t;
}

int task(bool status) {
    while (status==true) {
        if (feed_rate <= t)
        {
            Sleep(2000);
            digital_bit = 1;
            status = true;
            cout << "Signal:[EN]-" << digital_bit << " ";
        }
        else {
            digital_bit = 0;
            Sleep(2000);
            status = false;
            cout << "Signal:[DIS]-" << digital_bit << " ";
        }
        break;
    }
    return 0;
}

void poll() {

    for (int i = 0; i < t; i++) {
        if (feed_rate <= t) {
            feed_rate = feed_rate + 2.1453;
            ext_rate = ext_rate + 0.1453;
            cout << "Extrusion rate: " << ext_rate << " ";
            cout << "Feed rate: " << feed_rate << " ";;
            Sleep(1000);
        }
    }
}

int main() {

    cout << "Extruder getting started\r" << flush;
    Sleep(2000);
    cout << "                               __  __                                       " << endl;
    cout << "   _____ ___  _   __ ____     / / / /___   ____ ___   ___   _____ ____ _    " << endl;
    cout << "  / ___// _ \\| | / // __ \\   / /_/ // _ \\ / __ `__ \\ / _ \\ / ___// __ `/    " << endl; 
    cout << " / /   /  __/| |/ // /_/ /  / __  //  __// / / / / //  __// /   / /_/ /     " << endl; 
    cout << "/_/    \\___/ |___/ \\____/  /_/ /_/ \\___//_/ /_/ /_/ \\___//_/    \\__,_/      " << endl; 
    std::cout << "revo Hemera Emulator | version 1.3" << std::endl;
    std::cout << "MSc. Mechatronics - Mechatronics Design Build | University of Southern Denmark" << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << "\n\t\t\t   Author: J A C O B  T H O M A S  P U T H U K E R I L\n\n";
    std::cout << "\t\t\t\t\t\t    Repo: github.com/Jacob8089" << std::endl;
    std::cout << "\t\t\t\t\t\t\t\t   Uni: sdu.dk\n\n";
    std::cout << "==============================================================================" << std::endl;
    //auto start_time=high_resolution_clock::now();
    cout << "Enter the width of the material(mm): " << endl;
    cin >> w;
    cout << "Enter the height of the material(mm): " << endl;
    cin >> h;
    cout << "Enter the depth of the material(mm): " << endl;
    cin >> d;
    cout << "\nHot end getting ready with filament. Internals ready to poll" << endl;
    Sleep(5000);

    cout << "Temperature reached till 300°C. Processing time: " << processTime()/60 << " Hrs" << endl;

    std::thread t1(task, flag);
    std::thread t2(poll);

    system("Pause>0");
}