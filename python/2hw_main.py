from fun import read, task,dub
 
def main(F):
    """
      
    >>> g=open('66.txt','w')#empty
    >>> main('66.txt')
    -1
    
    
    >>> main('9991.txt')        
    -2
    

    >>> g=open('1.txt','w')
    >>> u=g.write('1 2 3 -7 -7 -8 4 5')
    >>> g.close()
    >>> main('1.txt')        
    [1, 1, 2, 2, 3, 3, -7, -7, -8, -8, 4, 4, 5, 5]

    >>> g=open('1.txt','w')
    >>> u=g.write('1 5 ')
    >>> g.close()
    >>> main('1.txt')        
    [1, 1, 5, 5]

    """
    #F='1.txt'
        
    s,er=read(F)
      
    if er==0:
        #print(s)    
        s1=task(s)
        print(s1)
    else: 
        print(er)
import doctest
doctest.testmod()  
#main('1.txt')      
