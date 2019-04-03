import math
def sr(F='1.txt'):
    """
    Srednee arif + srednee geometricheskoe
    >>> g=open('1.txt','w')
    >>> u=g.write(' 5    \\n            2  2 \\n     2')
    >>> g.close()
    >>> sr()
    (0, 2.0, 2.0)
    >>> g=open('2.txt','w')
    >>> u= g.write('')
    >>> g.close()
    >>> sr('2.txt')
    (-2, 0, 0)
    >>> g=open('2.txt','w')
    >>> u=g.write('  7 a \\n')
    >>> g.close()
    >>> sr('2.txt')
    (-1, 0, 0)
    >>> print(sr('kklklk3.txt'))
    (-3, 0, 0)
    >>> g=open('1.txt','w')
    >>> u=g.write('    \\n      22      -1  2 \\n     2')
    >>> g.close()
    >>> sr()
    (-1, 0, 0)
    
    """
    try:
        f=open(F,'r')
        s=0.
        p=1.
        n=0
        for line in f:
            for x1 in line.split(' '):
                for x in x1.split('\n'):
                    if(x!=''):
                        n+=1;
                        s+=float(x)
                        p*=float(x)
        f.close()
        return 0,s/n, math.pow(p,1./n)
    except ZeroDivisionError:
        return -2,0,0
    except FileNotFoundError:
        return -3,0,0
    except :
        return -1,0,0
import doctest
doctest.testmod()  
print(sr('1'))
