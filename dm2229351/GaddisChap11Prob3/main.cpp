/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 29, 2014, 11:42 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct Division{
    float q1sales,q2sales,q3sales,q4sales;
    float ann_sales,avg_quart;
};

using namespace std;

void input( Division&);
void print(Division);

int main(int argc, char** argv) {
    Division north,east,west,south;
    cout << "\nPlease enter the sales figures for north division\n";
    input(north);
    print (north);
    cout << "\nPlease enter the sales figures for east division\n";
    input(east);
    print (east);
    cout << "\nPlease enter the sales figures for west division\n";
    input(west);
    print (west);    
    cout << "\nPlease enter the sales figures for south division\n";
    input(south);
    print (south);    
    return 0;
}

void input(Division &div)
{
    float sales[4];
    float input;
    for(int i=0;i<4;i++)
    {
        cout << "Please enter quarter " << i+1 << " sales: " ;
        cin >> input;
        if(input<0)
        {
            cout << "\nSales not valid please re-enter: ";
                    cin >> input;
        }
        sales[i]=input;
    }
    div.q1sales=sales[0];
    div.q2sales=sales[1];
    div.q3sales=sales[2];
    div.q4sales=sales[3];
    
        
}
void print(Division div)
{
    float ann = (div.q1sales+div.q2sales+div.q3sales+div.q4sales);
    float avv = ((div.q1sales+div.q2sales+div.q3sales+div.q4sales)/4.0);
    cout << "Total annual sales: $" << ann << endl;
    cout << "Total average quarterly sales: $" << avv;
}