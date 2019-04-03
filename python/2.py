#сократить разделители между словами до одного
def words(s,q):
    i=0
    start=0
    while i < int(len(s)):
        if s[i] in q:
            if start ==0:
                s=s[0:i]+s[i+1:int(len(s))]#срез строки от 0 до i и дописывание
                i=i-1
            stat=0#почему
        else:
            stat=1
        i=i+1
    return s
def main():
    s='    fffrfqer6767  qt111rqt    tqrt    \n            qte qt   qttr    '
    q=' 1\n'
    print(s)
    s=words(s,q)
    print(s)
main()
