/* header file for Gaddis 11.4 & 11.5
*/

#ifndef WEATHER_H
#define	WEATHER_H

class weather{
public:
    std::string name;
    int tRain;
    int hTemp;
    int lTemp;
    int aTemp;
    
    void getInfo(void){
        std::string temp;
        std::cout<<"Please Enter info relevant to "<<name<<" (whole numbers):\n";
        do{
            std::cout<<"Total Rainfall:  ";
            std::getline(std::cin,temp);
        }while(!isNum(temp));
        tRain=isNum(temp);
        do{
            std::cout<<"Highest Temp:  ";
            std::getline(std::cin,temp);
        }while(!(isNum(temp)>=-100&&isNum(temp)<=140));
        hTemp=isNum(temp);
        do{
            std::cout<<"Lowest Temp:  ";
            std::getline(std::cin,temp);
        }while(!(isNum(temp)>=-100&&isNum(temp)<=140));
        lTemp=isNum(temp);
        do{
            std::cout<<"Average Temp:  ";
            std::getline(std::cin,temp);
        }while(!isNum(temp));
        aTemp=isNum(temp);
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

#endif	/* WEATHER_H */

