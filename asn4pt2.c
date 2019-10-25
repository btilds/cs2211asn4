//
//  main.c
//  Asn4pt2
//
//  Created by Ben Tilden on 2018-11-04.
//  Copyright © 2018 Ben Tilden. All rights reserved.
//

#include <stdio.h>

void calculate(){
    double n, i, e;
    double s = 1;
    double pi = 0;
    
    printf("Enter in a value of epsilon :\n");
    scanf("%lf", &e);
    n = (2/e);
    
    for(i = 1; i <= (n*2); i += 2){
        pi = pi + s * (4/i);
        s = -s;
    }
    printf("The approximate value of Pi is: %1.16lf\n", pi);
}

int main() {
    calculate();
}


