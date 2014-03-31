/* 
 * File:   customer.h
 * Author: rente_000
 *
 * Created on March 30, 2014, 8:02 AM
 */

#ifndef CUSTOMER_H
#define	CUSTOMER_H

class customer{
public:
  //Name
    std::string name;
  //Address
    std::string address;
    std::string strName;
    std::string city;
    std::string state;
    int zip;
    int street;
  //Phone Number
    std::string phone;
  //Account Balance
    float balance;
  //Last Payment
    std::string date;
    int month;
    int year;
    
    
    void setInfo(void){
        std::string temp;
      //Name
        std::cout<<"Name:  ";
        std::getline(std::cin,name);
      //Address
        do{
            std::cout<<"Street Number:  ";
            std::getline(std::cin,temp);
        }while(!isNum(temp)||isNum(temp)<0);
        street=isNum(temp);
        std::cout<<"Street Name:  ";
        std::getline(std::cin,strName);
        std::cout<<"City:  ";
        std::getline(std::cin,city);
        std::cout<<"State:  ";
        std::getline(std::cin,state);
        do{
            std::cout<<"Zip Code:  ";
            std::getline(std::cin,temp);
        }while(isNum(temp)>=100000||isNum(temp)<10000);
        zip=isNum(temp);
        setAddress();
      //Telephone
        std::cout<<"Cell Phone:  ";
        std::getline(std::cin,phone);
      //Balance
        std::cout<<"Balance:  ";
        std::cin>>balance;
        std::cin.ignore();
      //Date from last payment
        std::cout<<"Month Last Paid (int):  ";
        std::cin>>month;
        std::cin.ignore();
        std::cout<<"Year Last Paid(int):  ";
        std::cin>>year;
        std::cin.ignore();
        setDate();
        
    }
    void setAddress(void){
        std::stringstream str;
        str<<street;
        std::stringstream z;
        z<<zip;
        
        address = str.str() + " " + strName + "\n               " 
                + city + ", " + state + "\n               "
                + z.str();
    }
    void setDate(void){
        std::stringstream m;
        m<<month;
        std::stringstream y;
        y<<year;
        
        date = m.str() + "/" + y.str();
    }
    std::string printInfo(void){
        std::stringstream s;
        s<<balance;
        return   "Name:          " + name + "\n" 
               + "Address:       " + address + "\n" 
               + "Phone:         " + phone + "\n" 
               + "Balance:      $" + s.str() + "\n" 
               + "Last Payment:  " + date + "\n";
    }
    
    int isNum(std::string a){
        int n=0;
        std::string b=a;
        for(int i=0;i<a.length();i++){
            if((a[i]-'0'<0)||(a[i]-'0'>9))
                return 0;
        }
        for(int i=0,j=a.length()-1;i<a.length();i++){
            b[i]=a[j];
            j--;
        }

        for(int i=a.length()-1;i>=0;i--)
            n+=(b[i]-'0')*pow(10,i);
        return n;
    }
};

#endif	/* CUSTOMER_H */

