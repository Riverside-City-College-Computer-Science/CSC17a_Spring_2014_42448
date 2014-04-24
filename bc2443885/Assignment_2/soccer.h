// header file for Gaddis 11.6 

#ifndef SOCCER_H
#define	SOCCER_H

class player{
public:
    std::string name;
    int num;
    int score;
    
    void getInfo(void){
        std::string temp;
      //Get Name
            std::cout<<"Player Name:  ";
            std::getline(std::cin,name);
      //Get Number
        do{
            std::cout<<"Player Number:  ";
            std::getline(std::cin,temp);
        }while(!(isNum(temp)>=0));
        num=isNum(temp);
      //Get Score
        do{
            std::cout<<"Player Score:  ";
            std::getline(std::cin,temp);
        }while(!(isNum(temp)>=0));
        score=isNum(temp);
    }
    
    void printInfo(void){
        std::cout<<std::endl
                 <<std::setw(10)<<std::left<<name<<" | "
                 <<std::setw(10)<<std::left<<num<<" | "
                 <<std::setw(10)<<std::left<<score<<" | ";
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

#endif	/* SOCCER_H */

