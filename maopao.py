# 冒泡和选择排序


# 这是个虚假的冒泡算法，本来想写冒泡排序，结果随手写成了这样，后来发现这个是选择排序
# 这种算法是从前往后对比，每次都往后移一位，将后面的数中最小的放到当前的位置
def mympsort(hlist):
    for i in range(len(hlist)):
        for j in range(i+1, len(hlist)):
            if hlist[i] > hlist[j]:
                hlist[i], hlist[j] = hlist[j], hlist[i]
    print(hlist)


# 这个是真正的冒泡排序，即每次只是移动相邻的两位，经过length-1次
def mpsort(hlist):
    for i in range(len(hlist)-1):
        for j in range(len(hlist)-i-1):
            if hlist[j] > hlist[j+1]:
                hlist[j], hlist[j+1] = hlist[j+1], hlist[j]
    print(hlist)


if __name__ == "__main__":
    mympsort([75, 87, 56, 45, 89, 100, 76, 34, 89, 97])
    mpsort([75, 87, 56, 45, 89, 100, 76, 34, 89, 97])
    print(sorted([75, 87, 56, 45, 89, 100, 76, 34, 89, 97]))
