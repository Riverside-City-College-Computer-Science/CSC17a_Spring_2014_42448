/* 
 * File:   Array1D.h
 * Author: Scott Nevin
 * Created on April 9, 2014, 1:26 PM
 */

#ifndef ARRAY1D_H
#define	ARRAY1D_H

class Array1D{
   private:
       int *data;
       int size;
       void fillArray();//utility function
       void setsize(int);//Another utility function
   public:
       Array1D(int);
       ~Array1D(){
           delete []data;
       }
       void prntArray(int);
};

#endif	/* ARRAY1D_H */

