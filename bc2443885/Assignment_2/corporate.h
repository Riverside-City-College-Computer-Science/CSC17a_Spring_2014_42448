/* Header file for Gaddis 11.3
 */

#ifndef CORPORATE_H
#define	CORPORATE_H

class corporate{
public:
    std::string name;
    int q1;
    int q2;
    int q3;
    int q4;
    int t;
    int av;
    
    void getInfo(void){
        std::string temp;
        std::cout<<"Please Enter info relevant to "<<name<<" division:\n";
        do{
            std::cout<<"1st Quarter Sales:  ";
            std::getline(std::cin,temp);
        }while(!isNum(temp));
        q1=isNum(temp);
        do{
            std::cout<<"2nd Quarter Sales:  ";
            std::getline(std::cin,temp);
        }while(!isNum(temp));
        q2=isNum(temp);
        do{
            std::cout<<"3rd Quarter Sales:  ";
            std::getline(std::cin,temp);
        }while(!isNum(temp));
        q3=isNum(temp);
        do{
            std::cout<<"4th Quarter Sales:  ";
            std::getline(std::cin,temp);
        }while(!isNum(temp));
        q4=isNum(temp);
        setAnnual();
        setAverage();
    }
    void setAnnual(void){
        t = q1+q2+q3+q4;
    }
    void setAverage(void){
        setAnnual();
        av = t/4;
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


#endif	/* CORPORATE_H */

