from sys import *  
def fileprint ( ) : 
     print( "Hello World"   , file= sys . stderr   )   
def exception ( ) : 
     raise ValueError  ( "Weird value"  ) .with_traceback()   
if __name__ == "__main__" :
     print( "Hello World"   , end='')   
