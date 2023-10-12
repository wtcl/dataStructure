# 递归算法


# 求解 n!
def recure(n):
    if n == 1:
        return 1
    else:
        return recure(n-1)*n


# 折半查找(递归实现)
def halffind(s, e, num, testlist):
    if s > e:    # 表示没有找到
        return -1
    mid = (s + e)//2
    if testlist[mid] < num:
        return halffind(mid+1, e, num, testlist)
    elif testlist[mid] > num:
        return halffind(s, mid-1, num, testlist)
    else:
        return mid


if __name__ == "__main__":
    print(recure(6))
    test = [5, 13, 19, 21, 37, 56, 64, 75, 80, 88, 92]
    print(halffind(0, len(test)-1, 21, test))
