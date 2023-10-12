# 顺序表


class SeqList():
    def __init__(self, max=10):
        self.max = max
        self.num = 0
        self.data = [None] * self.max

    def is_empty(self):
        return self.num == 0

    def is_full(self):
        return self.num == self.max

    def __getitem__(self, index):
        if not isinstance(index, int):
            raise TypeError
        if 0 <= index < self.max:
            return self.data[index]
        else:
            raise IndexError

    def __setitem__(self, index, value):
        if not isinstance(index, int):
            raise TypeError
        if 0 <= index < self.max:
            self.data[index] = value
        else:
            raise IndexError

    def locate_item(self, value):
        for i in range(self.num):
            if self.data[i] == value:
                return i
        return -1

    def count(self):
        return self.num

    def append_last(self, value):
        if self.num > self.max:
            print("list is full")
        else:
            self.data[self.num] = value
            self.num += 1

    def insert(self, index, value):
        if self.num >= self.max:
            print("list is full")
        if not isinstance(index, int):
            raise TypeError
        if index < 0 or index > self.num:
            raise TypeError
        print("num：", self.num)
        for i in range(self.num, index, -1):
            self.data[i] = self.data[i-1]
        self.data[index] = value
        self.num += 1

    def remove(self, index):
        if not isinstance(index, int):
            raise TypeError
        if index < 0 or index >= self.num:
            raise IndexError
        for i in range(index, self.num):
            self.data[i] = self.data[i+1]
        self.num -= 1

    def print_list(self):
        for i in range(0, self.num):
            print(self.data[i])

    def destroy(self):
        self.__init__()


if __name__ == "__main__":
    sq = SeqList(20)
    print(sq.max)
    sq.insert(0, 9)
    sq.insert(1, 10)
    sq.print_list()
