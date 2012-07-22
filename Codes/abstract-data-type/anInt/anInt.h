#ifndef ANINT_H
#define ANINT_H

class anInt {
    // OVERVIEW: a trivial class to get/set a 
    //           single integer value
    int    v;
public:
    int    get_value();
          // EFFECTS: returns the current    
          //          value
    void   set_value(int newValue);    
          // MODIFIES: this
          // EFFECTS: sets the current value 
          // equal to arg
};

#endif
