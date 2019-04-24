import random
import time
from operator import itemgetter, attrgetter, methodcaller


def create(n):
    i=0
    m=[]
    tmp=0
    while i<n:
        tmp=random.randint(-n,n)
        m.append((key(tmp,i), tmp))
        i+=1
    return m


def key(m,j):
    i = 0
    l = 0
    while i < 16:
        if m & 1 == 1:
            l += 1
        m = m >> 1
        i += 1
    kk=[]
    kk.append(l)
    kk.append(-j)
   # print kk
    return kk



def Merge(m, l, mid, r):
    it1 = 0
    it2 = 0
    result = []
    i = 0
    while i < r - l:
        result.append(0)
        i += 1

    while l + it1 < mid and mid + it2 < r:
        if m[l + it1] < m[mid + it2]:
            result[it1 + it2] = m[l + it1]
            it1 += 1
        else:
            result[it1 + it2] = m[mid + it2]
            it2 += 1

    while l + it1 < mid:
        result[it1 + it2] = m[l + it1]
        it1 += 1

    while mid + it2 < r:
        result[it1 + it2] = m[mid + it2]
        it2 += 1
    i = 0
    while i < it1 + it2:
        m[l + i] = result[i]
        i += 1


def MergerRec(m, l, r,k):
    if l + 1 >= r:
        return
    mid = int((l + r) / 2)
    MergerRec(m, l, mid,0)
    MergerRec(m, mid, r,0)
    Merge(m, l, mid, r)
    if k==1:
        return m
#***********************#

def Merger(m, n):
    i = 1
    j = 0
    while i <= n:
        j = 0
        while j <= n - i:
            #print(j, j + i, min(j + 2 * i, n - 1))
            Merge(m, j, j + i, min(j + 2 * i, n))
            j += 2 * i
        i *= 2
    return m
#*************************#

def partition(m, l, r):
     v = m[(l + r) // 2]
     i = l
     j = r
     while i <= j:
         while m[i] < v:
             i += 1
         while m[j] > v:
             j -= 1
         if i >= j:
             break
         m[i], m[j] = m[j], m[i]
         i += 1
         j -= 1
     return j


def Qsort(m, l, r, k):
    if l < r:
        q = partition(m, l, r)
        Qsort(m, l, q, 0)
        Qsort(m, q + 1, r, 0)
    if k == 1:
        return m

def Heapify(m, i, n):
  left = 2 * i + 1
  right = 2 * i + 2
  largest = i
  if left < n and m[left] > m[largest]:
      largest = left
  if right < n and m[right] > m[largest]:
      largest = right
  if largest != i:
      m[i], m[largest] = m[largest], m[i]
      Heapify(m, largest, n)

def BuildBinaryHeap(m, n):
    i = n // 2
    while i > -1:
        Heapify(m, i, n)
        i -= 1

def HeapSort(m, n):
    BuildBinaryHeap(m, n)
    heap_size = n
    i = n -1
    while i > -1:
        m[0], m[i] = m[i], m[0]
        heap_size -= 1
        Heapify(m, 0, heap_size)
        i -= 1
    return m

def pravda(m,n):
    if m == n:
        print('ok')
    else:
        print('error')


def main():

    n=1000000
    m=create(n)
    print("Input list:")
    #print(m)
    mm=m[:]
    print('standart sort:  ')
    q0=time.time()
    mm.sort()
    q1=time.time()
    print('Time for standart sort: ')
    print(q1-q0)
    #print(mm)
    print
    print ('time for Recursiv.Sliyanie sort:   ')
    q2=time.time()
    pravda(MergerRec(m[:], 0, n, 1), mm)
    q3=time.time()
    print(q3-q2)
    print
    print ('time for Sliyanie sort:   ')
    q4=time.time()
    pravda(Merger(m[:], n), mm)
    q5=time.time()
    print(q5-q4)
    print
    print ('time for Qsort:   ')
    q6=time.time()
    pravda(Qsort(m[:], 0, n-1, 1), mm)
    q7=time.time()
    print(q7-q6)
    print
    print ('time for HeapSort:   ')
    q8=time.time()
    pravda(HeapSort(m[:], n), mm)
    q9=time.time()    
    print(q9-q8)
    print



main()


