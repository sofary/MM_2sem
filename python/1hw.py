import math

def sch(F):
    """

    >>> g=open('1.txt','w')
    >>> u=g.write(' 1    \\n            2  3 \\n     4')
    >>> g.close()
    >>> sch('1.txt')
    (26, 23, 0)
    >>> g=open('1.txt','w')
    >>> u= g.write('')
    >>> g.close()
    >>> sch('2.txt')
    (0, 1, -1)
    >>> g=open('1.txt','w')
    >>> u=g.write('  7 a \\n')
    >>> g.close()
    >>> sch('1.txt')
    (0, 3, -1)
    >>> print(sch('fgfg.txt'))
    (0, 1, -1)
    >>> g=open('1.txt','w')
    >>> u=g.write('    \\n      22      -1  2 \\n     2')
    >>> g.close()
    >>> sch('1.txt')
    (178, 262, 0)
    
    """
    try:
        n=2
        f = open(F, 'r')
        s=0#сумма
        d=0#производная
        h=0
        for line in f:#берем строку из файла
           
            for y in line.split(' '):
                for z in y.split('\n'):
                    if z!='':
                        #print(z)
                        h=h+1 
                        if h!=1:
                            d=d*n +s
                            s=s*n+int(z) 
                            

                           
                        else:
                            s=int(z)
                            d=0
                        
                        
        #print("proiz = ",d)
        #print("sum =",s)
        f.close()
        if h ==0:
            return 0,2,-1 #пустой файл  
        return s,d,0 
    
    except FileNotFoundError:#нет файла
        return 0,1,-1#второй возвращам ошибку

    except:
        return 0,3,-1


def main():
        ff='1.txt'
       
        a=sch(ff)
        #print(a)
        if a[2]<0:
            print("Error",a[1])
        else:
            print("Summa = ",a[0])
            print("Proizvodnaya = ",a[1])
import doctest
doctest.testmod()
main()

