/* Header file for Gaddis 11.1 & 11.2
 */

#ifndef MOVIEDATA_H
#define	MOVIEDATA_H

class movieData{
public:
    std::string title;
    std::string director;
    int year;
    int runtime;
    int cost;
    int revenue;

    std::string details(void){
        std::string d;
        std::stringstream y;
        std::stringstream h;
        std::stringstream m;
        
        y<<year;
        h<<runtime/60;
        m<<runtime%60;
        
        d = title + 
            "\nDirector:      " + director + 
            "\nRelease Year:  " + y.str() +
            "\nRuntime:       " + h.str() + ":" + m.str();
        
        return d;
    }
    
    std::string profit(void){
        std::string p;
        std::stringstream foo;
        
        foo<<(revenue - cost);
        
        p = "\nProfit:  " + foo.str();
        return p;
    }
};



#endif	/* MOVIEDATA_H */

