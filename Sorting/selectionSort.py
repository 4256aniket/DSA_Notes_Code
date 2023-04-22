def selectionSort(li):
    for i in range(len(li)-1):
        minIndex = i
        for j in range(i+1, len(li)):
            if(li[j] < li[minIndex]):
                minIndex = j
        li[minIndex],li[i] = li[i],li[minIndex]
        
n = int(input())
li = [int(x) for x in input().split()]
selectionSort(li)
print(li)