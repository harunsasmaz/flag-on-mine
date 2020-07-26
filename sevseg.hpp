#pragma once

#include <vector>
#include <cmath>
#include "setup.hpp"
#include "buffer.hpp" 
#include "color.hpp"

using namespace std;

const string numbers[10][5] = {
    {
        "╻══╻",
        "║  ║",
        "║  ║",
        "║  ║",
        "╹══╹"
    },

    {
        "   ╻",
        "   ║",
        "   ║",
        "   ║",
        "   ╹"
    },

    {
        " ══╻",
        "   ║",
        "╻══╹",
        "║   ",
        "╹══ "
    },

    {
        " ══╻",
        "   ║",
        " ══║",
        "   ║",
        " ══╹"
    }, 

    {
        "╻  ╻",     
        "║  ║",     
        "╹══║",     
        "   ║",     
        "   ╹"
    },

    {
        "╻══ ",
        "║   ",
        "╹══╻",
        "   ║",
        " ══╹"
    },

    {
        "╻══ ",
        "║   ",
        "║══╻",
        "║  ║",
        "╹══╹"
    },

    {
        " ══╻",
        "   ║",
        "   ║",
        "   ║",
        "   ╹"
    },

    {
        "╻══╻",
        "║  ║",
        "║══║",
        "║  ║",
        "╹══╹"
    },
    
    {
        "╻══╻",
        "║  ║",
        "╹══║",
        "   ║",
        " ══╹"
    }

};

class SevSegDisp{
    public:
        SevSegDisp(int,int);
        
        void operator ++(){
            if(number > int(pow(10, noOfDigits)) - 1) return;
            else ++number;
        }

        void operator --(){
            if(number) --number;
        }
        
        void set(int);
        void update(string);

    
    private:
    int noOfDigits;
    int number;
} flagDisp(5, 0), timeDisp(5, 0);

SevSegDisp::SevSegDisp(int dig, int n){
    noOfDigits = dig;
    number = n;
}

void SevSegDisp::set(int n){
    number = n;
}

void SevSegDisp::update(string prepend){
    int homeLine = writeBuf.getCurrLine();
    int nos[noOfDigits];
    int num = number;
    int dig = noOfDigits; 
    while(num || dig){
        nos[dig-1] = num % 10;
        num /= 10;
        --dig;
    }
    for(int i = 0; i < noOfDigits; ++i){
        for(auto str : numbers[nos[i]]){
            if(!i) writeBuf << reset << prepend;
            writeBuf << red_fg << str << " " << "\n" << reset;
        }
        if(i != noOfDigits -1) writeBuf.goToLine(homeLine); 
    }
}