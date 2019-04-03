#среднее арифметическое чисел
def srednee(F):
    """#эта функция делает среднее арифметическое ниже пишем тесты,создаём файлик
    >>> g.open('1.txt','w')
    >>> g.write('    1   2    \\n  -3  ')#  //только для перевода на новую строку при записи в файл
    >>> g.close()
    >>> srednee('1.txt')
    (0.,0)
    """
    try:
        f=open(F,'r')
        s=0
        n=0
        for line in f:#берем строку из файла
            for y in line.split(' '):#превращаем в список с вырез пробелами
                for z in y.split('\n'):
                    if x!='':
                        s+=int(x)#получаем элементы
                        n=1#получаем колличество
        f.close()
        return s/n,0
    except FileNotFoundError:#нет файла
        return 0, 1#второй возвращам ошибку
    except ZeroDivisionError:
        return 0,2 #пустой файл
    except:
        return 0,3
import doctest
doctest.testmod()#запускаем выше написанные тесты

