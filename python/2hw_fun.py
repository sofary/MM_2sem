def read(F):
    try: 
        f=open(F,'r')
        s=[]
        h=0
        for line in f:
            for y in line.split(' '):
                for z in y.split('\n'):
                    if z!='':
                        h=h+1
                        s.append(int(z))
        f.close
        if h==0:
            return 0,-1 

        return s,0
    except FileNotFoundError :
            return 0,-2
 
    except :
            return 0,-3
      
      
      
      
def task(s):
    i=1
    pr=1

    while i< len(s):
      #print(i)      
      if s[i-1]<s[i] :
        pr=pr+1
      else:
            if pr>1 :

                dub(i-pr,i-1,s)
                #print(s)
                i=i+pr
                pr=1
        
      if  i==len(s)-1:
            dub(i-pr+1,i,s)
            #print(s)
            
            i=i+pr 
            pr=1       

                
            
      i=i+1
      #print(len(s))
    return s
  
  
  
def dub(nach,kon, s):
    h=nach
    while  h<=kon:
      s.insert(h,s[h])
      h=h+2
      kon=kon+1 
