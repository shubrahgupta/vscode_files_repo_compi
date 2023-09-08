import string
import sys


def isValid(s):
    # code here

    comp = s.split('.')

    flag = True
    for i in range(len(comp)):
        if comp[i] == '':
            return False
        elif (len(comp[i]) > 3):
            return False
        for j in comp[i]:
            if ord(j) > 57 or ord(j) < 48:
                return False

        if (int(comp[i]) >= 0 and int(comp[i]) <= 255 and flag):
            continue
        else:
            flag = False
            return flag
    return flag

    

if __name__ == "__main__":
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    t = int(input())
    for _ in range(0, t):
        s = input()
        if (isValid(s)):
            print(1)
        else:
            print(0)
        # for i in s:
        #     if ord(i) > 57 or ord(i) < 48 or ord(i) != 46:
        #         print(False)
        #     else:
        #         print(True)
    # a = "frefe"
    # print(bytearray(a))
    # for i in range(len(a)):
    #     print(ord(a[i]))
